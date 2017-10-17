#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "BasicWater.h"
#include "ISky.h"

#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/Textures/Bitmap.h"
#include "System/Log/ILog.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBasicWater::CBasicWater()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CBasicWater::~CBasicWater()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
CBasicWater::GenWaterQuadsList(unsigned int textureWidth,
                               unsigned int textureHeight) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicWater::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
