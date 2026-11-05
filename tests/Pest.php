<?php

declare(strict_types=1);

if (! extension_loaded('freetype')) {
    throw new RuntimeException('The freetype extension is not loaded; run ./install-macos.sh or ./install-debian-trixie.sh');
}

/** The monospace test font: Menlo (face 0 of the collection) on macOS, DejaVu Sans Mono on Linux. */
function monoFont(): string
{
    return PHP_OS_FAMILY === 'Darwin'
        ? '/System/Library/Fonts/Menlo.ttc'
        : '/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf';
}

function monoFamily(): string
{
    return PHP_OS_FAMILY === 'Darwin' ? 'Menlo' : 'DejaVu Sans Mono';
}

/** Signal numbers a child process dies by (SIGBUS is 10 on macOS, 7 on Linux). */
const PROBE_SIGBUS = PHP_OS_FAMILY === 'Darwin' ? 10 : 7;
const PROBE_SIGSEGV = 11;

/**
 * Skips a tests/Probes test unless the loaded ext-freetype is a probe build (--enable-freetype-probes),
 * the only build where env PHPFT_PROBE_OFF turns a kept refusal off.
 */
function requireProbeBuild(): void
{
    if (! defined('PHPFT_PROBES')) {
        test()->markTestSkipped('ext-freetype is not a probe build (configure --enable-freetype-probes): PHPFT_PROBES is undefined');
    }
}

/**
 * Runs $code in a child of this PHP, with the same ini configuration. The code is a function body: what it
 * returns comes back as 'result' (JSON), a throw as 'threw' ("Class: message"). $siteOff names the kept
 * site env PHPFT_PROBE_OFF turns off (a probe build only); null keeps every site. $gmalloc runs the child
 * under libgmalloc with Zend's allocator off, so a native read of freed or short PHP memory faults.
 *
 * @return array{signal: ?int, exit: ?int, result: mixed, threw: ?string, survived: bool, stdout: string, stderr: string}
 */
function ftChild(string $code, ?string $siteOff = null, bool $gmalloc = false): array
{
    if ($gmalloc && PHP_OS_FAMILY !== 'Darwin') {
        test()->markTestSkipped('the probe faults its over-read at a libgmalloc guard page, which only macOS has');
    }

    $script = <<<PHP
    <?php
    declare(strict_types=1);
    try {
        \$result = (static function () {
    {$code}
        })();
        echo "\\nRESULT ", json_encode(\$result, JSON_PRESERVE_ZERO_FRACTION | JSON_PARTIAL_OUTPUT_ON_ERROR), "\\n";
    } catch (Throwable \$t) {
        echo "\\nREFUSED ", get_class(\$t), ': ', \$t->getMessage(), "\\n";
    }
    echo "SURVIVED\\n";
    PHP;

    $base = tempnam(sys_get_temp_dir(), 'ft-child');
    $file = $base.'.php';
    file_put_contents($file, $script);

    $env = getenv();
    unset($env['PHPFT_PROBE_OFF'], $env['DYLD_INSERT_LIBRARIES'], $env['USE_ZEND_ALLOC']);
    $env['XDEBUG_MODE'] = 'off';
    if ($siteOff !== null) {
        $env['PHPFT_PROBE_OFF'] = $siteOff;
    }
    if ($gmalloc) {
        $env['DYLD_INSERT_LIBRARIES'] = '/usr/lib/libgmalloc.dylib';
        $env['USE_ZEND_ALLOC'] = '0';
    }

    // No -n: the child reads the same ini files and PHP_INI_SCAN_DIR as this PHP, so it loads the same module.
    $process = proc_open([PHP_BINARY, '-d', 'memory_limit=128M', $file],
        [0 => ['file', '/dev/null', 'r'], 1 => ['pipe', 'w'], 2 => ['pipe', 'w']], $pipes, null, $env);
    $stdout = (string) stream_get_contents($pipes[1]);
    $stderr = (string) stream_get_contents($pipes[2]);
    fclose($pipes[1]);
    fclose($pipes[2]);
    do {
        $status = proc_get_status($process);
    } while ($status['running'] && usleep(10_000) === null);
    proc_close($process);
    @unlink($base);
    @unlink($file);

    return [
        'signal' => $status['signaled'] ? $status['termsig'] : null,
        'exit' => $status['signaled'] ? null : $status['exitcode'],
        'result' => preg_match('/^RESULT (.*)$/m', $stdout, $m) === 1 ? json_decode($m[1], true) : null,
        'threw' => preg_match('/^REFUSED (.*)$/m', $stdout, $m) === 1 ? $m[1] : null,
        'survived' => str_contains($stdout, "SURVIVED\n"),
        'stdout' => $stdout,
        'stderr' => $stderr,
    ];
}

/**
 * A library and the mono test face on it.
 *
 * @return array{0: FT_Library, 1: FT_Face}
 */
function monoFace(): array
{
    FT_Init_FreeType($lib) === 0 || throw new RuntimeException('FT_Init_FreeType failed');
    FT_New_Face($lib, monoFont(), 0, $face) === 0 || throw new RuntimeException('FT_New_Face failed for '.monoFont());

    return [$lib, $face];
}
