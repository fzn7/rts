#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DirtProjectile.h"

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Projectiles/ExpGenSpawnableMemberInfo.h"

CR_BIND_DERIVED(CDirtProjectile, CProjectile, )

CR_REG_METADATA(CDirtProjectile,
                (CR_MEMBER_BEGINFLAG(CM_Config),
                 CR_MEMBER(alpha),
                 CR_MEMBER(alphaFalloff),
                 CR_MEMBER(size),
                 CR_MEMBER(sizeExpansion),
                 CR_MEMBER(slowdown),
                 CR_MEMBER(color),
                 CR_MEMBER(texture),
                 CR_MEMBER_ENDFLAG(CM_Config)))

CDirtProjectile::CDirtProjectile(CUnit* owner,
                                 const float3& pos,
                                 const float3& speed,
                                 float ttl,
                                 float size,
                                 float expansion,
                                 float slowdown,
                                 const float3& color)
  : CProjectile(pos, speed, owner, false, false, false)
  ,

  alpha(255)
  , size(size)
  , sizeExpansion(expansion)
  , slowdown(slowdown)
  , color(color)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CDirtProjectile::CDirtProjectile()
  : CProjectile()
  , alpha(255.0f)
  , alphaFalloff(10.0f)
  , size(10.0f)
  , sizeExpansion(0.0f)
  , slowdown(1.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CDirtProjectile::~CDirtProjectile() {}

void
CDirtProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CDirtProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CDirtProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CDirtProjectile::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
