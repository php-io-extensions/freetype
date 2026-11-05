/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 714066fcebcc159fc31f6d8d09c60315c64d8f79 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_FT_Set_Char_Size, 0, 5, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, face, FT_Face, 0)
	ZEND_ARG_TYPE_INFO(0, char_width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, char_height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, horz_resolution, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, vert_resolution, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_FT_Set_Pixel_Sizes, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, face, FT_Face, 0)
	ZEND_ARG_TYPE_INFO(0, pixel_width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pixel_height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_TYPE_MASK_EX(arginfo_FT_Get_Sfnt_Table, 0, 2, TT_Header|TT_HoriHeader|TT_VertHeader|TT_OS2|TT_Postscript|TT_PCLT|TT_MaxProfile, MAY_BE_NULL)
	ZEND_ARG_OBJ_INFO(0, face, FT_Face, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_FT_Get_Char_Index, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, face, FT_Face, 0)
	ZEND_ARG_TYPE_INFO(0, charcode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_FT_Size___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_FT_Size_pointer, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_FT_Size_fromPointer, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, pointer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_FUNCTION(FT_Set_Char_Size);
ZEND_FUNCTION(FT_Set_Pixel_Sizes);
ZEND_FUNCTION(FT_Get_Sfnt_Table);
ZEND_FUNCTION(FT_Get_Char_Index);
ZEND_METHOD(FT_Size, __construct);
ZEND_METHOD(FT_Size, pointer);
ZEND_METHOD(FT_Size, fromPointer);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(FT_Set_Char_Size, arginfo_FT_Set_Char_Size)
	ZEND_FE(FT_Set_Pixel_Sizes, arginfo_FT_Set_Pixel_Sizes)
	ZEND_FE(FT_Get_Sfnt_Table, arginfo_FT_Get_Sfnt_Table)
	ZEND_FE(FT_Get_Char_Index, arginfo_FT_Get_Char_Index)
	ZEND_FE_END
};

static const zend_function_entry class_FT_Size_methods[] = {
	ZEND_ME(FT_Size, __construct, arginfo_class_FT_Size___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(FT_Size, pointer, arginfo_class_FT_Size_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(FT_Size, fromPointer, arginfo_class_FT_Size_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_FT_Size(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "FT_Size", class_FT_Size_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_metrics_default_value;
	ZVAL_UNDEF(&property_metrics_default_value);
	zend_string *property_metrics_name = zend_string_init("metrics", sizeof("metrics") - 1, 1);
	zend_string *property_metrics_class_FT_Size_Metrics = zend_string_init("FT_Size_Metrics", sizeof("FT_Size_Metrics")-1, 1);
	zend_declare_typed_property(class_entry, property_metrics_name, &property_metrics_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_metrics_class_FT_Size_Metrics, 0, 0));
	zend_string_release(property_metrics_name);

	return class_entry;
}

static zend_class_entry *register_class_FT_Size_Metrics(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "FT_Size_Metrics", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_x_ppem_default_value;
	ZVAL_LONG(&property_x_ppem_default_value, 0);
	zend_string *property_x_ppem_name = zend_string_init("x_ppem", sizeof("x_ppem") - 1, 1);
	zend_declare_typed_property(class_entry, property_x_ppem_name, &property_x_ppem_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_x_ppem_name);

	zval property_y_ppem_default_value;
	ZVAL_LONG(&property_y_ppem_default_value, 0);
	zend_string *property_y_ppem_name = zend_string_init("y_ppem", sizeof("y_ppem") - 1, 1);
	zend_declare_typed_property(class_entry, property_y_ppem_name, &property_y_ppem_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_y_ppem_name);

	zval property_x_scale_default_value;
	ZVAL_LONG(&property_x_scale_default_value, 0);
	zend_string *property_x_scale_name = zend_string_init("x_scale", sizeof("x_scale") - 1, 1);
	zend_declare_typed_property(class_entry, property_x_scale_name, &property_x_scale_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_x_scale_name);

	zval property_y_scale_default_value;
	ZVAL_LONG(&property_y_scale_default_value, 0);
	zend_string *property_y_scale_name = zend_string_init("y_scale", sizeof("y_scale") - 1, 1);
	zend_declare_typed_property(class_entry, property_y_scale_name, &property_y_scale_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_y_scale_name);

	zval property_ascender_default_value;
	ZVAL_LONG(&property_ascender_default_value, 0);
	zend_string *property_ascender_name = zend_string_init("ascender", sizeof("ascender") - 1, 1);
	zend_declare_typed_property(class_entry, property_ascender_name, &property_ascender_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ascender_name);

	zval property_descender_default_value;
	ZVAL_LONG(&property_descender_default_value, 0);
	zend_string *property_descender_name = zend_string_init("descender", sizeof("descender") - 1, 1);
	zend_declare_typed_property(class_entry, property_descender_name, &property_descender_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_descender_name);

	zval property_height_default_value;
	ZVAL_LONG(&property_height_default_value, 0);
	zend_string *property_height_name = zend_string_init("height", sizeof("height") - 1, 1);
	zend_declare_typed_property(class_entry, property_height_name, &property_height_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_height_name);

	zval property_max_advance_default_value;
	ZVAL_LONG(&property_max_advance_default_value, 0);
	zend_string *property_max_advance_name = zend_string_init("max_advance", sizeof("max_advance") - 1, 1);
	zend_declare_typed_property(class_entry, property_max_advance_name, &property_max_advance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_max_advance_name);

	return class_entry;
}

static zend_class_entry *register_class_TT_Header(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "TT_Header", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_Table_Version_default_value;
	ZVAL_LONG(&property_Table_Version_default_value, 0);
	zend_string *property_Table_Version_name = zend_string_init("Table_Version", sizeof("Table_Version") - 1, 1);
	zend_declare_typed_property(class_entry, property_Table_Version_name, &property_Table_Version_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Table_Version_name);

	zval property_Font_Revision_default_value;
	ZVAL_LONG(&property_Font_Revision_default_value, 0);
	zend_string *property_Font_Revision_name = zend_string_init("Font_Revision", sizeof("Font_Revision") - 1, 1);
	zend_declare_typed_property(class_entry, property_Font_Revision_name, &property_Font_Revision_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Font_Revision_name);

	zval property_CheckSum_Adjust_default_value;
	ZVAL_LONG(&property_CheckSum_Adjust_default_value, 0);
	zend_string *property_CheckSum_Adjust_name = zend_string_init("CheckSum_Adjust", sizeof("CheckSum_Adjust") - 1, 1);
	zend_declare_typed_property(class_entry, property_CheckSum_Adjust_name, &property_CheckSum_Adjust_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_CheckSum_Adjust_name);

	zval property_Magic_Number_default_value;
	ZVAL_LONG(&property_Magic_Number_default_value, 0);
	zend_string *property_Magic_Number_name = zend_string_init("Magic_Number", sizeof("Magic_Number") - 1, 1);
	zend_declare_typed_property(class_entry, property_Magic_Number_name, &property_Magic_Number_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Magic_Number_name);

	zval property_Flags_default_value;
	ZVAL_LONG(&property_Flags_default_value, 0);
	zend_string *property_Flags_name = zend_string_init("Flags", sizeof("Flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_Flags_name, &property_Flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Flags_name);

	zval property_Units_Per_EM_default_value;
	ZVAL_LONG(&property_Units_Per_EM_default_value, 0);
	zend_string *property_Units_Per_EM_name = zend_string_init("Units_Per_EM", sizeof("Units_Per_EM") - 1, 1);
	zend_declare_typed_property(class_entry, property_Units_Per_EM_name, &property_Units_Per_EM_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Units_Per_EM_name);

	zval property_Created_default_value;
	ZVAL_EMPTY_ARRAY(&property_Created_default_value);
	zend_string *property_Created_name = zend_string_init("Created", sizeof("Created") - 1, 1);
	zend_declare_typed_property(class_entry, property_Created_name, &property_Created_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_Created_name);

	zval property_Modified_default_value;
	ZVAL_EMPTY_ARRAY(&property_Modified_default_value);
	zend_string *property_Modified_name = zend_string_init("Modified", sizeof("Modified") - 1, 1);
	zend_declare_typed_property(class_entry, property_Modified_name, &property_Modified_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_Modified_name);

	zval property_xMin_default_value;
	ZVAL_LONG(&property_xMin_default_value, 0);
	zend_string *property_xMin_name = zend_string_init("xMin", sizeof("xMin") - 1, 1);
	zend_declare_typed_property(class_entry, property_xMin_name, &property_xMin_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_xMin_name);

	zval property_yMin_default_value;
	ZVAL_LONG(&property_yMin_default_value, 0);
	zend_string *property_yMin_name = zend_string_init("yMin", sizeof("yMin") - 1, 1);
	zend_declare_typed_property(class_entry, property_yMin_name, &property_yMin_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_yMin_name);

	zval property_xMax_default_value;
	ZVAL_LONG(&property_xMax_default_value, 0);
	zend_string *property_xMax_name = zend_string_init("xMax", sizeof("xMax") - 1, 1);
	zend_declare_typed_property(class_entry, property_xMax_name, &property_xMax_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_xMax_name);

	zval property_yMax_default_value;
	ZVAL_LONG(&property_yMax_default_value, 0);
	zend_string *property_yMax_name = zend_string_init("yMax", sizeof("yMax") - 1, 1);
	zend_declare_typed_property(class_entry, property_yMax_name, &property_yMax_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_yMax_name);

	zval property_Mac_Style_default_value;
	ZVAL_LONG(&property_Mac_Style_default_value, 0);
	zend_string *property_Mac_Style_name = zend_string_init("Mac_Style", sizeof("Mac_Style") - 1, 1);
	zend_declare_typed_property(class_entry, property_Mac_Style_name, &property_Mac_Style_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Mac_Style_name);

	zval property_Lowest_Rec_PPEM_default_value;
	ZVAL_LONG(&property_Lowest_Rec_PPEM_default_value, 0);
	zend_string *property_Lowest_Rec_PPEM_name = zend_string_init("Lowest_Rec_PPEM", sizeof("Lowest_Rec_PPEM") - 1, 1);
	zend_declare_typed_property(class_entry, property_Lowest_Rec_PPEM_name, &property_Lowest_Rec_PPEM_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Lowest_Rec_PPEM_name);

	zval property_Font_Direction_default_value;
	ZVAL_LONG(&property_Font_Direction_default_value, 0);
	zend_string *property_Font_Direction_name = zend_string_init("Font_Direction", sizeof("Font_Direction") - 1, 1);
	zend_declare_typed_property(class_entry, property_Font_Direction_name, &property_Font_Direction_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Font_Direction_name);

	zval property_Index_To_Loc_Format_default_value;
	ZVAL_LONG(&property_Index_To_Loc_Format_default_value, 0);
	zend_string *property_Index_To_Loc_Format_name = zend_string_init("Index_To_Loc_Format", sizeof("Index_To_Loc_Format") - 1, 1);
	zend_declare_typed_property(class_entry, property_Index_To_Loc_Format_name, &property_Index_To_Loc_Format_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Index_To_Loc_Format_name);

	zval property_Glyph_Data_Format_default_value;
	ZVAL_LONG(&property_Glyph_Data_Format_default_value, 0);
	zend_string *property_Glyph_Data_Format_name = zend_string_init("Glyph_Data_Format", sizeof("Glyph_Data_Format") - 1, 1);
	zend_declare_typed_property(class_entry, property_Glyph_Data_Format_name, &property_Glyph_Data_Format_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Glyph_Data_Format_name);

	return class_entry;
}

static zend_class_entry *register_class_TT_HoriHeader(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "TT_HoriHeader", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_Version_default_value;
	ZVAL_LONG(&property_Version_default_value, 0);
	zend_string *property_Version_name = zend_string_init("Version", sizeof("Version") - 1, 1);
	zend_declare_typed_property(class_entry, property_Version_name, &property_Version_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Version_name);

	zval property_Ascender_default_value;
	ZVAL_LONG(&property_Ascender_default_value, 0);
	zend_string *property_Ascender_name = zend_string_init("Ascender", sizeof("Ascender") - 1, 1);
	zend_declare_typed_property(class_entry, property_Ascender_name, &property_Ascender_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Ascender_name);

	zval property_Descender_default_value;
	ZVAL_LONG(&property_Descender_default_value, 0);
	zend_string *property_Descender_name = zend_string_init("Descender", sizeof("Descender") - 1, 1);
	zend_declare_typed_property(class_entry, property_Descender_name, &property_Descender_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Descender_name);

	zval property_Line_Gap_default_value;
	ZVAL_LONG(&property_Line_Gap_default_value, 0);
	zend_string *property_Line_Gap_name = zend_string_init("Line_Gap", sizeof("Line_Gap") - 1, 1);
	zend_declare_typed_property(class_entry, property_Line_Gap_name, &property_Line_Gap_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Line_Gap_name);

	zval property_advance_Width_Max_default_value;
	ZVAL_LONG(&property_advance_Width_Max_default_value, 0);
	zend_string *property_advance_Width_Max_name = zend_string_init("advance_Width_Max", sizeof("advance_Width_Max") - 1, 1);
	zend_declare_typed_property(class_entry, property_advance_Width_Max_name, &property_advance_Width_Max_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_advance_Width_Max_name);

	zval property_min_Left_Side_Bearing_default_value;
	ZVAL_LONG(&property_min_Left_Side_Bearing_default_value, 0);
	zend_string *property_min_Left_Side_Bearing_name = zend_string_init("min_Left_Side_Bearing", sizeof("min_Left_Side_Bearing") - 1, 1);
	zend_declare_typed_property(class_entry, property_min_Left_Side_Bearing_name, &property_min_Left_Side_Bearing_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_min_Left_Side_Bearing_name);

	zval property_min_Right_Side_Bearing_default_value;
	ZVAL_LONG(&property_min_Right_Side_Bearing_default_value, 0);
	zend_string *property_min_Right_Side_Bearing_name = zend_string_init("min_Right_Side_Bearing", sizeof("min_Right_Side_Bearing") - 1, 1);
	zend_declare_typed_property(class_entry, property_min_Right_Side_Bearing_name, &property_min_Right_Side_Bearing_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_min_Right_Side_Bearing_name);

	zval property_xMax_Extent_default_value;
	ZVAL_LONG(&property_xMax_Extent_default_value, 0);
	zend_string *property_xMax_Extent_name = zend_string_init("xMax_Extent", sizeof("xMax_Extent") - 1, 1);
	zend_declare_typed_property(class_entry, property_xMax_Extent_name, &property_xMax_Extent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_xMax_Extent_name);

	zval property_caret_Slope_Rise_default_value;
	ZVAL_LONG(&property_caret_Slope_Rise_default_value, 0);
	zend_string *property_caret_Slope_Rise_name = zend_string_init("caret_Slope_Rise", sizeof("caret_Slope_Rise") - 1, 1);
	zend_declare_typed_property(class_entry, property_caret_Slope_Rise_name, &property_caret_Slope_Rise_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_caret_Slope_Rise_name);

	zval property_caret_Slope_Run_default_value;
	ZVAL_LONG(&property_caret_Slope_Run_default_value, 0);
	zend_string *property_caret_Slope_Run_name = zend_string_init("caret_Slope_Run", sizeof("caret_Slope_Run") - 1, 1);
	zend_declare_typed_property(class_entry, property_caret_Slope_Run_name, &property_caret_Slope_Run_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_caret_Slope_Run_name);

	zval property_caret_Offset_default_value;
	ZVAL_LONG(&property_caret_Offset_default_value, 0);
	zend_string *property_caret_Offset_name = zend_string_init("caret_Offset", sizeof("caret_Offset") - 1, 1);
	zend_declare_typed_property(class_entry, property_caret_Offset_name, &property_caret_Offset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_caret_Offset_name);

	zval property_Reserved_default_value;
	ZVAL_EMPTY_ARRAY(&property_Reserved_default_value);
	zend_string *property_Reserved_name = zend_string_init("Reserved", sizeof("Reserved") - 1, 1);
	zend_declare_typed_property(class_entry, property_Reserved_name, &property_Reserved_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_Reserved_name);

	zval property_metric_Data_Format_default_value;
	ZVAL_LONG(&property_metric_Data_Format_default_value, 0);
	zend_string *property_metric_Data_Format_name = zend_string_init("metric_Data_Format", sizeof("metric_Data_Format") - 1, 1);
	zend_declare_typed_property(class_entry, property_metric_Data_Format_name, &property_metric_Data_Format_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_metric_Data_Format_name);

	zval property_number_Of_HMetrics_default_value;
	ZVAL_LONG(&property_number_Of_HMetrics_default_value, 0);
	zend_string *property_number_Of_HMetrics_name = zend_string_init("number_Of_HMetrics", sizeof("number_Of_HMetrics") - 1, 1);
	zend_declare_typed_property(class_entry, property_number_Of_HMetrics_name, &property_number_Of_HMetrics_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_number_Of_HMetrics_name);

	zval property_long_metrics_default_value;
	ZVAL_LONG(&property_long_metrics_default_value, 0);
	zend_string *property_long_metrics_name = zend_string_init("long_metrics", sizeof("long_metrics") - 1, 1);
	zend_declare_typed_property(class_entry, property_long_metrics_name, &property_long_metrics_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_long_metrics_name);

	zval property_short_metrics_default_value;
	ZVAL_LONG(&property_short_metrics_default_value, 0);
	zend_string *property_short_metrics_name = zend_string_init("short_metrics", sizeof("short_metrics") - 1, 1);
	zend_declare_typed_property(class_entry, property_short_metrics_name, &property_short_metrics_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_short_metrics_name);

	return class_entry;
}

static zend_class_entry *register_class_TT_VertHeader(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "TT_VertHeader", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_Version_default_value;
	ZVAL_LONG(&property_Version_default_value, 0);
	zend_string *property_Version_name = zend_string_init("Version", sizeof("Version") - 1, 1);
	zend_declare_typed_property(class_entry, property_Version_name, &property_Version_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Version_name);

	zval property_Ascender_default_value;
	ZVAL_LONG(&property_Ascender_default_value, 0);
	zend_string *property_Ascender_name = zend_string_init("Ascender", sizeof("Ascender") - 1, 1);
	zend_declare_typed_property(class_entry, property_Ascender_name, &property_Ascender_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Ascender_name);

	zval property_Descender_default_value;
	ZVAL_LONG(&property_Descender_default_value, 0);
	zend_string *property_Descender_name = zend_string_init("Descender", sizeof("Descender") - 1, 1);
	zend_declare_typed_property(class_entry, property_Descender_name, &property_Descender_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Descender_name);

	zval property_Line_Gap_default_value;
	ZVAL_LONG(&property_Line_Gap_default_value, 0);
	zend_string *property_Line_Gap_name = zend_string_init("Line_Gap", sizeof("Line_Gap") - 1, 1);
	zend_declare_typed_property(class_entry, property_Line_Gap_name, &property_Line_Gap_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Line_Gap_name);

	zval property_advance_Height_Max_default_value;
	ZVAL_LONG(&property_advance_Height_Max_default_value, 0);
	zend_string *property_advance_Height_Max_name = zend_string_init("advance_Height_Max", sizeof("advance_Height_Max") - 1, 1);
	zend_declare_typed_property(class_entry, property_advance_Height_Max_name, &property_advance_Height_Max_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_advance_Height_Max_name);

	zval property_min_Top_Side_Bearing_default_value;
	ZVAL_LONG(&property_min_Top_Side_Bearing_default_value, 0);
	zend_string *property_min_Top_Side_Bearing_name = zend_string_init("min_Top_Side_Bearing", sizeof("min_Top_Side_Bearing") - 1, 1);
	zend_declare_typed_property(class_entry, property_min_Top_Side_Bearing_name, &property_min_Top_Side_Bearing_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_min_Top_Side_Bearing_name);

	zval property_min_Bottom_Side_Bearing_default_value;
	ZVAL_LONG(&property_min_Bottom_Side_Bearing_default_value, 0);
	zend_string *property_min_Bottom_Side_Bearing_name = zend_string_init("min_Bottom_Side_Bearing", sizeof("min_Bottom_Side_Bearing") - 1, 1);
	zend_declare_typed_property(class_entry, property_min_Bottom_Side_Bearing_name, &property_min_Bottom_Side_Bearing_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_min_Bottom_Side_Bearing_name);

	zval property_yMax_Extent_default_value;
	ZVAL_LONG(&property_yMax_Extent_default_value, 0);
	zend_string *property_yMax_Extent_name = zend_string_init("yMax_Extent", sizeof("yMax_Extent") - 1, 1);
	zend_declare_typed_property(class_entry, property_yMax_Extent_name, &property_yMax_Extent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_yMax_Extent_name);

	zval property_caret_Slope_Rise_default_value;
	ZVAL_LONG(&property_caret_Slope_Rise_default_value, 0);
	zend_string *property_caret_Slope_Rise_name = zend_string_init("caret_Slope_Rise", sizeof("caret_Slope_Rise") - 1, 1);
	zend_declare_typed_property(class_entry, property_caret_Slope_Rise_name, &property_caret_Slope_Rise_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_caret_Slope_Rise_name);

	zval property_caret_Slope_Run_default_value;
	ZVAL_LONG(&property_caret_Slope_Run_default_value, 0);
	zend_string *property_caret_Slope_Run_name = zend_string_init("caret_Slope_Run", sizeof("caret_Slope_Run") - 1, 1);
	zend_declare_typed_property(class_entry, property_caret_Slope_Run_name, &property_caret_Slope_Run_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_caret_Slope_Run_name);

	zval property_caret_Offset_default_value;
	ZVAL_LONG(&property_caret_Offset_default_value, 0);
	zend_string *property_caret_Offset_name = zend_string_init("caret_Offset", sizeof("caret_Offset") - 1, 1);
	zend_declare_typed_property(class_entry, property_caret_Offset_name, &property_caret_Offset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_caret_Offset_name);

	zval property_Reserved_default_value;
	ZVAL_EMPTY_ARRAY(&property_Reserved_default_value);
	zend_string *property_Reserved_name = zend_string_init("Reserved", sizeof("Reserved") - 1, 1);
	zend_declare_typed_property(class_entry, property_Reserved_name, &property_Reserved_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_Reserved_name);

	zval property_metric_Data_Format_default_value;
	ZVAL_LONG(&property_metric_Data_Format_default_value, 0);
	zend_string *property_metric_Data_Format_name = zend_string_init("metric_Data_Format", sizeof("metric_Data_Format") - 1, 1);
	zend_declare_typed_property(class_entry, property_metric_Data_Format_name, &property_metric_Data_Format_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_metric_Data_Format_name);

	zval property_number_Of_VMetrics_default_value;
	ZVAL_LONG(&property_number_Of_VMetrics_default_value, 0);
	zend_string *property_number_Of_VMetrics_name = zend_string_init("number_Of_VMetrics", sizeof("number_Of_VMetrics") - 1, 1);
	zend_declare_typed_property(class_entry, property_number_Of_VMetrics_name, &property_number_Of_VMetrics_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_number_Of_VMetrics_name);

	zval property_long_metrics_default_value;
	ZVAL_LONG(&property_long_metrics_default_value, 0);
	zend_string *property_long_metrics_name = zend_string_init("long_metrics", sizeof("long_metrics") - 1, 1);
	zend_declare_typed_property(class_entry, property_long_metrics_name, &property_long_metrics_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_long_metrics_name);

	zval property_short_metrics_default_value;
	ZVAL_LONG(&property_short_metrics_default_value, 0);
	zend_string *property_short_metrics_name = zend_string_init("short_metrics", sizeof("short_metrics") - 1, 1);
	zend_declare_typed_property(class_entry, property_short_metrics_name, &property_short_metrics_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_short_metrics_name);

	return class_entry;
}

static zend_class_entry *register_class_TT_OS2(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "TT_OS2", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_version_default_value;
	ZVAL_LONG(&property_version_default_value, 0);
	zend_string *property_version_name = zend_string_init("version", sizeof("version") - 1, 1);
	zend_declare_typed_property(class_entry, property_version_name, &property_version_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_version_name);

	zval property_xAvgCharWidth_default_value;
	ZVAL_LONG(&property_xAvgCharWidth_default_value, 0);
	zend_string *property_xAvgCharWidth_name = zend_string_init("xAvgCharWidth", sizeof("xAvgCharWidth") - 1, 1);
	zend_declare_typed_property(class_entry, property_xAvgCharWidth_name, &property_xAvgCharWidth_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_xAvgCharWidth_name);

	zval property_usWeightClass_default_value;
	ZVAL_LONG(&property_usWeightClass_default_value, 0);
	zend_string *property_usWeightClass_name = zend_string_init("usWeightClass", sizeof("usWeightClass") - 1, 1);
	zend_declare_typed_property(class_entry, property_usWeightClass_name, &property_usWeightClass_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_usWeightClass_name);

	zval property_usWidthClass_default_value;
	ZVAL_LONG(&property_usWidthClass_default_value, 0);
	zend_string *property_usWidthClass_name = zend_string_init("usWidthClass", sizeof("usWidthClass") - 1, 1);
	zend_declare_typed_property(class_entry, property_usWidthClass_name, &property_usWidthClass_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_usWidthClass_name);

	zval property_fsType_default_value;
	ZVAL_LONG(&property_fsType_default_value, 0);
	zend_string *property_fsType_name = zend_string_init("fsType", sizeof("fsType") - 1, 1);
	zend_declare_typed_property(class_entry, property_fsType_name, &property_fsType_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_fsType_name);

	zval property_ySubscriptXSize_default_value;
	ZVAL_LONG(&property_ySubscriptXSize_default_value, 0);
	zend_string *property_ySubscriptXSize_name = zend_string_init("ySubscriptXSize", sizeof("ySubscriptXSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_ySubscriptXSize_name, &property_ySubscriptXSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ySubscriptXSize_name);

	zval property_ySubscriptYSize_default_value;
	ZVAL_LONG(&property_ySubscriptYSize_default_value, 0);
	zend_string *property_ySubscriptYSize_name = zend_string_init("ySubscriptYSize", sizeof("ySubscriptYSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_ySubscriptYSize_name, &property_ySubscriptYSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ySubscriptYSize_name);

	zval property_ySubscriptXOffset_default_value;
	ZVAL_LONG(&property_ySubscriptXOffset_default_value, 0);
	zend_string *property_ySubscriptXOffset_name = zend_string_init("ySubscriptXOffset", sizeof("ySubscriptXOffset") - 1, 1);
	zend_declare_typed_property(class_entry, property_ySubscriptXOffset_name, &property_ySubscriptXOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ySubscriptXOffset_name);

	zval property_ySubscriptYOffset_default_value;
	ZVAL_LONG(&property_ySubscriptYOffset_default_value, 0);
	zend_string *property_ySubscriptYOffset_name = zend_string_init("ySubscriptYOffset", sizeof("ySubscriptYOffset") - 1, 1);
	zend_declare_typed_property(class_entry, property_ySubscriptYOffset_name, &property_ySubscriptYOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ySubscriptYOffset_name);

	zval property_ySuperscriptXSize_default_value;
	ZVAL_LONG(&property_ySuperscriptXSize_default_value, 0);
	zend_string *property_ySuperscriptXSize_name = zend_string_init("ySuperscriptXSize", sizeof("ySuperscriptXSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_ySuperscriptXSize_name, &property_ySuperscriptXSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ySuperscriptXSize_name);

	zval property_ySuperscriptYSize_default_value;
	ZVAL_LONG(&property_ySuperscriptYSize_default_value, 0);
	zend_string *property_ySuperscriptYSize_name = zend_string_init("ySuperscriptYSize", sizeof("ySuperscriptYSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_ySuperscriptYSize_name, &property_ySuperscriptYSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ySuperscriptYSize_name);

	zval property_ySuperscriptXOffset_default_value;
	ZVAL_LONG(&property_ySuperscriptXOffset_default_value, 0);
	zend_string *property_ySuperscriptXOffset_name = zend_string_init("ySuperscriptXOffset", sizeof("ySuperscriptXOffset") - 1, 1);
	zend_declare_typed_property(class_entry, property_ySuperscriptXOffset_name, &property_ySuperscriptXOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ySuperscriptXOffset_name);

	zval property_ySuperscriptYOffset_default_value;
	ZVAL_LONG(&property_ySuperscriptYOffset_default_value, 0);
	zend_string *property_ySuperscriptYOffset_name = zend_string_init("ySuperscriptYOffset", sizeof("ySuperscriptYOffset") - 1, 1);
	zend_declare_typed_property(class_entry, property_ySuperscriptYOffset_name, &property_ySuperscriptYOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ySuperscriptYOffset_name);

	zval property_yStrikeoutSize_default_value;
	ZVAL_LONG(&property_yStrikeoutSize_default_value, 0);
	zend_string *property_yStrikeoutSize_name = zend_string_init("yStrikeoutSize", sizeof("yStrikeoutSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_yStrikeoutSize_name, &property_yStrikeoutSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_yStrikeoutSize_name);

	zval property_yStrikeoutPosition_default_value;
	ZVAL_LONG(&property_yStrikeoutPosition_default_value, 0);
	zend_string *property_yStrikeoutPosition_name = zend_string_init("yStrikeoutPosition", sizeof("yStrikeoutPosition") - 1, 1);
	zend_declare_typed_property(class_entry, property_yStrikeoutPosition_name, &property_yStrikeoutPosition_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_yStrikeoutPosition_name);

	zval property_sFamilyClass_default_value;
	ZVAL_LONG(&property_sFamilyClass_default_value, 0);
	zend_string *property_sFamilyClass_name = zend_string_init("sFamilyClass", sizeof("sFamilyClass") - 1, 1);
	zend_declare_typed_property(class_entry, property_sFamilyClass_name, &property_sFamilyClass_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_sFamilyClass_name);

	zval property_panose_default_value;
	ZVAL_EMPTY_ARRAY(&property_panose_default_value);
	zend_string *property_panose_name = zend_string_init("panose", sizeof("panose") - 1, 1);
	zend_declare_typed_property(class_entry, property_panose_name, &property_panose_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_panose_name);

	zval property_ulUnicodeRange1_default_value;
	ZVAL_LONG(&property_ulUnicodeRange1_default_value, 0);
	zend_string *property_ulUnicodeRange1_name = zend_string_init("ulUnicodeRange1", sizeof("ulUnicodeRange1") - 1, 1);
	zend_declare_typed_property(class_entry, property_ulUnicodeRange1_name, &property_ulUnicodeRange1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ulUnicodeRange1_name);

	zval property_ulUnicodeRange2_default_value;
	ZVAL_LONG(&property_ulUnicodeRange2_default_value, 0);
	zend_string *property_ulUnicodeRange2_name = zend_string_init("ulUnicodeRange2", sizeof("ulUnicodeRange2") - 1, 1);
	zend_declare_typed_property(class_entry, property_ulUnicodeRange2_name, &property_ulUnicodeRange2_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ulUnicodeRange2_name);

	zval property_ulUnicodeRange3_default_value;
	ZVAL_LONG(&property_ulUnicodeRange3_default_value, 0);
	zend_string *property_ulUnicodeRange3_name = zend_string_init("ulUnicodeRange3", sizeof("ulUnicodeRange3") - 1, 1);
	zend_declare_typed_property(class_entry, property_ulUnicodeRange3_name, &property_ulUnicodeRange3_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ulUnicodeRange3_name);

	zval property_ulUnicodeRange4_default_value;
	ZVAL_LONG(&property_ulUnicodeRange4_default_value, 0);
	zend_string *property_ulUnicodeRange4_name = zend_string_init("ulUnicodeRange4", sizeof("ulUnicodeRange4") - 1, 1);
	zend_declare_typed_property(class_entry, property_ulUnicodeRange4_name, &property_ulUnicodeRange4_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ulUnicodeRange4_name);

	zval property_achVendID_default_value;
	ZVAL_EMPTY_STRING(&property_achVendID_default_value);
	zend_string *property_achVendID_name = zend_string_init("achVendID", sizeof("achVendID") - 1, 1);
	zend_declare_typed_property(class_entry, property_achVendID_name, &property_achVendID_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_achVendID_name);

	zval property_fsSelection_default_value;
	ZVAL_LONG(&property_fsSelection_default_value, 0);
	zend_string *property_fsSelection_name = zend_string_init("fsSelection", sizeof("fsSelection") - 1, 1);
	zend_declare_typed_property(class_entry, property_fsSelection_name, &property_fsSelection_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_fsSelection_name);

	zval property_usFirstCharIndex_default_value;
	ZVAL_LONG(&property_usFirstCharIndex_default_value, 0);
	zend_string *property_usFirstCharIndex_name = zend_string_init("usFirstCharIndex", sizeof("usFirstCharIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_usFirstCharIndex_name, &property_usFirstCharIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_usFirstCharIndex_name);

	zval property_usLastCharIndex_default_value;
	ZVAL_LONG(&property_usLastCharIndex_default_value, 0);
	zend_string *property_usLastCharIndex_name = zend_string_init("usLastCharIndex", sizeof("usLastCharIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_usLastCharIndex_name, &property_usLastCharIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_usLastCharIndex_name);

	zval property_sTypoAscender_default_value;
	ZVAL_LONG(&property_sTypoAscender_default_value, 0);
	zend_string *property_sTypoAscender_name = zend_string_init("sTypoAscender", sizeof("sTypoAscender") - 1, 1);
	zend_declare_typed_property(class_entry, property_sTypoAscender_name, &property_sTypoAscender_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_sTypoAscender_name);

	zval property_sTypoDescender_default_value;
	ZVAL_LONG(&property_sTypoDescender_default_value, 0);
	zend_string *property_sTypoDescender_name = zend_string_init("sTypoDescender", sizeof("sTypoDescender") - 1, 1);
	zend_declare_typed_property(class_entry, property_sTypoDescender_name, &property_sTypoDescender_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_sTypoDescender_name);

	zval property_sTypoLineGap_default_value;
	ZVAL_LONG(&property_sTypoLineGap_default_value, 0);
	zend_string *property_sTypoLineGap_name = zend_string_init("sTypoLineGap", sizeof("sTypoLineGap") - 1, 1);
	zend_declare_typed_property(class_entry, property_sTypoLineGap_name, &property_sTypoLineGap_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_sTypoLineGap_name);

	zval property_usWinAscent_default_value;
	ZVAL_LONG(&property_usWinAscent_default_value, 0);
	zend_string *property_usWinAscent_name = zend_string_init("usWinAscent", sizeof("usWinAscent") - 1, 1);
	zend_declare_typed_property(class_entry, property_usWinAscent_name, &property_usWinAscent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_usWinAscent_name);

	zval property_usWinDescent_default_value;
	ZVAL_LONG(&property_usWinDescent_default_value, 0);
	zend_string *property_usWinDescent_name = zend_string_init("usWinDescent", sizeof("usWinDescent") - 1, 1);
	zend_declare_typed_property(class_entry, property_usWinDescent_name, &property_usWinDescent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_usWinDescent_name);

	zval property_ulCodePageRange1_default_value;
	ZVAL_LONG(&property_ulCodePageRange1_default_value, 0);
	zend_string *property_ulCodePageRange1_name = zend_string_init("ulCodePageRange1", sizeof("ulCodePageRange1") - 1, 1);
	zend_declare_typed_property(class_entry, property_ulCodePageRange1_name, &property_ulCodePageRange1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ulCodePageRange1_name);

	zval property_ulCodePageRange2_default_value;
	ZVAL_LONG(&property_ulCodePageRange2_default_value, 0);
	zend_string *property_ulCodePageRange2_name = zend_string_init("ulCodePageRange2", sizeof("ulCodePageRange2") - 1, 1);
	zend_declare_typed_property(class_entry, property_ulCodePageRange2_name, &property_ulCodePageRange2_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_ulCodePageRange2_name);

	zval property_sxHeight_default_value;
	ZVAL_LONG(&property_sxHeight_default_value, 0);
	zend_string *property_sxHeight_name = zend_string_init("sxHeight", sizeof("sxHeight") - 1, 1);
	zend_declare_typed_property(class_entry, property_sxHeight_name, &property_sxHeight_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_sxHeight_name);

	zval property_sCapHeight_default_value;
	ZVAL_LONG(&property_sCapHeight_default_value, 0);
	zend_string *property_sCapHeight_name = zend_string_init("sCapHeight", sizeof("sCapHeight") - 1, 1);
	zend_declare_typed_property(class_entry, property_sCapHeight_name, &property_sCapHeight_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_sCapHeight_name);

	zval property_usDefaultChar_default_value;
	ZVAL_LONG(&property_usDefaultChar_default_value, 0);
	zend_string *property_usDefaultChar_name = zend_string_init("usDefaultChar", sizeof("usDefaultChar") - 1, 1);
	zend_declare_typed_property(class_entry, property_usDefaultChar_name, &property_usDefaultChar_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_usDefaultChar_name);

	zval property_usBreakChar_default_value;
	ZVAL_LONG(&property_usBreakChar_default_value, 0);
	zend_string *property_usBreakChar_name = zend_string_init("usBreakChar", sizeof("usBreakChar") - 1, 1);
	zend_declare_typed_property(class_entry, property_usBreakChar_name, &property_usBreakChar_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_usBreakChar_name);

	zval property_usMaxContext_default_value;
	ZVAL_LONG(&property_usMaxContext_default_value, 0);
	zend_string *property_usMaxContext_name = zend_string_init("usMaxContext", sizeof("usMaxContext") - 1, 1);
	zend_declare_typed_property(class_entry, property_usMaxContext_name, &property_usMaxContext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_usMaxContext_name);

	zval property_usLowerOpticalPointSize_default_value;
	ZVAL_LONG(&property_usLowerOpticalPointSize_default_value, 0);
	zend_string *property_usLowerOpticalPointSize_name = zend_string_init("usLowerOpticalPointSize", sizeof("usLowerOpticalPointSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_usLowerOpticalPointSize_name, &property_usLowerOpticalPointSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_usLowerOpticalPointSize_name);

	zval property_usUpperOpticalPointSize_default_value;
	ZVAL_LONG(&property_usUpperOpticalPointSize_default_value, 0);
	zend_string *property_usUpperOpticalPointSize_name = zend_string_init("usUpperOpticalPointSize", sizeof("usUpperOpticalPointSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_usUpperOpticalPointSize_name, &property_usUpperOpticalPointSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_usUpperOpticalPointSize_name);

	return class_entry;
}

static zend_class_entry *register_class_TT_Postscript(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "TT_Postscript", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_FormatType_default_value;
	ZVAL_LONG(&property_FormatType_default_value, 0);
	zend_string *property_FormatType_name = zend_string_init("FormatType", sizeof("FormatType") - 1, 1);
	zend_declare_typed_property(class_entry, property_FormatType_name, &property_FormatType_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_FormatType_name);

	zval property_italicAngle_default_value;
	ZVAL_LONG(&property_italicAngle_default_value, 0);
	zend_string *property_italicAngle_name = zend_string_init("italicAngle", sizeof("italicAngle") - 1, 1);
	zend_declare_typed_property(class_entry, property_italicAngle_name, &property_italicAngle_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_italicAngle_name);

	zval property_underlinePosition_default_value;
	ZVAL_LONG(&property_underlinePosition_default_value, 0);
	zend_string *property_underlinePosition_name = zend_string_init("underlinePosition", sizeof("underlinePosition") - 1, 1);
	zend_declare_typed_property(class_entry, property_underlinePosition_name, &property_underlinePosition_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_underlinePosition_name);

	zval property_underlineThickness_default_value;
	ZVAL_LONG(&property_underlineThickness_default_value, 0);
	zend_string *property_underlineThickness_name = zend_string_init("underlineThickness", sizeof("underlineThickness") - 1, 1);
	zend_declare_typed_property(class_entry, property_underlineThickness_name, &property_underlineThickness_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_underlineThickness_name);

	zval property_isFixedPitch_default_value;
	ZVAL_LONG(&property_isFixedPitch_default_value, 0);
	zend_string *property_isFixedPitch_name = zend_string_init("isFixedPitch", sizeof("isFixedPitch") - 1, 1);
	zend_declare_typed_property(class_entry, property_isFixedPitch_name, &property_isFixedPitch_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_isFixedPitch_name);

	zval property_minMemType42_default_value;
	ZVAL_LONG(&property_minMemType42_default_value, 0);
	zend_string *property_minMemType42_name = zend_string_init("minMemType42", sizeof("minMemType42") - 1, 1);
	zend_declare_typed_property(class_entry, property_minMemType42_name, &property_minMemType42_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_minMemType42_name);

	zval property_maxMemType42_default_value;
	ZVAL_LONG(&property_maxMemType42_default_value, 0);
	zend_string *property_maxMemType42_name = zend_string_init("maxMemType42", sizeof("maxMemType42") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxMemType42_name, &property_maxMemType42_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxMemType42_name);

	zval property_minMemType1_default_value;
	ZVAL_LONG(&property_minMemType1_default_value, 0);
	zend_string *property_minMemType1_name = zend_string_init("minMemType1", sizeof("minMemType1") - 1, 1);
	zend_declare_typed_property(class_entry, property_minMemType1_name, &property_minMemType1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_minMemType1_name);

	zval property_maxMemType1_default_value;
	ZVAL_LONG(&property_maxMemType1_default_value, 0);
	zend_string *property_maxMemType1_name = zend_string_init("maxMemType1", sizeof("maxMemType1") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxMemType1_name, &property_maxMemType1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxMemType1_name);

	return class_entry;
}

static zend_class_entry *register_class_TT_PCLT(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "TT_PCLT", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_Version_default_value;
	ZVAL_LONG(&property_Version_default_value, 0);
	zend_string *property_Version_name = zend_string_init("Version", sizeof("Version") - 1, 1);
	zend_declare_typed_property(class_entry, property_Version_name, &property_Version_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Version_name);

	zval property_FontNumber_default_value;
	ZVAL_LONG(&property_FontNumber_default_value, 0);
	zend_string *property_FontNumber_name = zend_string_init("FontNumber", sizeof("FontNumber") - 1, 1);
	zend_declare_typed_property(class_entry, property_FontNumber_name, &property_FontNumber_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_FontNumber_name);

	zval property_Pitch_default_value;
	ZVAL_LONG(&property_Pitch_default_value, 0);
	zend_string *property_Pitch_name = zend_string_init("Pitch", sizeof("Pitch") - 1, 1);
	zend_declare_typed_property(class_entry, property_Pitch_name, &property_Pitch_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Pitch_name);

	zval property_xHeight_default_value;
	ZVAL_LONG(&property_xHeight_default_value, 0);
	zend_string *property_xHeight_name = zend_string_init("xHeight", sizeof("xHeight") - 1, 1);
	zend_declare_typed_property(class_entry, property_xHeight_name, &property_xHeight_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_xHeight_name);

	zval property_Style_default_value;
	ZVAL_LONG(&property_Style_default_value, 0);
	zend_string *property_Style_name = zend_string_init("Style", sizeof("Style") - 1, 1);
	zend_declare_typed_property(class_entry, property_Style_name, &property_Style_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Style_name);

	zval property_TypeFamily_default_value;
	ZVAL_LONG(&property_TypeFamily_default_value, 0);
	zend_string *property_TypeFamily_name = zend_string_init("TypeFamily", sizeof("TypeFamily") - 1, 1);
	zend_declare_typed_property(class_entry, property_TypeFamily_name, &property_TypeFamily_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_TypeFamily_name);

	zval property_CapHeight_default_value;
	ZVAL_LONG(&property_CapHeight_default_value, 0);
	zend_string *property_CapHeight_name = zend_string_init("CapHeight", sizeof("CapHeight") - 1, 1);
	zend_declare_typed_property(class_entry, property_CapHeight_name, &property_CapHeight_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_CapHeight_name);

	zval property_SymbolSet_default_value;
	ZVAL_LONG(&property_SymbolSet_default_value, 0);
	zend_string *property_SymbolSet_name = zend_string_init("SymbolSet", sizeof("SymbolSet") - 1, 1);
	zend_declare_typed_property(class_entry, property_SymbolSet_name, &property_SymbolSet_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_SymbolSet_name);

	zval property_TypeFace_default_value;
	ZVAL_EMPTY_STRING(&property_TypeFace_default_value);
	zend_string *property_TypeFace_name = zend_string_init("TypeFace", sizeof("TypeFace") - 1, 1);
	zend_declare_typed_property(class_entry, property_TypeFace_name, &property_TypeFace_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_TypeFace_name);

	zval property_CharacterComplement_default_value;
	ZVAL_EMPTY_STRING(&property_CharacterComplement_default_value);
	zend_string *property_CharacterComplement_name = zend_string_init("CharacterComplement", sizeof("CharacterComplement") - 1, 1);
	zend_declare_typed_property(class_entry, property_CharacterComplement_name, &property_CharacterComplement_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_CharacterComplement_name);

	zval property_FileName_default_value;
	ZVAL_EMPTY_STRING(&property_FileName_default_value);
	zend_string *property_FileName_name = zend_string_init("FileName", sizeof("FileName") - 1, 1);
	zend_declare_typed_property(class_entry, property_FileName_name, &property_FileName_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_FileName_name);

	zval property_StrokeWeight_default_value;
	ZVAL_LONG(&property_StrokeWeight_default_value, 0);
	zend_string *property_StrokeWeight_name = zend_string_init("StrokeWeight", sizeof("StrokeWeight") - 1, 1);
	zend_declare_typed_property(class_entry, property_StrokeWeight_name, &property_StrokeWeight_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_StrokeWeight_name);

	zval property_WidthType_default_value;
	ZVAL_LONG(&property_WidthType_default_value, 0);
	zend_string *property_WidthType_name = zend_string_init("WidthType", sizeof("WidthType") - 1, 1);
	zend_declare_typed_property(class_entry, property_WidthType_name, &property_WidthType_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_WidthType_name);

	zval property_SerifStyle_default_value;
	ZVAL_LONG(&property_SerifStyle_default_value, 0);
	zend_string *property_SerifStyle_name = zend_string_init("SerifStyle", sizeof("SerifStyle") - 1, 1);
	zend_declare_typed_property(class_entry, property_SerifStyle_name, &property_SerifStyle_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_SerifStyle_name);

	zval property_Reserved_default_value;
	ZVAL_LONG(&property_Reserved_default_value, 0);
	zend_string *property_Reserved_name = zend_string_init("Reserved", sizeof("Reserved") - 1, 1);
	zend_declare_typed_property(class_entry, property_Reserved_name, &property_Reserved_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_Reserved_name);

	return class_entry;
}

static zend_class_entry *register_class_TT_MaxProfile(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "TT_MaxProfile", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_version_default_value;
	ZVAL_LONG(&property_version_default_value, 0);
	zend_string *property_version_name = zend_string_init("version", sizeof("version") - 1, 1);
	zend_declare_typed_property(class_entry, property_version_name, &property_version_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_version_name);

	zval property_numGlyphs_default_value;
	ZVAL_LONG(&property_numGlyphs_default_value, 0);
	zend_string *property_numGlyphs_name = zend_string_init("numGlyphs", sizeof("numGlyphs") - 1, 1);
	zend_declare_typed_property(class_entry, property_numGlyphs_name, &property_numGlyphs_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_numGlyphs_name);

	zval property_maxPoints_default_value;
	ZVAL_LONG(&property_maxPoints_default_value, 0);
	zend_string *property_maxPoints_name = zend_string_init("maxPoints", sizeof("maxPoints") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxPoints_name, &property_maxPoints_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxPoints_name);

	zval property_maxContours_default_value;
	ZVAL_LONG(&property_maxContours_default_value, 0);
	zend_string *property_maxContours_name = zend_string_init("maxContours", sizeof("maxContours") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxContours_name, &property_maxContours_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxContours_name);

	zval property_maxCompositePoints_default_value;
	ZVAL_LONG(&property_maxCompositePoints_default_value, 0);
	zend_string *property_maxCompositePoints_name = zend_string_init("maxCompositePoints", sizeof("maxCompositePoints") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxCompositePoints_name, &property_maxCompositePoints_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxCompositePoints_name);

	zval property_maxCompositeContours_default_value;
	ZVAL_LONG(&property_maxCompositeContours_default_value, 0);
	zend_string *property_maxCompositeContours_name = zend_string_init("maxCompositeContours", sizeof("maxCompositeContours") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxCompositeContours_name, &property_maxCompositeContours_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxCompositeContours_name);

	zval property_maxZones_default_value;
	ZVAL_LONG(&property_maxZones_default_value, 0);
	zend_string *property_maxZones_name = zend_string_init("maxZones", sizeof("maxZones") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxZones_name, &property_maxZones_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxZones_name);

	zval property_maxTwilightPoints_default_value;
	ZVAL_LONG(&property_maxTwilightPoints_default_value, 0);
	zend_string *property_maxTwilightPoints_name = zend_string_init("maxTwilightPoints", sizeof("maxTwilightPoints") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxTwilightPoints_name, &property_maxTwilightPoints_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxTwilightPoints_name);

	zval property_maxStorage_default_value;
	ZVAL_LONG(&property_maxStorage_default_value, 0);
	zend_string *property_maxStorage_name = zend_string_init("maxStorage", sizeof("maxStorage") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxStorage_name, &property_maxStorage_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxStorage_name);

	zval property_maxFunctionDefs_default_value;
	ZVAL_LONG(&property_maxFunctionDefs_default_value, 0);
	zend_string *property_maxFunctionDefs_name = zend_string_init("maxFunctionDefs", sizeof("maxFunctionDefs") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxFunctionDefs_name, &property_maxFunctionDefs_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxFunctionDefs_name);

	zval property_maxInstructionDefs_default_value;
	ZVAL_LONG(&property_maxInstructionDefs_default_value, 0);
	zend_string *property_maxInstructionDefs_name = zend_string_init("maxInstructionDefs", sizeof("maxInstructionDefs") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxInstructionDefs_name, &property_maxInstructionDefs_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxInstructionDefs_name);

	zval property_maxStackElements_default_value;
	ZVAL_LONG(&property_maxStackElements_default_value, 0);
	zend_string *property_maxStackElements_name = zend_string_init("maxStackElements", sizeof("maxStackElements") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxStackElements_name, &property_maxStackElements_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxStackElements_name);

	zval property_maxSizeOfInstructions_default_value;
	ZVAL_LONG(&property_maxSizeOfInstructions_default_value, 0);
	zend_string *property_maxSizeOfInstructions_name = zend_string_init("maxSizeOfInstructions", sizeof("maxSizeOfInstructions") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxSizeOfInstructions_name, &property_maxSizeOfInstructions_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxSizeOfInstructions_name);

	zval property_maxComponentElements_default_value;
	ZVAL_LONG(&property_maxComponentElements_default_value, 0);
	zend_string *property_maxComponentElements_name = zend_string_init("maxComponentElements", sizeof("maxComponentElements") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxComponentElements_name, &property_maxComponentElements_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxComponentElements_name);

	zval property_maxComponentDepth_default_value;
	ZVAL_LONG(&property_maxComponentDepth_default_value, 0);
	zend_string *property_maxComponentDepth_name = zend_string_init("maxComponentDepth", sizeof("maxComponentDepth") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxComponentDepth_name, &property_maxComponentDepth_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxComponentDepth_name);

	return class_entry;
}
