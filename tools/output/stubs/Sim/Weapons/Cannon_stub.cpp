#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Cannon.h"
#include "Game/TraceRay.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Rendering/Env/Particles/Classes/HeatCloudProjectile.h"
#include "Rendering/Env/Particles/Classes/SmokeProjectile.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectileFactory.h"
#include "Sim/Units/Unit.h"
#include "System/Sync/SyncTracer.h"
#include "WeaponDefHandler.h"
#include "System/myMath.h"
#include "System/FastMath.h"

CR_BIND_DERIVED(CCannon, CWeapon, (NULL, NULL))

CR_REG_METADATA(CCannon,(
	CR_MEMBER(highTrajectory),
	CR_MEMBER(rangeFactor),
	CR_MEMBER(lastDiff),
	CR_MEMBER(lastDir),
	CR_MEMBER(gravity)
))

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCannon::CCannon(CUnit* owner, const WeaponDef* def)
	: CWeapon(owner, def)
	, rangeFactor(1.0f)
	, lastDir(-UpVector)
	, highTrajectory(false)
	, gravity(0.0f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CCannon::Init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CCannon::UpdateRange(const float val)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CCannon::UpdateWantedDir()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CCannon::HaveFreeLineOfFire(const float3 pos, const SWeaponTarget& trg, bool useMuzzle) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CCannon::FireImpl(const bool scriptCall)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CCannon::SlowUpdate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float3 CCannon::GetWantedDir(const float3& diff)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3 CCannon::GetWantedDir2(const float3& diff) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float CCannon::GetRange2D(float yDiff, float rFact) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float CCannon::GetRange2D(const float yDiff) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

