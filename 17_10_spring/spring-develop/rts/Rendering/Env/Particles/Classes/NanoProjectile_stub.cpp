#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "NanoProjectile.h"

#include "Game/Camera.h"
#include "Rendering/Colors.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Projectiles/ExpGenSpawnableMemberInfo.h"
#include "Sim/Projectiles/ProjectileHandler.h"

CR_BIND_DERIVED(CNanoProjectile, CProjectile, )

CR_REG_METADATA(CNanoProjectile,
                (CR_MEMBER_BEGINFLAG(CM_Config),
                 CR_MEMBER(deathFrame),
                 CR_MEMBER(color),
                 CR_MEMBER_ENDFLAG(CM_Config)))

CNanoProjectile::CNanoProjectile()
  : CProjectile()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CNanoProjectile::CNanoProjectile(float3 pos,
                                 float3 speed,
                                 int lifeTime,
                                 SColor c)
  : CProjectile(pos, speed, NULL, false, false, false)
  , deathFrame(gs->frameNum + lifeTime)
  , color(c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CNanoProjectile::~CNanoProjectile()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CNanoProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CNanoProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CNanoProjectile::DrawOnMinimap(CVertexArray& lines, CVertexArray& points)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CNanoProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CNanoProjectile::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
