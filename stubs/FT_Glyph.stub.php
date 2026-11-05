<?php

/** @generate-class-entries */

/**
 * @var int
 * @cvalue FT_LOAD_DEFAULT
 */
const FT_LOAD_DEFAULT = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_NO_SCALE
 */
const FT_LOAD_NO_SCALE = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_NO_HINTING
 */
const FT_LOAD_NO_HINTING = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_RENDER
 */
const FT_LOAD_RENDER = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_NO_BITMAP
 */
const FT_LOAD_NO_BITMAP = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_VERTICAL_LAYOUT
 */
const FT_LOAD_VERTICAL_LAYOUT = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_FORCE_AUTOHINT
 */
const FT_LOAD_FORCE_AUTOHINT = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_CROP_BITMAP
 */
const FT_LOAD_CROP_BITMAP = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_PEDANTIC
 */
const FT_LOAD_PEDANTIC = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH
 */
const FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_NO_RECURSE
 */
const FT_LOAD_NO_RECURSE = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_IGNORE_TRANSFORM
 */
const FT_LOAD_IGNORE_TRANSFORM = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_MONOCHROME
 */
const FT_LOAD_MONOCHROME = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_LINEAR_DESIGN
 */
const FT_LOAD_LINEAR_DESIGN = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_SBITS_ONLY
 */
const FT_LOAD_SBITS_ONLY = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_NO_AUTOHINT
 */
const FT_LOAD_NO_AUTOHINT = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_COLOR
 */
const FT_LOAD_COLOR = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_COMPUTE_METRICS
 */
const FT_LOAD_COMPUTE_METRICS = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_BITMAP_METRICS_ONLY
 */
const FT_LOAD_BITMAP_METRICS_ONLY = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_NO_SVG
 */
const FT_LOAD_NO_SVG = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_ADVANCE_ONLY
 */
const FT_LOAD_ADVANCE_ONLY = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_SVG_ONLY
 */
const FT_LOAD_SVG_ONLY = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_TARGET_NORMAL
 */
const FT_LOAD_TARGET_NORMAL = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_TARGET_LIGHT
 */
const FT_LOAD_TARGET_LIGHT = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_TARGET_MONO
 */
const FT_LOAD_TARGET_MONO = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_TARGET_LCD
 */
const FT_LOAD_TARGET_LCD = UNKNOWN;

/**
 * @var int
 * @cvalue FT_LOAD_TARGET_LCD_V
 */
const FT_LOAD_TARGET_LCD_V = UNKNOWN;

/**
 * @var int
 * @cvalue FT_RENDER_MODE_NORMAL
 */
const FT_RENDER_MODE_NORMAL = UNKNOWN;

/**
 * @var int
 * @cvalue FT_RENDER_MODE_LIGHT
 */
const FT_RENDER_MODE_LIGHT = UNKNOWN;

/**
 * @var int
 * @cvalue FT_RENDER_MODE_MONO
 */
const FT_RENDER_MODE_MONO = UNKNOWN;

/**
 * @var int
 * @cvalue FT_RENDER_MODE_LCD
 */
const FT_RENDER_MODE_LCD = UNKNOWN;

/**
 * @var int
 * @cvalue FT_RENDER_MODE_LCD_V
 */
const FT_RENDER_MODE_LCD_V = UNKNOWN;

/**
 * @var int
 * @cvalue FT_RENDER_MODE_SDF
 */
const FT_RENDER_MODE_SDF = UNKNOWN;

/**
 * @var int
 * @cvalue FT_RENDER_MODE_MAX
 */
const FT_RENDER_MODE_MAX = UNKNOWN;

/**
 * @var int
 * @cvalue FT_PIXEL_MODE_NONE
 */
const FT_PIXEL_MODE_NONE = UNKNOWN;

/**
 * @var int
 * @cvalue FT_PIXEL_MODE_MONO
 */
const FT_PIXEL_MODE_MONO = UNKNOWN;

/**
 * @var int
 * @cvalue FT_PIXEL_MODE_GRAY
 */
const FT_PIXEL_MODE_GRAY = UNKNOWN;

/**
 * @var int
 * @cvalue FT_PIXEL_MODE_GRAY2
 */
const FT_PIXEL_MODE_GRAY2 = UNKNOWN;

/**
 * @var int
 * @cvalue FT_PIXEL_MODE_GRAY4
 */
const FT_PIXEL_MODE_GRAY4 = UNKNOWN;

/**
 * @var int
 * @cvalue FT_PIXEL_MODE_LCD
 */
const FT_PIXEL_MODE_LCD = UNKNOWN;

/**
 * @var int
 * @cvalue FT_PIXEL_MODE_LCD_V
 */
const FT_PIXEL_MODE_LCD_V = UNKNOWN;

/**
 * @var int
 * @cvalue FT_PIXEL_MODE_BGRA
 */
const FT_PIXEL_MODE_BGRA = UNKNOWN;

/**
 * @var int
 * @cvalue FT_PIXEL_MODE_MAX
 */
const FT_PIXEL_MODE_MAX = UNKNOWN;

/**
 * An FT_GlyphSlot. Its face owns it: FT_Done_Face releases it. fromPointer() trusts any address other than 0.
 * The properties read the FT_GlyphSlotRec fields of the same names each time PHP reads them; struct fields
 * come back as fresh copies.
 */
final class FT_GlyphSlot
{
    public readonly int $glyph_index;
    public readonly FT_Glyph_Metrics $metrics;
    public readonly int $linearHoriAdvance;
    public readonly int $linearVertAdvance;
    public readonly FT_Vector $advance;
    public readonly int $format;
    public readonly FT_Bitmap $bitmap;
    public readonly int $bitmap_left;
    public readonly int $bitmap_top;
    public readonly FT_Outline $outline;

    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * The FT_Outline inside a glyph slot (FT_GlyphSlotRec.outline). Its slot owns it. fromPointer() trusts any
 * address other than 0.
 */
final class FT_Outline
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

final class FT_Glyph_Metrics
{
    public int $width = 0;
    public int $height = 0;
    public int $horiBearingX = 0;
    public int $horiBearingY = 0;
    public int $horiAdvance = 0;
    public int $vertBearingX = 0;
    public int $vertBearingY = 0;
    public int $vertAdvance = 0;
}

final class FT_Vector
{
    public int $x = 0;
    public int $y = 0;
}

final class FT_Matrix
{
    public int $xx = 0;
    public int $xy = 0;
    public int $yx = 0;
    public int $yy = 0;
}

/** buffer is the rows * abs(pitch) bytes the bitmap holds; palette is an address. */
final class FT_Bitmap
{
    public int $rows = 0;
    public int $width = 0;
    public int $pitch = 0;
    public string $buffer = '';
    public int $num_grays = 0;
    public int $pixel_mode = 0;
    public int $palette_mode = 0;
    public int $palette = 0;
}

function FT_Load_Glyph(FT_Face $face, int $glyph_index, int $load_flags): int {}

function FT_Render_Glyph(FT_GlyphSlot $slot, int $render_mode): int {}

function FT_Set_Transform(FT_Face $face, ?FT_Matrix $matrix, ?FT_Vector $delta): void {}

function FT_Outline_Embolden(FT_Outline $outline, int $strength): int {}
