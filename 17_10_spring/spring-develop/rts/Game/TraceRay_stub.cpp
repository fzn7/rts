#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "TraceRay.h"
#include "Camera.h"
#include "GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Rendering/GlobalRendering.h"
#include "Sim/Features/Feature.h"
#include "Sim/Misc/CollisionHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/GeometricObjects.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitTypes/Factory.h"
#include "Sim/Weapons/PlasmaRepulser.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/myMath.h"

#include <algorithm>
#include <vector>

//////////////////////////////////////////////////////////////////////
// Local/Helper functions
//////////////////////////////////////////////////////////////////////

/**
 * helper for TestCone
 * @return true if object <o> is in the firing cone, false otherwise
 */
inline static bool
TestConeHelper(const float3& pos3D,
               const float3& dir3D,
               const float length,
               const float spread,
               const CSolidObject* obj)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * helper for TestTrajectoryCone
 * @return true if object <o> is in the firing trajectory, false otherwise
 */
inline static bool
TestTrajectoryConeHelper(const float3& pos3D,
                         const float3& dir2D,
                         float length,
                         float linear,
                         float quadratic,
                         float spread,
                         float baseSize,
                         const CSolidObject* obj)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

//////////////////////////////////////////////////////////////////////
// Raytracing
//////////////////////////////////////////////////////////////////////

namespace TraceRay {

// called by {CRifle, CBeamLaser, CLightningCannon}::Fire(),
// CWeapon::HaveFreeLineOfFire(), and Skirmish AIs
float
TraceRay(const float3& start,
         const float3& dir,
         float length,
         int avoidFlags,
         const CUnit* owner,
         CUnit*& hitUnit,
         CFeature*& hitFeature,
         CollisionQuery* hitColQuery)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TraceRayShields(const CWeapon* emitter,
                const float3& start,
                const float3& dir,
                float length,
                std::vector<SShieldDist>& hitShields)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
GuiTraceRay(const float3& start,
            const float3& dir,
            const float length,
            const CUnit* exclude,
            const CUnit*& hitUnit,
            const CFeature*& hitFeature,
            bool useRadar,
            bool groundOnly,
            bool ignoreWater)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
TestCone(const float3& from,
         const float3& dir,
         float length,
         float spread,
         int allyteam,
         int avoidFlags,
         CUnit* owner)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
TestTrajectoryCone(const float3& from,
                   const float3& dir,
                   float length,
                   float linear,
                   float quadratic,
                   float spread,
                   int allyteam,
                   int avoidFlags,
                   CUnit* owner)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

} // namespace TraceRay
