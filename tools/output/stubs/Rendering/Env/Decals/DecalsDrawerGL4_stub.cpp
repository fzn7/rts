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
#include "Rendering/GlobalRendering.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/FBO.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/Textures/QuadtreeAtlasAlloc.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Weapons/WeaponDef.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include "System/TimeProfiler.h"
#include "System/Util.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"

#include <unordered_map>
#include <numeric>


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
}
#else


static CDecalsDrawerGL4* decalDrawer = nullptr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

struct SGLSLDecal {
	alignas(16) float3 pos;
		    float  alpha;
	alignas(16) float2 size;
		    float2 rotMatElements;
	alignas(16) float4 texOffsets;
	alignas(16) float4 texNormalOffsets;
};

struct SGLSLGroundLighting {
	alignas(16) float3 ambientColor;
	alignas(16) float3 diffuseColor;
	alignas(16) float3 specularColor;
	alignas(16) float3 dir;
	alignas(16) float3 fogColor;
	float fogEnd;
	float fogScale;
	float3 unused;
};


struct STex {
	GLuint id;
	int2 size;
};

typedef float4 SAtlasTex;
static std::unordered_map<std::string, SAtlasTex> atlasTexs;


static std::string GetExtraTextureName(const std::string& s)
{
    //stub method
}


bool CDecalsDrawerGL4::Decal::IsValid() const
{
    //stub method
}


bool CDecalsDrawerGL4::Decal::InView() const
{
    //stub method
}


float CDecalsDrawerGL4::Decal::GetRating(bool inview_test) const
{
    //stub method
}


void CDecalsDrawerGL4::Decal::SetOwner(const void* o)
{
    //stub method
}


int CDecalsDrawerGL4::Decal::GetIdx() const
{
    //stub method
}


void CDecalsDrawerGL4::Decal::Free() const
{
    //stub method
}


void CDecalsDrawerGL4::Decal::Invalidate() const
{
    //stub method
}


bool CDecalsDrawerGL4::Decal::InvalidateExtents() const
{
    //stub method
}


void CDecalsDrawerGL4::Decal::SetTexture(const std::string& name)
{
    //stub method
}


std::string CDecalsDrawerGL4::Decal::GetTexture() const
{
    //stub method
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
}


CDecalsDrawerGL4::~CDecalsDrawerGL4()
{
    //stub method
}


void CDecalsDrawerGL4::OnDecalLevelChanged()
{
    //stub method
}










//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void CDecalsDrawerGL4::DetectMaxDecals()
{
    //stub method
}


void CDecalsDrawerGL4::LoadShaders()
{
    //stub method
}


static STex LoadTexture(const std::string& name)
{
    //stub method
}


static inline void GetBuildingDecals(std::unordered_map<std::string, STex>& textures)
{
    //stub method
}


static inline void GetGroundScars(std::unordered_map<std::string, STex>& textures)
{
    //stub method
}


static inline void GetFallbacks(std::unordered_map<std::string, STex>& textures)
{
    //stub method
}


void CDecalsDrawerGL4::GenerateAtlasTexture()
{
    //stub method
}


void CDecalsDrawerGL4::CreateBoundingBoxVBOs()
{
    //stub method
}


void CDecalsDrawerGL4::CreateStructureVBOs()
{
    //stub method
}


void CDecalsDrawerGL4::ViewResize()
{
    //stub method
}


void CDecalsDrawerGL4::SunChanged()
{
    //stub method
}










//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CDecalsDrawerGL4::AnyDecalsInView() const
{
    //stub method
}


void CDecalsDrawerGL4::Draw()
{
    //stub method
}


void CDecalsDrawerGL4::DrawDecals()
{
    //stub method
}


void CDecalsDrawerGL4::UpdateDecalsVBO()
{
    //stub method
}


void CDecalsDrawerGL4::Update()
{
    //stub method
}


void CDecalsDrawerGL4::GameFrame(int n)
{
    //stub method
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

static inline std::array<float2, 4> GetEdgePoinsOfDecal(const CDecalsDrawerGL4::Decal& d)
{
    //stub method
}


static inline bool Overlap(const CDecalsDrawerGL4::SDecalGroup& g1, const CDecalsDrawerGL4::SDecalGroup& g2)
{
    //stub method
}


static inline bool Overlap(const CDecalsDrawerGL4::Decal& d1, const CDecalsDrawerGL4::Decal& d2)
{
    //stub method
}

static inline bool Overlap(const CDecalsDrawerGL4::SDecalGroup& g, const CDecalsDrawerGL4::Decal& d)
{
    //stub method
}


void CDecalsDrawerGL4::UpdateBoundingBox(SDecalGroup& g)
{
    //stub method
}


bool CDecalsDrawerGL4::TryToCombineDecalGroups(SDecalGroup& g1, SDecalGroup& g2)
{
    //stub method
}


bool CDecalsDrawerGL4::AddDecalToGroup(SDecalGroup& g, const Decal& d, const int decalIdx)
{
    //stub method
}


bool CDecalsDrawerGL4::FindAndAddToGroup(int decalIdx)
{
    //stub method
}


void CDecalsDrawerGL4::RemoveFromGroup(int idx)
{
    //stub method
}


void CDecalsDrawerGL4::OptimizeGroups()
{
    //stub method
}


static void DRAW_DECAL(CVertexArray* va, const CDecalsDrawerGL4::Decal* d)
{
    //stub method
}


void CDecalsDrawerGL4::UpdateOverlap()
{
    //stub method
}


std::vector<int> CDecalsDrawerGL4::UpdateOverlap_PreCheck()
{
    //stub method
}


std::vector<int> CDecalsDrawerGL4::CandidatesForOverlap() const
{
    //stub method
}


void CDecalsDrawerGL4::UpdateOverlap_Initialize()
{
    //stub method
}


void CDecalsDrawerGL4::UpdateOverlap_GenerateQueries(const std::vector<int>& candidatesForOverlap)
{
    //stub method
}


std::vector<int> CDecalsDrawerGL4::UpdateOverlap_CheckQueries()
{
    //stub method
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void CDecalsDrawerGL4::GetWorstRatedDecal(int* idx, float* rating, const bool inview_test) const
{
    //stub method
}


int CDecalsDrawerGL4::CreateLuaDecal()
{
    //stub method
}


int CDecalsDrawerGL4::NewDecal(const Decal& d)
{
    //stub method
}


void CDecalsDrawerGL4::FreeDecal(int idx)
{
    //stub method
}


CDecalsDrawerGL4::Decal& CDecalsDrawerGL4::GetDecalOwnedBy(const void* owner)
{
    //stub method
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

static inline bool HasGroundDecalDef(const CSolidObject* object)
{
    //stub method
}


static inline bool ExplosionInAirLos(const CExplosionParams& event)
{
    //stub method
}


void CDecalsDrawerGL4::AddExplosion(float3 pos, float damage, float radius)
{
    //stub method
}


void CDecalsDrawerGL4::CreateBuildingDecal(const CSolidObject* object)
{
    //stub method
}


void CDecalsDrawerGL4::DeownBuildingDecal(const CSolidObject* object)
{
    //stub method
}


void CDecalsDrawerGL4::ForceRemoveSolidObject(CSolidObject* object)
{
    //stub method
}



void CDecalsDrawerGL4::ExplosionOccurred(const CExplosionParams& event) {
	if ((event.weaponDef != nullptr) && !event.weaponDef->visuals.explosionScar)
		return;

	if (!ExplosionInAirLos(event))
		return;

	AddExplosion(event.pos, event.damages.GetDefault(), event.craterAreaOfEffect);
}

void CDecalsDrawerGL4::RenderUnitCreated(const CUnit* unit, int cloaked) { CreateBuildingDecal(unit); }
void CDecalsDrawerGL4::RenderFeatureCreated(const CFeature* feature)     { CreateBuildingDecal(feature); }
void CDecalsDrawerGL4::RenderUnitDestroyed(const CUnit* unit)          { DeownBuildingDecal(unit); }
void CDecalsDrawerGL4::RenderFeatureDestroyed(const CFeature* feature) { DeownBuildingDecal(feature); }


void CDecalsDrawerGL4::GhostCreated(CSolidObject* object, GhostSolidObject* gb)
{
    //stub method
}

void CDecalsDrawerGL4::GhostDestroyed(GhostSolidObject* gb)
{
    //stub method
}





#endif // !defined(GL_VERSION_4_0) || HEADLESS
