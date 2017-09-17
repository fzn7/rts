/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "Game/Camera.h"
#include "Game/GameHelper.h"
#include "Map/Ground.h"
#include "MissileProjectile.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Misc/GeometricObjects.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Rendering/Env/Particles/Classes/SmokeTrailProjectile.h"
#include "Sim/Units/Unit.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/Matrix44f.h"
#include "System/myMath.h"
#include "System/Sync/SyncTracer.h"

const float CMissileProjectile::SMOKE_TIME = 60.0f;

CR_BIND_DERIVED(CMissileProjectile, CWeaponProjectile, )

CR_REG_METADATA(CMissileProjectile,(
	CR_SETFLAG(CF_Synced),
	CR_MEMBER(ignoreError),
	CR_MEMBER(maxSpeed),
	// CR_MEMBER(ttl),
	CR_MEMBER(age),
	CR_MEMBER(oldSmoke),
	CR_MEMBER(oldDir),
	CR_MEMBER(numParts),
	CR_MEMBER(isWobbling),
	CR_MEMBER(wobbleDir),
	CR_MEMBER(wobbleTime),
	CR_MEMBER(wobbleDif),
	CR_MEMBER(danceMove),
	CR_MEMBER(danceCenter),
	CR_MEMBER(danceTime),
	CR_MEMBER(isDancing),
	CR_MEMBER(extraHeight),
	CR_MEMBER(extraHeightDecay),
	CR_MEMBER(extraHeightTime),
	CR_IGNORED(smokeTrail)
))


CMissileProjectile::CMissileProjectile(const ProjectileParams& params): CWeaponProjectile(params)
	, ignoreError(false)
	, maxSpeed(0.0f)
	, extraHeight(0.0f)
	, extraHeightDecay(0.0f)

	, age(0)
	, numParts(0)
	, extraHeightTime(0)

	, isDancing(false)
	, isWobbling(false)

	, danceTime(1)
	, wobbleTime(1)

	, oldSmoke(pos)
	, oldDir(dir)
	, smokeTrail(nullptr)
{
    //stub method
}

void CMissileProjectile::Collision()
{
    //stub method
}

void CMissileProjectile::Collision(CUnit* unit)
{
    //stub method
}

void CMissileProjectile::Collision(CFeature* feature)
{
    //stub method
}

void CMissileProjectile::Update()
{
    //stub method
}

void CMissileProjectile::UpdateWobble() {
	if (!isWobbling)
		return;

	if ((--wobbleTime) <= 0) {
		wobbleDif = (gs->randVector() - wobbleDir) * (1.0f / 16);
		wobbleTime = 16;
	}

	float wobbleFact = weaponDef->wobble;

	if (owner() != NULL)
		wobbleFact *= CUnit::ExperienceScale(owner()->limExperience, weaponDef->ownerExpAccWeight);

	wobbleDir += wobbleDif;
	dir = (dir + wobbleDir * wobbleFact).Normalize();
}

void CMissileProjectile::UpdateDance() {
	if (!isDancing)
		return;

	if ((--danceTime) <= 0) {
		danceMove = gs->randVector() * weaponDef->dance - danceCenter;
		danceCenter += danceMove;
		danceTime = 8;
	}

	SetPosition(pos + danceMove);
}


void CMissileProjectile::UpdateGroundBounce() {
	if (luaMoveCtrl)
		return;

	const float4 oldSpeed = speed;

	CWeaponProjectile::UpdateGroundBounce();

	if (oldSpeed != speed) {
		SetVelocityAndSpeed(speed);
	}
}



void CMissileProjectile::Draw()
{
    //stub method
}

int CMissileProjectile::ShieldRepulse(const float3& shieldPos, float shieldForce, float shieldMaxSpeed)
{
    //stub method
}

int CMissileProjectile::GetProjectilesCount() const
{
    //stub method
}
