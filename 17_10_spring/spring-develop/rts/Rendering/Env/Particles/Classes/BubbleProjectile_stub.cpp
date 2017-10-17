#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "BubbleProjectile.h"

#include "Game/Camera.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Projectiles/ExpGenSpawnableMemberInfo.h"
#include "Sim/Projectiles/ProjectileHandler.h"

CR_BIND_DERIVED(CBubbleProjectile, CProjectile, )

CR_REG_METADATA(CBubbleProjectile,
                (CR_MEMBER_BEGINFLAG(CM_Config),
                 CR_MEMBER(ttl),
                 CR_MEMBER(alpha),
                 CR_MEMBER(startSize),
                 CR_MEMBER(sizeExpansion),
                 CR_MEMBER_ENDFLAG(CM_Config),
                 CR_MEMBER(size)))

CBubbleProjectile::CBubbleProjectile()
  : CProjectile()
  , ttl(0)
  , alpha(0.0f)
  , size(0.0f)
  , startSize(0.0f)
  , sizeExpansion(0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CBubbleProjectile::CBubbleProjectile(
	CUnit* owner,
	float3 pos,
	float3 speed,
	int ttl,
	float startSize,
	float sizeExpansion,
	float alpha
):
	CProjectile(pos, speed, owner, false, false, false),
	ttl(ttl),
	alpha(alpha),
	size(startSize * 0.4f),
	startSize(startSize),
	sizeExpansion(sizeExpansion)
{
	//stub method
    std::cout << __FUNCTION__ << std::endl;
}

CBubbleProjectile::~CBubbleProjectile() {}

void
CBubbleProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBubbleProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CBubbleProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CBubbleProjectile::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
