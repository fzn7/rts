#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AdvSky.h"

#include "Game/Camera.h"
#include "Map/MapInfo.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/Bitmap.h"
#include "Sim/Misc/GlobalSynced.h"
#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/Matrix44f.h"
#include "System/TimeProfiler.h"
#include "System/myMath.h"

#define Y_PART 10.0
#define X_PART 10.0

#define CLOUD_DETAIL 6
#define CLOUD_MASK (CLOUD_SIZE - 1)

CAdvSky::CAdvSky()
  : skydir1(ZeroVector)
  , skydir2(ZeroVector)
  , cdtex(0)
  , cloudFP(0)
  , drawFlare(false)
  , cloudTexMem(NULL)
  , skyTex(0)
  , skyDot3Tex(0)
  , cloudDot3Tex(0)
  , sunTex(0)
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
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::CreateSkyDomeList()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CAdvSky::~CAdvSky()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CAdvSky::GetCoord(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::CreateClouds()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline void
CAdvSky::UpdatePart(int ast, int aed, int a3cstart, int a4cstart)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::CreateRandMatrix(int** matrix, float mod)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::CreateRandDetailMatrix(unsigned char* matrix, int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::CreateTransformVectors()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::DrawSun()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::UpdateSunFlare()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::InitSun()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::CreateCover(int baseX, int baseY, float* buf) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::CreateDetailTex()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::UpdateSunDir()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::UpdateSkyDir()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::UpdateSkyTexture()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CAdvSky::GetDirFromTexCoord(float x, float y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// should be improved
// only take stuff in yz plane
float
CAdvSky::GetTexCoordFromDir(const float3& dir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::UpdateTexPartDot3(int x, int y, unsigned char (*texp)[4])
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvSky::UpdateTexPart(int x, int y, unsigned char (*texp)[4])
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
