/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ExpGenSpawner.h"

#include "ExpGenSpawnableMemberInfo.h"
#include "ExplosionGenerator.h"

CR_BIND_DERIVED(CExpGenSpawner, CProjectile, )
CR_REG_METADATA(CExpGenSpawner,
(
	CR_MEMBER_BEGINFLAG(CM_Config),
		CR_MEMBER(delay),
		CR_MEMBER(damage),
		CR_MEMBER(explosionGenerator),
	CR_MEMBER_ENDFLAG(CM_Config)
))


CExpGenSpawner::CExpGenSpawner() :
	CProjectile(),
	delay(1),
	damage(0.0f),
	explosionGenerator(NULL)
{
    //stub method
}


void CExpGenSpawner::Update()
{
    //stub method
}


int CExpGenSpawner::GetProjectilesCount() const
{
    //stub method
}


bool CExpGenSpawner::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
}
