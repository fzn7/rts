#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GenericParticleProjectile.h"
#include "Game/Camera.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/ColorMap.h"
#include "Sim/Projectiles/ProjectileHandler.h"

CR_BIND_DERIVED(CGenericParticleProjectile, CProjectile, )

CR_REG_METADATA(CGenericParticleProjectile,
                (CR_MEMBER(gravity),
                 CR_MEMBER(texture),
                 CR_MEMBER(colorMap),
                 CR_MEMBER(directional),
                 CR_MEMBER(life),
                 CR_MEMBER(decayrate),
                 CR_MEMBER(size),
                 CR_MEMBER(airdrag),
                 CR_MEMBER(sizeGrowth),
                 CR_MEMBER(sizeMod)))

CGenericParticleProjectile::CGenericParticleProjectile(const CUnit* owner,
                                                       const float3& pos,
                                                       const float3& speed)
  : CProjectile(pos, speed, owner, false, false, false)

  , gravity(ZeroVector)
  , texture(NULL)
  , colorMap(NULL)
  , directional(false)
  , life(0.0f)
  , decayrate(0.0f)
  , size(0.0f)
  , airdrag(0.0f)
  , sizeGrowth(0.0f)
  , sizeMod(0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CGenericParticleProjectile::~CGenericParticleProjectile() {}

void
CGenericParticleProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGenericParticleProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CGenericParticleProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
