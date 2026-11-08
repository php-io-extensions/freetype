# Log

## 2026-11-08

* **Version**: 0.11.1 in `PHP_FREETYPE_VERSION` (`php_freetype.h`) and the README's phpinfo block; nothing else changed.

## 2026-11-05

* Bundle created with ext-freetype 0.11.0: `FT_Init_FreeType`, `FT_Done_FreeType`, `FT_New_Face`, `FT_New_Memory_Face`, `FT_Done_Face`, `FT_Set_Char_Size`, `FT_Set_Pixel_Sizes`, `FT_Get_Sfnt_Table`, `FT_Get_Char_Index`, `FT_Load_Glyph`, `FT_Render_Glyph`, `FT_Set_Transform`, `FT_Outline_Embolden` at the FreeType 2.13.2 API, the floor (Ubuntu 24.04's FreeType). Built on Homebrew PHP 8.4 NTS and ZTS against FreeType 2.15.0, and on Ubuntu against 2.13.2. [bindings](api/bindings.md), [handles](architecture/handles.md), [structs](architecture/structs.md), [build](runbooks/build.md).
* **Released handles pass through**: FreeType checks NULL itself (`0x23` invalid face, `0x06` invalid argument, `0x14` invalid outline, `0x21` invalid library), so only a read of a NULL handle's record crashes. That read is refused (site `freetype-null-record`), as is an `FT_New_Memory_Face` size past the string or below 0 (`freetype-memory-face-size`): FreeType reads a negative size as unsigned. Each has a probe in `tests/Probes`.
* **Memory face bytes**: the native face owns a persistent copy of the PHP string (`generic.data`, freed by `generic.finalizer`). The face can outlive `FT_Done_Face` (hb-ft takes its own reference) and the PHP objects; when the bytes went with the PHP handle instead, shaping read freed memory (SIGSEGV under libgmalloc).
* **Handle runtime**: identity is keyed by address and class, so a `fromPointer()` of another class does not clear a live handle. A parent drops released children when it gains a new one, and `get_gc` reports its children. Record handles answer `isset()`, `empty()` and `var_dump()` from the record. Handler tables are static per class, with no fixed limit. A struct property after `unset()` throws PHP's uninitialized-property `Error` instead of reading as 0.
* **Coverage**: `scripts/support.php` counts every `FT_EXPORT( type ) name(` of `include/freetype/*.h` and `include/freetype/config/*.h` at `VER-2-13-2`; `internal/` is not read.

## 2026-11-06

* **`FT_Outline_Decompose`** and the `FT_Outline_Funcs` struct (`?Closure` members, as PHP cannot type a property `callable`). Each callback gets fresh `FT_Vector` copies and then `$user`; its int return passes through, and a PHP exception stops the walk and is rethrown. Two refusals, each probed: a null member, which FreeType calls through NULL (`freetype-outline-funcs`), and a callback that released the face or moved the outline's points, tags or contours, which FreeType goes on reading (`freetype-outline-walk`). A reload into the same arrays is not refused. `phpft_walk_call` is marshal. Coverage 14 / 224. [bindings](api/bindings.md).
* **Probe runs**: run `tests/Probes` with a parent PHP that loads only freetype (`zhp -n -d extension=…/freetype.so`). With every Homebrew extension loaded in the parent, a child's SIGSEGV does not end it: it spins on the faulting instruction (seen with `freetype-null-record` as well). [build](runbooks/build.md).
