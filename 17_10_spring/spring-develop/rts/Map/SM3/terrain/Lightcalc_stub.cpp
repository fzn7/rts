#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Lightcalc.h"
#include "Map/ReadMap.h"
#include "Map/SM3/Vector3.h"
#include "Rendering/GL/myGL.h"
#include "System/Log/ILog.h"
#include "System/Matrix44f.h"
#include "System/Util.h"
#include "Terrain.h"
#include "TerrainBase.h"
#include "TerrainNode.h"
#include "Textures.h"
#include <cstring>

#include <IL/il.h>
#include <assert.h>

#include "System/Misc/SpringTime.h"

namespace terrain {

using std::min;

void
BlurGrayscaleImage(int w, int h, uchar* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Lightmap::Lightmap(Heightmap* orghm,
                   int level,
                   int shadowLevelDif,
                   LightingInfo* li)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Lightmap::~Lightmap()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Lightmap::CalculateShadows(uchar* dst,
                           int dstw,
                           float lightX,
                           float lightY,
                           float lightH,
                           float* centerhm,
                           int hmw,
                           int hmscale,
                           bool directional)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
