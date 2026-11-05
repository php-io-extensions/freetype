<?php

/** @generate-class-entries */

/**
 * An FT_Size. Its face owns it: FT_Done_Face releases it. fromPointer() trusts any address other than 0.
 * metrics reads FT_SizeRec.metrics each time PHP reads it, as a fresh FT_Size_Metrics.
 */
final class FT_Size
{
    public readonly FT_Size_Metrics $metrics;

    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

final class FT_Size_Metrics
{
    public int $x_ppem = 0;
    public int $y_ppem = 0;
    public int $x_scale = 0;
    public int $y_scale = 0;
    public int $ascender = 0;
    public int $descender = 0;
    public int $height = 0;
    public int $max_advance = 0;
}

/** Created and Modified are FT_ULong[2]: lists of two ints. */
final class TT_Header
{
    public int $Table_Version = 0;
    public int $Font_Revision = 0;
    public int $CheckSum_Adjust = 0;
    public int $Magic_Number = 0;
    public int $Flags = 0;
    public int $Units_Per_EM = 0;
    public array $Created = [];
    public array $Modified = [];
    public int $xMin = 0;
    public int $yMin = 0;
    public int $xMax = 0;
    public int $yMax = 0;
    public int $Mac_Style = 0;
    public int $Lowest_Rec_PPEM = 0;
    public int $Font_Direction = 0;
    public int $Index_To_Loc_Format = 0;
    public int $Glyph_Data_Format = 0;
}

/** Reserved is FT_Short[4]: a list of four ints. long_metrics and short_metrics are addresses. */
final class TT_HoriHeader
{
    public int $Version = 0;
    public int $Ascender = 0;
    public int $Descender = 0;
    public int $Line_Gap = 0;
    public int $advance_Width_Max = 0;
    public int $min_Left_Side_Bearing = 0;
    public int $min_Right_Side_Bearing = 0;
    public int $xMax_Extent = 0;
    public int $caret_Slope_Rise = 0;
    public int $caret_Slope_Run = 0;
    public int $caret_Offset = 0;
    public array $Reserved = [];
    public int $metric_Data_Format = 0;
    public int $number_Of_HMetrics = 0;
    public int $long_metrics = 0;
    public int $short_metrics = 0;
}

/** Reserved is FT_Short[4]: a list of four ints. long_metrics and short_metrics are addresses. */
final class TT_VertHeader
{
    public int $Version = 0;
    public int $Ascender = 0;
    public int $Descender = 0;
    public int $Line_Gap = 0;
    public int $advance_Height_Max = 0;
    public int $min_Top_Side_Bearing = 0;
    public int $min_Bottom_Side_Bearing = 0;
    public int $yMax_Extent = 0;
    public int $caret_Slope_Rise = 0;
    public int $caret_Slope_Run = 0;
    public int $caret_Offset = 0;
    public array $Reserved = [];
    public int $metric_Data_Format = 0;
    public int $number_Of_VMetrics = 0;
    public int $long_metrics = 0;
    public int $short_metrics = 0;
}

/** panose is FT_Byte[10]: a list of ten ints. achVendID is FT_Char[4]: its four bytes. */
final class TT_OS2
{
    public int $version = 0;
    public int $xAvgCharWidth = 0;
    public int $usWeightClass = 0;
    public int $usWidthClass = 0;
    public int $fsType = 0;
    public int $ySubscriptXSize = 0;
    public int $ySubscriptYSize = 0;
    public int $ySubscriptXOffset = 0;
    public int $ySubscriptYOffset = 0;
    public int $ySuperscriptXSize = 0;
    public int $ySuperscriptYSize = 0;
    public int $ySuperscriptXOffset = 0;
    public int $ySuperscriptYOffset = 0;
    public int $yStrikeoutSize = 0;
    public int $yStrikeoutPosition = 0;
    public int $sFamilyClass = 0;
    public array $panose = [];
    public int $ulUnicodeRange1 = 0;
    public int $ulUnicodeRange2 = 0;
    public int $ulUnicodeRange3 = 0;
    public int $ulUnicodeRange4 = 0;
    public string $achVendID = '';
    public int $fsSelection = 0;
    public int $usFirstCharIndex = 0;
    public int $usLastCharIndex = 0;
    public int $sTypoAscender = 0;
    public int $sTypoDescender = 0;
    public int $sTypoLineGap = 0;
    public int $usWinAscent = 0;
    public int $usWinDescent = 0;
    public int $ulCodePageRange1 = 0;
    public int $ulCodePageRange2 = 0;
    public int $sxHeight = 0;
    public int $sCapHeight = 0;
    public int $usDefaultChar = 0;
    public int $usBreakChar = 0;
    public int $usMaxContext = 0;
    public int $usLowerOpticalPointSize = 0;
    public int $usUpperOpticalPointSize = 0;
}

final class TT_Postscript
{
    public int $FormatType = 0;
    public int $italicAngle = 0;
    public int $underlinePosition = 0;
    public int $underlineThickness = 0;
    public int $isFixedPitch = 0;
    public int $minMemType42 = 0;
    public int $maxMemType42 = 0;
    public int $minMemType1 = 0;
    public int $maxMemType1 = 0;
}

/** TypeFace, CharacterComplement and FileName are FT_Char[16], [8] and [6]: their bytes. */
final class TT_PCLT
{
    public int $Version = 0;
    public int $FontNumber = 0;
    public int $Pitch = 0;
    public int $xHeight = 0;
    public int $Style = 0;
    public int $TypeFamily = 0;
    public int $CapHeight = 0;
    public int $SymbolSet = 0;
    public string $TypeFace = '';
    public string $CharacterComplement = '';
    public string $FileName = '';
    public int $StrokeWeight = 0;
    public int $WidthType = 0;
    public int $SerifStyle = 0;
    public int $Reserved = 0;
}

final class TT_MaxProfile
{
    public int $version = 0;
    public int $numGlyphs = 0;
    public int $maxPoints = 0;
    public int $maxContours = 0;
    public int $maxCompositePoints = 0;
    public int $maxCompositeContours = 0;
    public int $maxZones = 0;
    public int $maxTwilightPoints = 0;
    public int $maxStorage = 0;
    public int $maxFunctionDefs = 0;
    public int $maxInstructionDefs = 0;
    public int $maxStackElements = 0;
    public int $maxSizeOfInstructions = 0;
    public int $maxComponentElements = 0;
    public int $maxComponentDepth = 0;
}

function FT_Set_Char_Size(FT_Face $face, int $char_width, int $char_height, int $horz_resolution, int $vert_resolution): int {}

function FT_Set_Pixel_Sizes(FT_Face $face, int $pixel_width, int $pixel_height): int {}

/** A copy of the table $tag names, or null when the face has none. */
function FT_Get_Sfnt_Table(FT_Face $face, int $tag): TT_Header|TT_HoriHeader|TT_VertHeader|TT_OS2|TT_Postscript|TT_PCLT|TT_MaxProfile|null {}

function FT_Get_Char_Index(FT_Face $face, int $charcode): int {}
