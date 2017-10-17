#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ShieldSegmentProjectile.h"
#include "Game/Camera.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Units/Unit.h"
#include "Sim/Weapons/PlasmaRepulser.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/EventHandler.h"
#include "System/myMath.h"

CR_BIND(ShieldSegmentCollection, )
CR_REG_METADATA(ShieldSegmentCollection,
                (CR_MEMBER(shield),
                 CR_IGNORED(shieldTexture),
                 CR_IGNORED(lastAllowDrawingframe),
                 CR_IGNORED(allowDrawing),
                 CR_MEMBER(shieldSegments),
                 CR_MEMBER(color),
                 CR_MEMBER(size),

                 CR_POSTLOAD(PostLoad)))

CR_BIND_DERIVED(ShieldSegmentProjectile, CProjectile, )
CR_REG_METADATA(ShieldSegmentProjectile,
                (CR_IGNORED(collection),
                 CR_IGNORED(vertices),
                 CR_IGNORED(texCoors)))

static std::vector<float3> spherevertices;
static std::map<const AtlasedTexture*, std::vector<float2>> spheretexcoords;

#define NUM_SEGMENTS_X 6
#define NUM_SEGMENTS_Y 4

ShieldSegmentCollection::ShieldSegmentCollection(CPlasmaRepulser* shield_)
  : shield(shield_)
  , shieldTexture(NULL)
  , lastAllowDrawingframe(-1)
  , allowDrawing(false)
  , size(shield->weaponDef->shieldRadius)
  , color(255, 255, 255, 0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
ShieldSegmentCollection::UsingPerlinNoise() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ShieldSegmentCollection::PostLoad()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

ShieldSegmentCollection::~ShieldSegmentCollection()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
ShieldSegmentCollection::AllowDrawing()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ShieldSegmentCollection::UpdateColor()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
ShieldSegmentCollection::GetShieldDrawPos() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#define NUM_VERTICES_X 5
#define NUM_VERTICES_Y 3

ShieldSegmentProjectile::ShieldSegmentProjectile(
  ShieldSegmentCollection* collection_,
  const WeaponDef* shieldWeaponDef,
  const float3& shieldSegmentPos,
  int xpart,
  int ypart)
  : CProjectile(shieldSegmentPos,
                ZeroVector,
                collection_->GetShield()->owner,
                false,
                false,
                false)
  , collection(collection_)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ShieldSegmentProjectile::Reload(ShieldSegmentCollection* collection_,
                                int xpart,
                                int ypart)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

ShieldSegmentProjectile::~ShieldSegmentProjectile() {}

void
ShieldSegmentProjectile::PreDelete()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const float3*
ShieldSegmentProjectile::GetSegmentVertices(const int xpart, const int ypart)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const float2*
ShieldSegmentProjectile::GetSegmentTexCoords(const AtlasedTexture* texture,
                                             const int xpart,
                                             const int ypart)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ShieldSegmentProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ShieldSegmentProjectile::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
ShieldSegmentProjectile::GetProjectilesCount() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
