#include "runtime.h"
#include FT_OUTLINE_H
#include "../stubs/FT_Glyph_arginfo.h"

zend_class_entry *phpft_ce_FT_GlyphSlot;
static zend_class_entry *phpft_ce_FT_Outline;
static zend_class_entry *phpft_ce_FT_Glyph_Metrics;
static zend_class_entry *phpft_ce_FT_Vector;
static zend_class_entry *phpft_ce_FT_Matrix;
static zend_class_entry *phpft_ce_FT_Bitmap;

PHPFT_HANDLE_METHODS(FT_GlyphSlot)
PHPFT_HANDLE_METHODS(FT_Outline)

/* A typed int property of a struct object: the type is enforced on write, so it is an int or, after
 * unset(), uninitialized; then PHP's own Error is thrown and the caller checks EG(exception). */
static FT_Long phpft_long_prop(zend_object *obj, const char *name, size_t len)
{
	zval rv, *value = zend_read_property(obj->ce, obj, name, len, false, &rv);

	return Z_TYPE_P(value) == IS_LONG ? (FT_Long) Z_LVAL_P(value) : 0;
}

static zval *phpft_slot_read(zend_object *obj, zend_string *name, int type, void **cache_slot, zval *rv)
{
	FT_GlyphSlot slot = phpft_handle_from(obj)->ptr;
	const char *n = ZSTR_VAL(name);

	if (strcmp(n, "glyph_index") == 0) { ZVAL_LONG(rv, slot->glyph_index); return rv; }
	if (strcmp(n, "linearHoriAdvance") == 0) { ZVAL_LONG(rv, slot->linearHoriAdvance); return rv; }
	if (strcmp(n, "linearVertAdvance") == 0) { ZVAL_LONG(rv, slot->linearVertAdvance); return rv; }
	if (strcmp(n, "format") == 0) { ZVAL_LONG(rv, slot->format); return rv; }
	if (strcmp(n, "bitmap_left") == 0) { ZVAL_LONG(rv, slot->bitmap_left); return rv; }
	if (strcmp(n, "bitmap_top") == 0) { ZVAL_LONG(rv, slot->bitmap_top); return rv; }
	if (strcmp(n, "metrics") == 0) {
		object_init_ex(rv, phpft_ce_FT_Glyph_Metrics);
		PHPFT_SET_LONG(rv, "width", slot->metrics.width);
		PHPFT_SET_LONG(rv, "height", slot->metrics.height);
		PHPFT_SET_LONG(rv, "horiBearingX", slot->metrics.horiBearingX);
		PHPFT_SET_LONG(rv, "horiBearingY", slot->metrics.horiBearingY);
		PHPFT_SET_LONG(rv, "horiAdvance", slot->metrics.horiAdvance);
		PHPFT_SET_LONG(rv, "vertBearingX", slot->metrics.vertBearingX);
		PHPFT_SET_LONG(rv, "vertBearingY", slot->metrics.vertBearingY);
		PHPFT_SET_LONG(rv, "vertAdvance", slot->metrics.vertAdvance);
		return rv;
	}
	if (strcmp(n, "advance") == 0) {
		object_init_ex(rv, phpft_ce_FT_Vector);
		PHPFT_SET_LONG(rv, "x", slot->advance.x);
		PHPFT_SET_LONG(rv, "y", slot->advance.y);
		return rv;
	}
	if (strcmp(n, "bitmap") == 0) {
		const FT_Bitmap *b = &slot->bitmap;
		size_t bytes = b->buffer != NULL ? (size_t) b->rows * (size_t) abs(b->pitch) : 0;

		object_init_ex(rv, phpft_ce_FT_Bitmap);
		PHPFT_SET_LONG(rv, "rows", b->rows);
		PHPFT_SET_LONG(rv, "width", b->width);
		PHPFT_SET_LONG(rv, "pitch", b->pitch);
		PHPFT_SET_BYTES(rv, "buffer", bytes != 0 ? (const char *) b->buffer : "", bytes);
		PHPFT_SET_LONG(rv, "num_grays", b->num_grays);
		PHPFT_SET_LONG(rv, "pixel_mode", b->pixel_mode);
		PHPFT_SET_LONG(rv, "palette_mode", b->palette_mode);
		PHPFT_SET_LONG(rv, "palette", (uintptr_t) b->palette);
		return rv;
	}
	if (strcmp(n, "outline") == 0) {
		phpft_box(rv, &slot->outline, phpft_ce_FT_Outline, obj);
		return rv;
	}
	return zend_std_read_property(obj, name, type, cache_slot, rv);
}

ZEND_FUNCTION(FT_Load_Glyph)
{
	zval *face;
	zend_long glyph_index, load_flags;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(face, phpft_ce_FT_Face)
		Z_PARAM_LONG(glyph_index)
		Z_PARAM_LONG(load_flags)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(FT_Load_Glyph(phpft_handle_ptr(face), (FT_UInt) glyph_index, (FT_Int32) load_flags));
}

ZEND_FUNCTION(FT_Render_Glyph)
{
	zval *slot;
	zend_long render_mode;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(slot, phpft_ce_FT_GlyphSlot)
		Z_PARAM_LONG(render_mode)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(FT_Render_Glyph(phpft_handle_ptr(slot), (FT_Render_Mode) render_mode));
}

ZEND_FUNCTION(FT_Set_Transform)
{
	zval *face, *matrix_obj, *delta_obj;
	FT_Matrix matrix;
	FT_Vector delta;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(face, phpft_ce_FT_Face)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(matrix_obj, phpft_ce_FT_Matrix)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(delta_obj, phpft_ce_FT_Vector)
	ZEND_PARSE_PARAMETERS_END();

	if (matrix_obj != NULL) {
		matrix.xx = (FT_Fixed) phpft_long_prop(Z_OBJ_P(matrix_obj), ZEND_STRL("xx"));
		matrix.xy = (FT_Fixed) phpft_long_prop(Z_OBJ_P(matrix_obj), ZEND_STRL("xy"));
		matrix.yx = (FT_Fixed) phpft_long_prop(Z_OBJ_P(matrix_obj), ZEND_STRL("yx"));
		matrix.yy = (FT_Fixed) phpft_long_prop(Z_OBJ_P(matrix_obj), ZEND_STRL("yy"));
	}
	if (delta_obj != NULL) {
		delta.x = (FT_Pos) phpft_long_prop(Z_OBJ_P(delta_obj), ZEND_STRL("x"));
		delta.y = (FT_Pos) phpft_long_prop(Z_OBJ_P(delta_obj), ZEND_STRL("y"));
	}
	if (EG(exception)) {
		RETURN_THROWS();
	}
	FT_Set_Transform(phpft_handle_ptr(face), matrix_obj != NULL ? &matrix : NULL, delta_obj != NULL ? &delta : NULL);
}

ZEND_FUNCTION(FT_Outline_Embolden)
{
	zval *outline;
	zend_long strength;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(outline, phpft_ce_FT_Outline)
		Z_PARAM_LONG(strength)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(FT_Outline_Embolden(phpft_handle_ptr(outline), (FT_Pos) strength));
}

void phpft_register_FT_Glyph(int module_number)
{
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
	register_FT_Glyph_symbols(module_number);
	phpft_ce_FT_GlyphSlot = register_class_FT_GlyphSlot();
	phpft_handle_setup(phpft_ce_FT_GlyphSlot, phpft_slot_read);
	phpft_ce_FT_Outline = register_class_FT_Outline();
	phpft_handle_setup(phpft_ce_FT_Outline, NULL);
	phpft_ce_FT_Glyph_Metrics = register_class_FT_Glyph_Metrics();
	phpft_struct_setup(phpft_ce_FT_Glyph_Metrics);
	phpft_ce_FT_Vector = register_class_FT_Vector();
	phpft_struct_setup(phpft_ce_FT_Vector);
	phpft_ce_FT_Matrix = register_class_FT_Matrix();
	phpft_struct_setup(phpft_ce_FT_Matrix);
	phpft_ce_FT_Bitmap = register_class_FT_Bitmap();
	phpft_struct_setup(phpft_ce_FT_Bitmap);
}
