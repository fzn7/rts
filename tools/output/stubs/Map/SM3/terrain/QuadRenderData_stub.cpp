#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Rendering/GL/myGL.h"
#include <assert.h>
#include <cstring>

#include "TerrainBase.h"
#include "TerrainNode.h"
#include "TerrainTexture.h"

namespace terrain {

QuadRenderData::QuadRenderData()
  : normalMap(0)
  , normalMapW(0)
  , normalMapTexWidth(0)
  , vertexSize(0)
  , index(0)
  , used(false)
  , quad(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

uint
QuadRenderData::GetDataSize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

RenderDataManager::RenderDataManager(Heightmap* rhm, QuadMap* rqm)
  : normalDataAllocates(0)
  , renderDataAllocates(0)
  , roothm(rhm)
  , rootQMap(rqm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

QuadRenderData*
RenderDataManager::Allocate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
RenderDataManager::PruneFreeList(int maxFreeRD)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
RenderDataManager::Free(QuadRenderData* rd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
RenderDataManager::UpdateRect(int sx, int sy, int w, int h)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// delete all renderdata that is not used this frame and has maxlod <
// VBufMinDetail
void
RenderDataManager::FreeUnused()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
RenderDataManager::InitializeNode(TQuad* q)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
RenderDataManager::InitializeNodeNormalMap(TQuad* q, int cfgNormalMapLevel)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
};
