#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "BeamLaserProjectile.h"
#include "Game/Camera.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Weapons/WeaponDef.h"
#include <cstring> //memset

CR_BIND_DERIVED(CBeamLaserProjectile, CWeaponProjectile, )

CR_REG_METADATA(CBeamLaserProjectile,
                (CR_SETFLAG(CF_Synced),
                 CR_MEMBER(coreColStart),
                 CR_MEMBER(coreColEnd),
                 CR_MEMBER(edgeColStart),
                 CR_MEMBER(edgeColEnd),
                 CR_MEMBER(thickness),
                 CR_MEMBER(corethickness),
                 CR_MEMBER(flaresize),
                 CR_MEMBER(decay),
                 CR_MEMBER(midtexx)))

CBeamLaserProjectile::CBeamLaserProjectile(const ProjectileParams& params)
  : CWeaponProjectile(params)
  , thickness(0.0f)
  , corethickness(0.0f)
  , flaresize(0.0f)
  , decay(0.0f)
  , midtexx(0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBeamLaserProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBeamLaserProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBeamLaserProjectile::DrawOnMinimap(CVertexArray& lines, CVertexArray& points)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CBeamLaserProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
