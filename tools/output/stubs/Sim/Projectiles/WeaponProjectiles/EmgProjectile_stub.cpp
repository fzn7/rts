#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "EmgProjectile.h"
#include "Game/Camera.h"
#include "Map/Ground.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/Sync/SyncTracer.h"

CR_BIND_DERIVED(CEmgProjectile, CWeaponProjectile, )

CR_REG_METADATA(CEmgProjectile,(
	CR_SETFLAG(CF_Synced),
	CR_MEMBER(intensity),
	CR_MEMBER(color)
))


CEmgProjectile::CEmgProjectile(const ProjectileParams& params): CWeaponProjectile(params)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CEmgProjectile::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CEmgProjectile::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int CEmgProjectile::ShieldRepulse(const float3& shieldPos, float shieldForce, float shieldMaxSpeed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int CEmgProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
