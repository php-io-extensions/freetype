/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 9a39347c76194312f7ff84b3fa95c22500a90478 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_FT_Load_Glyph, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, face, FT_Face, 0)
	ZEND_ARG_TYPE_INFO(0, glyph_index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, load_flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_FT_Render_Glyph, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, slot, FT_GlyphSlot, 0)
	ZEND_ARG_TYPE_INFO(0, render_mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_FT_Set_Transform, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, face, FT_Face, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, FT_Matrix, 1)
	ZEND_ARG_OBJ_INFO(0, delta, FT_Vector, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_FT_Outline_Embolden, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, outline, FT_Outline, 0)
	ZEND_ARG_TYPE_INFO(0, strength, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_FT_GlyphSlot___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_FT_GlyphSlot_pointer, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_FT_GlyphSlot_fromPointer, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, pointer, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_FT_Outline___construct arginfo_class_FT_GlyphSlot___construct

#define arginfo_class_FT_Outline_pointer arginfo_class_FT_GlyphSlot_pointer

#define arginfo_class_FT_Outline_fromPointer arginfo_class_FT_GlyphSlot_fromPointer

ZEND_FUNCTION(FT_Load_Glyph);
ZEND_FUNCTION(FT_Render_Glyph);
ZEND_FUNCTION(FT_Set_Transform);
ZEND_FUNCTION(FT_Outline_Embolden);
ZEND_METHOD(FT_GlyphSlot, __construct);
ZEND_METHOD(FT_GlyphSlot, pointer);
ZEND_METHOD(FT_GlyphSlot, fromPointer);
ZEND_METHOD(FT_Outline, __construct);
ZEND_METHOD(FT_Outline, pointer);
ZEND_METHOD(FT_Outline, fromPointer);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(FT_Load_Glyph, arginfo_FT_Load_Glyph)
	ZEND_FE(FT_Render_Glyph, arginfo_FT_Render_Glyph)
	ZEND_FE(FT_Set_Transform, arginfo_FT_Set_Transform)
	ZEND_FE(FT_Outline_Embolden, arginfo_FT_Outline_Embolden)
	ZEND_FE_END
};

static const zend_function_entry class_FT_GlyphSlot_methods[] = {
	ZEND_ME(FT_GlyphSlot, __construct, arginfo_class_FT_GlyphSlot___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(FT_GlyphSlot, pointer, arginfo_class_FT_GlyphSlot_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(FT_GlyphSlot, fromPointer, arginfo_class_FT_GlyphSlot_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_FT_Outline_methods[] = {
	ZEND_ME(FT_Outline, __construct, arginfo_class_FT_Outline___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(FT_Outline, pointer, arginfo_class_FT_Outline_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(FT_Outline, fromPointer, arginfo_class_FT_Outline_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static void register_FT_Glyph_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("FT_LOAD_DEFAULT", FT_LOAD_DEFAULT, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_NO_SCALE", FT_LOAD_NO_SCALE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_NO_HINTING", FT_LOAD_NO_HINTING, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_RENDER", FT_LOAD_RENDER, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_NO_BITMAP", FT_LOAD_NO_BITMAP, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_VERTICAL_LAYOUT", FT_LOAD_VERTICAL_LAYOUT, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_FORCE_AUTOHINT", FT_LOAD_FORCE_AUTOHINT, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_CROP_BITMAP", FT_LOAD_CROP_BITMAP, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_PEDANTIC", FT_LOAD_PEDANTIC, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH", FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_NO_RECURSE", FT_LOAD_NO_RECURSE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_IGNORE_TRANSFORM", FT_LOAD_IGNORE_TRANSFORM, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_MONOCHROME", FT_LOAD_MONOCHROME, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_LINEAR_DESIGN", FT_LOAD_LINEAR_DESIGN, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_SBITS_ONLY", FT_LOAD_SBITS_ONLY, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_NO_AUTOHINT", FT_LOAD_NO_AUTOHINT, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_COLOR", FT_LOAD_COLOR, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_COMPUTE_METRICS", FT_LOAD_COMPUTE_METRICS, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_BITMAP_METRICS_ONLY", FT_LOAD_BITMAP_METRICS_ONLY, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_NO_SVG", FT_LOAD_NO_SVG, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_ADVANCE_ONLY", FT_LOAD_ADVANCE_ONLY, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_SVG_ONLY", FT_LOAD_SVG_ONLY, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_TARGET_NORMAL", FT_LOAD_TARGET_NORMAL, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_TARGET_LIGHT", FT_LOAD_TARGET_LIGHT, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_TARGET_MONO", FT_LOAD_TARGET_MONO, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_TARGET_LCD", FT_LOAD_TARGET_LCD, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_LOAD_TARGET_LCD_V", FT_LOAD_TARGET_LCD_V, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_RENDER_MODE_NORMAL", FT_RENDER_MODE_NORMAL, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_RENDER_MODE_LIGHT", FT_RENDER_MODE_LIGHT, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_RENDER_MODE_MONO", FT_RENDER_MODE_MONO, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_RENDER_MODE_LCD", FT_RENDER_MODE_LCD, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_RENDER_MODE_LCD_V", FT_RENDER_MODE_LCD_V, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_RENDER_MODE_SDF", FT_RENDER_MODE_SDF, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_RENDER_MODE_MAX", FT_RENDER_MODE_MAX, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_PIXEL_MODE_NONE", FT_PIXEL_MODE_NONE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_PIXEL_MODE_MONO", FT_PIXEL_MODE_MONO, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_PIXEL_MODE_GRAY", FT_PIXEL_MODE_GRAY, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_PIXEL_MODE_GRAY2", FT_PIXEL_MODE_GRAY2, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_PIXEL_MODE_GRAY4", FT_PIXEL_MODE_GRAY4, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_PIXEL_MODE_LCD", FT_PIXEL_MODE_LCD, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_PIXEL_MODE_LCD_V", FT_PIXEL_MODE_LCD_V, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_PIXEL_MODE_BGRA", FT_PIXEL_MODE_BGRA, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("FT_PIXEL_MODE_MAX", FT_PIXEL_MODE_MAX, CONST_PERSISTENT);
}

static zend_class_entry *register_class_FT_GlyphSlot(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "FT_GlyphSlot", class_FT_GlyphSlot_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_glyph_index_default_value;
	ZVAL_UNDEF(&property_glyph_index_default_value);
	zend_string *property_glyph_index_name = zend_string_init("glyph_index", sizeof("glyph_index") - 1, 1);
	zend_declare_typed_property(class_entry, property_glyph_index_name, &property_glyph_index_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_glyph_index_name);

	zval property_metrics_default_value;
	ZVAL_UNDEF(&property_metrics_default_value);
	zend_string *property_metrics_name = zend_string_init("metrics", sizeof("metrics") - 1, 1);
	zend_string *property_metrics_class_FT_Glyph_Metrics = zend_string_init("FT_Glyph_Metrics", sizeof("FT_Glyph_Metrics")-1, 1);
	zend_declare_typed_property(class_entry, property_metrics_name, &property_metrics_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_metrics_class_FT_Glyph_Metrics, 0, 0));
	zend_string_release(property_metrics_name);

	zval property_linearHoriAdvance_default_value;
	ZVAL_UNDEF(&property_linearHoriAdvance_default_value);
	zend_string *property_linearHoriAdvance_name = zend_string_init("linearHoriAdvance", sizeof("linearHoriAdvance") - 1, 1);
	zend_declare_typed_property(class_entry, property_linearHoriAdvance_name, &property_linearHoriAdvance_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_linearHoriAdvance_name);

	zval property_linearVertAdvance_default_value;
	ZVAL_UNDEF(&property_linearVertAdvance_default_value);
	zend_string *property_linearVertAdvance_name = zend_string_init("linearVertAdvance", sizeof("linearVertAdvance") - 1, 1);
	zend_declare_typed_property(class_entry, property_linearVertAdvance_name, &property_linearVertAdvance_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_linearVertAdvance_name);

	zval property_advance_default_value;
	ZVAL_UNDEF(&property_advance_default_value);
	zend_string *property_advance_name = zend_string_init("advance", sizeof("advance") - 1, 1);
	zend_string *property_advance_class_FT_Vector = zend_string_init("FT_Vector", sizeof("FT_Vector")-1, 1);
	zend_declare_typed_property(class_entry, property_advance_name, &property_advance_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_advance_class_FT_Vector, 0, 0));
	zend_string_release(property_advance_name);

	zval property_format_default_value;
	ZVAL_UNDEF(&property_format_default_value);
	zend_string *property_format_name = zend_string_init("format", sizeof("format") - 1, 1);
	zend_declare_typed_property(class_entry, property_format_name, &property_format_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_format_name);

	zval property_bitmap_default_value;
	ZVAL_UNDEF(&property_bitmap_default_value);
	zend_string *property_bitmap_name = zend_string_init("bitmap", sizeof("bitmap") - 1, 1);
	zend_string *property_bitmap_class_FT_Bitmap = zend_string_init("FT_Bitmap", sizeof("FT_Bitmap")-1, 1);
	zend_declare_typed_property(class_entry, property_bitmap_name, &property_bitmap_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bitmap_class_FT_Bitmap, 0, 0));
	zend_string_release(property_bitmap_name);

	zval property_bitmap_left_default_value;
	ZVAL_UNDEF(&property_bitmap_left_default_value);
	zend_string *property_bitmap_left_name = zend_string_init("bitmap_left", sizeof("bitmap_left") - 1, 1);
	zend_declare_typed_property(class_entry, property_bitmap_left_name, &property_bitmap_left_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_bitmap_left_name);

	zval property_bitmap_top_default_value;
	ZVAL_UNDEF(&property_bitmap_top_default_value);
	zend_string *property_bitmap_top_name = zend_string_init("bitmap_top", sizeof("bitmap_top") - 1, 1);
	zend_declare_typed_property(class_entry, property_bitmap_top_name, &property_bitmap_top_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_bitmap_top_name);

	zval property_outline_default_value;
	ZVAL_UNDEF(&property_outline_default_value);
	zend_string *property_outline_name = zend_string_init("outline", sizeof("outline") - 1, 1);
	zend_string *property_outline_class_FT_Outline = zend_string_init("FT_Outline", sizeof("FT_Outline")-1, 1);
	zend_declare_typed_property(class_entry, property_outline_name, &property_outline_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_outline_class_FT_Outline, 0, 0));
	zend_string_release(property_outline_name);

	return class_entry;
}

static zend_class_entry *register_class_FT_Outline(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "FT_Outline", class_FT_Outline_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	return class_entry;
}

static zend_class_entry *register_class_FT_Glyph_Metrics(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "FT_Glyph_Metrics", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_width_default_value;
	ZVAL_LONG(&property_width_default_value, 0);
	zend_string *property_width_name = zend_string_init("width", sizeof("width") - 1, 1);
	zend_declare_typed_property(class_entry, property_width_name, &property_width_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_width_name);

	zval property_height_default_value;
	ZVAL_LONG(&property_height_default_value, 0);
	zend_string *property_height_name = zend_string_init("height", sizeof("height") - 1, 1);
	zend_declare_typed_property(class_entry, property_height_name, &property_height_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_height_name);

	zval property_horiBearingX_default_value;
	ZVAL_LONG(&property_horiBearingX_default_value, 0);
	zend_string *property_horiBearingX_name = zend_string_init("horiBearingX", sizeof("horiBearingX") - 1, 1);
	zend_declare_typed_property(class_entry, property_horiBearingX_name, &property_horiBearingX_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_horiBearingX_name);

	zval property_horiBearingY_default_value;
	ZVAL_LONG(&property_horiBearingY_default_value, 0);
	zend_string *property_horiBearingY_name = zend_string_init("horiBearingY", sizeof("horiBearingY") - 1, 1);
	zend_declare_typed_property(class_entry, property_horiBearingY_name, &property_horiBearingY_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_horiBearingY_name);

	zval property_horiAdvance_default_value;
	ZVAL_LONG(&property_horiAdvance_default_value, 0);
	zend_string *property_horiAdvance_name = zend_string_init("horiAdvance", sizeof("horiAdvance") - 1, 1);
	zend_declare_typed_property(class_entry, property_horiAdvance_name, &property_horiAdvance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_horiAdvance_name);

	zval property_vertBearingX_default_value;
	ZVAL_LONG(&property_vertBearingX_default_value, 0);
	zend_string *property_vertBearingX_name = zend_string_init("vertBearingX", sizeof("vertBearingX") - 1, 1);
	zend_declare_typed_property(class_entry, property_vertBearingX_name, &property_vertBearingX_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_vertBearingX_name);

	zval property_vertBearingY_default_value;
	ZVAL_LONG(&property_vertBearingY_default_value, 0);
	zend_string *property_vertBearingY_name = zend_string_init("vertBearingY", sizeof("vertBearingY") - 1, 1);
	zend_declare_typed_property(class_entry, property_vertBearingY_name, &property_vertBearingY_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_vertBearingY_name);

	zval property_vertAdvance_default_value;
	ZVAL_LONG(&property_vertAdvance_default_value, 0);
	zend_string *property_vertAdvance_name = zend_string_init("vertAdvance", sizeof("vertAdvance") - 1, 1);
	zend_declare_typed_property(class_entry, property_vertAdvance_name, &property_vertAdvance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_vertAdvance_name);

	return class_entry;
}

static zend_class_entry *register_class_FT_Vector(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "FT_Vector", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_x_default_value;
	ZVAL_LONG(&property_x_default_value, 0);
	zend_string *property_x_name = zend_string_init("x", sizeof("x") - 1, 1);
	zend_declare_typed_property(class_entry, property_x_name, &property_x_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_x_name);

	zval property_y_default_value;
	ZVAL_LONG(&property_y_default_value, 0);
	zend_string *property_y_name = zend_string_init("y", sizeof("y") - 1, 1);
	zend_declare_typed_property(class_entry, property_y_name, &property_y_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_y_name);

	return class_entry;
}

static zend_class_entry *register_class_FT_Matrix(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "FT_Matrix", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_xx_default_value;
	ZVAL_LONG(&property_xx_default_value, 0);
	zend_string *property_xx_name = zend_string_init("xx", sizeof("xx") - 1, 1);
	zend_declare_typed_property(class_entry, property_xx_name, &property_xx_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_xx_name);

	zval property_xy_default_value;
	ZVAL_LONG(&property_xy_default_value, 0);
	zend_string *property_xy_name = zend_string_init("xy", sizeof("xy") - 1, 1);
	zend_declare_typed_property(class_entry, property_xy_name, &property_xy_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_xy_name);

	zval property_yx_default_value;
	ZVAL_LONG(&property_yx_default_value, 0);
	zend_string *property_yx_name = zend_string_init("yx", sizeof("yx") - 1, 1);
	zend_declare_typed_property(class_entry, property_yx_name, &property_yx_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_yx_name);

	zval property_yy_default_value;
	ZVAL_LONG(&property_yy_default_value, 0);
	zend_string *property_yy_name = zend_string_init("yy", sizeof("yy") - 1, 1);
	zend_declare_typed_property(class_entry, property_yy_name, &property_yy_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_yy_name);

	return class_entry;
}

static zend_class_entry *register_class_FT_Bitmap(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "FT_Bitmap", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_rows_default_value;
	ZVAL_LONG(&property_rows_default_value, 0);
	zend_string *property_rows_name = zend_string_init("rows", sizeof("rows") - 1, 1);
	zend_declare_typed_property(class_entry, property_rows_name, &property_rows_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_rows_name);

	zval property_width_default_value;
	ZVAL_LONG(&property_width_default_value, 0);
	zend_string *property_width_name = zend_string_init("width", sizeof("width") - 1, 1);
	zend_declare_typed_property(class_entry, property_width_name, &property_width_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_width_name);

	zval property_pitch_default_value;
	ZVAL_LONG(&property_pitch_default_value, 0);
	zend_string *property_pitch_name = zend_string_init("pitch", sizeof("pitch") - 1, 1);
	zend_declare_typed_property(class_entry, property_pitch_name, &property_pitch_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_pitch_name);

	zval property_buffer_default_value;
	ZVAL_EMPTY_STRING(&property_buffer_default_value);
	zend_string *property_buffer_name = zend_string_init("buffer", sizeof("buffer") - 1, 1);
	zend_declare_typed_property(class_entry, property_buffer_name, &property_buffer_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_buffer_name);

	zval property_num_grays_default_value;
	ZVAL_LONG(&property_num_grays_default_value, 0);
	zend_string *property_num_grays_name = zend_string_init("num_grays", sizeof("num_grays") - 1, 1);
	zend_declare_typed_property(class_entry, property_num_grays_name, &property_num_grays_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_num_grays_name);

	zval property_pixel_mode_default_value;
	ZVAL_LONG(&property_pixel_mode_default_value, 0);
	zend_string *property_pixel_mode_name = zend_string_init("pixel_mode", sizeof("pixel_mode") - 1, 1);
	zend_declare_typed_property(class_entry, property_pixel_mode_name, &property_pixel_mode_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_pixel_mode_name);

	zval property_palette_mode_default_value;
	ZVAL_LONG(&property_palette_mode_default_value, 0);
	zend_string *property_palette_mode_name = zend_string_init("palette_mode", sizeof("palette_mode") - 1, 1);
	zend_declare_typed_property(class_entry, property_palette_mode_name, &property_palette_mode_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_palette_mode_name);

	zval property_palette_default_value;
	ZVAL_LONG(&property_palette_default_value, 0);
	zend_string *property_palette_name = zend_string_init("palette", sizeof("palette") - 1, 1);
	zend_declare_typed_property(class_entry, property_palette_name, &property_palette_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_palette_name);

	return class_entry;
}
