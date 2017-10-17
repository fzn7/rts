#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifdef _MSC_VER
#pragma warning(disable : 4258)
#endif

#include <assert.h>

#include "BasicSky.h"

#include "Game/Camera.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/Bitmap.h"
#include "System/Config/ConfigHandler.h"
#include "System/Matrix44f.h"
#include "System/TimeProfiler.h"
#include "System/myMath.h"

CONFIG(bool, DynamicSky)
  .defaultValue(false)
  .description("Sets whether the clouds in the sky will be procedurally "
               "generated and moved. Resource heavy!");

//////////////////////////////////////////////////////////////////////
// Construction/Destruction

//////////////////////////////////////////////////////////////////////

#define Y_PART 10.0
#define X_PART 10.0

#define CLOUD_DETAIL 6
#define CLOUD_MASK (CLOUD_SIZE - 1)

CBasicSky::CBasicSky()
  : skydir1(ZeroVector)
  , skydir2(ZeroVector)
  , skyTex(0)
  , skyDot3Tex(0)
  , cloudDot3Tex(0)
  , sunFlareTex(0)
  , skyTexUpdateIter(0)
  , skyDomeList(0)
  , sunFlareList(0)
  , skyAngle(0.0f)
  , domeheight(0.0f)
  , domeWidth(0.0f)
  , sunTexCoordX(0.0f)
  , sunTexCoordY(0.0f)
  , randMatrix(NULL)
  , rawClouds(NULL)
  , blendMatrix(NULL)
  , cloudThickness(NULL)
  , oldCoverBaseX(-5)
  , oldCoverBaseY(0)
  , updatecounter(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::CreateSkyDomeList()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CBasicSky::~CBasicSky()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CBasicSky::GetCoord(int x, int y)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::CreateClouds()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::UpdatePart(int ast, int aed, int a3cstart, int a4cstart)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::CreateRandMatrix(int** matrix, float mod)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::CreateTransformVectors()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::DrawSun()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::UpdateSunFlare()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::InitSun()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline unsigned char
CBasicSky::GetCloudThickness(int x, int y)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::CreateCover(int baseX, int baseY, float* buf)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::UpdateSunDir()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::UpdateSkyDir()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::UpdateSkyTexture()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CBasicSky::GetDirFromTexCoord(float x, float y)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// should be improved
// only take stuff in yz plane
float
CBasicSky::GetTexCoordFromDir(const float3& dir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::UpdateTexPartDot3(int x, int y, unsigned char (*texp)[4])
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBasicSky::UpdateTexPart(int x, int y, unsigned char (*texp)[4])
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
