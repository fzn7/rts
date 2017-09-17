/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <algorithm>

#include "Projectile.h"
#include "ProjectileHandler.h"
#include "Game/GlobalUnsynced.h"
#include "Game/TraceRay.h"
#include "Map/Ground.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/GroundFlash.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Misc/CollisionHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Rendering/Env/Particles/Classes/FlyingPiece.h"
#include "Rendering/Env/Particles/Classes/NanoProjectile.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectile.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Weapons/WeaponDef.h"
#include "Sim/Weapons/PlasmaRepulser.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/TimeProfiler.h"
#include "System/creg/STL_Deque.h"


// reserve 5% of maxNanoParticles for important stuff such as capture and reclaim other teams' units
#define NORMAL_NANO_PRIO 0.95f
#define HIGH_NANO_PRIO 1.0f


using namespace std;

CONFIG(int, MaxParticles).defaultValue(3000).headlessValue(1).minimumValue(1);
CONFIG(int, MaxNanoParticles).defaultValue(2000).headlessValue(1).minimumValue(1);

CProjectileHandler* projectileHandler = NULL;


CR_BIND(CProjectileHandler, )
CR_REG_METADATA(CProjectileHandler, (
	CR_MEMBER(syncedProjectiles),
	CR_MEMBER(unsyncedProjectiles),
	CR_MEMBER_UN(flyingPieces),
	CR_MEMBER_UN(groundFlashes),
	CR_MEMBER_UN(resortFlyingPieces),

	CR_MEMBER(maxParticles),
	CR_MEMBER(maxNanoParticles),
	CR_MEMBER(currentNanoParticles),
	CR_MEMBER_UN(lastCurrentParticles),
	CR_MEMBER_UN(lastSyncedProjectilesCount),
	CR_MEMBER_UN(lastUnsyncedProjectilesCount),

	CR_MEMBER(freeSyncedIDs),
	CR_MEMBER(freeUnsyncedIDs),
	CR_MEMBER(syncedProjectileIDs),
	CR_MEMBER(unsyncedProjectileIDs)
))



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProjectileHandler::CProjectileHandler()
: currentNanoParticles(0)
, lastCurrentParticles(0)
, lastSyncedProjectilesCount(0)
, lastUnsyncedProjectilesCount(0)
, resortFlyingPieces({false})
, syncedProjectileIDs(1024, nullptr)
#if UNSYNCED_PROJ_NOEVENT
, unsyncedProjectileIDs(0, nullptr)
#else
, unsyncedProjectileIDs(8192, nullptr)
#endif
{
    //stub method
}

CProjectileHandler::~CProjectileHandler()
{
    //stub method
}


void CProjectileHandler::ConfigNotify(const std::string& key, const std::string& value)
{
    //stub method
}


static void MAPPOS_SANITY_CHECK(const float3 v)
{
    //stub method
}


void CProjectileHandler::UpdateProjectileContainer(ProjectileContainer& pc, bool synced)
{
    //stub method
}


template<class T>
static void UPDATE_PTR_CONTAINER(T& cont) {
	if (cont.empty())
		return;

#ifndef NDEBUG
	const size_t origSize = cont.size();
#endif
	size_t size = cont.size();

	for (unsigned int i = 0; i < size; /*no-op*/) {
		auto*& p = cont[i];

		if (!p->Update()) {
			delete p;
			p = cont[size -= 1];
			continue;
		}

		++i;
	}

	//WARNING: check if the vector got enlarged while iterating, in that case
	// we didn't update the newest items
	assert(cont.size() == origSize);

	cont.erase(cont.begin() + size, cont.end());
}

template<class T>
static void UPDATE_REF_CONTAINER(T& cont) {
	if (cont.empty())
		return;

#ifndef NDEBUG
	const size_t origSize = cont.size();
#endif
	size_t size = cont.size();

	for (unsigned int i = 0; i < size; /*no-op*/) {
		auto& p = cont[i];

		if (!p.Update()) {
			p = std::move(cont[size -= 1]);
			continue;
		}

		++i;
	}

	//WARNING: check if the vector got enlarged while iterating, in that case
	// we didn't update the newest items
	assert(cont.size() == origSize);

	cont.erase(cont.begin() + size, cont.end());
}


void CProjectileHandler::Update()
{
    //stub method
}



void CProjectileHandler::AddProjectile(CProjectile* p)
{
    //stub method
}




void CProjectileHandler::CheckUnitCollisions(
	CProjectile* p,
	std::vector<CUnit*>& tempUnits,
	const float3 ppos0,
	const float3 ppos1)
{
    //stub method
}

void CProjectileHandler::CheckFeatureCollisions(
	CProjectile* p,
	std::vector<CFeature*>& tempFeatures,
	const float3 ppos0,
	const float3 ppos1)
{
    //stub method
}


void CProjectileHandler::CheckShieldCollisions(
	CProjectile* p,
	std::vector<CPlasmaRepulser*>& tempRepulsers,
	const float3 ppos0,
	const float3 ppos1)
{
    //stub method
}

void CProjectileHandler::CheckUnitFeatureCollisions(ProjectileContainer& pc)
{
    //stub method
}

void CProjectileHandler::CheckGroundCollisions(ProjectileContainer& pc)
{
    //stub method
}

void CProjectileHandler::CheckCollisions()
{
    //stub method
}



void CProjectileHandler::AddGroundFlash(CGroundFlash* flash)
{
    //stub method
}


void CProjectileHandler::AddFlyingPiece(
	int modelType,
	const S3DModelPiece* piece,
	const CMatrix44f& m,
	const float3 pos,
	const float3 speed,
	const float2 pieceParams,
	const int2 renderParams
) {
	flyingPieces[modelType].emplace_back(piece, m, pos, speed, pieceParams, renderParams);
	resortFlyingPieces[modelType] = true;
}


void CProjectileHandler::AddNanoParticle(
	const float3 startPos,
	const float3 endPos,
	const UnitDef* unitDef,
	int teamNum,
	bool highPriority)
{
    //stub method
}

void CProjectileHandler::AddNanoParticle(
	const float3 startPos,
	const float3 endPos,
	const UnitDef* unitDef,
	int teamNum,
	float radius,
	bool inverse,
	bool highPriority)
{
    //stub method
}


CProjectile* CProjectileHandler::GetProjectileBySyncedID(int id)
{
    //stub method
}


CProjectile* CProjectileHandler::GetProjectileByUnsyncedID(int id)
{
    //stub method
}


float CProjectileHandler::GetParticleSaturation(const bool withRandomization) const
{
    //stub method
}

int CProjectileHandler::GetCurrentParticles() const
{
    //stub method
}
