#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cmath>

#include "Game/Camera.h"
#include "GrassDrawer.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/Env/CubeMapHandler.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/FBO.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Textures/Bitmap.h"
#include "Sim/Misc/Wind.h"
#include "System/Color.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"
#include "System/ThreadPool.h"
#include "System/TimeProfiler.h"
#include "System/UnsyncedRNG.h"
#include "System/Util.h"
#include "System/myMath.h"

CONFIG(int, GrassDetail)
  .defaultValue(7)
  .headlessValue(0)
  .minimumValue(0)
  .description(
    "Sets how detailed the engine rendered grass will be on any given map.");

static const float turfSize = 20.0f;               // single turf size
static const float partTurfSize = turfSize * 1.0f; // single turf size
static const int grassSquareSize = 4; // mapsquares per grass square
static const int grassBlockSize = 4;  // grass squares per grass block
static const int blockMapSize = grassSquareSize * grassBlockSize;

static const int gSSsq = SQUARE_SIZE * grassSquareSize;
static const int bMSsq = SQUARE_SIZE * blockMapSize;

static UnsyncedRNG rng;

static float
GetCamDistOfGrassBlock(const int x, const int y, const bool square = false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const bool
GrassSort(const CGrassDrawer::GrassStruct* a,
          const CGrassDrawer::GrassStruct* b)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const bool
GrassSortNear(const CGrassDrawer::InviewNearGrass& a,
              const CGrassDrawer::InviewNearGrass& b)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
/// CGrassBlockDrawer

class CGrassBlockDrawer : public CReadMap::IQuadDrawer
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CGrassDrawer::~CGrassDrawer()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CGrassDrawer::GrassStruct::~GrassStruct()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::ChangeDetail(int detail)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::ConfigNotify(const std::string& key, const std::string& value)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::LoadGrassShaders()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::EnableShader(const GrassShaderProgram type)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

struct STurfParams
{
    //stub method
    //std::cout << __FUNCTION__ << std::endl;
};

void
CGrassDrawer::DrawNear(const std::vector<InviewNearGrass>& inviewGrass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::DrawBillboard(const int x,
                            const int y,
                            const float dist,
                            VA_TYPE_TN* va_tn)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::DrawFarBillboards(const std::vector<GrassStruct*>& inviewFarGrass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::DrawNearBillboards(
  const std::vector<InviewNearGrass>& inviewNearGrass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::DrawShadow()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::SetupGlStateNear()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::ResetGlStateNear()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::SetupGlStateFar()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::ResetGlStateFar()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::CreateGrassDispList(int listNum)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::CreateGrassBladeTex(unsigned char* buf)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::CreateFarTex()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::ResetPos(const int grassBlockX, const int grassBlockZ)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::ResetPos(const float3& pos)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::AddGrass(const float3& pos)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::RemoveGrass(const float3& pos)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGrassDrawer::UnsyncedHeightMapUpdate(const SRectangle& rect)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
