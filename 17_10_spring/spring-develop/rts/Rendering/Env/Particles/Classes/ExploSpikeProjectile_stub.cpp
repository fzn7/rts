#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ExploSpikeProjectile.h"

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Projectiles/ExpGenSpawnableMemberInfo.h"

CR_BIND_DERIVED(CExploSpikeProjectile, CProjectile, )

CR_REG_METADATA(CExploSpikeProjectile,
                (CR_MEMBER_BEGINFLAG(CM_Config),
                 CR_MEMBER(length),
                 CR_MEMBER(width),
                 CR_MEMBER(alpha),
                 CR_MEMBER(alphaDecay),
                 CR_MEMBER(lengthGrowth),
                 CR_MEMBER(color),
                 CR_MEMBER_ENDFLAG(CM_Config)))

CExploSpikeProjectile::CExploSpikeProjectile()
  : CProjectile()
  , length(0.0f)
  , width(0.0f)
  , alpha(0.0f)
  , alphaDecay(0.0f)
  , lengthGrowth(0.0f)
  , color(1.0f, 0.8f, 0.5f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CExploSpikeProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CExploSpikeProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CExploSpikeProjectile::Init(const CUnit* owner, const float3& offset)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CExploSpikeProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CExploSpikeProjectile::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
