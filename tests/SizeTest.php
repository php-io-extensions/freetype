<?php

declare(strict_types=1);

it('sizes a face and reads the size metrics', function (): void {
    [$lib, $face] = monoFace();

    expect(FT_Set_Pixel_Sizes($face, 0, 32))->toBe(0)
        ->and($face->size)->toBeInstanceOf(FT_Size::class)
        ->and($face->size->metrics)->toBeInstanceOf(FT_Size_Metrics::class)
        ->and($face->size->metrics->y_ppem)->toBe(32)
        ->and(FT_Set_Char_Size($face, 0, 16 * 64, 72, 72))->toBe(0)
        ->and($face->size->metrics->y_ppem)->toBe(16)
        ->and($face->size->metrics->ascender)->toBeGreaterThan(0);
});

it('reads the OS/2 table', function (): void {
    [$lib, $face] = monoFace();
    $os2 = FT_Get_Sfnt_Table($face, FT_SFNT_OS2);

    expect($os2)->toBeInstanceOf(TT_OS2::class)
        ->and($os2->xAvgCharWidth)->toBe(1233)
        ->and($os2->yStrikeoutSize)->toBe(102)
        ->and($os2->panose)->toHaveCount(10)
        ->and(strlen($os2->achVendID))->toBe(4);
});

it('reads the head table, whose units per EM match the face record', function (): void {
    [$lib, $face] = monoFace();
    $head = FT_Get_Sfnt_Table($face, FT_SFNT_HEAD);

    expect($head)->toBeInstanceOf(TT_Header::class)
        ->and($head->Units_Per_EM)->toBe($face->units_per_EM)
        ->and($head->Created)->toHaveCount(2);
});

it('finds a glyph index, and 0 for a character the font lacks', function (): void {
    [$lib, $face] = monoFace();

    expect(FT_Get_Char_Index($face, ord('M')))->toBeGreaterThan(0)
        ->and(FT_Get_Char_Index($face, 0x4E2D))->toBe(0);
});
