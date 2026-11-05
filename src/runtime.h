#ifndef PHPFT_RUNTIME_H
#define PHPFT_RUNTIME_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "php_freetype.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_TRUETYPE_TABLES_H

ZEND_BEGIN_MODULE_GLOBALS(freetype)
	HashTable boxes;               /* (native address, class) => zend_object*, live handles only, not refcounted */
ZEND_END_MODULE_GLOBALS(freetype)

ZEND_EXTERN_MODULE_GLOBALS(freetype)
#define PHPFT_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(freetype, v)

typedef struct {
	void *ptr;                     /* the native handle; NULL once released, or from fromPointer(0) */
	zval children;                 /* handles whose native object goes with this one: a library's faces, a face's slot */
	zend_object std;
} phpft_handle;

static zend_always_inline phpft_handle *phpft_handle_from(zend_object *obj)
{
	return (phpft_handle *) ((char *) obj - XtOffsetOf(phpft_handle, std));
}

/* Handle class setup: object layout, no clone, not serializable, final. read is the class's
 * read_property handler for the C record fields it exposes, or NULL. Each call site keeps its own
 * static handler table, so there is no limit on the number of handle classes. */
typedef struct {
	zend_object_handlers std;      /* first: obj->handlers points here */
	zend_object_read_property_t read;
} phpft_handlers;
void phpft_handle_setup_in(phpft_handlers *h, zend_class_entry *ce, zend_object_read_property_t read);
#define phpft_handle_setup(ce, read) do { static phpft_handlers phpft_h_; phpft_handle_setup_in(&phpft_h_, (ce), (read)); } while (0)
/* The PHP object holding ptr, or a new one of class ce; NULL ptr → null. A new object becomes a
 * child of parent (NULL for none), so releasing parent releases it. */
void phpft_box(zval *rv, void *ptr, zend_class_entry *ce, zend_object *parent);
/* The native pointer a handle parameter holds (NULL once released). */
void *phpft_handle_ptr(zval *zv);
/* The native object is gone: pointer cleared, identity entry dropped, kept string let go, children released. */
void phpft_release(zend_object *obj);
/* Struct class setup: final, no clone, not serializable. */
void phpft_struct_setup(zend_class_entry *ce);
/* A new struct object of class ce in rv; set its fields with the PHPFT_SET_* macros. */
#define PHPFT_SET_LONG(rv, field, value) zend_update_property_long(Z_OBJCE_P(rv), Z_OBJ_P(rv), field, sizeof(field) - 1, (zend_long) (value))
#define PHPFT_SET_BYTES(rv, field, bytes, len) zend_update_property_stringl(Z_OBJCE_P(rv), Z_OBJ_P(rv), field, sizeof(field) - 1, (const char *) (bytes), (len))
/* A C array field as a PHP list of ints. */
#define PHPFT_SET_LIST(rv, field, array) do { zval phpft_list_; array_init(&phpft_list_); \
	for (size_t phpft_i_ = 0; phpft_i_ < sizeof(array) / sizeof((array)[0]); phpft_i_++) add_next_index_long(&phpft_list_, (zend_long) (array)[phpft_i_]); \
	zend_update_property(Z_OBJCE_P(rv), Z_OBJ_P(rv), field, sizeof(field) - 1, &phpft_list_); zval_ptr_dtor(&phpft_list_); } while (0)

#ifdef PHPFT_PROBES
bool phpft_probe_off(const char *id);
# define PHPFT_PROBE_OFF(id) phpft_probe_off(id)
#else
# define PHPFT_PROBE_OFF(id) 0
#endif

/* __construct (private, empty), pointer() and fromPointer() for a handle class. fromPointer(0) answers a
 * handle that holds NULL, which every FreeType call receives as NULL. Any other address is trusted. */
#define PHPFT_HANDLE_METHODS(cls) \
	ZEND_METHOD(cls, __construct) { ZEND_PARSE_PARAMETERS_NONE(); } \
	ZEND_METHOD(cls, pointer) { ZEND_PARSE_PARAMETERS_NONE(); RETURN_LONG((zend_long) (uintptr_t) phpft_handle_ptr(ZEND_THIS)); } \
	ZEND_METHOD(cls, fromPointer) { zend_long p; ZEND_PARSE_PARAMETERS_START(1, 1) Z_PARAM_LONG(p) ZEND_PARSE_PARAMETERS_END(); \
		zend_class_entry *scope = zend_get_called_scope(execute_data); \
		if (p == 0) { object_init_ex(return_value, scope); return; } \
		phpft_box(return_value, (void *) (uintptr_t) p, scope, NULL); }

extern zend_class_entry *phpft_ce_FT_Library;
extern zend_class_entry *phpft_ce_FT_Face;
extern zend_class_entry *phpft_ce_FT_Size;
extern zend_class_entry *phpft_ce_FT_Size_Metrics;

void phpft_register_FT_Face(int module_number);
void phpft_register_FT_Size(int module_number);
void phpft_register_FT_Glyph(int module_number);
extern zend_class_entry *phpft_ce_FT_GlyphSlot;
/* FT_Size_Metrics copied into a new FT_Size_Metrics object. */
void phpft_size_metrics(zval *rv, const FT_Size_Metrics *m);

#endif
