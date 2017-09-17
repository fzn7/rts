#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/creg/STL_List.h"
#include "System/creg/STL_Set.h"
#include "PlasmaRepulser.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Rendering/Env/Particles/Classes/ShieldSegmentProjectile.h"
#include "Rendering/Env/Particles/Classes/RepulseGfx.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectile.h"
#include "Sim/Units/Scripts/UnitScript.h"
#include "Sim/Units/Unit.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/EventHandler.h"
#include "System/myMath.h"
#include "System/Util.h"

CR_BIND_DERIVED(CPlasmaRepulser, CWeapon, (NULL, NULL))

CR_REG_METADATA(CPlasmaRepulser, (
	CR_MEMBER(radius),
	CR_MEMBER(sqRadius),
	CR_MEMBER(lastPos),
	CR_MEMBER(curPower),
	CR_MEMBER(hitFrames),
	CR_MEMBER(rechargeDelay),
	CR_MEMBER(isEnabled),
	CR_MEMBER(segmentCollection),
	CR_MEMBER(repulsedProjectiles),

	CR_MEMBER(quads),
	CR_MEMBER(collisionVolume),
	CR_MEMBER(tempNum)
))


CPlasmaRepulser::CPlasmaRepulser(CUnit* owner, const WeaponDef* def): CWeapon(owner, def),
	tempNum(0),
	curPower(0.0f),
	hitFrames(0),
	rechargeDelay(0),
	isEnabled(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CPlasmaRepulser::Init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CPlasmaRepulser::IsRepulsing(CWeaponProjectile* p) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CPlasmaRepulser::IsActive() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CPlasmaRepulser::HaveFreeLineOfFire(const float3 pos, const SWeaponTarget& trg, bool useMuzzle) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CPlasmaRepulser::CanIntercept(unsigned interceptedType, int allyTeam) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CPlasmaRepulser::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Returns true if the projectile is destroyed.
bool CPlasmaRepulser::IncomingProjectile(CWeaponProjectile* p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CPlasmaRepulser::SlowUpdate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CPlasmaRepulser::IncomingBeam(const CWeapon* emitter, const float3& start, float damageMultiplier)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CPlasmaRepulser::DependentDied(CObject* o)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
