#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FeatureDrawer.h"

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/Env/IGroundDecalDrawer.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/ITreeDrawer.h"
#include "Rendering/Env/IWater.h"
#include "Rendering/FarTextureHandler.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GL/glExtra.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/LuaObjectDrawer.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Textures/3DOTextureHandler.h"
#include "Rendering/Textures/S3OTextureHandler.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/UnitDrawerState.hpp"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Misc/GlobalSynced.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Util.h"
#include "System/myMath.h"

#define DRAW_QUAD_SIZE 32

CONFIG(bool, ShowRezBars).defaultValue(true).headlessValue(false);

CONFIG(float, FeatureDrawDistance)
  .defaultValue(6000.0f)
  .minimumValue(0.0f)
  .description("Maximum distance at which features will be drawn.");

CONFIG(float, FeatureFadeDistance)
  .defaultValue(4500.0f)
  .minimumValue(0.0f)
  .description("Distance at which features will begin to fade from view.");

static bool
SetFeatureDrawAlpha(CFeature* f,
                    const CCamera* cam,
                    float sqFadeDistMin = -1.0f,
                    float sqFadeDistMax = -1.0f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const void
SetFeatureAlphaMatSSP(const CFeature* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
static const void
SetFeatureAlphaMatFFP(const CFeature* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

typedef const void (*SetFeatureAlphaMatFunc)(const CFeature*);

static const SetFeatureAlphaMatFunc setFeatureAlphaMatFuncs[] = {
    SetFeatureAlphaMatSSP,
    SetFeatureAlphaMatFFP,
};

CFeatureDrawer* featureDrawer = nullptr;

/******************************************************************************/

CFeatureDrawer::CFeatureDrawer()
  : CEventClient("[CFeatureDrawer]", 313373, false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CFeatureDrawer::~CFeatureDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::RenderFeatureCreated(const CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::RenderFeatureDestroyed(const CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::FeatureMoved(const CFeature* feature, const float3& oldpos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::UpdateDrawQuad(CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline void
CFeatureDrawer::UpdateDrawPos(CFeature* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::DrawOpaquePass(bool deferredPass, bool, bool)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::DrawOpaqueFeatures(int modelType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFeatureDrawer::CanDrawFeature(const CFeature* feature) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline void
CFeatureDrawer::DrawFeatureModel(const CFeature* feature, bool noLuaCall)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::DrawFeatureNoTrans(const CFeature* feature,
                                   unsigned int preList,
                                   unsigned int postList,
                                   bool /*lodCall*/,
                                   bool noLuaCall)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::DrawFeature(const CFeature* feature,
                            unsigned int preList,
                            unsigned int postList,
                            bool lodCall,
                            bool noLuaCall)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::PushIndividualState(const CFeature* feature, bool deferredPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::PopIndividualState(const CFeature* feature, bool deferredPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::DrawIndividual(const CFeature* feature, bool noLuaCall)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::DrawIndividualNoTrans(const CFeature* feature, bool noLuaCall)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::DrawAlphaPass()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::DrawAlphaFeatures(int modelType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::DrawShadowPass()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

class CFeatureQuadDrawer : public CReadMap::IQuadDrawer
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFeatureDrawer::GetVisibleFeatures(CCamera* cam, int extraSize, bool drawFar)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
