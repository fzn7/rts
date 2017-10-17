#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "TracerProjectile.h"

#include "Rendering/GL/myGL.h"
#include "Sim/Projectiles/ExpGenSpawnableMemberInfo.h"

CR_BIND_DERIVED(CTracerProjectile, CProjectile, )

CR_REG_METADATA(CTracerProjectile,
                (CR_MEMBER(speedf),
                 CR_MEMBER(drawLength),
                 CR_MEMBER_BEGINFLAG(CM_Config),
                 CR_MEMBER(length),
                 CR_MEMBER_ENDFLAG(CM_Config)))

CTracerProjectile::CTracerProjectile()
  : speedf(0.0f)
  , length(0.0f)
  , drawLength(0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CTracerProjectile::CTracerProjectile(CUnit* owner,
                                     const float3& pos,
                                     const float3& spd,
                                     const float range)
  : CProjectile(pos, spd, owner, false, false, false)
  , length(range)
  , drawLength(0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CTracerProjectile::Init(const CUnit* owner, const float3& offset)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CTracerProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CTracerProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CTracerProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CTracerProjectile::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
