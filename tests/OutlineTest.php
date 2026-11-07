<?php

declare(strict_types=1);

/** The outline of $char at 32 px in the mono test face, with the library and face that own it. */
function monoOutline(string $char): array
{
    [$lib, $face] = monoFace();
    FT_Set_Pixel_Sizes($face, 0, 32);
    FT_Load_Glyph($face, FT_Get_Char_Index($face, ord($char)), FT_LOAD_NO_HINTING);

    return [$lib, $face, $face->glyph->outline];
}

/** An FT_Outline_Funcs whose callbacks count their calls by name into $calls and return 0. */
function countingFuncs(?array &$calls): FT_Outline_Funcs
{
    $calls = [];
    $funcs = new FT_Outline_Funcs();
    foreach (['move_to', 'line_to', 'conic_to', 'cubic_to'] as $name) {
        $calls[$name] = 0;
        $funcs->{$name} = function () use (&$calls, $name): int {
            $calls[$name]++;

            return 0;
        };
    }

    return $funcs;
}

it('walks O as two contours of curves', function (): void {
    [$lib, $face, $outline] = monoOutline('O');

    expect(FT_Outline_Decompose($outline, countingFuncs($calls), null))->toBe(0)
        ->and($calls['move_to'])->toBe(2)
        ->and($calls['conic_to'] + $calls['cubic_to'])->toBeGreaterThanOrEqual(4);
});

it('passes 26.6 points and the user value to each callback', function (): void {
    [$lib, $face, $outline] = monoOutline('O');
    $funcs = countingFuncs($calls);
    $seen = [];
    $funcs->move_to = function (FT_Vector $to, mixed $user) use (&$seen): int {
        $seen[] = [$to->x, $to->y, $user];

        return 0;
    };
    FT_Outline_Decompose($outline, $funcs, 'mine');

    expect($seen)->toHaveCount(2)
        ->and($seen[0][2])->toBe('mine')
        ->and(abs($seen[0][0]))->toBeLessThan(32 * 64 * 2);
});

it('stops the walk at a non-zero return and answers it', function (): void {
    [$lib, $face, $outline] = monoOutline('O');
    $funcs = countingFuncs($calls);
    $stopped = 0;
    $funcs->line_to = $funcs->conic_to = $funcs->cubic_to = function () use (&$stopped): int {
        $stopped++;

        return 7;
    };

    expect(FT_Outline_Decompose($outline, $funcs, null))->toBe(7)
        ->and($stopped)->toBe(1)
        ->and($calls['move_to'])->toBe(1);
});

it('applies shift and delta to every point', function (): void {
    [$lib, $face, $outline] = monoOutline('O');
    $first = function (int $shift, int $delta) use ($outline): array {
        $funcs = countingFuncs($calls);
        $funcs->shift = $shift;
        $funcs->delta = $delta;
        $at = null;
        $funcs->move_to = function (FT_Vector $to) use (&$at): int {
            $at ??= [$to->x, $to->y];

            return 0;
        };
        FT_Outline_Decompose($outline, $funcs, null);

        return $at;
    };
    [$x, $y] = $first(0, 0);

    expect($first(1, 0))->toBe([$x << 1, $y << 1])
        ->and($first(0, 5))->toBe([$x - 5, $y - 5]);
});

it('lets a callback exception through and stops the walk', function (): void {
    [$lib, $face, $outline] = monoOutline('O');
    $funcs = countingFuncs($calls);
    $moves = 0;
    $funcs->move_to = function () use (&$moves): int {
        $moves++;

        throw new LogicException('from the callback');
    };

    expect(fn () => FT_Outline_Decompose($outline, $funcs, null))->toThrow(LogicException::class, 'from the callback')
        ->and($moves)->toBe(1);
});

it('refuses a missing callback, which FreeType calls through NULL', function (): void {
    [$lib, $face, $outline] = monoOutline('O');
    $funcs = countingFuncs($calls);
    $funcs->cubic_to = null;

    expect(fn () => FT_Outline_Decompose($outline, $funcs, null))
        ->toThrow(ValueError::class, 'FT_Outline_Decompose(): Argument #2 ($func_interface) must have a callable in move_to, line_to, conic_to and cubic_to');
});

it('refuses to go on once a callback released the face', function (): void {
    [$lib, $face, $outline] = monoOutline('O');
    $funcs = countingFuncs($calls);
    $funcs->conic_to = $funcs->cubic_to = function () use ($face): int {
        FT_Done_Face($face);

        return 0;
    };

    expect(fn () => FT_Outline_Decompose($outline, $funcs, null))
        ->toThrow(ValueError::class, 'FT_Outline_Decompose(): a callback released or reloaded the outline being walked');
});
