#ifndef PHP_FREETYPE_H
#define PHP_FREETYPE_H

extern zend_module_entry freetype_module_entry;
#define phpext_freetype_ptr &freetype_module_entry

#define PHP_FREETYPE_VERSION "0.11.0"

#if defined(ZTS) && defined(COMPILE_DL_FREETYPE)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif
