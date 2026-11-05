<?php

/** @generate-class-entries */

/**
 * An FT_Library. One PHP object per native pointer; dropping it does not call FT_Done_FreeType.
 * fromPointer() trusts any address other than 0.
 */
final class FT_Library
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * An FT_Face. One PHP object per native pointer; dropping it does not call FT_Done_Face.
 * fromPointer() trusts any address other than 0. The properties read the FT_FaceRec fields of the same
 * names each time PHP reads them.
 */
final class FT_Face
{
    public readonly int $num_faces;
    public readonly int $face_index;
    public readonly int $face_flags;
    public readonly int $style_flags;
    public readonly int $num_glyphs;
    public readonly ?string $family_name;
    public readonly ?string $style_name;
    public readonly int $units_per_EM;
    public readonly int $ascender;
    public readonly int $descender;
    public readonly int $height;
    public readonly int $max_advance_width;
    public readonly int $max_advance_height;
    public readonly int $underline_position;
    public readonly int $underline_thickness;
    public readonly ?FT_GlyphSlot $glyph;
    public readonly ?FT_Size $size;

    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

function FT_Init_FreeType(?FT_Library &$alibrary): int {}

function FT_Done_FreeType(FT_Library $library): int {}

function FT_New_Face(FT_Library $library, string $filepathname, int $face_index, ?FT_Face &$aface): int {}

/** The face reads $file_base for its life; the extension keeps the string until FT_Done_Face. */
function FT_New_Memory_Face(FT_Library $library, string $file_base, int $file_size, int $face_index, ?FT_Face &$aface): int {}

function FT_Done_Face(FT_Face $face): int {}
