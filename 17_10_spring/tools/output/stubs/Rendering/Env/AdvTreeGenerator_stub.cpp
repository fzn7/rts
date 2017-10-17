#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cstring>
#include <vector>

#include "AdvTreeGenerator.h"

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Lua/LuaParser.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/FBO.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Textures/Bitmap.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"

using std::max;
using std::min;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdvTreeGenerator* treeGen;

CAdvTreeGenerator::CAdvTreeGenerator()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CAdvTreeGenerator::~CAdvTreeGenerator()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeGenerator::Draw() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeGenerator::MainTrunk(int numBranch, float height, float width)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeGenerator::TrunkIterator(const float3& start,
                                 const float3& dir,
                                 float length,
                                 float size,
                                 int depth)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeGenerator::CreateLeaves(const float3& start,
                                const float3& dir,
                                float length,
                                float3& orto1,
                                float3& orto2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeGenerator::CreateFarTex(Shader::IProgramObject* treeShader)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeGenerator::CreateFarView(unsigned char* mem,
                                 int dx,
                                 int dy,
                                 unsigned int displist)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeGenerator::CreateGranTex(unsigned char* data,
                                 int xpos,
                                 int ypos,
                                 int xsize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeGenerator::CreateGranTexBranch(const float3& start, const float3& end)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeGenerator::PineTree(int numBranch, float height)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeGenerator::DrawPineTrunk(const float3& start,
                                 const float3& end,
                                 float size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeGenerator::DrawPineBranch(const float3& start,
                                  const float3& dir,
                                  float size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeGenerator::CreateLeafTex(unsigned int baseTex,
                                 int xpos,
                                 int ypos,
                                 unsigned char buf[256][2048][4])
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
