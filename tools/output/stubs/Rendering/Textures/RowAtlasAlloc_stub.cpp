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
}


inline int CRowAtlasAlloc::CompareTex(SAtlasEntry* tex1, SAtlasEntry* tex2)
{
    //stub method
}


void CRowAtlasAlloc::EstimateNeededSize()
{
    //stub method
}


CRowAtlasAlloc::Row* CRowAtlasAlloc::AddRow(int glyphWidth, int glyphHeight)
{
    //stub method
}


bool CRowAtlasAlloc::Allocate()
{
    //stub method
}


CRowAtlasAlloc::Row* CRowAtlasAlloc::FindRow(int glyphWidth, int glyphHeight)
{
    //stub method
}
