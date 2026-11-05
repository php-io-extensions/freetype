/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: bf045c091a68656ca4643aaf7c268544513d68a9 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_FT_Init_FreeType, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(1, alibrary, FT_Library, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_FT_Done_FreeType, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, library, FT_Library, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_FT_New_Face, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, library, FT_Library, 0)
	ZEND_ARG_TYPE_INFO(0, filepathname, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, face_index, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(1, aface, FT_Face, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_FT_New_Memory_Face, 0, 5, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, library, FT_Library, 0)
	ZEND_ARG_TYPE_INFO(0, file_base, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, file_size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, face_index, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(1, aface, FT_Face, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_FT_Done_Face, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, face, FT_Face, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_FT_Library___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_FT_Library_pointer, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_FT_Library_fromPointer, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, pointer, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_FT_Face___construct arginfo_class_FT_Library___construct

#define arginfo_class_FT_Face_pointer arginfo_class_FT_Library_pointer

#define arginfo_class_FT_Face_fromPointer arginfo_class_FT_Library_fromPointer

ZEND_FUNCTION(FT_Init_FreeType);
ZEND_FUNCTION(FT_Done_FreeType);
ZEND_FUNCTION(FT_New_Face);
ZEND_FUNCTION(FT_New_Memory_Face);
ZEND_FUNCTION(FT_Done_Face);
ZEND_METHOD(FT_Library, __construct);
ZEND_METHOD(FT_Library, pointer);
ZEND_METHOD(FT_Library, fromPointer);
ZEND_METHOD(FT_Face, __construct);
ZEND_METHOD(FT_Face, pointer);
ZEND_METHOD(FT_Face, fromPointer);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(FT_Init_FreeType, arginfo_FT_Init_FreeType)
	ZEND_FE(FT_Done_FreeType, arginfo_FT_Done_FreeType)
	ZEND_FE(FT_New_Face, arginfo_FT_New_Face)
	ZEND_FE(FT_New_Memory_Face, arginfo_FT_New_Memory_Face)
	ZEND_FE(FT_Done_Face, arginfo_FT_Done_Face)
	ZEND_FE_END
};

static const zend_function_entry class_FT_Library_methods[] = {
	ZEND_ME(FT_Library, __construct, arginfo_class_FT_Library___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(FT_Library, pointer, arginfo_class_FT_Library_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(FT_Library, fromPointer, arginfo_class_FT_Library_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_FT_Face_methods[] = {
	ZEND_ME(FT_Face, __construct, arginfo_class_FT_Face___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(FT_Face, pointer, arginfo_class_FT_Face_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(FT_Face, fromPointer, arginfo_class_FT_Face_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_FT_Library(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "FT_Library", class_FT_Library_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	return class_entry;
}

static zend_class_entry *register_class_FT_Face(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "FT_Face", class_FT_Face_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_num_faces_default_value;
	ZVAL_UNDEF(&property_num_faces_default_value);
	zend_string *property_num_faces_name = zend_string_init("num_faces", sizeof("num_faces") - 1, 1);
	zend_declare_typed_property(class_entry, property_num_faces_name, &property_num_faces_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_num_faces_name);

	zval property_face_index_default_value;
	ZVAL_UNDEF(&property_face_index_default_value);
	zend_string *property_face_index_name = zend_string_init("face_index", sizeof("face_index") - 1, 1);
	zend_declare_typed_property(class_entry, property_face_index_name, &property_face_index_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_face_index_name);

	zval property_face_flags_default_value;
	ZVAL_UNDEF(&property_face_flags_default_value);
	zend_string *property_face_flags_name = zend_string_init("face_flags", sizeof("face_flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_face_flags_name, &property_face_flags_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_face_flags_name);

	zval property_style_flags_default_value;
	ZVAL_UNDEF(&property_style_flags_default_value);
	zend_string *property_style_flags_name = zend_string_init("style_flags", sizeof("style_flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_style_flags_name, &property_style_flags_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_style_flags_name);

	zval property_num_glyphs_default_value;
	ZVAL_UNDEF(&property_num_glyphs_default_value);
	zend_string *property_num_glyphs_name = zend_string_init("num_glyphs", sizeof("num_glyphs") - 1, 1);
	zend_declare_typed_property(class_entry, property_num_glyphs_name, &property_num_glyphs_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_num_glyphs_name);

	zval property_family_name_default_value;
	ZVAL_UNDEF(&property_family_name_default_value);
	zend_string *property_family_name_name = zend_string_init("family_name", sizeof("family_name") - 1, 1);
	zend_declare_typed_property(class_entry, property_family_name_name, &property_family_name_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_family_name_name);

	zval property_style_name_default_value;
	ZVAL_UNDEF(&property_style_name_default_value);
	zend_string *property_style_name_name = zend_string_init("style_name", sizeof("style_name") - 1, 1);
	zend_declare_typed_property(class_entry, property_style_name_name, &property_style_name_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_style_name_name);

	zval property_units_per_EM_default_value;
	ZVAL_UNDEF(&property_units_per_EM_default_value);
	zend_string *property_units_per_EM_name = zend_string_init("units_per_EM", sizeof("units_per_EM") - 1, 1);
	zend_declare_typed_property(class_entry, property_units_per_EM_name, &property_units_per_EM_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_units_per_EM_name);

	zval property_ascender_default_value;
	ZVAL_UNDEF(&property_ascender_default_value);
	zend_string *property_ascender_name = zend_string_init("ascender", sizeof("ascender") - 1, 1);
	zend_declare_typed_property(class_entry, property_ascender_name, &property_ascender_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ascender_name);

	zval property_descender_default_value;
	ZVAL_UNDEF(&property_descender_default_value);
	zend_string *property_descender_name = zend_string_init("descender", sizeof("descender") - 1, 1);
	zend_declare_typed_property(class_entry, property_descender_name, &property_descender_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_descender_name);

	zval property_height_default_value;
	ZVAL_UNDEF(&property_height_default_value);
	zend_string *property_height_name = zend_string_init("height", sizeof("height") - 1, 1);
	zend_declare_typed_property(class_entry, property_height_name, &property_height_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_height_name);

	zval property_max_advance_width_default_value;
	ZVAL_UNDEF(&property_max_advance_width_default_value);
	zend_string *property_max_advance_width_name = zend_string_init("max_advance_width", sizeof("max_advance_width") - 1, 1);
	zend_declare_typed_property(class_entry, property_max_advance_width_name, &property_max_advance_width_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_max_advance_width_name);

	zval property_max_advance_height_default_value;
	ZVAL_UNDEF(&property_max_advance_height_default_value);
	zend_string *property_max_advance_height_name = zend_string_init("max_advance_height", sizeof("max_advance_height") - 1, 1);
	zend_declare_typed_property(class_entry, property_max_advance_height_name, &property_max_advance_height_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_max_advance_height_name);

	zval property_underline_position_default_value;
	ZVAL_UNDEF(&property_underline_position_default_value);
	zend_string *property_underline_position_name = zend_string_init("underline_position", sizeof("underline_position") - 1, 1);
	zend_declare_typed_property(class_entry, property_underline_position_name, &property_underline_position_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_underline_position_name);

	zval property_underline_thickness_default_value;
	ZVAL_UNDEF(&property_underline_thickness_default_value);
	zend_string *property_underline_thickness_name = zend_string_init("underline_thickness", sizeof("underline_thickness") - 1, 1);
	zend_declare_typed_property(class_entry, property_underline_thickness_name, &property_underline_thickness_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_underline_thickness_name);

	zval property_glyph_default_value;
	ZVAL_UNDEF(&property_glyph_default_value);
	zend_string *property_glyph_name = zend_string_init("glyph", sizeof("glyph") - 1, 1);
	zend_string *property_glyph_class_FT_GlyphSlot = zend_string_init("FT_GlyphSlot", sizeof("FT_GlyphSlot")-1, 1);
	zend_declare_typed_property(class_entry, property_glyph_name, &property_glyph_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_glyph_class_FT_GlyphSlot, 0, MAY_BE_NULL));
	zend_string_release(property_glyph_name);

	zval property_size_default_value;
	ZVAL_UNDEF(&property_size_default_value);
	zend_string *property_size_name = zend_string_init("size", sizeof("size") - 1, 1);
	zend_string *property_size_class_FT_Size = zend_string_init("FT_Size", sizeof("FT_Size")-1, 1);
	zend_declare_typed_property(class_entry, property_size_name, &property_size_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_size_class_FT_Size, 0, MAY_BE_NULL));
	zend_string_release(property_size_name);

	return class_entry;
}
