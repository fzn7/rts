#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GameHelper.h"

#include "Camera.h"
#include "Game/GlobalUnsynced.h"
#include "GameSetup.h"
#include "Lua/LuaUI.h"
#include "Map/Ground.h"
#include "Map/MapDamage.h"
#include "Map/ReadMap.h"
#include "Rendering/Models/3DModel.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Misc/BuildingMaskMap.h"
#include "Sim/Misc/CollisionHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/DamageArray.h"
#include "Sim/Misc/GeometricObjects.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/MoveTypes/MoveMath/MoveMath.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ExplosionListener.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/CommandAI/MobileCAI.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitTypes/Factory.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/EventHandler.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Sync/SyncTracer.h"
#include "System/myMath.h"

#define NUM_WAITING_DAMAGE_LISTS 128

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGameHelper* helper;

CGameHelper::CGameHelper()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CGameHelper::~CGameHelper()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////
// Explosions/Damage
//////////////////////////////////////////////////////////////////////

float
CGameHelper::CalcImpulseScale(const DamageArray& damages,
                              const float expDistanceMod)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGameHelper::DoExplosionDamage(CUnit* unit,
                               CUnit* owner,
                               const float3& expPos,
                               const float expRadius,
                               const float expSpeed,
                               const float expEdgeEffect,
                               const bool ignoreOwner,
                               const DamageArray& damages,
                               const int weaponDefID,
                               const int projectileID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGameHelper::DoExplosionDamage(CFeature* feature,
                               CUnit* owner,
                               const float3& expPos,
                               const float expRadius,
                               const float expEdgeEffect,
                               const DamageArray& damages,
                               const int weaponDefID,
                               const int projectileID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGameHelper::DamageObjectsInExplosionRadius(const CExplosionParams& params,
                                            const float expRad,
                                            const int weaponDefID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGameHelper::Explosion(const CExplosionParams& params)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////
// Spatial unit queries
//////////////////////////////////////////////////////////////////////

/**
 * @brief Generic spatial unit query.
 *
 * Filter should implement two methods:
 *  - bool Team(int allyTeam): returns true if this allyteam should be
 * considered
 *  - bool Unit(const CUnit*): returns true if the unit should be returned
 *
 * Query should implement three methods:
 *  - float3 GetPos(): returns the center of the (circular) search area
 *  - float GetRadius(): returns the radius of the search area
 *  - void AddUnit(const CUnit*): add the unit to the result
 *
 * The area as returned by Query is approximate; exact circular filtering
 * should be implemented in the Query object if desired.
 * (It isn't necessary for e.g. GetClosest** methods.)
 */
template<typename TFilter, typename TQuery>
static inline void
QueryUnits(TFilter filter, TQuery& query)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

namespace {
namespace Filter {

/**
 * Base class for Filter::Friendly and Filter::Enemy.
 */
struct Base
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CUnit*
CGameHelper::GetClosestUnit(const float3& pos, float searchRadius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CUnit*
CGameHelper::GetClosestEnemyUnit(const CUnit* excludeUnit,
                                 const float3& pos,
                                 float searchRadius,
                                 int searchAllyteam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CUnit*
CGameHelper::GetClosestValidTarget(const float3& pos,
                                   float searchRadius,
                                   int searchAllyteam,
                                   const CMobileCAI* cai)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CUnit*
CGameHelper::GetClosestEnemyUnitNoLosTest(const CUnit* excludeUnit,
                                          const float3& pos,
                                          float searchRadius,
                                          int searchAllyteam,
                                          bool sphere,
                                          bool canBeBlind)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CUnit*
CGameHelper::GetClosestFriendlyUnit(const CUnit* excludeUnit,
                                    const float3& pos,
                                    float searchRadius,
                                    int searchAllyteam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CUnit*
CGameHelper::GetClosestEnemyAircraft(const CUnit* excludeUnit,
                                     const float3& pos,
                                     float searchRadius,
                                     int searchAllyteam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGameHelper::GetEnemyUnits(const float3& pos,
                           float searchRadius,
                           int searchAllyteam,
                           vector<int>& found)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGameHelper::GetEnemyUnitsNoLosTest(const float3& pos,
                                    float searchRadius,
                                    int searchAllyteam,
                                    vector<int>& found)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////
// Miscellaneous (i.e. not yet categorized)
//////////////////////////////////////////////////////////////////////

void
CGameHelper::BuggerOff(float3 pos,
                       float radius,
                       bool spherical,
                       bool forced,
                       int teamId,
                       CUnit* excludeUnit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CGameHelper::Pos2BuildPos(const BuildInfo& buildInfo, bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

struct SearchOffset
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
static const vector<SearchOffset>&
GetSearchOffsetTable(int radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//! only used by the AI callback of the same name
float3
CGameHelper::ClosestBuildSite(int team,
                              const UnitDef* unitDef,
                              float3 pos,
                              float searchRadius,
                              int minDist,
                              int facing)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// find the reference height for a build-position
// against which to compare all footprint squares
float
CGameHelper::GetBuildHeight(const float3& pos,
                            const UnitDef* unitdef,
                            bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CGameHelper::BuildSquareStatus
CGameHelper::TestUnitBuildSquare(const BuildInfo& buildInfo,
                                 CFeature*& feature,
                                 int allyteam,
                                 bool synced,
                                 std::vector<float3>* canbuildpos,
                                 std::vector<float3>* featurepos,
                                 std::vector<float3>* nobuildpos,
                                 const std::vector<Command>* commands)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CGameHelper::BuildSquareStatus
CGameHelper::TestBuildSquare(const float3& pos,
                             const int2& xrange,
                             const int2& zrange,
                             const UnitDef* unitDef,
                             const MoveDef* moveDef,
                             CFeature*& feature,
                             int allyteam,
                             boost::uint16_t mask,
                             bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Returns a build Command that intersects the ray described by pos and dir from
 * the command queues of the units 'units' on team number 'team'.
 * @brief returns a build Command that intersects the ray described by pos and
 * dir
 * @return the build Command, or a Command with id 0 if none is found
 */
Command
CGameHelper::GetBuildCommand(const float3& pos, const float3& dir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGameHelper::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
