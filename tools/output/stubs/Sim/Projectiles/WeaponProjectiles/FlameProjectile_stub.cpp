/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "FlameProjectile.h"
#include "Game/Camera.h"
#include "Map/Ground.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/ColorMap.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Weapons/WeaponDef.h"

CR_BIND_DERIVED(CFlameProjectile, CWeaponProjectile, )

CR_REG_METADATA(CFlameProjectile,(
	CR_SETFLAG(CF_Synced),
	CR_MEMBER(spread),
	CR_MEMBER(curTime),
	CR_MEMBER(physLife),
	CR_MEMBER(invttl)
))


CFlameProjectile::CFlameProjectile(const ProjectileParams& params):CWeaponProjectile(params)
	, curTime(0.0f)
	, physLife(0.0f)
	, invttl(1.0f / ttl)
	, spread(params.spread)
{
    //stub method
}

void CFlameProjectile::Collision()
{
    //stub method
}

void CFlameProjectile::Update()
{
    //stub method
}

void CFlameProjectile::Draw()
{
    //stub method
}

int CFlameProjectile::ShieldRepulse(const float3& shieldPos, float shieldForce, float shieldMaxSpeed)
{
    //stub method
}

int CFlameProjectile::GetProjectilesCount() const
{
    //stub method
}
