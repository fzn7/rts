#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "WakeProjectile.h"
#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Rendering/Env/IWater.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/TextureAtlas.h"

CR_BIND_DERIVED(CWakeProjectile, CProjectile, )

CR_REG_METADATA(CWakeProjectile,
                (CR_MEMBER(alpha),
                 CR_MEMBER(alphaFalloff),
                 CR_MEMBER(alphaAdd),
                 CR_MEMBER(alphaAddTime),
                 CR_MEMBER(size),
                 CR_MEMBER(sizeExpansion),
                 CR_MEMBER(rotation),
                 CR_MEMBER(rotSpeed)))

CWakeProjectile::CWakeProjectile(CUnit* owner,
                                 const float3& pos,
                                 const float3& speed,
                                 float startSize,
                                 float sizeExpansion,
                                 float alpha,
                                 float alphaFalloff,
                                 float fadeupTime)
  : CProjectile(pos, speed, owner, false, false, false)
  , alpha(0.0f)
  , alphaFalloff(alphaFalloff)
  , alphaAdd(alpha / fadeupTime)
  , alphaAddTime((int)fadeupTime)
  , size(startSize)
  , sizeExpansion(sizeExpansion)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWakeProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWakeProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CWakeProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
