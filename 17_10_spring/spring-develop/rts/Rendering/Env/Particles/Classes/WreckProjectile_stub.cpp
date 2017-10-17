#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "WreckProjectile.h"
#include "Game/Camera.h"
#include "Map/Ground.h"
#include "Rendering/Colors.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "SmokeProjectile.h"

CR_BIND_DERIVED(CWreckProjectile, CProjectile, )
CR_REG_METADATA(CWreckProjectile, )

CWreckProjectile::CWreckProjectile(CUnit* owner,
                                   float3 pos,
                                   float3 speed,
                                   float temperature)
  : CProjectile(pos, speed, owner, false, false, false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWreckProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWreckProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWreckProjectile::DrawOnMinimap(CVertexArray& lines, CVertexArray& points)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CWreckProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
