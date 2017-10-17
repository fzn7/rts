#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ExplosiveProjectile.h"
#include "Game/Camera.h"
#include "Map/Ground.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/ColorMap.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Weapons/WeaponDef.h"

#ifdef TRACE_SYNC
#include "System/Sync/SyncTracer.h"
#endif

CR_BIND_DERIVED(CExplosiveProjectile, CWeaponProjectile, )

CR_REG_METADATA(CExplosiveProjectile,
                (CR_SETFLAG(CF_Synced), CR_MEMBER(invttl), CR_MEMBER(curTime)))

CExplosiveProjectile::CExplosiveProjectile(const ProjectileParams& params)
  : CWeaponProjectile(params)
  , invttl(0.0f)
  , curTime(0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CExplosiveProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CExplosiveProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CExplosiveProjectile::ShieldRepulse(const float3& shieldPos,
                                    float shieldForce,
                                    float shieldMaxSpeed)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CExplosiveProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
