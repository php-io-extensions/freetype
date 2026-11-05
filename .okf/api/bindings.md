---
type: API
title: Bindings
description: Every bound FreeType function, handle, struct and constant group, by the stub that declares it.
resource: stubs/
tags: [freetype, api]
status: draft
generated: { by: claude/opus-5.5, at: 2026-11-05T12:00:00-05:00 }
sources:
  - id: stubs
    resource: stubs/
    title: The stubs
---

# Overview

| Stub | C file | Functions | Classes | Constants |
|---|---|---|---|---|
| `freetype.stub.php` | `src/freetype.c` | — | — | `FT_FACE_FLAG_*`, `FT_STYLE_FLAG_*`, `FT_SFNT_*` |
| `FT_Face.stub.php` | `src/FT_Face.c` | `FT_Init_FreeType`, `FT_Done_FreeType`, `FT_New_Face`, `FT_New_Memory_Face`, `FT_Done_Face` | `FT_Library`, `FT_Face` | — |
| `FT_Size.stub.php` | `src/FT_Size.c` | `FT_Set_Char_Size`, `FT_Set_Pixel_Sizes`, `FT_Get_Sfnt_Table`, `FT_Get_Char_Index` | `FT_Size`, `FT_Size_Metrics`, `TT_Header`, `TT_HoriHeader`, `TT_VertHeader`, `TT_OS2`, `TT_Postscript`, `TT_PCLT`, `TT_MaxProfile` | — |
| `FT_Glyph.stub.php` | `src/FT_Glyph.c` | `FT_Load_Glyph`, `FT_Render_Glyph`, `FT_Set_Transform`, `FT_Outline_Embolden` | `FT_GlyphSlot`, `FT_Outline`, `FT_Glyph_Metrics`, `FT_Vector`, `FT_Matrix`, `FT_Bitmap` | `FT_LOAD_*`, `FT_RENDER_MODE_*`, `FT_PIXEL_MODE_*` |

`FT_GLYPH_FORMAT_*` are not bound yet: ext-guard's C header reader does not see enum members declared through `FT_IMAGE_TAG( … )`.[^stubs]

`FT_Face` properties: `num_faces`, `face_index`, `face_flags`, `style_flags`, `num_glyphs`, `family_name`, `style_name`, `units_per_EM`, `ascender`, `descender`, `height`, `max_advance_width`, `max_advance_height`, `underline_position`, `underline_thickness`, `glyph`, `size`. `FT_Size`: `metrics`. `FT_GlyphSlot`: `glyph_index`, `metrics`, `linearHoriAdvance`, `linearVertAdvance`, `advance`, `format`, `bitmap`, `bitmap_left`, `bitmap_top`, `outline`.

[^stubs]: The stubs
