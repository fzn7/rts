#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LightningProjectile.h"
#include "Game/Camera.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Weapons/WeaponDef.h"

#ifdef TRACE_SYNC
#include "System/Sync/SyncTracer.h"
#endif

CR_BIND_DERIVED(CLightningProjectile, CWeaponProjectile, )

CR_REG_METADATA(CLightningProjectile,
                (CR_SETFLAG(CF_Synced),
                 CR_MEMBER(color),
                 CR_MEMBER(displacements),
                 CR_MEMBER(displacements2)))

CLightningProjectile::CLightningProjectile(const ProjectileParams& params)
  : CWeaponProjectile(params)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLightningProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLightningProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLightningProjectile::DrawOnMinimap(CVertexArray& lines, CVertexArray& points)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CLightningProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
