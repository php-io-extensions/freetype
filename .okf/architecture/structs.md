---
type: Module
title: Structs
description: C structs as final classes with one typed property per field, copied in and out at the call.
resource: src/FT_Size.c
tags: [freetype, structs]
status: draft
generated: { by: claude/opus-5.5, at: 2026-11-05T12:00:00-05:00 }
sources:
  - id: macros
    resource: src/runtime.h
    title: PHPFT_SET_LONG, PHPFT_SET_BYTES, PHPFT_SET_LIST
---

# Overview

A struct class is `final`, not cloneable, not serializable, with one typed public property per C field in field order under the C name, zero by default, and no constructor (`phpft_struct_setup`).[^macros]

Out of FreeType, a struct is copied into a new object with `PHPFT_SET_LONG` (integer fields), `PHPFT_SET_BYTES` (a `char` array as its full-length bytes, `FT_Bitmap.buffer` as `rows * abs(pitch)` bytes) and `PHPFT_SET_LIST` (another array as a list of ints). A pointer field is its address as an `int`.[^macros]

Into FreeType, `FT_Set_Transform` reads the typed `int` properties of `FT_Matrix` and `FT_Vector` into C structs on the stack; a `null` argument passes NULL. A property that was `unset()` is read without the silent flag, so PHP throws its uninitialized-property `Error` and FreeType is not called.

`FT_Get_Sfnt_Table` copies the table its tag names into `TT_Header`, `TT_MaxProfile`, `TT_OS2`, `TT_HoriHeader`, `TT_VertHeader`, `TT_Postscript` or `TT_PCLT`, and returns `null` when FreeType returns NULL.

[^macros]: PHPFT_SET_LONG, PHPFT_SET_BYTES, PHPFT_SET_LIST
