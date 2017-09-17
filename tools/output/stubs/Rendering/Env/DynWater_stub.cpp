/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "DynWater.h"
#include "Game/Camera.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
// #include "Game/UI/MouseHandler.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/Bitmap.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "System/Log/ILog.h"
#include "System/bitops.h"
#include "System/Exceptions.h"

#define LOG_SECTION_DYN_WATER "DynWater"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_DYN_WATER)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
	#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_DYN_WATER


#define W_SIZE 5
#define WF_SIZE 5120
#define WH_SIZE 2560
/*
#define W_SIZE 4
#define WF_SIZE 4096
#define WH_SIZE 2048
*/
CDynWater::CDynWater()
	: camPosX(0)
	, camPosZ(0)
{
    //stub method
}

CDynWater::~CDynWater()
{
    //stub method
}

void CDynWater::Draw()
{
    //stub method
}

void CDynWater::UpdateWater(CGame* game)
{
    //stub method
}

void CDynWater::Update()
{
    //stub method
}

void CDynWater::DrawReflection(CGame* game)
{
    //stub method
}

void CDynWater::DrawRefraction(CGame* game)
{
    //stub method
}

void CDynWater::DrawWaves()
{
    //stub method
}

void CDynWater::DrawHeightTex()
{
    //stub method
}


// ((40*2*2)*(2<<5))>>1 == WF_SIZE
#define LOD_SIZE_FACT (40*2*2)
#define WSQUARE_SIZE W_SIZE

static CVertexArray* va;

static inline void DrawVertexAQ(int x, int y)
{
    //stub method
}

void CDynWater::DrawWaterSurface()
{
    //stub method
}

void CDynWater::DrawDetailNormalTex()
{
    //stub method
}

void CDynWater::AddShipWakes()
{
    //stub method
}

void CDynWater::AddExplosions()
{
    //stub method
}

void CDynWater::AddExplosion(const float3& pos, float strength, float size)
{
    //stub method
}

void CDynWater::DrawUpdateSquare(float dx, float dy, int* resetTexs)
{
    //stub method
}

void CDynWater::DrawSingleUpdateSquare(float startx, float starty, float endx, float endy)
{
    //stub method
}

void CDynWater::DrawOuterSurface()
{
    //stub method
}

