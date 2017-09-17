#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "BasicTreeDrawer.h"
#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Lua/LuaParser.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/Bitmap.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureHandler.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

static const float MAX_TREE_HEIGHT_25 = MAX_TREE_HEIGHT * 0.25f;
static const float MAX_TREE_HEIGHT_3 = MAX_TREE_HEIGHT * 0.3f;
static const float MAX_TREE_HEIGHT_36 = MAX_TREE_HEIGHT * 0.36f;
static const float MAX_TREE_HEIGHT_6 = MAX_TREE_HEIGHT * 0.6f;

CBasicTreeDrawer::CBasicTreeDrawer()
  : ITreeDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CBasicTreeDrawer::~CBasicTreeDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void inline SetArrayQ(CVertexArray* va, float t1, float t2, float3 v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

struct CBasicTreeSquareDrawer : public CReadMap::IQuadDrawer
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
