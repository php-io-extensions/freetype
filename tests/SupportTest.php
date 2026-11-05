<?php

declare(strict_types=1);

require_once __DIR__.'/../scripts/support.php';

it('counts the FT_EXPORT functions of each header, across lines, sorted, once each, not in comments or macros', function (): void {
    $header = "  FT_EXPORT( FT_Error )\n  FT_Init_FreeType( FT_Library  *alibrary );\n"
        ."  FT_EXPORT( FT_UInt )\n  FT_Get_Char_Index( FT_Face   face,\n                     FT_ULong  charcode );\n"
        ."  /* FT_EXPORT( void ) FT_Commented_Out( void ); */\n"
        ."#define FT_EXPORT( x )  FT_PUBLIC_FUNCTION_ATTRIBUTE extern x\n";

    expect(support_counted(['freetype.h' => $header]))
        ->toBe(['freetype.h' => ['FT_Get_Char_Index', 'FT_Init_FreeType']]);
});

it('measures the public headers and their config headers, not the internal ones', function (): void {
    expect(support_measured('freetype.h'))->toBeTrue()
        ->and(support_measured('config/ftoption.h'))->toBeTrue()
        ->and(support_measured('internal/ftobjs.h'))->toBeFalse()
        ->and(support_measured('config'))->toBeFalse();
});

it('reads the top-level functions of a stub, not class methods', function (): void {
    $stub = "<?php\nfunction FT_Init_FreeType(?FT_Library &\$alibrary): int {}\nfinal class FT_Face { public function pointer(): int {} }\nfunction FT_Done_Face(FT_Face \$face): int {}\n";

    expect(support_functions($stub))->toBe(['FT_Init_FreeType', 'FT_Done_Face']);
});

it('renders one line per function and lists the bindings that match none', function (): void {
    $md = support_render(['freetype.h' => ['FT_Done_Face', 'FT_Init_FreeType']], ['FT_Init_FreeType' => true, 'ft_helper' => true], 'FreeType 2.13.2', '2026-11-05');

    expect($md)->toContain('- [x] `FT_Init_FreeType`')
        ->toContain('- [ ] `FT_Done_Face`')
        ->toContain('## freetype.h (1 / 2)')
        ->toContain('FreeType 2.13.2 — 1 / 2 members bound (50.0%) — 2026-11-05')
        ->toContain('- `ft_helper`');
});

it('computes the badge from the counts', function (): void {
    expect(support_badge('FreeType API', 31, 209))
        ->toBe('[![FreeType API](https://img.shields.io/badge/FreeType_API-14.8%25_%2831%2F209%29-blue?style=flat-square)](SUPPORT.md)');
});

it('compares a support list without its date', function (): void {
    expect(support_same("FreeType 2.13.2 — 2 / 4 members bound (50.0%) — 2026-11-05\n", "FreeType 2.13.2 — 2 / 4 members bound (50.0%) — 2026-11-09\n"))->toBeTrue()
        ->and(support_same("FreeType 2.13.2 — 2 / 4 members bound (50.0%) — 2026-11-05\n", "FreeType 2.13.2 — 3 / 4 members bound (75.0%) — 2026-11-05\n"))->toBeFalse();
});
