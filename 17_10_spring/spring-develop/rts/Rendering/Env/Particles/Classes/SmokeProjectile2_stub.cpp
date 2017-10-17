#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SmokeProjectile2.h"

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Misc/Wind.h"
#include "Sim/Projectiles/ExpGenSpawnableMemberInfo.h"

CR_BIND_DERIVED(CSmokeProjectile2, CProjectile, )

CR_REG_METADATA(CSmokeProjectile2,
                (CR_MEMBER_BEGINFLAG(CM_Config),
                 CR_MEMBER(color),
                 CR_MEMBER(ageSpeed),
                 CR_MEMBER(size),
                 CR_MEMBER(startSize),
                 CR_MEMBER(sizeExpansion),
                 CR_MEMBER(wantedPos),
                 CR_MEMBER(glowFalloff),
                 CR_MEMBER_ENDFLAG(CM_Config),
                 CR_MEMBER(age),
                 CR_MEMBER(textureNum)))

CSmokeProjectile2::CSmokeProjectile2()
  : CProjectile()
  , color(0.5f)
  , age(0.0f)
  , ageSpeed(1.0f)
  , size(0.0f)
  , startSize(0.0f)
  , sizeExpansion(0.0f)
  , textureNum(0)
  , glowFalloff(0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CSmokeProjectile2::CSmokeProjectile2(CUnit* owner,
                                     const float3& pos,
                                     const float3& wantedPos,
                                     const float3& speed,
                                     float ttl,
                                     float startSize,
                                     float sizeExpansion,
                                     float color)
  : CProjectile(pos, speed, owner, false, false, false)
  , color(color)
  , age(0)
  , size(0)
  , startSize(startSize)
  , sizeExpansion(sizeExpansion)
  , wantedPos(wantedPos)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSmokeProjectile2::Init(const CUnit* owner, const float3& offset)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSmokeProjectile2::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSmokeProjectile2::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CSmokeProjectile2::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CSmokeProjectile2::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
