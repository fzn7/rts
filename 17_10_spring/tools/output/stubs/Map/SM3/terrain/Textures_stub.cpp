#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/TdfParser.h"

#include <cassert>
#include <cstring>
#include <deque>

#include "Map/SM3/Plane.h"
#include "Rendering/Textures/Bitmap.h"
#include "System/FileSystem/FileSystem.h"
#include "System/float3.h"
#include "TerrainBase.h"
#include "TerrainNode.h"
#include "Textures.h"
#if defined(TERRAIN_USE_IL)
#include <IL/il.h>
#endif // defined(TERRAIN_USE_IL)

namespace terrain {

void
SetTexCoordGen(float* tgv)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//-----------------------------------------------------------------------
// Texturing objects
//-----------------------------------------------------------------------

BaseTexture::BaseTexture()
  : id(0)
  , tilesize(10.0f, 10.0f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
BaseTexture::CalcTexGenVector(float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
BaseTexture::SetupTexGen()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

TiledTexture::TiledTexture() {}

TiledTexture::~TiledTexture() {}

void
TiledTexture::Load(const std::string& name,
                   const std::string& section,
                   ILoadCallback* cb,
                   const TdfParser* tdf,
                   bool isBumpmap)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

TiledTexture*
TiledTexture::CreateFlatBumpmap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Blendmap::Blendmap()
  : generatorInfo(NULL)
  , image(NULL)
  , curAreaResult(AlphaImage::AREA_ONE)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Blendmap::Load(const std::string& name,
               const std::string& section,
               Heightmap* heightmap,
               ILoadCallback* cb,
               const TdfParser* tdf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
BlendmapFilter(AlphaImage* img)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Blendmap::Generate(Heightmap* rootHm,
                   int lodLevel,
                   float hmScale,
                   float hmOffset)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
DetailBumpmap::CalcTexGenVector(float* v4)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

DetailBumpmap::~DetailBumpmap() {}

// Util functions

GLuint
GenSphereBumpmap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

GLuint
LoadTexture(const std::string& fn, bool isBumpmap)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SaveImage(const char* fn, int components, GLenum type, int w, int h, void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
