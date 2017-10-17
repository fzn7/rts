#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GeoSquareProjectile.h"
#include "Game/Camera.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/TextureAtlas.h"

CR_BIND_DERIVED(CGeoSquareProjectile, CProjectile, )

CR_REG_METADATA(CGeoSquareProjectile,
                (CR_MEMBER(p1),
                 CR_MEMBER(p2),
                 CR_MEMBER(v1),
                 CR_MEMBER(v2),
                 CR_MEMBER(w1),
                 CR_MEMBER(w2),
                 CR_MEMBER(r),
                 CR_MEMBER(g),
                 CR_MEMBER(b),
                 CR_MEMBER(a)))

CGeoSquareProjectile::CGeoSquareProjectile(const float3& p1,
                                           const float3& p2,
                                           const float3& v1,
                                           const float3& v2,
                                           float w1,
                                           float w2)
  : CProjectile((p1 + p2) * 0.5f, ZeroVector, NULL, false, false, false)
  , p1(p1)
  , p2(p2)
  , v1(v1)
  , v2(v2)
  , w1(w1)
  , w2(w2)
  , r(0.5f)
  , g(1.0f)
  , b(0.5f)
  , a(0.5f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CGeoSquareProjectile::~CGeoSquareProjectile() {}

void
CGeoSquareProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGeoSquareProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int CGeoSquareProjectile::GetProjectilesCount() const
{
	return 1;
}
