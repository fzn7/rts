/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "Game/Camera.h"
#include "LightningProjectile.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Weapons/WeaponDef.h"

#ifdef TRACE_SYNC
	#include "System/Sync/SyncTracer.h"
#endif

CR_BIND_DERIVED(CLightningProjectile, CWeaponProjectile, )

CR_REG_METADATA(CLightningProjectile,(
	CR_SETFLAG(CF_Synced),
	CR_MEMBER(color),
	CR_MEMBER(displacements),
	CR_MEMBER(displacements2)
))


CLightningProjectile::CLightningProjectile(const ProjectileParams& params): CWeaponProjectile(params)
{
    //stub method
}

void CLightningProjectile::Update()
{
    //stub method
}

void CLightningProjectile::Draw()
{
    //stub method
}

void CLightningProjectile::DrawOnMinimap(CVertexArray& lines, CVertexArray& points)
{
    //stub method
}

int CLightningProjectile::GetProjectilesCount() const
{
    //stub method
}

