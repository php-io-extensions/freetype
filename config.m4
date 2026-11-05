PHP_ARG_ENABLE([freetype],
  [whether to enable freetype support],
  [AS_HELP_STRING([--enable-freetype], [Enable the FreeType bindings])],
  [no])

PHP_ARG_ENABLE([freetype-probes],
  [whether to build the freetype probe switch],
  [AS_HELP_STRING([--enable-freetype-probes],
    [Build the PHPFT_PROBE_OFF switch that tests/Probes drives: env PHPFT_PROBE_OFF=<site id> turns that kept refusal off. Never for a release build])],
  [no],
  [no])

if test "$PHP_FREETYPE" != "no"; then
  if test "$PHP_FREETYPE_PROBES" != "no"; then
    AC_DEFINE([PHPFT_PROBES], [1], [Kept refusal sites can be turned off through env PHPFT_PROBE_OFF])
  fi

  dnl freetype2 26.1.20 is FreeType 2.13.2, the floor.
  PKG_CHECK_MODULES([FREETYPE], [freetype2 >= 26.1.20])
  PHP_EVAL_INCLINE([$FREETYPE_CFLAGS])
  PHP_EVAL_LIBLINE([$FREETYPE_LIBS], [FREETYPE_SHARED_LIBADD])
  PHP_SUBST([FREETYPE_SHARED_LIBADD])

  PHP_NEW_EXTENSION([freetype],
    [src/freetype.c src/runtime.c src/FT_Face.c src/FT_Size.c src/FT_Glyph.c],
    [$ext_shared],, [-DZEND_ENABLE_STATIC_TSRMLS_CACHE=1 -Wall -Wextra])
  PHP_ADD_BUILD_DIR([$ext_builddir/src])
fi
