<?php

declare(strict_types=1);

// Site freetype-null-record (outcome 1): a property of FT_Face, FT_Size or FT_GlyphSlot reads a field of
// the native record. A handle that holds NULL (released by FT_Done_Face / FT_Done_FreeType, or made by
// fromPointer(0)) has no record: the read dereferences NULL.

beforeEach(fn () => requireProbeBuild());

it('refuses a record read through a released face, which dereferences NULL (SIGSEGV) without the refusal', function (): void {
    $code = <<<'PHP'
        FT_Init_FreeType($lib);
        FT_New_Face($lib, '%s', 0, $face);
        FT_Done_Face($face);

        return $face->ascender;
    PHP;
    $code = sprintf($code, monoFont());

    $kept = ftChild($code);
    $off = ftChild($code, 'freetype-null-record');

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toBe('ValueError: FT_Face holds NULL: it was released, or made from address 0')
        ->and($off['signal'])->toBe(PROBE_SIGSEGV);
});

it('refuses a record read through fromPointer(0), which dereferences NULL (SIGSEGV) without the refusal', function (): void {
    $code = 'return FT_GlyphSlot::fromPointer(0)->bitmap_left;';

    $kept = ftChild($code);
    $off = ftChild($code, 'freetype-null-record');

    expect($kept['threw'])->toBe('ValueError: FT_GlyphSlot holds NULL: it was released, or made from address 0')
        ->and($off['signal'])->toBe(PROBE_SIGSEGV);
});

it('passes a released face to FreeType, which answers its own error code', function (): void {
    $code = sprintf(<<<'PHP'
        FT_Init_FreeType($lib);
        FT_New_Face($lib, '%s', 0, $face);
        FT_Done_Face($face);

        return FT_Load_Glyph($face, 48, FT_LOAD_DEFAULT);
    PHP, monoFont());

    expect(ftChild($code)['result'])->toBe(0x23); // FT_Err_Invalid_Face_Handle
});
