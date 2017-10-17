#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "StarburstProjectile.h"
#include "Game/Camera.h"
#include "Game/GameHelper.h"
#include "Map/Ground.h"
#include "Rendering/Env/Particles/Classes/SmokeTrailProjectile.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/Unit.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/Color.h"
#include "System/Matrix44f.h"
#include "System/Sync/SyncTracer.h"
#include "System/myMath.h"

// the smokes life-time in frames
static const float SMOKE_TIME = 70.0f;

static const float TRACER_PARTS_STEP = 2.0f;
static const unsigned int MAX_NUM_AGEMODS = 32;

CR_BIND(CStarburstProjectile::TracerPart, )
CR_REG_METADATA_SUB(CStarburstProjectile,
                    TracerPart,
                    (CR_MEMBER(pos),
                     CR_MEMBER(dir),
                     CR_MEMBER(speedf),
                     CR_MEMBER(ageMods),
                     CR_MEMBER(numAgeMods)))

CR_BIND_DERIVED(CStarburstProjectile, CWeaponProjectile, )
CR_REG_METADATA(CStarburstProjectile,
                (CR_SETFLAG(CF_Synced),
                 CR_MEMBER(tracking),
                 CR_MEMBER(ignoreError),
                 CR_MEMBER(maxGoodDif),
                 CR_MEMBER(maxSpeed),
                 CR_MEMBER(acceleration),
                 CR_MEMBER(uptime),
                 CR_MEMBER(age),
                 CR_MEMBER(oldSmoke),
                 CR_MEMBER(oldSmokeDir),
                 CR_MEMBER(numParts),
                 CR_MEMBER(doturn),
                 CR_MEMBER(smokeTrail),
                 CR_MEMBER(missileAge),
                 CR_MEMBER(distanceToTravel),
                 CR_MEMBER(aimError),
                 CR_MEMBER(curTracerPart),
                 CR_MEMBER(tracerParts)))

CStarburstProjectile::CStarburstProjectile(const ProjectileParams& params)
  : CWeaponProjectile(params)
  , aimError(params.error)
  , tracking(params.tracking)
  , ignoreError(false)
  , doturn(true)
  , maxGoodDif(0.0f)
  , maxSpeed(0.0f)
  , acceleration(0.f)
  , distanceToTravel(params.maxRange)

  , uptime(params.upTime)
  , age(0)

  , oldSmoke(pos)
  , smokeTrail(nullptr)

  , numParts(0)
  , missileAge(0)
  , curTracerPart(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStarburstProjectile::Collision()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStarburstProjectile::Collision(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStarburstProjectile::Collision(CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStarburstProjectile::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStarburstProjectile::UpdateTrajectory()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStarburstProjectile::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CStarburstProjectile::ShieldRepulse(const float3& shieldPos,
                                    float shieldForce,
                                    float shieldMaxSpeed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CStarburstProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
