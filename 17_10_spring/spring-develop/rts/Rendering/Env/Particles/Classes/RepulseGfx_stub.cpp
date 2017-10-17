#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "RepulseGfx.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Units/Unit.h"

CR_BIND_DERIVED(CRepulseGfx, CProjectile, )

CR_REG_METADATA(CRepulseGfx,
                (CR_MEMBER(repulsed),
                 CR_MEMBER(sqMaxDist),
                 CR_MEMBER(age),
                 CR_MEMBER(color),
                 CR_MEMBER(difs)))

CRepulseGfx::CRepulseGfx(CUnit* owner,
                         CProjectile* repulsed,
                         float maxDist,
                         const float3& color)
  : CProjectile(repulsed ? repulsed->pos : ZeroVector,
                repulsed ? repulsed->speed : ZeroVector,
                owner,
                false,
                false,
                false)
  , repulsed(repulsed)
  , sqMaxDist((maxDist * maxDist) + 100)
  , age(0)
  , color(color)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CRepulseGfx::~CRepulseGfx() {}

void
CRepulseGfx::DependentDied(CObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CRepulseGfx::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CRepulseGfx::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CRepulseGfx::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
