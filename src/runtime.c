#include "runtime.h"

/* The boxes key: one PHP object per native address and class, so two classes at one address (a struct and
 * its first field, or a fromPointer() of another class) each keep their own handle. */
typedef struct {
	void *ptr;
	zend_class_entry *ce;
} phpft_box_key;

/* A handle property reads the native record; a handle that holds NULL has none to read. */
static zval *phpft_read_record(zend_object *obj, zend_string *name, int type, void **cache_slot, zval *rv)
{
	if (!PHPFT_PROBE_OFF("freetype-null-record") && phpft_handle_from(obj)->ptr == NULL) {
		zend_value_error("%s holds NULL: it was released, or made from address 0", ZSTR_VAL(obj->ce->name)); /* binding:freetype-null-record */
		return &EG(uninitialized_zval);
	}
	return ((const phpft_handlers *) obj->handlers)->read(obj, name, type, cache_slot, rv);
}

/* isset() and empty() on a record property ask the native record; a handle that holds NULL has none. */
static int phpft_has_record(zend_object *obj, zend_string *name, int check_empty, void **cache_slot)
{
	zval rv, *value;
	int has;

	if (phpft_handle_from(obj)->ptr == NULL) {
		return zend_std_has_property(obj, name, check_empty, cache_slot);
	}
	value = obj->handlers->read_property(obj, name, BP_VAR_IS, NULL, &rv);
	has = check_empty == ZEND_PROPERTY_NOT_EMPTY ? zend_is_true(value) : Z_TYPE_P(value) != IS_NULL;
	if (value == &rv) {
		zval_ptr_dtor(&rv);
	}
	return has;
}

/* var_dump() and print_r() show the native record, read field by field. */
static HashTable *phpft_record_debug_info(zend_object *obj, int *is_temp)
{
	zend_property_info *info;
	HashTable *fields;

	if (phpft_handle_from(obj)->ptr == NULL) {
		*is_temp = 0;
		return zend_std_get_properties(obj);
	}
	*is_temp = 1;
	fields = zend_new_array(zend_hash_num_elements(&obj->ce->properties_info));
	ZEND_HASH_MAP_FOREACH_PTR(&obj->ce->properties_info, info) {
		zval rv, copy, *value;

		if (info->flags & ZEND_ACC_STATIC) {
			continue;
		}
		value = obj->handlers->read_property(obj, info->name, BP_VAR_IS, NULL, &rv);
		ZVAL_COPY(&copy, value);
		if (value == &rv) {
			zval_ptr_dtor(&rv);
		}
		zend_hash_update(fields, info->name, &copy);
	} ZEND_HASH_FOREACH_END();

	return fields;
}

/* The GC sees the children a handle keeps alive. */
static HashTable *phpft_get_gc(zend_object *obj, zval **table, int *n)
{
	zend_get_gc_buffer *buffer = zend_get_gc_buffer_create();
	zval *props_table;
	int props_count;
	HashTable *props = zend_std_get_gc(obj, &props_table, &props_count);

	for (int i = 0; i < props_count; i++) {
		zend_get_gc_buffer_add_zval(buffer, &props_table[i]);
	}
	zend_get_gc_buffer_add_zval(buffer, &phpft_handle_from(obj)->children);
	zend_get_gc_buffer_use(buffer, table, n);

	return props;
}

static zend_object *phpft_create_object(zend_class_entry *ce)
{
	phpft_handle *intern = zend_object_alloc(sizeof(phpft_handle), ce);

	zend_object_std_init(&intern->std, ce);
	object_properties_init(&intern->std, ce);
	intern->std.handlers = ce->default_object_handlers;
	intern->ptr = NULL;
	ZVAL_UNDEF(&intern->children);

	return &intern->std;
}

static void phpft_forget(phpft_handle *intern)
{
	phpft_box_key key = { intern->ptr, intern->std.ce };

	if (intern->ptr != NULL
		&& zend_hash_str_find_ptr(&PHPFT_G(boxes), (const char *) &key, sizeof(key)) == &intern->std) {
		zend_hash_str_del(&PHPFT_G(boxes), (const char *) &key, sizeof(key));
	}
}

static void phpft_free_object(zend_object *object)
{
	phpft_handle *intern = phpft_handle_from(object);

	phpft_forget(intern);
	intern->ptr = NULL;
	zval_ptr_dtor(&intern->children);
	zend_object_std_dtor(object);
}

void phpft_handle_setup_in(phpft_handlers *handlers, zend_class_entry *ce, zend_object_read_property_t read)
{
	zend_object_handlers *h = &handlers->std;

	memcpy(h, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	h->offset = XtOffsetOf(phpft_handle, std);
	h->free_obj = phpft_free_object;
	h->clone_obj = NULL;
	h->get_gc = phpft_get_gc;
	handlers->read = read;
	if (read != NULL) {
		h->read_property = phpft_read_record;
		h->has_property = phpft_has_record;
		h->get_debug_info = phpft_record_debug_info;
	}

	ce->create_object = phpft_create_object;
	ce->default_object_handlers = h;
	ce->ce_flags |= ZEND_ACC_NOT_SERIALIZABLE | ZEND_ACC_FINAL;
}

void phpft_struct_setup(zend_class_entry *ce)
{
	static zend_object_handlers handlers;
	static bool ready = false;

	if (!ready) {
		memcpy(&handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
		handlers.clone_obj = NULL;
		ready = true;
	}
	ce->default_object_handlers = &handlers;
	ce->ce_flags |= ZEND_ACC_NOT_SERIALIZABLE | ZEND_ACC_FINAL;
}

/* Drops the children whose native object was released, so a long-lived parent does not grow. */
static void phpft_prune_children(phpft_handle *owner)
{
	zend_ulong index;
	zval *child;

	ZEND_HASH_FOREACH_NUM_KEY_VAL(Z_ARRVAL(owner->children), index, child) {
		if (phpft_handle_from(Z_OBJ_P(child))->ptr == NULL) {
			zend_hash_index_del(Z_ARRVAL(owner->children), index);
		}
	} ZEND_HASH_FOREACH_END();
}

void phpft_box(zval *rv, void *ptr, zend_class_entry *ce, zend_object *parent)
{
	phpft_box_key key = { ptr, ce };
	zend_object *existing;

	if (ptr == NULL) {
		ZVAL_NULL(rv);
		return;
	}

	existing = zend_hash_str_find_ptr(&PHPFT_G(boxes), (const char *) &key, sizeof(key));
	if (existing != NULL) {
		ZVAL_OBJ_COPY(rv, existing);
		return;
	}

	object_init_ex(rv, ce);
	phpft_handle_from(Z_OBJ_P(rv))->ptr = ptr;
	zend_hash_str_update_ptr(&PHPFT_G(boxes), (const char *) &key, sizeof(key), Z_OBJ_P(rv));

	if (parent != NULL) {
		phpft_handle *owner = phpft_handle_from(parent);
		zval child;

		if (Z_TYPE(owner->children) != IS_ARRAY) {
			array_init(&owner->children);
		} else {
			phpft_prune_children(owner);
		}
		ZVAL_OBJ_COPY(&child, Z_OBJ_P(rv));
		zend_hash_next_index_insert(Z_ARRVAL(owner->children), &child);
	}
}

void *phpft_handle_ptr(zval *zv)
{
	return phpft_handle_from(Z_OBJ_P(zv))->ptr;
}

void phpft_release(zend_object *obj)
{
	phpft_handle *intern = phpft_handle_from(obj);
	zval children, *child;

	phpft_forget(intern);
	intern->ptr = NULL;

	ZVAL_COPY_VALUE(&children, &intern->children);
	ZVAL_UNDEF(&intern->children);
	if (Z_TYPE(children) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL(children), child) {
			phpft_release(Z_OBJ_P(child));
		} ZEND_HASH_FOREACH_END();
	}
	zval_ptr_dtor(&children);
}

#ifdef PHPFT_PROBES
bool phpft_probe_off(const char *id)
{
	const char *off = getenv("PHPFT_PROBE_OFF");

	return off != NULL && strcmp(off, id) == 0;
}
#endif
