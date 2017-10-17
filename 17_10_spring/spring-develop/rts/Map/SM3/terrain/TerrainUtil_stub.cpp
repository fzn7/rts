#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "TerrainBase.h"
#include "TerrainNode.h"
#include "TerrainTexture.h"
#include "TerrainVertexBuffer.h"

#include "Rendering/Textures/Bitmap.h"

#include <cassert>

namespace terrain {

//-----------------------------------------------------------------------
// Heightmap class
//-----------------------------------------------------------------------

Heightmap::Heightmap()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
Heightmap::~Heightmap()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Heightmap::Alloc(int W, int H)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Heightmap::LodScaleDown(Heightmap* dst)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Heightmap*
Heightmap::CreateLowDetailHM()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Heightmap::FindMinMax(int2 st,
                      int2 size,
                      float& minHgt,
                      float& maxHgt,
                      bool synced)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// level > 0 returns a high detail HM
// level < 0 returns a lower detail HM
const Heightmap*
Heightmap::GetLevel(int level)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Heightmap::GenerateNormals()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Heightmap::UpdateLowerUnsynced(int sx, int sy, int w, int h)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

//-----------------------------------------------------------------------
// Index calculater
//-----------------------------------------------------------------------

IndexTable::IndexTable()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#define TRI(a, b, c)                                                           \
    {                                                                          \
        *(i++) = (a);                                                          \
        *(i++) = b;                                                            \
        *(i++) = c;                                                            \
    }
#define VRT(x, y) ((y)*VERTC + (x))

void
IndexTable::Calculate(int sides)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#undef VRT
#undef TRI

void
SetTexGen(float scale)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

//-----------------------------------------------------------------------
// AlphaImage
//-----------------------------------------------------------------------
AlphaImage::AlphaImage()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
AlphaImage::~AlphaImage()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AlphaImage::Alloc(int W, int H)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
AlphaImage::CopyFromBitmap(CBitmap& bm)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

AlphaImage*
AlphaImage::CreateMipmap()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// NO CLIPPING!
void
AlphaImage::Blit(AlphaImage* dst,
                 int srcx,
                 int srcy,
                 int dstx,
                 int dsty,
                 int w,
                 int h)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
AlphaImage::Save(const char* fn)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

AlphaImage::AreaTestResult
AlphaImage::TestArea(int xstart, int ystart, int xend, int yend, float epsilon)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
TextureUsage::AddTextureCoordRead(int maxCoords, BaseTexture* texture)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
TextureUsage::AddTextureRead(int maxUnits, BaseTexture* texture)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
};
