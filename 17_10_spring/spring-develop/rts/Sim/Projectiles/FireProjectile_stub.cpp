#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FireProjectile.h"
#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Features/Feature.h"
#include "Sim/Misc/DamageArray.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/Wind.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/Unit.h"
#include "System/creg/STL_List.h"

CR_BIND_DERIVED(CFireProjectile, CProjectile, )
CR_BIND(CFireProjectile::SubParticle, )

CR_REG_METADATA(CFireProjectile,
                (CR_SETFLAG(CF_Synced),
                 CR_MEMBER(ttl),
                 CR_MEMBER(emitPos),
                 CR_MEMBER(emitRadius),
                 CR_MEMBER(particleTime),
                 CR_MEMBER(particleSize),
                 CR_MEMBER(ageSpeed),
                 CR_MEMBER(subParticles2),
                 CR_MEMBER(subParticles)))

CR_REG_METADATA_SUB(CFireProjectile,
                    SubParticle,
                    (CR_MEMBER(pos),
                     CR_MEMBER(posDif),
                     CR_MEMBER(age),
                     CR_MEMBER(maxSize),
                     CR_MEMBER(rotSpeed),
                     CR_MEMBER(smokeType)))

CFireProjectile::CFireProjectile(const float3& pos,
                                 const float3& spd,
                                 CUnit* owner,
                                 int emitTtl,
                                 int particleTtl,
                                 float emitRadius,
                                 float particleSize)
  : // these are synced, but neither weapon nor piece
    // (only burning features create instances of them)
  CProjectile(pos, speed, owner, true, false, false)
  , ttl(emitTtl)
  , emitPos(pos)
  , emitRadius(emitRadius)
  , particleTime(particleTtl)
  , particleSize(particleSize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFireProjectile::StopFire()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFireProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFireProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CFireProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
