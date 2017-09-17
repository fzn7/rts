/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <sstream>
#include <cstring>

#include "ColorMap.h"
#include "Bitmap.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Util.h"
#include "System/Exceptions.h"

std::deque<CColorMap> CColorMap::colorMaps;
std::map<std::string, CColorMap*> CColorMap::colorMapsMap;

CR_BIND(CColorMap,)
CR_REG_METADATA(CColorMap, (
	CR_MEMBER_UN(map),
	CR_MEMBER_UN(xsize),
	CR_MEMBER_UN(nxsize),
	CR_MEMBER_UN(ysize),
	CR_MEMBER_UN(nysize)
))

CColorMap::CColorMap()
	: map(2, SColor(128, 128, 128))
	, xsize(2)
	, nxsize(1)
	, ysize(1)
	, nysize(0)
{
    //stub method
}

CColorMap::CColorMap(const std::vector<float>& vec)
{
    //stub method
}

CColorMap::CColorMap(const std::string& fileName)
{
    //stub method
}


void CColorMap::LoadMap(const unsigned char* buf, int num)
{
    //stub method
}


CColorMap* CColorMap::LoadFromBitmapFile(const std::string& fileName)
{
    //stub method
}

CColorMap* CColorMap::LoadFromFloatVector(const std::vector<float>& vec)
{
    //stub method
}


CColorMap* CColorMap::LoadFromDefString(const std::string& dString)
{
    //stub method
}


void CColorMap::GetColor(unsigned char* color, float pos)
{
    //stub method
}
