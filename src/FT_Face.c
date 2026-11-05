#include "runtime.h"
#include "../stubs/FT_Face_arginfo.h"

zend_class_entry *phpft_ce_FT_Library;
zend_class_entry *phpft_ce_FT_Face;

PHPFT_HANDLE_METHODS(FT_Library)
PHPFT_HANDLE_METHODS(FT_Face)

/* FT_FaceRec fields, read from the native record each time PHP reads them. */
static zval *phpft_face_read(zend_object *obj, zend_string *name, int type, void **cache_slot, zval *rv)
{
	FT_Face face = phpft_handle_from(obj)->ptr;
	const char *n = ZSTR_VAL(name);

#define PHPFT_LONG_FIELD(field) if (strcmp(n, #field) == 0) { ZVAL_LONG(rv, (zend_long) face->field); return rv; }
#define PHPFT_STRING_FIELD(field) if (strcmp(n, #field) == 0) { if (face->field) ZVAL_STRING(rv, face->field); else ZVAL_NULL(rv); return rv; }
	PHPFT_LONG_FIELD(num_faces)
	PHPFT_LONG_FIELD(face_index)
	PHPFT_LONG_FIELD(face_flags)
	PHPFT_LONG_FIELD(style_flags)
	PHPFT_LONG_FIELD(num_glyphs)
	PHPFT_STRING_FIELD(family_name)
	PHPFT_STRING_FIELD(style_name)
	PHPFT_LONG_FIELD(units_per_EM)
	PHPFT_LONG_FIELD(ascender)
	PHPFT_LONG_FIELD(descender)
	PHPFT_LONG_FIELD(height)
	PHPFT_LONG_FIELD(max_advance_width)
	PHPFT_LONG_FIELD(max_advance_height)
	PHPFT_LONG_FIELD(underline_position)
	PHPFT_LONG_FIELD(underline_thickness)
#undef PHPFT_LONG_FIELD
#undef PHPFT_STRING_FIELD
	if (zend_string_equals_literal(name, "glyph")) {
		phpft_box(rv, face->glyph, phpft_ce_FT_GlyphSlot, obj);
		return rv;
	}
	if (zend_string_equals_literal(name, "size")) {
		phpft_box(rv, face->size, phpft_ce_FT_Size, obj);
		return rv;
	}

	return zend_std_read_property(obj, name, type, cache_slot, rv);
}

ZEND_FUNCTION(FT_Init_FreeType)
{
	zval *alibrary;
	FT_Library library = NULL;
	FT_Error error;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(alibrary)
	ZEND_PARSE_PARAMETERS_END();

	error = FT_Init_FreeType(&library);

	zval boxed;
	phpft_box(&boxed, error == 0 ? library : NULL, phpft_ce_FT_Library, NULL);
	ZEND_TRY_ASSIGN_REF_TMP(alibrary, &boxed);
	RETURN_LONG(error);
}

ZEND_FUNCTION(FT_Done_FreeType)
{
	zval *library;
	FT_Error error;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(library, phpft_ce_FT_Library)
	ZEND_PARSE_PARAMETERS_END();

	error = FT_Done_FreeType(phpft_handle_ptr(library));
	if (error == 0) {
		phpft_release(Z_OBJ_P(library));
	}
	RETURN_LONG(error);
}

ZEND_FUNCTION(FT_New_Face)
{
	zval *library, *aface;
	zend_string *filepathname;
	zend_long face_index;
	FT_Face face = NULL;
	FT_Error error;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(library, phpft_ce_FT_Library)
		Z_PARAM_PATH_STR(filepathname)
		Z_PARAM_LONG(face_index)
		Z_PARAM_ZVAL(aface)
	ZEND_PARSE_PARAMETERS_END();

	error = FT_New_Face(phpft_handle_ptr(library), ZSTR_VAL(filepathname), (FT_Long) face_index, &face);

	zval boxed;
	phpft_box(&boxed, error == 0 ? face : NULL, phpft_ce_FT_Face, Z_OBJ_P(library));
	ZEND_TRY_ASSIGN_REF_TMP(aface, &boxed);
	RETURN_LONG(error);
}

/* FT_Generic finalizer of a memory face: FreeType calls it when the last reference to the face goes. */
static void phpft_free_face_bytes(void *object)
{
	FT_Face face = object;

	zend_string_release_ex((zend_string *) face->generic.data, 1);
}

ZEND_FUNCTION(FT_New_Memory_Face)
{
	zval *library, *aface;
	zend_string *file_base;
	zend_long file_size, face_index;
	FT_Face face = NULL;
	FT_Error error;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(library, phpft_ce_FT_Library)
		Z_PARAM_STR(file_base)
		Z_PARAM_LONG(file_size)
		Z_PARAM_LONG(face_index)
		Z_PARAM_ZVAL(aface)
	ZEND_PARSE_PARAMETERS_END();

	if (!PHPFT_PROBE_OFF("freetype-memory-face-size") && (file_size < 0 || file_size > (zend_long) ZSTR_LEN(file_base))) {
		zend_argument_value_error(3, "must be between 0 and the length of argument #2 ($file_base)"); /* binding:freetype-memory-face-size */
		RETURN_THROWS();
	}
	/* FreeType reads the font from this memory until the native face is destroyed, which can be after the
	 * PHP objects (hb-ft references the face) and after the request: a persistent copy, freed by the face. */
	zend_string *bytes = zend_string_dup(file_base, 1);
	error = FT_New_Memory_Face(phpft_handle_ptr(library), (const FT_Byte *) ZSTR_VAL(bytes), (FT_Long) file_size,
		(FT_Long) face_index, &face);
	if (error == 0) {
		face->generic.data = bytes;
		face->generic.finalizer = phpft_free_face_bytes;
	} else {
		zend_string_release_ex(bytes, 1);
	}

	zval boxed;
	phpft_box(&boxed, error == 0 ? face : NULL, phpft_ce_FT_Face, Z_OBJ_P(library));
	ZEND_TRY_ASSIGN_REF_TMP(aface, &boxed);
	RETURN_LONG(error);
}

ZEND_FUNCTION(FT_Done_Face)
{
	zval *face;
	FT_Error error;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(face, phpft_ce_FT_Face)
	ZEND_PARSE_PARAMETERS_END();

	error = FT_Done_Face(phpft_handle_ptr(face));
	if (error == 0) {
		phpft_release(Z_OBJ_P(face));
	}
	RETURN_LONG(error);
}

void phpft_register_FT_Face(int module_number)
{
	(void) module_number;
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
	phpft_ce_FT_Library = register_class_FT_Library();
	phpft_handle_setup(phpft_ce_FT_Library, NULL);
	phpft_ce_FT_Face = register_class_FT_Face();
	phpft_handle_setup(phpft_ce_FT_Face, phpft_face_read);
}
