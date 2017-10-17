#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MuzzleFlame.h"
#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/TextureAtlas.h"

CR_BIND_DERIVED(CMuzzleFlame, CProjectile, )

CR_REG_METADATA(CMuzzleFlame,
                (CR_MEMBER(size),
                 CR_MEMBER(age),
                 CR_MEMBER(numFlame),
                 CR_MEMBER(numSmoke),
                 CR_MEMBER(randSmokeDir)))

CMuzzleFlame::CMuzzleFlame(const float3& pos,
                           const float3& speed,
                           const float3& dir,
                           float size)
  : CProjectile(pos, speed, NULL, false, false, false)
  , size(size)
  , age(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CMuzzleFlame::~CMuzzleFlame()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMuzzleFlame::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMuzzleFlame::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CMuzzleFlame::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
