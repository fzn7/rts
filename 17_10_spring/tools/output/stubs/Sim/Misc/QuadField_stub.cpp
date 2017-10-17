#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <algorithm>

#include "Map/ReadMap.h"
#include "QuadField.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"

#ifndef UNIT_TEST
#include "Sim/Features/Feature.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Units/Unit.h"
#include "Sim/Weapons/PlasmaRepulser.h"
#endif

#include "System/Util.h"

CR_BIND(CQuadField, (int2(1, 1), 1))
CR_REG_METADATA(CQuadField,
                (CR_MEMBER(baseQuads),
                 CR_MEMBER(numQuadsX),
                 CR_MEMBER(numQuadsZ),
                 CR_MEMBER(quadSizeX),
                 CR_MEMBER(quadSizeZ),

                 CR_IGNORED(tempUnits),
                 CR_IGNORED(tempFeatures),
                 CR_IGNORED(tempProjectiles),
                 CR_IGNORED(tempSolids),
                 CR_IGNORED(tempQuads)))

CR_BIND(CQuadField::Quad, )
CR_REG_METADATA_SUB(CQuadField,
                    Quad,
                    (CR_MEMBER(units),
                     CR_IGNORED(teamUnits),
                     CR_MEMBER(features),
                     CR_MEMBER(projectiles),
                     CR_MEMBER(repulsers),

                     CR_POSTLOAD(PostLoad)))

CQuadField* quadField = NULL;

#ifndef UNIT_TEST
/*
void CQuadField::Resize(int quad_size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
*/
#endif

CQuadField::Quad::Quad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CQuadField::Quad::PostLoad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CQuadField::CQuadField(int2 mapDims, int quad_size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CQuadField::~CQuadField() {}

int2
CQuadField::WorldPosToQuadField(const float3 p) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CQuadField::WorldPosToQuadFieldIdx(const float3 p) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifndef UNIT_TEST
const std::vector<int>&
CQuadField::GetQuads(float3 pos, float radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<int>&
CQuadField::GetQuadsRectangle(const float3& mins, const float3& maxs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif // UNIT_TEST

/// note: this function got an UnitTest, check the tests/ folder!
const std::vector<int>&
CQuadField::GetQuadsOnRay(const float3& start, const float3& dir, float length)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifndef UNIT_TEST
void
CQuadField::MovedUnit(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CQuadField::RemoveUnit(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CQuadField::MovedRepulser(CPlasmaRepulser* repulser)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CQuadField::RemoveRepulser(CPlasmaRepulser* repulser)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CQuadField::AddFeature(CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CQuadField::RemoveFeature(CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CQuadField::MovedProjectile(CProjectile* p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CQuadField::AddProjectile(CProjectile* p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CQuadField::RemoveProjectile(CProjectile* p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<CUnit*>&
CQuadField::GetUnits(const float3& pos, float radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<CUnit*>&
CQuadField::GetUnitsExact(const float3& pos, float radius, bool spherical)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<CUnit*>&
CQuadField::GetUnitsExact(const float3& mins, const float3& maxs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<CFeature*>&
CQuadField::GetFeaturesExact(const float3& pos, float radius, bool spherical)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<CFeature*>&
CQuadField::GetFeaturesExact(const float3& mins, const float3& maxs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<CProjectile*>&
CQuadField::GetProjectilesExact(const float3& pos, float radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<CProjectile*>&
CQuadField::GetProjectilesExact(const float3& mins, const float3& maxs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<CSolidObject*>&
CQuadField::GetSolidsExact(const float3& pos,
                           const float radius,
                           const unsigned int physicalStateBits,
                           const unsigned int collisionStateBits)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CQuadField::NoSolidsExact(const float3& pos,
                          const float radius,
                          const unsigned int physicalStateBits,
                          const unsigned int collisionStateBits)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// optimization specifically for projectile collisions
void
CQuadField::GetUnitsAndFeaturesColVol(const float3& pos,
                                      const float radius,
                                      std::vector<CUnit*>& units,
                                      std::vector<CFeature*>& features,
                                      std::vector<CPlasmaRepulser*>* repulsers)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif // UNIT_TEST
