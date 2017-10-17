#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SimpleParticleSystem.h"

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "GenericParticleProjectile.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/ColorMap.h"
#include "Sim/Projectiles/ExpGenSpawnableMemberInfo.h"
#include "System/Log/ILog.h"
#include "System/float3.h"

CR_BIND_DERIVED(CSimpleParticleSystem, CProjectile, )

CR_REG_METADATA(CSimpleParticleSystem,
                (CR_MEMBER_BEGINFLAG(CM_Config),
                 CR_MEMBER(emitVector),
                 CR_MEMBER(emitMul),
                 CR_MEMBER(gravity),
                 CR_MEMBER(colorMap),
                 CR_MEMBER(texture),
                 CR_MEMBER(airdrag),
                 CR_MEMBER(particleLife),
                 CR_MEMBER(particleLifeSpread),
                 CR_MEMBER(numParticles),
                 CR_MEMBER(particleSpeed),
                 CR_MEMBER(particleSpeedSpread),
                 CR_MEMBER(particleSize),
                 CR_MEMBER(particleSizeSpread),
                 CR_MEMBER(emitRot),
                 CR_MEMBER(emitRotSpread),
                 CR_MEMBER(directional),
                 CR_MEMBER(sizeGrowth),
                 CR_MEMBER(sizeMod),
                 CR_MEMBER_ENDFLAG(CM_Config),
                 CR_MEMBER(particles)))

CR_BIND(CSimpleParticleSystem::Particle, )

CR_REG_METADATA_SUB(CSimpleParticleSystem,
                    Particle,
                    (CR_MEMBER(pos),
                     CR_MEMBER(life),
                     CR_MEMBER(speed),
                     CR_MEMBER(decayrate),
                     CR_MEMBER(size),
                     CR_MEMBER(sizeGrowth),
                     CR_MEMBER(sizeMod)))

CSimpleParticleSystem::CSimpleParticleSystem()
  : CProjectile()
  , emitVector(ZeroVector)
  , emitMul(1.0f, 1.0f, 1.0f)
  , gravity(ZeroVector)
  , particleSpeed(0.0f)
  , particleSpeedSpread(0.0f)
  , emitRot(0.0f)
  , emitRotSpread(0.0f)
  , texture(NULL)
  , colorMap(NULL)
  , directional(false)
  , particleLife(0.0f)
  , particleLifeSpread(0.0f)
  , particleSize(0.0f)
  , particleSizeSpread(0.0f)
  , airdrag(0.0f)
  , sizeGrowth(0.0f)
  , sizeMod(0.0f)
  , numParticles(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSimpleParticleSystem::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSimpleParticleSystem::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSimpleParticleSystem::Init(const CUnit* owner, const float3& offset)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CSimpleParticleSystem::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CSimpleParticleSystem::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CR_BIND_DERIVED(CSphereParticleSpawner, CSimpleParticleSystem, )

CR_REG_METADATA(CSphereParticleSpawner, )

void
CSphereParticleSpawner::Init(const CUnit* owner, const float3& offset)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CSphereParticleSpawner::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
