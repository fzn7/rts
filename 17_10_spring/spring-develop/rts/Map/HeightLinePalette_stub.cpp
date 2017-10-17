#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "HeightLinePalette.h"
#include "System/Config/ConfigHandler.h"

CONFIG(bool, ColorElev)
  .defaultValue(true)
  .description("If heightmap (default hotkey [F1]) should be colored or not.");

static std::array<SColor, 256>
CreateColored()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static std::array<SColor, 256>
CreateBW()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::array<SColor, 256> CHeightLinePalette::paletteColored = CreateColored();
std::array<SColor, 256> CHeightLinePalette::paletteBlackAndWhite = CreateBW();

const SColor*
CHeightLinePalette::GetData()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
