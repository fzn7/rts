#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/TdfParser.h"

#include "Terrain.h"
#include "TerrainBase.h"
#include "TerrainTexture.h"

#include "Lightcalc.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "TerrainTexEnvCombine.h"
#include "TerrainTextureGLSL.h"

#include <algorithm>
#include <cassert>
#include <deque>
#include <map>
#include <vector>

#include <SDL_keysym.h>

namespace terrain {

//-----------------------------------------------------------------------
// RenderSetup
//-----------------------------------------------------------------------

RenderSetup::~RenderSetup()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
RenderSetup::Clear()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
RenderSetup::DebugOutput()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

//-----------------------------------------------------------------------
// RenderSetupCollection
//-----------------------------------------------------------------------

RenderSetupCollection::~RenderSetupCollection()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

//-----------------------------------------------------------------------
// Terrain Texturing class
//-----------------------------------------------------------------------

TerrainTexture::TerrainTexture()
  : debugShader(-1)
  , heightmapW(0)
  , blendmapLOD(0)
  , useBumpMaps(false)
  , optimizeEpsilon(0.0f)
  , currentRenderSetup(NULL)
  , shaderHandler(NULL)
  , maxPasses(0)
  , tdfParser(NULL)
  , lightmap(NULL)
  , flatBumpmap(NULL)
  , shadowMapParams(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

struct TerrainTexture::GenerateInfo
{
    //stub method
    //std::cout << __FUNCTION__ << std::endl;
};

void
TerrainTexture::Load(const TdfParser* tdf,
                     Heightmap* heightmap,
                     TQuad* quadtree,
                     const std::vector<QuadMap*>& qmaps,
                     Config* cfg,
                     ILoadCallback* cb,
                     LightingInfo* li)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TerrainTexture::ReloadShaders(TQuad* quadtree, Config* cfg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TerrainTexture::ReloadTexProg(TQuad* node, TerrainTexture::GenerateInfo* gi)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TerrainTexture::CreateTexProg(TQuad* node, TerrainTexture::GenerateInfo* gi)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

uint
TerrainTexture::CalcBlendmapSortKey()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TerrainTexture::InstantiateShaders(Config* cfg, ILoadCallback* cb)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
TerrainTexture::SetupNode(TQuad* q, int pass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
TerrainTexture::SetupShading(RenderPass* p, int passIndex)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TerrainTexture::EndTexturing()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
TerrainTexture::BeginTexturing()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
TerrainTexture::NumPasses() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TerrainTexture::EndPass()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
TerrainTexture::BeginPass(int p)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TerrainTexture::SetShaderParams(const Vector3& lightDir, const Vector3& eyePos)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TerrainTexture::SetShadowMapParams(const ShadowMapParams* smp)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TerrainTexture::DebugEvent(const std::string& event)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#ifndef TERRAINRENDERERLIB_EXPORTS
void
TerrainTexture::DebugPrint(IFontRenderer* fontRenderer)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
#endif

void
ShaderDef::LoadStages(int numStages,
                      const char* stagename,
                      const TdfParser& tdf,
                      std::vector<ShaderDef::Stage>& stages)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ShaderDef::Parse(const TdfParser& tdf, bool needNormalMap)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ShaderDef::Optimize(ShaderDef* dst)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ShaderDef::OptimizeStages(std::vector<Stage>& src, std::vector<Stage>& dst)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ShaderDef::Output()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
};
