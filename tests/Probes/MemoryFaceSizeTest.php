<?php

declare(strict_types=1);

// Site freetype-memory-face-size (outcome 1): FT_New_Memory_Face reads $file_size bytes from $file_base.
// A size larger than the string makes FreeType read past the string's end.

beforeEach(fn () => requireProbeBuild());

it('refuses a file size larger than the string, which FreeType reads past (SIGSEGV) without the refusal', function (): void {
    $code = sprintf(<<<'PHP'
        FT_Init_FreeType($lib);
        $bytes = file_get_contents('%s');
        $short = substr($bytes, 0, 4096);
        FT_New_Memory_Face($lib, $short, strlen($bytes), 0, $face);
        for ($glyph = 0; $glyph < 50; $glyph++) {
            FT_Load_Glyph($face, $glyph, FT_LOAD_RENDER);
        }

        return 'loaded';
    PHP, monoFont());

    $kept = ftChild($code, null, gmalloc: true);
    $off = ftChild($code, 'freetype-memory-face-size', gmalloc: true);

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toBe('ValueError: FT_New_Memory_Face(): Argument #3 ($file_size) must be between 0 and the length of argument #2 ($file_base)')
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
});

it('refuses a negative file size, which FreeType reads as ULONG_MAX bytes (SIGSEGV) without the refusal', function (): void {
    $code = sprintf(<<<'PHP'
        FT_Init_FreeType($lib);
        $short = substr(file_get_contents('%s'), 0, 4096);
        FT_New_Memory_Face($lib, $short, -1, 0, $face);
        for ($glyph = 0; $glyph < 50; $glyph++) {
            FT_Load_Glyph($face, $glyph, FT_LOAD_RENDER);
        }

        return 'loaded';
    PHP, monoFont());

    $kept = ftChild($code, null, gmalloc: true);
    $off = ftChild($code, 'freetype-memory-face-size', gmalloc: true);

    expect($kept['threw'])->toBe('ValueError: FT_New_Memory_Face(): Argument #3 ($file_size) must be between 0 and the length of argument #2 ($file_base)')
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
});
