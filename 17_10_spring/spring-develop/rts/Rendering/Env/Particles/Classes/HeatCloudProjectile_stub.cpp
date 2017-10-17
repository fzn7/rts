#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "HeatCloudProjectile.h"

#include "Game/Camera.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Projectiles/ExpGenSpawnableMemberInfo.h"

CR_BIND_DERIVED(CHeatCloudProjectile, CProjectile, )

CR_REG_METADATA(CHeatCloudProjectile,
                (CR_MEMBER_BEGINFLAG(CM_Config),
                 CR_MEMBER(heat),
                 CR_MEMBER(maxheat),
                 CR_MEMBER(heatFalloff),
                 CR_MEMBER(size),
                 CR_MEMBER(sizeGrowth),
                 CR_MEMBER(sizemod),
                 CR_MEMBER(sizemodmod),
                 CR_MEMBER(texture),
                 CR_MEMBER_ENDFLAG(CM_Config)))

CHeatCloudProjectile::CHeatCloudProjectile()
  : CProjectile()

  , heat(0.0f)
  , maxheat(0.0f)
  , heatFalloff(0.0f)
  , size(0.0f)
  , sizeGrowth(0.0f)
  , sizemod(0.0f)
  , sizemodmod(0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CHeatCloudProjectile::CHeatCloudProjectile(CUnit* owner,
                                           const float3& pos,
                                           const float3& speed,
                                           const float temperature,
                                           const float size)
  : CProjectile(pos, speed, owner, false, false, false)

  , heat(temperature)
  , maxheat(temperature)
  , heatFalloff(1.0f)
  , size(0.0f)
  , sizemod(0.0f)
  , sizemodmod(0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CHeatCloudProjectile::~CHeatCloudProjectile() {}

void
CHeatCloudProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CHeatCloudProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CHeatCloudProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CHeatCloudProjectile::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
