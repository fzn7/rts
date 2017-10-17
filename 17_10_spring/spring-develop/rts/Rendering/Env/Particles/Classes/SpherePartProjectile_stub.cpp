#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SpherePartProjectile.h"

#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Projectiles/ExpGenSpawnableMemberInfo.h"

CR_BIND_DERIVED(CSpherePartProjectile, CProjectile, )

CR_REG_METADATA(CSpherePartProjectile,
                (CR_MEMBER(centerPos),
                 CR_MEMBER(vectors),
                 CR_MEMBER(color),
                 CR_MEMBER(sphereSize),
                 CR_MEMBER(expansionSpeed),
                 CR_MEMBER(xbase),
                 CR_MEMBER(ybase),
                 CR_MEMBER(baseAlpha),
                 CR_MEMBER(age),
                 CR_MEMBER(ttl),
                 CR_MEMBER(texx),
                 CR_MEMBER(texy)))

CSpherePartProjectile::CSpherePartProjectile(const CUnit* owner,
                                             const float3& centerPos,
                                             int xpart,
                                             int ypart,
                                             float expansionSpeed,
                                             float alpha,
                                             int ttl,
                                             const float3& color)
  : CProjectile(centerPos, ZeroVector, owner, false, false, false)
  , centerPos(centerPos)
  , color(color)
  , sphereSize(expansionSpeed)
  , expansionSpeed(expansionSpeed)
  , xbase(xpart)
  , ybase(ypart)
  , baseAlpha(alpha)
  , age(0)
  , ttl(ttl)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSpherePartProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSpherePartProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CSpherePartProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSpherePartProjectile::CreateSphere(const CUnit* owner,
                                    int ttl,
                                    float alpha,
                                    float expansionSpeed,
                                    float3 pos,
                                    float3 color)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CSpherePartSpawner::CSpherePartSpawner()
  : CProjectile()
  , alpha(0.0f)
  , ttl(0)
  , expansionSpeed(0.0f)
  , color(ZeroVector)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CR_BIND_DERIVED(CSpherePartSpawner, CProjectile, )

CR_REG_METADATA(CSpherePartSpawner,
(
	CR_MEMBER_BEGINFLAG(CM_Config),
		CR_MEMBER(alpha),
		CR_MEMBER(ttl),
		CR_MEMBER(expansionSpeed),
		CR_MEMBER(color),
	CR_MEMBER_ENDFLAG(CM_Config)
))

void CSpherePartSpawner::Init(const CUnit* owner, const float3& offset)
{
	//stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CSpherePartSpawner::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CSpherePartSpawner::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
