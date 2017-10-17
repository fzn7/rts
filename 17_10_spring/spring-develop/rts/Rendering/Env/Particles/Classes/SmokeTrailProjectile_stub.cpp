#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SmokeTrailProjectile.h"

#include "Game/Camera.h"
#include "Map/Ground.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "System/myMath.h"

CR_BIND_DERIVED(CSmokeTrailProjectile, CProjectile, )

CR_REG_METADATA(CSmokeTrailProjectile,
                (CR_MEMBER(pos1),
                 CR_MEMBER(pos2),
                 CR_MEMBER(orgSize),
                 CR_MEMBER(creationTime),
                 CR_MEMBER(lifeTime),
                 CR_MEMBER(color),
                 CR_MEMBER(dir1),
                 CR_MEMBER(dir2),
                 CR_MEMBER(dirpos1),
                 CR_MEMBER(dirpos2),
                 CR_MEMBER(midpos),
                 CR_MEMBER(middir),
                 CR_MEMBER(drawSegmented),
                 CR_MEMBER(firstSegment),
                 CR_MEMBER(lastSegment),
                 CR_MEMBER(texture)))

CSmokeTrailProjectile::CSmokeTrailProjectile(const CUnit* owner,
                                             const float3& pos1,
                                             const float3& pos2,
                                             const float3& dir1,
                                             const float3& dir2,
                                             bool firstSegment,
                                             bool lastSegment,
                                             float size,
                                             int time,
                                             float color,
                                             AtlasedTexture* texture)
  : CProjectile((pos1 + pos2) * 0.5f, ZeroVector, owner, false, false, false)
  ,

  pos1(pos1)
  , pos2(pos2)
  , orgSize(size)
  , creationTime(gs->frameNum)
  , lifeTime(time)
  , color(color)
  , dir1(dir1)
  , dir2(dir2)
  , drawSegmented(false)
  , firstSegment(firstSegment)
  , lastSegment(lastSegment)
  , texture(texture == NULL ? projectileDrawer->smoketrailtex : texture)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSmokeTrailProjectile::UpdateEndPos(const float3 pos, const float3 dir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSmokeTrailProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSmokeTrailProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CSmokeTrailProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
