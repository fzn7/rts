#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CollisionVolume.h"
#include "Rendering/Models/3DModel.h"
#include "Sim/Features/Feature.h"
#include "Sim/Units/Unit.h"
#include "System/Matrix44f.h"
#include "System/Util.h"
#include "System/myMath.h"

CR_BIND(CollisionVolume, )
CR_REG_METADATA(CollisionVolume,
                (CR_MEMBER(fullAxisScales),
                 CR_IGNORED(halfAxisScales),
                 CR_IGNORED(halfAxisScalesSqr),
                 CR_IGNORED(halfAxisScalesInv),
                 CR_MEMBER(axisOffsets),
                 CR_IGNORED(volumeBoundingRadius),
                 CR_IGNORED(volumeBoundingRadiusSq),
                 CR_MEMBER(volumeType),
                 CR_MEMBER(volumeAxes),
                 CR_MEMBER(ignoreHits),
                 CR_MEMBER(useContHitTest),
                 CR_MEMBER(defaultToFootPrint),
                 CR_MEMBER(defaultToPieceTree),

                 CR_POSTLOAD(PostLoad)))

// base ctor (CREG-only)
CollisionVolume::CollisionVolume()
  : fullAxisScales(OnesVector * 2.0f)
  , halfAxisScales(OnesVector)
  , halfAxisScalesSqr(OnesVector)
  , halfAxisScalesInv(OnesVector)
  , axisOffsets(ZeroVector)
  , volumeBoundingRadius(1.0f)
  , volumeBoundingRadiusSq(1.0f)
  , volumeType(COLVOL_TYPE_SPHERE)
  , ignoreHits(false)
  , useContHitTest(COLVOL_HITTEST_CONT)
  , defaultToFootPrint(false)
  , defaultToPieceTree(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CollisionVolume&
CollisionVolume::operator=(const CollisionVolume& v)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CollisionVolume::CollisionVolume(const std::string& cvTypeString,
                                 const float3& cvScales,
                                 const float3& cvOffsets)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CollisionVolume::PostLoad()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CollisionVolume::InitSphere(float radius)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CollisionVolume::InitBox(const float3& scales, const float3& offsets)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CollisionVolume::InitShape(const float3& scales,
                           const float3& offsets,
                           const int vType,
                           const int tType,
                           const int pAxis)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CollisionVolume::SetBoundingRadius()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CollisionVolume::SetAxisScales(const float3& scales)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CollisionVolume::RescaleAxes(const float3& scales)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CollisionVolume::FixTypeAndScale(float3& scales)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CollisionVolume::GetWorldSpacePos(const CSolidObject* o,
                                  const float3& extOffsets) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CollisionVolume::GetPointSurfaceDistance(const CUnit* u,
                                         const LocalModelPiece* lmp,
                                         const float3& pos) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CollisionVolume::GetPointSurfaceDistance(const CFeature* f,
                                         const LocalModelPiece* lmp,
                                         const float3& pos) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CollisionVolume::GetPointSurfaceDistance(const CSolidObject* obj,
                                         const LocalModelPiece* lmp,
                                         const CMatrix44f& mat,
                                         const float3& pos) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CollisionVolume::GetPointSurfaceDistance(const CMatrix44f& mv,
                                         const float3& p) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CollisionVolume::GetCylinderDistance(const float3& pv,
                                     size_t axisA,
                                     size_t axisB,
                                     size_t axisC) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#define MAX_ITERATIONS 10
#define THRESHOLD 0.001

// Newton's method according to
// http://wwwf.imperial.ac.uk/~rn/distance2ellipse.pdf
float
CollisionVolume::GetEllipsoidDistance(const float3& pv) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
