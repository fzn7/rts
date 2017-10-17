#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MissileProjectile.h"
#include "Game/Camera.h"
#include "Game/GameHelper.h"
#include "Map/Ground.h"
#include "Rendering/Env/Particles/Classes/SmokeTrailProjectile.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Misc/GeometricObjects.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/Unit.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/Matrix44f.h"
#include "System/Sync/SyncTracer.h"
#include "System/myMath.h"

const float CMissileProjectile::SMOKE_TIME = 60.0f;

CR_BIND_DERIVED(CMissileProjectile, CWeaponProjectile, )

CR_REG_METADATA(CMissileProjectile,
                (CR_SETFLAG(CF_Synced),
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
                 CR_IGNORED(smokeTrail)))

CMissileProjectile::CMissileProjectile(const ProjectileParams& params)
  : CWeaponProjectile(params)
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
    std::cout << _FUNCTION_ << std::endl;
}

void
CMissileProjectile::Collision()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CMissileProjectile::Collision(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CMissileProjectile::Collision(CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CMissileProjectile::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CMissileProjectile::UpdateWobble()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CMissileProjectile::UpdateDance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CMissileProjectile::UpdateGroundBounce()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CMissileProjectile::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CMissileProjectile::ShieldRepulse(const float3& shieldPos,
                                  float shieldForce,
                                  float shieldMaxSpeed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CMissileProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
