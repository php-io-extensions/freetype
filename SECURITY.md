# Security Policy

## Supported versions

ext-freetype is pre-1.0. No 0.x release receives security fixes or advisories; fixes land in the
next release line. Security support starts with 1.0.

| Version | Security fixes |
|---------|----------------|
| < 1.0   | No             |

## Reporting a vulnerability

Please don't open a public issue for a security problem.

Report it privately through GitHub: the **Report a vulnerability** button on the
[php-io-extensions/freetype](https://github.com/php-io-extensions/freetype) repository's **Security** tab.
If that isn't available, email **info@projectsaturnstudios.com**.

Include what you found, the affected version, your platform, PHP build (NTS or ZTS) and the
FreeType version (`php --ri freetype` shows the headers it was built against), the font file that
triggers it if you can share it, and the smallest PHP script that shows it. Reports are read and
weighed for the release line in development; before 1.0 there is no response-time commitment.

A defect in FreeType itself belongs with the FreeType project. Report it here as well when
ext-freetype should guard against it.

## Security model

ext-freetype binds FreeType one to one: it passes what PHP gives it to FreeType and does not
validate font files, so it is exactly as robust as the FreeType it is linked against. Keep it
patched; the installers link whatever pkg-config finds. Treat a font from the network as untrusted
input to FreeType.

- **Pass-through.** A released handle holds NULL, and FreeType checks NULL itself and answers an
  error code. Those calls reach FreeType unchanged.
- **Refusals.** The extension refuses a call only where FreeType would read memory it should not:
  a property read on a handle that holds NULL, and an `FT_New_Memory_Face()` size that is negative or
  larger than the string. Each refusal is a `ValueError`, and each has a probe test that shows the
  crash without it.
- **Memory faces.** The native face owns its own copy of the font bytes and frees it when the last
  reference to the face goes, so the bytes outlive `FT_Done_Face()` while another library (HarfBuzz)
  still holds the face.
- **Addresses.** `fromPointer()` trusts any address it is given. Never pass it an integer from
  untrusted input.

A report is in scope when ext-freetype itself reads or writes memory it should not, leaks, or
crashes on a call that its README does not document as a pass-through.
