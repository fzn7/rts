#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LaserProjectile.h"
#include "Game/Camera.h"
#include "Map/Ground.h"
#include "Rendering/Env/Particles/Classes/SimpleParticleSystem.h"
#include "Rendering/GL/VertexArray.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Weapons/WeaponDef.h"

#ifdef TRACE_SYNC
#include "System/Sync/SyncTracer.h"
#endif

CR_BIND_DERIVED(CLaserProjectile, CWeaponProjectile, )

CR_REG_METADATA(CLaserProjectile,
                (CR_SETFLAG(CF_Synced),
                 CR_MEMBER(intensity),
                 CR_MEMBER(color),
                 CR_MEMBER(color2),
                 CR_MEMBER(speedf),
                 CR_MEMBER(maxLength),
                 CR_MEMBER(curLength),
                 CR_MEMBER(stayTime),
                 CR_MEMBER(intensityFalloff),
                 CR_MEMBER(midtexx)))

CLaserProjectile::CLaserProjectile(const ProjectileParams& params)
  : CWeaponProjectile(params)
  , speedf(0.0f)
  , maxLength(0.0f)
  , curLength(0.0f)
  , intensity(0.0f)
  , intensityFalloff(0.0f)
  , midtexx(0.0f)

  , stayTime(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLaserProjectile::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLaserProjectile::UpdateIntensity()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLaserProjectile::UpdateLength()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLaserProjectile::UpdatePos(const float4& oldSpeed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLaserProjectile::CollisionCommon(const float3& oldPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLaserProjectile::Collision(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLaserProjectile::Collision(CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLaserProjectile::Collision()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLaserProjectile::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLaserProjectile::ShieldRepulse(const float3& shieldPos,
                                float shieldForce,
                                float shieldMaxSpeed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLaserProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
