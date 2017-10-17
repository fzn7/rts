#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FlareProjectile.h"
#include "Game/Camera.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Projectiles/WeaponProjectiles/MissileProjectile.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"

CR_BIND_DERIVED(CFlareProjectile, CProjectile, )

CR_REG_METADATA(CFlareProjectile,
                (CR_SETFLAG(CF_Synced),
                 CR_MEMBER(activateFrame),
                 CR_MEMBER(deathFrame),

                 CR_MEMBER(numSub),
                 CR_MEMBER(lastSub),
                 CR_MEMBER(subPos),
                 CR_MEMBER(subSpeed),
                 CR_MEMBER(alphaFalloff)))

CFlareProjectile::CFlareProjectile(const float3& pos,
                                   const float3& speed,
                                   CUnit* owner,
                                   int activateFrame)
  : //! these are synced, but neither weapon nor piece
    //! (only created by units that can drop flares)
  CProjectile(pos, speed, owner, true, false, false)
  , activateFrame(activateFrame)
  , deathFrame(activateFrame + (owner ? owner->unitDef->flareTime : 1))
  , numSub(0)
  , lastSub(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CFlareProjectile::~CFlareProjectile() {}

void
CFlareProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFlareProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CFlareProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
