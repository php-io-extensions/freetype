---
type: Module
title: Handles
description: One PHP object per native pointer and class, children released with their parent, record fields read live, and the bytes a memory face owns.
resource: src/runtime.c
tags: [freetype, zend, lifetime]
status: draft
generated: { by: claude/opus-5.5, at: 2026-11-05T12:00:00-05:00 }
sources:
  - id: runtime
    resource: src/runtime.h
    title: phpft_handle and the identity table
---

# Overview

A handle is `phpft_handle { void *ptr; zval children; zend_object std; }`. `ptr` is the native object, or NULL once released or when made by `fromPointer(0)`. `free_obj` drops the identity entry and `children`. It never calls `FT_Done_*`.[^runtime]

`phpft_box(rv, ptr, ce, parent)` returns the PHP object already stored for that address and class, or a new one. The identity table is module global `boxes`, keyed by (address, class) to a `zend_object*` (not refcounted), so each ZTS thread has its own, and two classes at one address (a `fromPointer()` of another class) are two objects that do not disturb each other. A new object with a parent goes into the parent's `children`: a library's faces, a face's size and glyph slot, a slot's outline. Before a parent takes a new child it drops the children already released, so a library that opens and closes faces does not grow. `get_gc` reports `children` to the cycle collector.[^runtime]

`phpft_release` clears `ptr`, drops the identity entry, and releases every child. `FT_Done_Face` and `FT_Done_FreeType` call it after the native call succeeds. A released handle holds NULL, which FreeType receives as NULL and answers with its own error code.[^runtime]

Handle properties are read by the class's `read_property` handler from the native record each time PHP reads them; struct-valued fields come back as fresh copies. `has_property` (`isset()`, `empty()`) and `get_debug_info` (`var_dump()`, `print_r()`) read the record the same way; on a handle holding NULL they fall back to the standard handlers, so `isset()` answers false without throwing. Reading a field of a handle holding NULL is refused (site `freetype-null-record`). `phpft_handle_setup` is a macro that gives each call site its own static handler table (`phpft_handlers`: the Zend handlers plus the class's record reader), so there is no limit on the number of handle classes. `FT_New_Memory_Face` hands FreeType a persistent copy of the PHP string and stores it in the face's `generic.data`, with `generic.finalizer` freeing it. FreeType reads the font from that memory for the native face's life, which can outlive `FT_Done_Face` (hb-ft's `FT_Reference_Face`), the PHP objects and the request; the finalizer runs when the last reference goes.[^runtime]

[^runtime]: phpft_handle and the identity table
