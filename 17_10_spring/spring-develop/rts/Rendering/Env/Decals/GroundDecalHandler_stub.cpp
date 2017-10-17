#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <algorithm>
#include <cctype>

#include "Game/Camera.h"
#include "Game/GameHelper.h"
#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "GroundDecalHandler.h"
#include "Lua/LuaParser.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/UnitDrawer.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Projectiles/ExplosionListener.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/myMath.h"

using std::max;
using std::min;

CONFIG(int, GroundScarAlphaFade).defaultValue(0);

CGroundDecalHandler::CGroundDecalHandler()
  : CEventClient("[CGroundDecalHandler]", 314159, false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CGroundDecalHandler::~CGroundDecalHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::LoadDecalShaders()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::SunChanged()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline void
AddQuadVertices(CVertexArray* va,
                int x,
                float* yv,
                int z,
                const float* uv,
                unsigned char* color)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline void
CGroundDecalHandler::DrawObjectDecal(SolidObjectGroundDecal* decal)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline void
CGroundDecalHandler::DrawGroundScar(CGroundDecalHandler::Scar* scar, bool fade)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::GatherDecalsForType(
  CGroundDecalHandler::SolidObjectDecalType* decalType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::DrawObjectDecals()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::AddScars()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::DrawScars()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::BindTextures()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::KillTextures()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::BindShader(const float3& ambientColor)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::DrawDecals()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::AddDecal(CUnit* unit, const float3& newPos)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::AddExplosion(float3 pos, float damage, float radius)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::LoadScar(const std::string& file,
                              unsigned char* buf,
                              int xoffset,
                              int yoffset)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CGroundDecalHandler::OverlapSize(Scar* s1, Scar* s2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::TestOverlaps(Scar* scar)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::RemoveScar(Scar* scar, bool removeFromScars)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CGroundDecalHandler::GetSolidObjectDecalType(const std::string& name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

SolidObjectGroundDecal::~SolidObjectGroundDecal()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CGroundDecalHandler::Scar::~Scar()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::MoveSolidObject(CSolidObject* object, const float3& pos)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::RemoveSolidObject(CSolidObject* object,
                                       GhostSolidObject* gb)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief immediately remove an object's ground decal, if any (without fade out)
 */
void
CGroundDecalHandler::ForceRemoveSolidObject(CSolidObject* object)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::UnitMoved(const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::GhostDestroyed(GhostSolidObject* gb)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::GhostCreated(CSolidObject* object, GhostSolidObject* gb)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
CGroundDecalHandler::FeatureMoved(const CFeature* feature, const float3& oldpos)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::ExplosionOccurred(const CExplosionParams& event)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::RenderUnitCreated(const CUnit* unit, int cloaked)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
CGroundDecalHandler::RenderUnitDestroyed(const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundDecalHandler::RenderFeatureCreated(const CFeature* feature)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
CGroundDecalHandler::RenderFeatureDestroyed(const CFeature* feature)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// FIXME: Add a RenderUnitLoaded event
void
CGroundDecalHandler::UnitLoaded(const CUnit* unit, const CUnit* transport)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
CGroundDecalHandler::UnitUnloaded(const CUnit* unit, const CUnit* transport)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
