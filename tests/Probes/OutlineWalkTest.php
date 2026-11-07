<?php

declare(strict_types=1);

// Site freetype-outline-walk (outcome 1): FT_Outline_Decompose keeps reading the outline's points, tags and
// contours between callbacks. A callback that releases the face (or reloads the slot into new arrays) frees
// them, and the walk goes on through freed memory.

beforeEach(fn () => requireProbeBuild());

it('refuses to go on after a callback released the face, which FreeType reads freed (SIGSEGV) without the refusal', function (): void {
    $code = sprintf(<<<'PHP'
        FT_Init_FreeType($lib);
        FT_New_Face($lib, '%s', 0, $face);
        FT_Set_Pixel_Sizes($face, 0, 32);
        FT_Load_Glyph($face, FT_Get_Char_Index($face, ord('O')), FT_LOAD_NO_HINTING);
        $funcs = new FT_Outline_Funcs();
        $funcs->line_to = $funcs->conic_to = $funcs->cubic_to = fn (): int => 0;
        $funcs->move_to = function () use ($face): int {
            FT_Done_Face($face);

            return 0;
        };

        return FT_Outline_Decompose($face->glyph->outline, $funcs, null);
    PHP, monoFont());

    $kept = ftChild($code, null, gmalloc: true);
    $off = ftChild($code, 'freetype-outline-walk', gmalloc: true);

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toBe('ValueError: FT_Outline_Decompose(): a callback released or reloaded the outline being walked')
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
});
