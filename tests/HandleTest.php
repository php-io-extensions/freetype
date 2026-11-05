<?php

declare(strict_types=1);

it('keeps a handle when another class boxes its address', function (): void {
    [$lib, $face] = monoFace();
    $slot = $face->glyph;
    $address = $slot->pointer();

    FT_Outline::fromPointer($address);

    expect($slot->pointer())->toBe($address)
        ->and($face->glyph)->toBe($slot);
});

it('answers isset and var_dump from the native record', function (): void {
    [$lib, $face] = monoFace();

    ob_start();
    var_dump($face);
    $dump = (string) ob_get_clean();

    expect(isset($face->family_name))->toBeTrue()
        ->and(isset($face->glyph))->toBeTrue()
        ->and(empty($face->num_glyphs))->toBeFalse()
        ->and($dump)->toContain('string('.strlen(monoFamily()).') "'.monoFamily().'"')
        ->and($dump)->not->toContain('uninitialized');
});

it('answers isset false for a handle that holds NULL, without throwing', function (): void {
    expect(isset(FT_Face::fromPointer(0)->family_name))->toBeFalse();
});

it('refuses a struct whose property was unset, instead of reading it as 0', function (): void {
    [$lib, $face] = monoFace();
    $delta = new FT_Vector();
    unset($delta->y);

    expect(fn () => FT_Set_Transform($face, null, $delta))
        ->toThrow(Error::class, 'must not be accessed before initialization');
});

it('drops released faces from their library', function (): void {
    FT_Init_FreeType($lib);
    $cycle = function () use ($lib): void {
        FT_New_Face($lib, monoFont(), 0, $face);
        FT_Done_Face($face);
    };
    $cycle();
    $before = memory_get_usage();

    for ($i = 0; $i < 1000; $i++) {
        $cycle();
    }

    expect(memory_get_usage() - $before)->toBeLessThan(16 * 1024);
    FT_Done_FreeType($lib);
});
