<?php

declare(strict_types=1);

it('loads and renders M as an 8-bit coverage bitmap', function (): void {
    [$lib, $face] = monoFace();
    FT_Set_Pixel_Sizes($face, 0, 32);

    expect(FT_Load_Glyph($face, FT_Get_Char_Index($face, ord('M')), FT_LOAD_DEFAULT))->toBe(0)
        ->and($face->glyph)->toBeInstanceOf(FT_GlyphSlot::class)
        ->and(FT_Render_Glyph($face->glyph, FT_RENDER_MODE_NORMAL))->toBe(0);

    $b = $face->glyph->bitmap;
    expect($b)->toBeInstanceOf(FT_Bitmap::class)
        ->and($b->pixel_mode)->toBe(FT_PIXEL_MODE_GRAY)
        ->and($b->rows)->toBeGreaterThan(0)
        ->and(strlen($b->buffer))->toBe($b->rows * abs($b->pitch))
        ->and($face->glyph->format)->toBe(0x62697473) // FT_GLYPH_FORMAT_BITMAP, FT_IMAGE_TAG 'b','i','t','s'
        ->and($face->glyph->advance->x)->toBeGreaterThan(0)
        ->and($face->glyph->metrics->horiAdvance)->toBe($face->glyph->advance->x);
});

it('renders a space as an empty bitmap', function (): void {
    [$lib, $face] = monoFace();
    FT_Set_Pixel_Sizes($face, 0, 32);
    FT_Load_Glyph($face, FT_Get_Char_Index($face, ord(' ')), FT_LOAD_RENDER);

    expect($face->glyph->bitmap->rows)->toBe(0)
        ->and($face->glyph->bitmap->width)->toBe(0)
        ->and($face->glyph->bitmap->buffer)->toBe('');
});

it('moves the bitmap by a 26.6 delta', function (): void {
    [$lib, $face] = monoFace();
    FT_Set_Pixel_Sizes($face, 0, 32);
    $glyph = FT_Get_Char_Index($face, ord('M'));
    FT_Load_Glyph($face, $glyph, FT_LOAD_RENDER);
    $left = $face->glyph->bitmap_left;

    $delta = new FT_Vector();
    $delta->x = 3 * 64;
    FT_Set_Transform($face, null, $delta);
    FT_Load_Glyph($face, $glyph, FT_LOAD_RENDER);

    expect($face->glyph->bitmap_left)->toBe($left + 3);
});

it('emboldens an outline: the rendered glyph gets wider', function (): void {
    [$lib, $face] = monoFace();
    FT_Set_Pixel_Sizes($face, 0, 32);
    $glyph = FT_Get_Char_Index($face, ord('l'));
    FT_Load_Glyph($face, $glyph, FT_LOAD_RENDER);
    $width = $face->glyph->bitmap->width;

    FT_Load_Glyph($face, $glyph, FT_LOAD_DEFAULT);
    expect($face->glyph->outline)->toBeInstanceOf(FT_Outline::class)
        ->and(FT_Outline_Embolden($face->glyph->outline, 2 * 64))->toBe(0)
        ->and(FT_Render_Glyph($face->glyph, FT_RENDER_MODE_NORMAL))->toBe(0)
        ->and($face->glyph->bitmap->width)->toBeGreaterThan($width);
});

it('loads glyphs from a memory face after PHP dropped its string', function (): void {
    FT_Init_FreeType($lib);
    $open = function () use ($lib): FT_Face {
        $bytes = file_get_contents(monoFont());
        FT_New_Memory_Face($lib, $bytes, strlen($bytes), 0, $face);

        return $face;
    };
    $face = $open();
    gc_collect_cycles();

    $rendered = [];
    FT_Set_Pixel_Sizes($face, 0, 32);
    foreach (str_split('Mgjq@') as $char) {
        expect(FT_Load_Glyph($face, FT_Get_Char_Index($face, ord($char)), FT_LOAD_RENDER))->toBe(0);
        $rendered[] = $face->glyph->bitmap->rows;
    }

    expect(min($rendered))->toBeGreaterThan(0);
});
