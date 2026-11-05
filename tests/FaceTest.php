<?php

declare(strict_types=1);

it('opens and closes a library', function (): void {
    expect(FT_Init_FreeType($lib))->toBe(0)
        ->and($lib)->toBeInstanceOf(FT_Library::class)
        ->and(FT_Done_FreeType($lib))->toBe(0);
});

it('opens the mono test font and reads its record', function (): void {
    FT_Init_FreeType($lib);

    expect(FT_New_Face($lib, monoFont(), 0, $face))->toBe(0)
        ->and($face)->toBeInstanceOf(FT_Face::class)
        ->and($face->family_name)->toBe(monoFamily())
        ->and($face->face_flags & FT_FACE_FLAG_FIXED_WIDTH)->toBe(FT_FACE_FLAG_FIXED_WIDTH)
        ->and($face->units_per_EM)->toBe(2048)
        ->and($face->ascender)->toBeGreaterThan(0)
        ->and($face->descender)->toBeLessThan(0);

    expect(FT_Done_Face($face))->toBe(0)
        ->and(FT_Done_FreeType($lib))->toBe(0);
});

it('answers FreeType error codes for a missing file and a non-font', function (): void {
    FT_Init_FreeType($lib);

    expect(FT_New_Face($lib, '/nonexistent.ttf', 0, $missing))->toBe(1)
        ->and($missing)->toBeNull()
        ->and(FT_New_Face($lib, __FILE__, 0, $text))->toBe(2)
        ->and($text)->toBeNull();

    FT_Done_FreeType($lib);
});

it('keeps the bytes of a memory face after PHP drops its string', function (): void {
    FT_Init_FreeType($lib);
    $open = function () use ($lib): FT_Face {
        $bytes = file_get_contents(monoFont());
        FT_New_Memory_Face($lib, $bytes, strlen($bytes), 0, $face);

        return $face;
    };

    $face = $open();
    gc_collect_cycles();
    // Fills freed memory with garbage, so a face reading a freed string reads garbage.
    for ($i = 0; $i < 64; $i++) {
        $junk[] = str_repeat("\xAA", 1 << 16);
    }

    expect($face->family_name)->toBe(monoFamily())
        ->and($face->num_glyphs)->toBeGreaterThan(0);

    FT_Done_FreeType($lib);
});

it('gives one object per native face', function (): void {
    FT_Init_FreeType($lib);
    FT_New_Face($lib, monoFont(), 0, $face);

    expect(FT_Face::fromPointer($face->pointer()))->toBe($face);

    FT_Done_FreeType($lib);
});
