#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "TorpedoProjectile.h"
#include "Game/Camera.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Rendering/Env/Particles/Classes/BubbleProjectile.h"
#include "Rendering/Env/Particles/Classes/SmokeTrailProjectile.h"
#include "Sim/Units/Unit.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/myMath.h"

#ifdef TRACE_SYNC
	#include "System/Sync/SyncTracer.h"
#endif

CR_BIND_DERIVED(CTorpedoProjectile, CWeaponProjectile, )

CR_REG_METADATA(CTorpedoProjectile,(
	CR_SETFLAG(CF_Synced),
	CR_MEMBER(tracking),
	CR_MEMBER(ignoreError),
	CR_MEMBER(maxSpeed),
	CR_MEMBER(nextBubble),
	CR_MEMBER(texx),
	CR_MEMBER(texy)
))


CTorpedoProjectile::CTorpedoProjectile(const ProjectileParams& params): CWeaponProjectile(params)
	, tracking(0.0f)
	, ignoreError(false)
	, maxSpeed(0.0f)

	, nextBubble(4)
	, texx(0.0f)
	, texy(0.0f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CTorpedoProjectile::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CTorpedoProjectile::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int CTorpedoProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
