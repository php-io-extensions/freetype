/*
 * freetype: 1:1 bindings of FreeType at the 2.13.2 API. Functions, handles, structs and constants
 * keep their C names. Dropping the last PHP reference does not destroy the native object.
 */

#include "runtime.h"
#include "ext/standard/info.h"
#include "../stubs/freetype_arginfo.h"

ZEND_DECLARE_MODULE_GLOBALS(freetype)

static PHP_GINIT_FUNCTION(freetype)
{
#if defined(COMPILE_DL_FREETYPE) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	zend_hash_init(&freetype_globals->boxes, 64, NULL, NULL, 1);
}

static PHP_GSHUTDOWN_FUNCTION(freetype)
{
	zend_hash_destroy(&freetype_globals->boxes);
}

PHP_MINIT_FUNCTION(freetype)
{
	register_freetype_symbols(module_number);
#ifdef PHPFT_PROBES
	/* A probe build: env PHPFT_PROBE_OFF=<site id> turns that kept refusal off (tests/Probes). */
	REGISTER_BOOL_CONSTANT("PHPFT_PROBES", true, CONST_PERSISTENT);
#endif
	phpft_register_FT_Face(module_number);
	phpft_register_FT_Size(module_number);
	phpft_register_FT_Glyph(module_number);

	return SUCCESS;
}

PHP_RINIT_FUNCTION(freetype)
{
#if defined(COMPILE_DL_FREETYPE) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}

PHP_MINFO_FUNCTION(freetype)
{
	char built[32];

	snprintf(built, sizeof(built), "%d.%d.%d", FREETYPE_MAJOR, FREETYPE_MINOR, FREETYPE_PATCH);
	php_info_print_table_start();
	php_info_print_table_row(2, "freetype support", "enabled");
	php_info_print_table_row(2, "Version", PHP_FREETYPE_VERSION);
	php_info_print_table_row(2, "FreeType headers", built);
	php_info_print_table_end();
}

zend_module_entry freetype_module_entry = {
	STANDARD_MODULE_HEADER,
	"freetype",
	NULL,
	PHP_MINIT(freetype),
	NULL,
	PHP_RINIT(freetype),
	NULL,
	PHP_MINFO(freetype),
	PHP_FREETYPE_VERSION,
	PHP_MODULE_GLOBALS(freetype),
	PHP_GINIT(freetype),
	PHP_GSHUTDOWN(freetype),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_FREETYPE
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(freetype)
#endif
