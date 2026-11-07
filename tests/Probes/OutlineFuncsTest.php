<?php

declare(strict_types=1);

// Site freetype-outline-funcs (outcome 2): FT_Outline_Decompose calls move_to, line_to, conic_to and cubic_to
// without checking them. A null member reaches FreeType as a NULL function pointer, which it calls.

beforeEach(fn () => requireProbeBuild());

it('refuses a null callback, which FreeType calls through NULL (SIGSEGV) without the refusal', function (): void {
    $code = sprintf(<<<'PHP'
        FT_Init_FreeType($lib);
        FT_New_Face($lib, '%s', 0, $face);
        FT_Set_Pixel_Sizes($face, 0, 32);
        FT_Load_Glyph($face, FT_Get_Char_Index($face, ord('O')), FT_LOAD_NO_HINTING);
        $funcs = new FT_Outline_Funcs();
        $funcs->move_to = $funcs->line_to = $funcs->cubic_to = fn (): int => 0;

        return FT_Outline_Decompose($face->glyph->outline, $funcs, null);
    PHP, monoFont());

    $kept = ftChild($code);
    $off = ftChild($code, 'freetype-outline-funcs');

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toBe('ValueError: FT_Outline_Decompose(): Argument #2 ($func_interface) must have a callable in move_to, line_to, conic_to and cubic_to')
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
});
