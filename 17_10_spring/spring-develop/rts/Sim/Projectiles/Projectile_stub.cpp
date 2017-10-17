#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Projectile.h"
#include "Map/MapInfo.h"
#include "Rendering/Colors.h"
#include "Rendering/GL/VertexArray.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/ExpGenSpawnableMemberInfo.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "System/Matrix44f.h"

CR_BIND_DERIVED_INTERFACE(CProjectile, CExpGenSpawnable)

CR_REG_METADATA(
  CProjectile,
  (CR_MEMBER(synced),
   CR_MEMBER(weapon),
   CR_MEMBER(piece),
   CR_MEMBER(hitscan),

   CR_MEMBER(luaMoveCtrl),
   CR_MEMBER(checkCol),
   CR_MEMBER(ignoreWater),
   CR_MEMBER(deleteMe),
   CR_IGNORED(callEvent), // we want the render event called for all projectiles

   CR_MEMBER(castShadow),
   CR_MEMBER(drawSorted),

   CR_MEMBER_BEGINFLAG(CM_Config),
   CR_MEMBER(dir),
   CR_MEMBER_ENDFLAG(CM_Config),
   CR_MEMBER(drawPos),

   CR_MEMBER(mygravity),
   CR_IGNORED(sortDist),
   CR_MEMBER(sortDistOffset),
   CR_MEMBER(tempNum),

   CR_MEMBER(ownerID),
   CR_MEMBER(teamID),
   CR_MEMBER(allyteamID),
   CR_MEMBER(cegID),

   CR_MEMBER(projectileType),
   CR_MEMBER(collisionFlags),

   CR_MEMBER(quads)))

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
bool CProjectile::inArray = false;
CVertexArray* CProjectile::va = NULL;

CProjectile::CProjectile()
  : synced(false)
  , weapon(false)
  , piece(false)
  , hitscan(false)

  , luaMoveCtrl(false)
  , checkCol(true)
  , ignoreWater(false)
  , deleteMe(false)
  , callEvent(true)
  , castShadow(false)
  , drawSorted(true)

  , mygravity(mapInfo ? mapInfo->map.gravity : 0.0f)
  , sortDist(0.0f)
  , sortDistOffset(0.0f)
  , tempNum(0)

  , ownerID(-1u)
  , teamID(-1u)
  , allyteamID(-1)
  , cegID(-1u)

  , projectileType(-1u)
  , collisionFlags(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CProjectile::~CProjectile()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CProjectile::Init(const CUnit* owner, const float3& offset)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CProjectile::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CProjectile::Delete()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CProjectile::DrawOnMinimap(CVertexArray& lines, CVertexArray& points)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CProjectile::DrawArray()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CUnit*
CProjectile::owner() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CMatrix44f
CProjectile::GetTransformMatrix(bool offsetPos) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CProjectile::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
