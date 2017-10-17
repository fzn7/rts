#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectile.h"
#include "Game/GameHelper.h"
#include "Map/Ground.h"
#include "Rendering/Colors.h"
#include "Rendering/GL/VertexArray.h"
#include "Sim/Features/Feature.h"
#include "Sim/Misc/DamageArray.h"
#include "Sim/Misc/InterceptHandler.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Projectiles/ProjectileParams.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/Matrix44f.h"
#include "System/creg/DefTypes.h"
#include "System/myMath.h"

CR_BIND_DERIVED_INTERFACE(CWeaponProjectile, CProjectile)

CR_REG_METADATA(CWeaponProjectile,
                (CR_SETFLAG(CF_Synced),
                 CR_MEMBER(damages),
                 CR_MEMBER(targeted),
                 CR_MEMBER(weaponDef),
                 CR_MEMBER(target),
                 CR_MEMBER(targetPos),
                 CR_MEMBER(startPos),
                 CR_MEMBER(ttl),
                 CR_MEMBER(bounces),
                 CR_MEMBER(weaponNum),

                 CR_POSTLOAD(PostLoad)))

CWeaponProjectile::CWeaponProjectile(const ProjectileParams& params)
  : CProjectile(params.pos,
                params.speed,
                params.owner,
                true,
                true,
                false,
                false)

  , damages(nullptr)
  , weaponDef(params.weaponDef)
  , target(params.target)

  , ttl(params.ttl)
  , bounces(0)

  , targeted(false)

  , startPos(params.pos)
  , targetPos(params.end)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CWeaponProjectile::~CWeaponProjectile()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CWeaponProjectile::Explode(CUnit* hitUnit,
                           CFeature* hitFeature,
                           float3 impactPos,
                           float3 impactDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CWeaponProjectile::Collision()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CWeaponProjectile::Collision(CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CWeaponProjectile::Collision(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CWeaponProjectile::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CWeaponProjectile::UpdateInterception()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CWeaponProjectile::UpdateGroundBounce()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CWeaponProjectile::TraveledRange() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CWeaponProjectile::DrawOnMinimap(CVertexArray& lines, CVertexArray& points)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CWeaponProjectile::CanBeInterceptedBy(const WeaponDef* wd) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CWeaponProjectile::DependentDied(CObject* o)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CWeaponProjectile::PostLoad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
