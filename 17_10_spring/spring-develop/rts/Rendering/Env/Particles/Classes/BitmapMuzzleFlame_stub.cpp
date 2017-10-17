#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "BitmapMuzzleFlame.h"

#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/ColorMap.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Projectiles/ExpGenSpawnableMemberInfo.h"
#include "Sim/Projectiles/ProjectileHandler.h"

CR_BIND_DERIVED(CBitmapMuzzleFlame, CProjectile, )

CR_REG_METADATA(CBitmapMuzzleFlame,
                (CR_MEMBER(invttl),
                 CR_MEMBER(life),
                 CR_MEMBER(createTime),
                 CR_MEMBER_BEGINFLAG(CM_Config),
                 CR_MEMBER(sideTexture),
                 CR_MEMBER(frontTexture),
                 CR_MEMBER(colorMap),
                 CR_MEMBER(size),
                 CR_MEMBER(length),
                 CR_MEMBER(sizeGrowth),
                 CR_MEMBER(ttl),
                 CR_MEMBER(frontOffset),
                 CR_MEMBER_ENDFLAG(CM_Config)))

CBitmapMuzzleFlame::CBitmapMuzzleFlame()
  : CProjectile()
  , sideTexture(NULL)
  , frontTexture(NULL)
  , colorMap(NULL)
  , size(0.0f)
  , length(0.0f)
  , sizeGrowth(0.0f)
  , frontOffset(0.0f)
  , ttl(0)
  , invttl(0.0f)
  , life(0.0f)
  , createTime(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBitmapMuzzleFlame::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBitmapMuzzleFlame::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBitmapMuzzleFlame::Init(const CUnit* owner, const float3& offset)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CBitmapMuzzleFlame::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CBitmapMuzzleFlame::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
