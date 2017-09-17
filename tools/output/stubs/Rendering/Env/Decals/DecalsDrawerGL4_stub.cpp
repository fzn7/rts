#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DecalsDrawerGL4.h"
#include "Game/Camera.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Lua/LuaParser.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Map/SMF/SMFReadMap.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/FBO.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/Textures/QuadtreeAtlasAlloc.h"
#include "Rendering/UnitDrawer.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/TimeProfiler.h"
#include "System/Util.h"
#include "System/myMath.h"

#include <numeric>
#include <unordered_map>

CONFIG(bool, GroundDecalsParallaxMapping).defaultValue(true);

//#define DEBUG_SAVE_ATLAS

#define LOG_SECTION_DECALS_GL4 "DecalsDrawerGL4"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_DECALS_GL4)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_DECALS_GL4

#if !defined(GL_VERSION_4_3) || HEADLESS
CDecalsDrawerGL4::CDecalsDrawerGL4()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#else

static CDecalsDrawerGL4* decalDrawer = nullptr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

struct SGLSLDecal
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CDecalsDrawerGL4::Decal::IsValid() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CDecalsDrawerGL4::Decal::InView() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CDecalsDrawerGL4::Decal::GetRating(bool inview_test) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::Decal::SetOwner(const void* o)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CDecalsDrawerGL4::Decal::GetIdx() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::Decal::Free() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::Decal::Invalidate() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CDecalsDrawerGL4::Decal::InvalidateExtents() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::Decal::SetTexture(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CDecalsDrawerGL4::Decal::GetTexture() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

CDecalsDrawerGL4::CDecalsDrawerGL4()
  : CEventClient("[CDecalsDrawerGL4]", 314159, false)
  , curWorstDecalIdx(-1)
  , curWorstDecalRating(1e6)
  , maxDecals(0)
  , maxDecalGroups(0)
  , useSSBO(false)
  , laggedFrames(0)
  , overlapStage(0)
  , depthTex(0)
  , atlasTex(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CDecalsDrawerGL4::~CDecalsDrawerGL4()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::OnDecalLevelChanged()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void
CDecalsDrawerGL4::DetectMaxDecals()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::LoadShaders()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static STex
LoadTexture(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline void
GetBuildingDecals(std::unordered_map<std::string, STex>& textures)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline void
GetGroundScars(std::unordered_map<std::string, STex>& textures)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline void
GetFallbacks(std::unordered_map<std::string, STex>& textures)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::GenerateAtlasTexture()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::CreateBoundingBoxVBOs()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::CreateStructureVBOs()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::ViewResize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::SunChanged()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

bool
CDecalsDrawerGL4::AnyDecalsInView() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::DrawDecals()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::UpdateDecalsVBO()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::GameFrame(int n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

static inline std::array<float2, 4>
GetEdgePoinsOfDecal(const CDecalsDrawerGL4::Decal& d)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline bool
Overlap(const CDecalsDrawerGL4::SDecalGroup& g1,
        const CDecalsDrawerGL4::SDecalGroup& g2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline bool
Overlap(const CDecalsDrawerGL4::Decal& d1, const CDecalsDrawerGL4::Decal& d2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline bool
Overlap(const CDecalsDrawerGL4::SDecalGroup& g,
        const CDecalsDrawerGL4::Decal& d)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::UpdateBoundingBox(SDecalGroup& g)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CDecalsDrawerGL4::TryToCombineDecalGroups(SDecalGroup& g1, SDecalGroup& g2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CDecalsDrawerGL4::AddDecalToGroup(SDecalGroup& g,
                                  const Decal& d,
                                  const int decalIdx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CDecalsDrawerGL4::FindAndAddToGroup(int decalIdx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::RemoveFromGroup(int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::OptimizeGroups()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
DRAW_DECAL(CVertexArray* va, const CDecalsDrawerGL4::Decal* d)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::UpdateOverlap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::vector<int>
CDecalsDrawerGL4::UpdateOverlap_PreCheck()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::vector<int>
CDecalsDrawerGL4::CandidatesForOverlap() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::UpdateOverlap_Initialize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::UpdateOverlap_GenerateQueries(
  const std::vector<int>& candidatesForOverlap)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::vector<int>
CDecalsDrawerGL4::UpdateOverlap_CheckQueries()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void
CDecalsDrawerGL4::GetWorstRatedDecal(int* idx,
                                     float* rating,
                                     const bool inview_test) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CDecalsDrawerGL4::CreateLuaDecal()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CDecalsDrawerGL4::NewDecal(const Decal& d)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::FreeDecal(int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CDecalsDrawerGL4::Decal&
CDecalsDrawerGL4::GetDecalOwnedBy(const void* owner)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

static inline bool
HasGroundDecalDef(const CSolidObject* object)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline bool
ExplosionInAirLos(const CExplosionParams& event)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::AddExplosion(float3 pos, float damage, float radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::CreateBuildingDecal(const CSolidObject* object)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::DeownBuildingDecal(const CSolidObject* object)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::ForceRemoveSolidObject(CSolidObject* object)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::ExplosionOccurred(const CExplosionParams& event)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::RenderUnitCreated(const CUnit* unit, int cloaked)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CDecalsDrawerGL4::RenderFeatureCreated(const CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CDecalsDrawerGL4::RenderUnitDestroyed(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CDecalsDrawerGL4::RenderFeatureDestroyed(const CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::GhostCreated(CSolidObject* object, GhostSolidObject* gb)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDecalsDrawerGL4::GhostDestroyed(GhostSolidObject* gb)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#endif // !defined(GL_VERSION_4_0) || HEADLESS
