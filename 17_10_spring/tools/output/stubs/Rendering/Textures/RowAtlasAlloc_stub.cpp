#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "RowAtlasAlloc.h"
#include "System/bitops.h"

#include <algorithm>
#include <vector>

// texture spacing in the atlas (in pixels)
static const int ATLAS_PADDING = 1;

CRowAtlasAlloc::CRowAtlasAlloc()
  : nextRowPos(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline int
CRowAtlasAlloc::CompareTex(SAtlasEntry* tex1, SAtlasEntry* tex2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CRowAtlasAlloc::EstimateNeededSize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CRowAtlasAlloc::Row*
CRowAtlasAlloc::AddRow(int glyphWidth, int glyphHeight)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CRowAtlasAlloc::Allocate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CRowAtlasAlloc::Row*
CRowAtlasAlloc::FindRow(int glyphWidth, int glyphHeight)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
