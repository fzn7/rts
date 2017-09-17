#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "FireBallProjectile.h"
#include "Game/Camera.h"
#include "Map/Ground.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/creg/STL_Deque.h"

CR_BIND_DERIVED(CFireBallProjectile, CWeaponProjectile, )
CR_BIND(CFireBallProjectile::Spark, )

CR_REG_METADATA(CFireBallProjectile,(
	CR_SETFLAG(CF_Synced),
	CR_MEMBER(sparks)
))

CR_REG_METADATA_SUB(CFireBallProjectile,Spark,(
	CR_MEMBER(pos),
	CR_MEMBER(speed),
	CR_MEMBER(size),
	CR_MEMBER(ttl)
))


CFireBallProjectile::CFireBallProjectile(const ProjectileParams& params): CWeaponProjectile(params)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CFireBallProjectile::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CFireBallProjectile::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CFireBallProjectile::EmitSpark()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CFireBallProjectile::Collision()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int CFireBallProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
