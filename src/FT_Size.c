#include "runtime.h"
#include "../stubs/FT_Size_arginfo.h"

zend_class_entry *phpft_ce_FT_Size;
zend_class_entry *phpft_ce_FT_Size_Metrics;
static zend_class_entry *phpft_ce_TT_Header;
static zend_class_entry *phpft_ce_TT_HoriHeader;
static zend_class_entry *phpft_ce_TT_VertHeader;
static zend_class_entry *phpft_ce_TT_OS2;
static zend_class_entry *phpft_ce_TT_Postscript;
static zend_class_entry *phpft_ce_TT_PCLT;
static zend_class_entry *phpft_ce_TT_MaxProfile;

PHPFT_HANDLE_METHODS(FT_Size)

void phpft_size_metrics(zval *rv, const FT_Size_Metrics *m)
{
	object_init_ex(rv, phpft_ce_FT_Size_Metrics);
	PHPFT_SET_LONG(rv, "x_ppem", m->x_ppem);
	PHPFT_SET_LONG(rv, "y_ppem", m->y_ppem);
	PHPFT_SET_LONG(rv, "x_scale", m->x_scale);
	PHPFT_SET_LONG(rv, "y_scale", m->y_scale);
	PHPFT_SET_LONG(rv, "ascender", m->ascender);
	PHPFT_SET_LONG(rv, "descender", m->descender);
	PHPFT_SET_LONG(rv, "height", m->height);
	PHPFT_SET_LONG(rv, "max_advance", m->max_advance);
}

static zval *phpft_size_read(zend_object *obj, zend_string *name, int type, void **cache_slot, zval *rv)
{
	FT_Size size = phpft_handle_from(obj)->ptr;

	if (zend_string_equals_literal(name, "metrics")) {
		phpft_size_metrics(rv, &size->metrics);
		return rv;
	}
	return zend_std_read_property(obj, name, type, cache_slot, rv);
}

ZEND_FUNCTION(FT_Set_Char_Size)
{
	zval *face;
	zend_long char_width, char_height, horz_resolution, vert_resolution;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(face, phpft_ce_FT_Face)
		Z_PARAM_LONG(char_width)
		Z_PARAM_LONG(char_height)
		Z_PARAM_LONG(horz_resolution)
		Z_PARAM_LONG(vert_resolution)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(FT_Set_Char_Size(phpft_handle_ptr(face), (FT_F26Dot6) char_width, (FT_F26Dot6) char_height,
		(FT_UInt) horz_resolution, (FT_UInt) vert_resolution));
}

ZEND_FUNCTION(FT_Set_Pixel_Sizes)
{
	zval *face;
	zend_long pixel_width, pixel_height;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(face, phpft_ce_FT_Face)
		Z_PARAM_LONG(pixel_width)
		Z_PARAM_LONG(pixel_height)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(FT_Set_Pixel_Sizes(phpft_handle_ptr(face), (FT_UInt) pixel_width, (FT_UInt) pixel_height));
}

static void phpft_tt_header(zval *rv, const TT_Header *t)
{
	object_init_ex(rv, phpft_ce_TT_Header);
	PHPFT_SET_LONG(rv, "Table_Version", t->Table_Version);
	PHPFT_SET_LONG(rv, "Font_Revision", t->Font_Revision);
	PHPFT_SET_LONG(rv, "CheckSum_Adjust", t->CheckSum_Adjust);
	PHPFT_SET_LONG(rv, "Magic_Number", t->Magic_Number);
	PHPFT_SET_LONG(rv, "Flags", t->Flags);
	PHPFT_SET_LONG(rv, "Units_Per_EM", t->Units_Per_EM);
	PHPFT_SET_LIST(rv, "Created", t->Created);
	PHPFT_SET_LIST(rv, "Modified", t->Modified);
	PHPFT_SET_LONG(rv, "xMin", t->xMin);
	PHPFT_SET_LONG(rv, "yMin", t->yMin);
	PHPFT_SET_LONG(rv, "xMax", t->xMax);
	PHPFT_SET_LONG(rv, "yMax", t->yMax);
	PHPFT_SET_LONG(rv, "Mac_Style", t->Mac_Style);
	PHPFT_SET_LONG(rv, "Lowest_Rec_PPEM", t->Lowest_Rec_PPEM);
	PHPFT_SET_LONG(rv, "Font_Direction", t->Font_Direction);
	PHPFT_SET_LONG(rv, "Index_To_Loc_Format", t->Index_To_Loc_Format);
	PHPFT_SET_LONG(rv, "Glyph_Data_Format", t->Glyph_Data_Format);
}

/* TT_HoriHeader and TT_VertHeader share their layout; the five fields that differ are named per table. */
#define PHPFT_TT_METRICS_HEADER(rv, ce, t, adv, first, second, extent, count) do { \
	object_init_ex(rv, ce); \
	PHPFT_SET_LONG(rv, "Version", (t)->Version); \
	PHPFT_SET_LONG(rv, "Ascender", (t)->Ascender); \
	PHPFT_SET_LONG(rv, "Descender", (t)->Descender); \
	PHPFT_SET_LONG(rv, "Line_Gap", (t)->Line_Gap); \
	PHPFT_SET_LONG(rv, #adv, (t)->adv); \
	PHPFT_SET_LONG(rv, #first, (t)->first); \
	PHPFT_SET_LONG(rv, #second, (t)->second); \
	PHPFT_SET_LONG(rv, #extent, (t)->extent); \
	PHPFT_SET_LONG(rv, "caret_Slope_Rise", (t)->caret_Slope_Rise); \
	PHPFT_SET_LONG(rv, "caret_Slope_Run", (t)->caret_Slope_Run); \
	PHPFT_SET_LONG(rv, "caret_Offset", (t)->caret_Offset); \
	PHPFT_SET_LIST(rv, "Reserved", (t)->Reserved); \
	PHPFT_SET_LONG(rv, "metric_Data_Format", (t)->metric_Data_Format); \
	PHPFT_SET_LONG(rv, #count, (t)->count); \
	PHPFT_SET_LONG(rv, "long_metrics", (uintptr_t) (t)->long_metrics); \
	PHPFT_SET_LONG(rv, "short_metrics", (uintptr_t) (t)->short_metrics); \
} while (0)

static void phpft_tt_os2(zval *rv, const TT_OS2 *t)
{
	object_init_ex(rv, phpft_ce_TT_OS2);
	PHPFT_SET_LONG(rv, "version", t->version);
	PHPFT_SET_LONG(rv, "xAvgCharWidth", t->xAvgCharWidth);
	PHPFT_SET_LONG(rv, "usWeightClass", t->usWeightClass);
	PHPFT_SET_LONG(rv, "usWidthClass", t->usWidthClass);
	PHPFT_SET_LONG(rv, "fsType", t->fsType);
	PHPFT_SET_LONG(rv, "ySubscriptXSize", t->ySubscriptXSize);
	PHPFT_SET_LONG(rv, "ySubscriptYSize", t->ySubscriptYSize);
	PHPFT_SET_LONG(rv, "ySubscriptXOffset", t->ySubscriptXOffset);
	PHPFT_SET_LONG(rv, "ySubscriptYOffset", t->ySubscriptYOffset);
	PHPFT_SET_LONG(rv, "ySuperscriptXSize", t->ySuperscriptXSize);
	PHPFT_SET_LONG(rv, "ySuperscriptYSize", t->ySuperscriptYSize);
	PHPFT_SET_LONG(rv, "ySuperscriptXOffset", t->ySuperscriptXOffset);
	PHPFT_SET_LONG(rv, "ySuperscriptYOffset", t->ySuperscriptYOffset);
	PHPFT_SET_LONG(rv, "yStrikeoutSize", t->yStrikeoutSize);
	PHPFT_SET_LONG(rv, "yStrikeoutPosition", t->yStrikeoutPosition);
	PHPFT_SET_LONG(rv, "sFamilyClass", t->sFamilyClass);
	PHPFT_SET_LIST(rv, "panose", t->panose);
	PHPFT_SET_LONG(rv, "ulUnicodeRange1", t->ulUnicodeRange1);
	PHPFT_SET_LONG(rv, "ulUnicodeRange2", t->ulUnicodeRange2);
	PHPFT_SET_LONG(rv, "ulUnicodeRange3", t->ulUnicodeRange3);
	PHPFT_SET_LONG(rv, "ulUnicodeRange4", t->ulUnicodeRange4);
	PHPFT_SET_BYTES(rv, "achVendID", t->achVendID, sizeof(t->achVendID));
	PHPFT_SET_LONG(rv, "fsSelection", t->fsSelection);
	PHPFT_SET_LONG(rv, "usFirstCharIndex", t->usFirstCharIndex);
	PHPFT_SET_LONG(rv, "usLastCharIndex", t->usLastCharIndex);
	PHPFT_SET_LONG(rv, "sTypoAscender", t->sTypoAscender);
	PHPFT_SET_LONG(rv, "sTypoDescender", t->sTypoDescender);
	PHPFT_SET_LONG(rv, "sTypoLineGap", t->sTypoLineGap);
	PHPFT_SET_LONG(rv, "usWinAscent", t->usWinAscent);
	PHPFT_SET_LONG(rv, "usWinDescent", t->usWinDescent);
	PHPFT_SET_LONG(rv, "ulCodePageRange1", t->ulCodePageRange1);
	PHPFT_SET_LONG(rv, "ulCodePageRange2", t->ulCodePageRange2);
	PHPFT_SET_LONG(rv, "sxHeight", t->sxHeight);
	PHPFT_SET_LONG(rv, "sCapHeight", t->sCapHeight);
	PHPFT_SET_LONG(rv, "usDefaultChar", t->usDefaultChar);
	PHPFT_SET_LONG(rv, "usBreakChar", t->usBreakChar);
	PHPFT_SET_LONG(rv, "usMaxContext", t->usMaxContext);
	PHPFT_SET_LONG(rv, "usLowerOpticalPointSize", t->usLowerOpticalPointSize);
	PHPFT_SET_LONG(rv, "usUpperOpticalPointSize", t->usUpperOpticalPointSize);
}

static void phpft_tt_postscript(zval *rv, const TT_Postscript *t)
{
	object_init_ex(rv, phpft_ce_TT_Postscript);
	PHPFT_SET_LONG(rv, "FormatType", t->FormatType);
	PHPFT_SET_LONG(rv, "italicAngle", t->italicAngle);
	PHPFT_SET_LONG(rv, "underlinePosition", t->underlinePosition);
	PHPFT_SET_LONG(rv, "underlineThickness", t->underlineThickness);
	PHPFT_SET_LONG(rv, "isFixedPitch", t->isFixedPitch);
	PHPFT_SET_LONG(rv, "minMemType42", t->minMemType42);
	PHPFT_SET_LONG(rv, "maxMemType42", t->maxMemType42);
	PHPFT_SET_LONG(rv, "minMemType1", t->minMemType1);
	PHPFT_SET_LONG(rv, "maxMemType1", t->maxMemType1);
}

static void phpft_tt_pclt(zval *rv, const TT_PCLT *t)
{
	object_init_ex(rv, phpft_ce_TT_PCLT);
	PHPFT_SET_LONG(rv, "Version", t->Version);
	PHPFT_SET_LONG(rv, "FontNumber", t->FontNumber);
	PHPFT_SET_LONG(rv, "Pitch", t->Pitch);
	PHPFT_SET_LONG(rv, "xHeight", t->xHeight);
	PHPFT_SET_LONG(rv, "Style", t->Style);
	PHPFT_SET_LONG(rv, "TypeFamily", t->TypeFamily);
	PHPFT_SET_LONG(rv, "CapHeight", t->CapHeight);
	PHPFT_SET_LONG(rv, "SymbolSet", t->SymbolSet);
	PHPFT_SET_BYTES(rv, "TypeFace", t->TypeFace, sizeof(t->TypeFace));
	PHPFT_SET_BYTES(rv, "CharacterComplement", t->CharacterComplement, sizeof(t->CharacterComplement));
	PHPFT_SET_BYTES(rv, "FileName", t->FileName, sizeof(t->FileName));
	PHPFT_SET_LONG(rv, "StrokeWeight", t->StrokeWeight);
	PHPFT_SET_LONG(rv, "WidthType", t->WidthType);
	PHPFT_SET_LONG(rv, "SerifStyle", t->SerifStyle);
	PHPFT_SET_LONG(rv, "Reserved", t->Reserved);
}

static void phpft_tt_maxp(zval *rv, const TT_MaxProfile *t)
{
	object_init_ex(rv, phpft_ce_TT_MaxProfile);
	PHPFT_SET_LONG(rv, "version", t->version);
	PHPFT_SET_LONG(rv, "numGlyphs", t->numGlyphs);
	PHPFT_SET_LONG(rv, "maxPoints", t->maxPoints);
	PHPFT_SET_LONG(rv, "maxContours", t->maxContours);
	PHPFT_SET_LONG(rv, "maxCompositePoints", t->maxCompositePoints);
	PHPFT_SET_LONG(rv, "maxCompositeContours", t->maxCompositeContours);
	PHPFT_SET_LONG(rv, "maxZones", t->maxZones);
	PHPFT_SET_LONG(rv, "maxTwilightPoints", t->maxTwilightPoints);
	PHPFT_SET_LONG(rv, "maxStorage", t->maxStorage);
	PHPFT_SET_LONG(rv, "maxFunctionDefs", t->maxFunctionDefs);
	PHPFT_SET_LONG(rv, "maxInstructionDefs", t->maxInstructionDefs);
	PHPFT_SET_LONG(rv, "maxStackElements", t->maxStackElements);
	PHPFT_SET_LONG(rv, "maxSizeOfInstructions", t->maxSizeOfInstructions);
	PHPFT_SET_LONG(rv, "maxComponentElements", t->maxComponentElements);
	PHPFT_SET_LONG(rv, "maxComponentDepth", t->maxComponentDepth);
}

ZEND_FUNCTION(FT_Get_Sfnt_Table)
{
	zval *face;
	zend_long tag;
	void *table;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(face, phpft_ce_FT_Face)
		Z_PARAM_LONG(tag)
	ZEND_PARSE_PARAMETERS_END();

	table = FT_Get_Sfnt_Table(phpft_handle_ptr(face), (FT_Sfnt_Tag) tag);
	if (table == NULL) {
		RETURN_NULL();
	}
	switch (tag) {
		case FT_SFNT_HEAD: phpft_tt_header(return_value, table); return;
		case FT_SFNT_MAXP: phpft_tt_maxp(return_value, table); return;
		case FT_SFNT_OS2: phpft_tt_os2(return_value, table); return;
		case FT_SFNT_HHEA: {
			const TT_HoriHeader *t = table;
			PHPFT_TT_METRICS_HEADER(return_value, phpft_ce_TT_HoriHeader, t, advance_Width_Max, min_Left_Side_Bearing,
				min_Right_Side_Bearing, xMax_Extent, number_Of_HMetrics);
			return;
		}
		case FT_SFNT_VHEA: {
			const TT_VertHeader *t = table;
			PHPFT_TT_METRICS_HEADER(return_value, phpft_ce_TT_VertHeader, t, advance_Height_Max, min_Top_Side_Bearing,
				min_Bottom_Side_Bearing, yMax_Extent, number_Of_VMetrics);
			return;
		}
		case FT_SFNT_POST: phpft_tt_postscript(return_value, table); return;
		case FT_SFNT_PCLT: phpft_tt_pclt(return_value, table); return;
	}
	/* FreeType answers NULL for a tag it does not know, so a table here has one of the tags above. */
	RETURN_NULL();
}

ZEND_FUNCTION(FT_Get_Char_Index)
{
	zval *face;
	zend_long charcode;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(face, phpft_ce_FT_Face)
		Z_PARAM_LONG(charcode)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(FT_Get_Char_Index(phpft_handle_ptr(face), (FT_ULong) charcode));
}

void phpft_register_FT_Size(int module_number)
{
	(void) module_number;
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
	phpft_ce_FT_Size = register_class_FT_Size();
	phpft_handle_setup(phpft_ce_FT_Size, phpft_size_read);
	phpft_ce_FT_Size_Metrics = register_class_FT_Size_Metrics();
	phpft_struct_setup(phpft_ce_FT_Size_Metrics);
	phpft_ce_TT_Header = register_class_TT_Header();
	phpft_struct_setup(phpft_ce_TT_Header);
	phpft_ce_TT_HoriHeader = register_class_TT_HoriHeader();
	phpft_struct_setup(phpft_ce_TT_HoriHeader);
	phpft_ce_TT_VertHeader = register_class_TT_VertHeader();
	phpft_struct_setup(phpft_ce_TT_VertHeader);
	phpft_ce_TT_OS2 = register_class_TT_OS2();
	phpft_struct_setup(phpft_ce_TT_OS2);
	phpft_ce_TT_Postscript = register_class_TT_Postscript();
	phpft_struct_setup(phpft_ce_TT_Postscript);
	phpft_ce_TT_PCLT = register_class_TT_PCLT();
	phpft_struct_setup(phpft_ce_TT_PCLT);
	phpft_ce_TT_MaxProfile = register_class_TT_MaxProfile();
	phpft_struct_setup(phpft_ce_TT_MaxProfile);
}
