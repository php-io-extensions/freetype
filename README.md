<div align="center" id="header">

<h1>ext-freetype</h1>

<h3>FreeType 2 bound 1:1 into PHP 8.4+, at the 2.13.2 API</h3>


[![CI](https://img.shields.io/github/actions/workflow/status/php-io-extensions/freetype/ci.yml?style=flat-square&label=CI)](https://github.com/php-io-extensions/freetype/actions/workflows/ci.yml)
[![FreeType API](https://img.shields.io/badge/FreeType_API-6.2%25_%2814%2F224%29-blue?style=flat-square)](SUPPORT.md)
[![Packagist](https://img.shields.io/packagist/v/php-io-extensions/freetype?style=flat-square)](https://packagist.org/packages/php-io-extensions/freetype)
[![PHP](https://img.shields.io/packagist/dependency-v/php-io-extensions/freetype/php?style=flat-square&label=PHP)](https://packagist.org/packages/php-io-extensions/freetype)
[![License](https://img.shields.io/github/license/php-io-extensions/freetype?style=flat-square)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-linux_%7C_macos-blue?style=flat-square&logo=linux&logoColor=white)](#requirements)
[![OKF](https://img.shields.io/badge/OKF-0.2-6f42c1?style=flat-square&label=knowledge%20bundle)](.okf/index.md)
[![PIE](https://img.shields.io/badge/PIE-installable-4f5b93?style=flat-square&logo=php&logoColor=white)](https://github.com/php/pie)

</div>

Anything that draws its own text, be it a canvas, a game, a framebuffer, or a GPU texture, needs each character as pixels: a glyph's outline scaled to a size, rasterised into coverage values, and placed at the right distance from its neighbours. A font file doesn't give you that. It holds outlines in font units, hinting programs, metrics tables and a character map, in TrueType, OpenType or CFF form, and every one has to be read before the first pixel exists.

<b>FreeType</b> is the library that reads them. It has rendered the text on Linux desktops, Android and most of the world's embedded screens for two decades: open a face, set a size, load a glyph and get its bitmap, its metrics and the pen advance. It is written in C, and its documentation covers every call.

<b>The only problem?</b> PHP can't reach it. gd's `imagettftext()` draws a whole string into a gd image and hides everything in between: no glyph bitmaps, no metrics, no control over where each glyph lands. This extension binds FreeType one to one under the C names, at the FreeType 2.13.2 API: faces, sizes, SFNT tables, character indexes, glyph loading and rendering, transforms and emboldening. A face's record fields are read live from FreeType, structs are typed classes, and FreeType's error codes come back as the return values, as in C. No defaults, no composites, no opinions: what FreeType documents is what you call.

## Basic usage

Most ways you will interface with ext-freetype are in two parts -

Open a face and size it. `FT_Init_FreeType()` and `FT_New_Face()` write their handle to a by-reference argument and return FreeType's error code; the face's record fields are properties, read from FreeType each time:

```php
FT_Init_FreeType($library);
FT_New_Face($library, '/System/Library/Fonts/Menlo.ttc', 0, $face);   // DejaVuSansMono.ttf on Linux
FT_Set_Pixel_Sizes($face, 0, 16);

echo "{$face->family_name} {$face->style_name}, {$face->num_glyphs} glyphs, ascender " . $face->size->metrics->ascender / 64 . " px\n";
```

Load and render a glyph. `FT_LOAD_RENDER` leaves an 8-bit coverage bitmap in the face's glyph slot, one byte per pixel, `pitch` bytes per row; the advance is in 26.6 fixed point. Close the face and the library when you're done:

```php
FT_Load_Glyph($face, FT_Get_Char_Index($face, ord('g')), FT_LOAD_RENDER);
$bitmap = $face->glyph->bitmap;
for ($row = 0; $row < $bitmap->rows; $row++) {
    $line = '';
    for ($x = 0; $x < $bitmap->width; $x++) {
        $line .= ' .:-=+*#%@'[intdiv(ord($bitmap->buffer[$row * $bitmap->pitch + $x]) * 9, 255)];
    }
    echo $line, "\n";
}
echo 'advance ', $face->glyph->advance->x / 64, " px\n";

FT_Done_Face($face);
FT_Done_FreeType($library);
```

```console
$ php glyph.php
Menlo Regular, 3157 glyphs, ascender 15 px
  -#%#=@.
 :%= :%@.
 *#   +@.
 %+   -@.
 %=   :@.
 %+   -@.
 *#   +@.
 :@= :%@.
  -#%*=@.
      -%
  +. .#+
  :#%#=
advance 10 px
```

Draw each row at `bitmap_left` from the pen and `bitmap_top` above the baseline, then move the pen by the advance.

## Requirements

| | |
|---|---|
| OS | Linux or macOS. `composer.json` lists those two families. |
| PHP | 8.4 or newer, NTS or ZTS. |
| Libraries | FreeType 2.13.2 or newer, with its headers, found through `pkg-config` (`freetype2`). 2.13.2 is the floor: nothing newer is bound. |

To build it you need a C compiler, `pkg-config`, FreeType's development files, and the development files of the PHP you intend to load it into:

```bash
# Debian, Ubuntu, Raspberry Pi OS
sudo apt install build-essential pkg-config libfreetype-dev php8.4-dev

# macOS: Xcode Command Line Tools, and Homebrew's PHP ships phpize and php-config
xcode-select --install
brew install pkgconf freetype php@8.4
```

## Installation

### With PHP PIE (recommended)

[PIE](https://github.com/php/pie) is the PHP Foundation's installer for extensions. It downloads the tagged source from Packagist, builds it against the PHP on your `PATH`, installs the module and enables it. `sudo` where your PHP's extension directory is root-owned, as on Debian; not on a Homebrew Mac. Install FreeType first:

```bash
pie install php-io-extensions/freetype
```

### Manually (install script)

The repository ships two installers, one per platform. Each one builds for each PHP it targets, installs `freetype.so` into that PHP's `extension_dir`, writes `30-freetype.ini` into its `conf.d` scan directory, and checks the module loads. The macOS one builds in a temporary copy of the checkout and ad-hoc signs the module so the system loads it on first use; the Debian one builds in the checkout, writes the ini into the CLI, FPM and Apache `conf.d` of that PHP, and cleans the build products out afterwards.

```bash
git clone https://github.com/php-io-extensions/freetype.git
cd freetype

./install-debian-trixie.sh             # Debian Trixie, Ubuntu 24.04+, Raspberry Pi OS: the php on PATH
./install-macos.sh                     # Homebrew php@8.4 and php@8.4-zts
./install-macos.sh /path/to/bin/php    # the macOS script takes specific PHP binaries
```

### Manually (phpize)

```bash
git clone https://github.com/php-io-extensions/freetype.git
cd freetype
phpize
./configure --enable-freetype
make -j"$(nproc 2>/dev/null || sysctl -n hw.ncpu)"
sudo make install
```

Then enable it: add `extension=freetype.so` to your `php.ini`, or drop that line into a file in the scan directory that `php --ini` reports.

### Verify

`php --ri freetype` also names the FreeType headers it was built against:

```console
$ php --ri freetype

freetype

freetype support => enabled
Version => 0.11.0
FreeType headers => 2.15.0
```

## API

Function, handle, struct, field and constant names are the C names, so [FreeType's API reference](https://freetype.org/freetype2/docs/reference/index.html) is the reference: 13 functions, one stub per group in [`stubs/`](stubs), each declared with its PHP types. [SUPPORT.md](SUPPORT.md) lists every function FreeType 2.13.2 declares in its public headers, bound or not; the API badge is computed from it.

| Stub | Functions | What it covers |
|---|---|---|
| `FT_Face` | 5 | `FT_Init_FreeType()`, `FT_Done_FreeType()`, `FT_New_Face()`, `FT_New_Memory_Face()`, `FT_Done_Face()`; the `FT_Library` and `FT_Face` handles. |
| `FT_Size` | 4 | `FT_Set_Char_Size()`, `FT_Set_Pixel_Sizes()`, `FT_Get_Sfnt_Table()`, `FT_Get_Char_Index()`; `FT_Size`, `FT_Size_Metrics` and the seven SFNT table structs. |
| `FT_Glyph` | 4 | `FT_Load_Glyph()`, `FT_Render_Glyph()`, `FT_Set_Transform()`, `FT_Outline_Embolden()`; `FT_GlyphSlot`, `FT_Outline`, `FT_Glyph_Metrics`, `FT_Vector`, `FT_Matrix`, `FT_Bitmap`. |
| `freetype` | — | The `FT_FACE_FLAG_*`, `FT_STYLE_FLAG_*`, `FT_SFNT_*`, `FT_LOAD_*`, `FT_RENDER_MODE_*` and `FT_PIXEL_MODE_*` constants, with values from the FreeType headers. |

### Translations

Every C parameter is its own PHP parameter, in C order. The only differences from C:

- An out-parameter is a by-reference parameter: `FT_Init_FreeType(?FT_Library &$alibrary): int`. It is `null` when the call fails.
- `const char *` is a `string`. `const FT_Byte *` and its `FT_Long` size stay two parameters: `FT_New_Memory_Face($library, $bytes, strlen($bytes), 0, $face)`.
- FreeType's integer types (`FT_Error`, `FT_UInt`, `FT_Long`, `FT_F26Dot6`, `FT_Fixed`, `FT_Pos`, enums) are `int`. FreeType's error codes are the return values.
- A struct is a `final` class with one typed public property per field, under the field's name, zero by default. A `char` array field is its bytes as a `string`, another array field a list of ints, a pointer field an `int` address. `FT_Bitmap::$buffer` is the bitmap's `rows * abs(pitch)` bytes. `FT_Get_Sfnt_Table()` returns a copy of the table its tag names, or `null`. A struct property that was `unset()` is not read as 0: passing the struct throws PHP's `Error` for an uninitialized typed property.
- `FT_Library`, `FT_Face`, `FT_Size`, `FT_GlyphSlot` and `FT_Outline` are `final` handles with a private constructor, not cloneable or serializable, with `pointer(): int` and `static fromPointer(int $pointer): static`. `fromPointer()` trusts any address. The same native pointer and class in one thread is the same PHP object. A handle's properties read the native record each time PHP reads them, and so do `isset()`, `empty()`, `var_dump()` and `print_r()`.

### Lifetime

Dropping the last PHP reference does not destroy the native object. `FT_Done_Face()` releases the face and the size, glyph slot and outline handles read from it; `FT_Done_FreeType()` releases the library and its faces. A released handle holds NULL, and FreeType answers its own error code when it receives one: `FT_Load_Glyph()` on a released face returns `0x23` (`FT_Err_Invalid_Face_Handle`).

`FT_New_Memory_Face()` hands FreeType a copy of the string that the face owns and frees when its last reference goes, so the face can outlive `FT_Done_Face()` (another reference, such as an hb-ft font), the PHP objects and the request.

### Refusals

The extension refuses two calls, each of which crashes the process otherwise ([`tests/Probes`](tests/Probes) shows each crash on a probe build):

- Reading a property of a handle that holds NULL throws `ValueError` ("FT_Face holds NULL: it was released, or made from address 0"). The property would read the record at address 0.
- `FT_New_Memory_Face()` with a `$file_size` below 0 or larger than the string throws `ValueError`. FreeType would read past the end of the string; a negative size is read as an unsigned one.

## Extensions you might use with this one

* [ext-harfbuzz](https://github.com/php-io-extensions/harfbuzz): text shaping over an ext-freetype `FT_Face`. HarfBuzz decides which glyphs a string becomes and where each goes; FreeType renders them.
* [ext-fontconfig](https://github.com/php-io-extensions/fontconfig): finds the font file for a family, a style, or a character no other font has, to hand to `FT_New_Face()`.
* [ext-fb](https://github.com/php-io-extensions/fb): a pixel store in your display's byte layout, for the coverage bitmaps FreeType renders.

## AI-assisted development

This codebase was built with LLM assistance under human direction. Prompts, reviews, and architectural decisions were owned by a professional software engineer — the model accelerates drafting and exploration; it does not replace judgment on APIs, dependency direction, or what ships.

## Agentic Documentation

This repository carries an [Open Knowledge Format](https://github.com/GoogleCloudPlatform/knowledge-catalog/blob/main/okf/SPEC.md) bundle at [`.okf/`](.okf/): Markdown with YAML frontmatter, readable by you and loadable by a coding agent. It records what the README doesn't: every function, class and constant by stub, how handles keep one PHP object per native pointer and release their children, how record fields and structs are copied, who owns a memory face's bytes, how to build release and probe builds, how to add a binding, and a log of every change that altered behaviour.

Start at [`.okf/index.md`](.okf/index.md). [`AGENTS.md`](AGENTS.md) is the short rule sheet an agent reads before touching the C, the stubs, or packaging; each rule points into the bundle for the reason behind it.

Point your agent at the repo and it has the same context the maintainer has. Point yourself at it when the README's answer is "it does X" and you want "because".

## Resources

* [FreeType API reference](https://freetype.org/freetype2/docs/reference/index.html): the manual for every call this extension binds; this README only adds what PHP changes.
* [FreeType 2.13.2](https://gitlab.freedesktop.org/freetype/freetype/-/tree/VER-2-13-2): the upstream tag the stubs and [SUPPORT.md](SUPPORT.md) are checked against.
* [PIE](https://github.com/php/pie): the PHP Foundation's extension installer.
* [`gen_stub.php`](https://github.com/php/php-src/blob/master/build/gen_stub.php): the php-src stub format. [`stubs/`](stubs) holds the API declarations; each `*_arginfo.h` is generated from its stub.
* [Open Knowledge Format](https://github.com/GoogleCloudPlatform/knowledge-catalog/blob/main/okf/SPEC.md): the spec the [`.okf/`](.okf/) bundle follows.

## Running the test suite

The suite is Pest v4: faces from a file and from memory, sizes, SFNT tables, glyph loading and rendering, transforms, emboldening, handle identity and release, and the coverage script. It runs on Linux and macOS, with Menlo on macOS and DejaVu Sans Mono on Linux (`fonts-dejavu-core`). Build the module, then enable it through an ini scan directory rather than `-d`, so the child processes the tests start load it too:

```bash
git clone https://github.com/php-io-extensions/freetype.git
cd freetype
phpize && ./configure --enable-freetype && make -j"$(nproc 2>/dev/null || sysctl -n hw.ncpu)"
composer install
mkdir -p /tmp/freetype-ini && echo "extension=$PWD/modules/freetype.so" > /tmp/freetype-ini/freetype.ini
PHP_INI_SCAN_DIR=":/tmp/freetype-ini" php -d memory_limit=128M vendor/bin/pest
```

```console
Tests:    5 skipped, 25 passed (85 assertions)
Duration: 0.17s
```

The five skipped tests are in [`tests/Probes`](tests/Probes): they run only against a probe build (`./configure --enable-freetype --enable-freetype-probes`, or `FREETYPE_CONFIGURE=--enable-freetype-probes ./install-macos.sh`), which can turn each refusal off to show the crash it prevents. Never install a probe build for use.

The leading `:` keeps your PHP's own scan directory and adds the second one. If that PHP already loads an installed `freetype.so`, the suite warns `Module "freetype" is already loaded` and tests the installed one instead; copy the scan directory somewhere, replace its freetype ini with the line above, and point `PHP_INI_SCAN_DIR` at the copy without the colon. A module only loads in the PHP whose `phpize` built it: for Homebrew's ZTS build, run `phpize` and pass `--with-php-config` from `/opt/homebrew/opt/php@8.4-zts/bin`. Set `XDEBUG_MODE=off` for any timing you intend to read.

## Contributing

Open an issue first for anything beyond a typo. Pull requests change a stub in `stubs/` and the C under `src/` together, regenerate the `*_arginfo.h` files with gen_stub, regenerate [SUPPORT.md](SUPPORT.md) and the API badge with `php scripts/support.php`, and add a Pest test for the behaviour. A new refusal needs a probe test that shows the crash it prevents. CI must be green on every cell of the matrix, NTS and ZTS alike. Read [`AGENTS.md`](AGENTS.md) for the rules the code follows.

## Security

ext-freetype hands font files, which often come from the network, to FreeType. See [SECURITY.md](SECURITY.md) for what it guards against and how to report a vulnerability.

## License

MIT. See [LICENSE](LICENSE). FreeType is dual-licensed under the FreeType License and GPLv2; it is linked, not shipped.
