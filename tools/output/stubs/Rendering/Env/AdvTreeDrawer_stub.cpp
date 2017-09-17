#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AdvTreeDrawer.h"
#include "AdvTreeGenerator.h"
#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/FBO.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Textures/Bitmap.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/LosHandler.h"
#include "System/Matrix44f.h"

static const float TEX_LEAF_START_Y1 = 0.001f;
static const float TEX_LEAF_END_Y1 = 0.124f;
static const float TEX_LEAF_START_Y2 = 0.126f;
static const float TEX_LEAF_END_Y2 = 0.249f;
static const float TEX_LEAF_START_Y3 = 0.251f;
static const float TEX_LEAF_END_Y3 = 0.374f;
static const float TEX_LEAF_START_Y4 = 0.376f;
static const float TEX_LEAF_END_Y4 = 0.499f;

static const float TEX_LEAF_START_X1 = 0.0f;
static const float TEX_LEAF_END_X1 = 0.125f;
static const float TEX_LEAF_START_X2 = 0.0f;
static const float TEX_LEAF_END_X2 = 0.125f;
static const float TEX_LEAF_START_X3 = 0.0f;
static const float TEX_LEAF_END_X3 = 0.125f;

static const float PART_MAX_TREE_HEIGHT = MAX_TREE_HEIGHT * 0.4f;
static const float HALF_MAX_TREE_HEIGHT = MAX_TREE_HEIGHT * 0.5f;

CAdvTreeDrawer::CAdvTreeDrawer()
  : ITreeDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CAdvTreeDrawer::~CAdvTreeDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeDrawer::LoadTreeShaders()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeDrawer::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline void
SetArrayQ(CVertexArray* va, float t1, float t2, const float3& v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeDrawer::DrawTreeVertexA(CVertexArray* va,
                                float3& ftpos,
                                float dx,
                                float dy)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeDrawer::DrawTreeVertex(CVertexArray* va,
                               const float3& pos,
                               float dx,
                               float dy,
                               bool enlarge)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeDrawer::DrawTreeVertexMid(CVertexArray* va,
                                  const float3& pos,
                                  float dx,
                                  float dy,
                                  bool enlarge)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeDrawer::DrawTreeVertexFar(CVertexArray* va,
                                  const float3& pos,
                                  const float3& swd,
                                  float dx,
                                  float dy,
                                  bool enlarge)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

struct CAdvTreeSquareDrawer : public CReadMap::IQuadDrawer
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeDrawer::Draw(float treeDistance, bool drawReflection)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

struct CAdvTreeSquareShadowPassDrawer : public CReadMap::IQuadDrawer
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeDrawer::DrawShadowPass()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAdvTreeDrawer::AddFallingTree(int treeID,
                               int treeType,
                               const float3& pos,
                               const float3& dir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
