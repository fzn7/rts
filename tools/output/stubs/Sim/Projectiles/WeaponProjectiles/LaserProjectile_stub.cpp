#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "Game/Camera.h"
#include "LaserProjectile.h"
#include "Map/Ground.h"
#include "Rendering/GL/VertexArray.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Rendering/Env/Particles/Classes/SimpleParticleSystem.h"
#include "Sim/Weapons/WeaponDef.h"

#ifdef TRACE_SYNC
	#include "System/Sync/SyncTracer.h"
#endif

CR_BIND_DERIVED(CLaserProjectile, CWeaponProjectile, )

CR_REG_METADATA(CLaserProjectile,(
	CR_SETFLAG(CF_Synced),
	CR_MEMBER(intensity),
	CR_MEMBER(color),
	CR_MEMBER(color2),
	CR_MEMBER(speedf),
	CR_MEMBER(maxLength),
	CR_MEMBER(curLength),
	CR_MEMBER(stayTime),
	CR_MEMBER(intensityFalloff),
	CR_MEMBER(midtexx)
))


CLaserProjectile::CLaserProjectile(const ProjectileParams& params): CWeaponProjectile(params)
	, speedf(0.0f)
	, maxLength(0.0f)
	, curLength(0.0f)
	, intensity(0.0f)
	, intensityFalloff(0.0f)
	, midtexx(0.0f)

	, stayTime(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CLaserProjectile::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CLaserProjectile::UpdateIntensity() {
	if (ttl > 0) {
		explGenHandler->GenExplosion(cegID, pos, speed, ttl, intensity, 0.0f, NULL, NULL);
		return;
	}

	if (weaponDef->laserHardStop) {
		if (curLength < maxLength && speed != ZeroVector) {
			// bolt reached its max-range but wasn't fully extended yet
			stayTime = 1 + int((maxLength - curLength) / speedf);
		}

		SetVelocityAndSpeed(ZeroVector);
	} else {
		// fade out over the next 5 frames at most
		intensity -= std::max(intensityFalloff * 0.2f, 0.2f);
		intensity = std::max(intensity, 0.0f);
	}
}

void CLaserProjectile::UpdateLength() {
	if (speed != ZeroVector) {
		// expand bolt to maximum length if not
		// stopped / collided OR after hardstop
		curLength += speedf;
		curLength = std::min(maxLength, curLength);
	} else {
		if (stayTime == 0) {
			// contract bolt to zero length after stayTime
			// expires (can be immediately if not hardstop)
			curLength -= speedf;
			curLength = std::max(curLength, 0.0f);
		}
	}

	stayTime = std::max(stayTime - 1, 0);
}

void CLaserProjectile::UpdatePos(const float4& oldSpeed) {
	if (luaMoveCtrl)
		return;

	SetPosition(pos + speed);
	// note: this can change pos *and* speed
	UpdateGroundBounce();

	if (oldSpeed != speed) {
		SetVelocityAndSpeed(speed);
	}
}



void CLaserProjectile::CollisionCommon(const float3& oldPos) {
	// we will fade out over some time
	deleteMe = false;

	if (weaponDef->noExplode)
		return;

	checkCol = false;

	SetPosition(oldPos);
	SetVelocityAndSpeed(ZeroVector);

	if (curLength < maxLength) {
		stayTime = 1 + int((maxLength - curLength) / speedf);
	}
}

void CLaserProjectile::Collision(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CLaserProjectile::Collision(CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CLaserProjectile::Collision()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CLaserProjectile::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int CLaserProjectile::ShieldRepulse(const float3& shieldPos, float shieldForce, float shieldMaxSpeed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int CLaserProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
