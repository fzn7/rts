#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GroundMoveType.h"
#include "ExternalAI/EngineOutHandler.h"
#include "Game/Camera.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/SelectedUnitsHandler.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "MoveDefHandler.h"
#include "MoveMath/MoveMath.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/GeometricObjects.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Path/IPathController.hpp"
#include "Sim/Path/IPathManager.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/CommandAI/MobileCAI.h"
#include "Sim/Units/Scripts/CobInstance.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/EventHandler.h"
#include "System/FastMath.h"
#include "System/Log/ILog.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Sync/HsiehHash.h"
#include "System/Sync/SyncTracer.h"
#include "System/TimeProfiler.h"
#include "System/myMath.h"
#include "System/type2.h"

#if 1
#include "Rendering/IPathDrawer.h"
#define DEBUG_DRAWING_ENABLED                                                  \
    ((gs->cheatEnabled || gu->spectatingFullView) && pathDrawer->IsEnabled())
#else
#define DEBUG_DRAWING_ENABLED false
#endif

#define LOG_SECTION_GMT "GroundMoveType"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_GMT)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_GMT

// speeds near (MAX_UNIT_SPEED * 1e1) elmos / frame can be caused by explosion
// impulses CUnitHandler removes units with speeds > MAX_UNIT_SPEED as soon as
// they exit the map, so the assertion can be less strict
#define ASSERT_SANE_OWNER_SPEED(v)                                             \
    assert(v.SqLength() < (MAX_UNIT_SPEED * MAX_UNIT_SPEED * 1e2));

// magic number to reduce damage taken from collisions
// between a very heavy and a very light CSolidObject
#define COLLISION_DAMAGE_MULT 0.02f

#define MAX_IDLING_SLOWUPDATES 16
#define IGNORE_OBSTACLES 0
#define WAIT_FOR_PATH 1

#define UNIT_CMD_QUE_SIZE(u) (u->commandAI->commandQue.size())
// Not using IsMoveCommand on purpose, as the following is changing the
// effective goalRadius
#define UNIT_HAS_MOVE_CMD(u)                                                   \
    (u->commandAI->commandQue.empty() ||                                       \
     u->commandAI->commandQue[0].GetID() == CMD_MOVE ||                        \
     u->commandAI->commandQue[0].GetID() == CMD_FIGHT)

#define FOOTPRINT_RADIUS(xs, zs, s)                                            \
    ((math::sqrt((xs * xs + zs * zs)) * 0.5f * SQUARE_SIZE) * s)

CR_BIND_DERIVED(CGroundMoveType, AMoveType, (nullptr))
CR_REG_METADATA(CGroundMoveType,
                (CR_IGNORED(pathController),

                 CR_MEMBER(currWayPoint),
                 CR_MEMBER(nextWayPoint),

                 CR_MEMBER(waypointDir),
                 CR_MEMBER(flatFrontDir),
                 CR_MEMBER(lastAvoidanceDir),
                 CR_MEMBER(mainHeadingPos),
                 CR_MEMBER(skidRotVector),

                 CR_MEMBER(turnRate),
                 CR_MEMBER(turnSpeed),
                 CR_MEMBER(turnAccel),
                 CR_MEMBER(accRate),
                 CR_MEMBER(decRate),
                 CR_MEMBER(myGravity),

                 CR_MEMBER(maxReverseDist),
                 CR_MEMBER(minReverseAngle),
                 CR_MEMBER(maxReverseSpeed),

                 CR_MEMBER(wantedSpeed),
                 CR_MEMBER(currentSpeed),
                 CR_MEMBER(deltaSpeed),

                 CR_MEMBER(atGoal),
                 CR_MEMBER(atEndOfPath),
                 CR_MEMBER(wantRepath),

                 CR_MEMBER(currWayPointDist),
                 CR_MEMBER(prevWayPointDist),
                 CR_MEMBER(goalRadius),

                 CR_MEMBER(numIdlingUpdates),
                 CR_MEMBER(numIdlingSlowUpdates),
                 CR_MEMBER(wantedHeading),

                 CR_MEMBER(pathID),

                 CR_MEMBER(nextObstacleAvoidanceFrame),

                 CR_MEMBER(reversing),
                 CR_MEMBER(idling),
                 CR_MEMBER(canReverse),
                 CR_MEMBER(useMainHeading),
                 CR_MEMBER(useRawMovement),

                 CR_MEMBER(skidRotSpeed),
                 CR_MEMBER(skidRotAccel),

                 CR_POSTLOAD(PostLoad)))

CGroundMoveType::CGroundMoveType(CUnit* owner)
  : AMoveType(owner)
  , pathController((owner != nullptr) ? IPathController::GetInstance(owner)
                                      : nullptr)
  ,

  currWayPoint(ZeroVector)
  , nextWayPoint(ZeroVector)
  ,

  flatFrontDir(FwdVector)
  , lastAvoidanceDir(ZeroVector)
  , mainHeadingPos(ZeroVector)
  , skidRotVector(UpVector)
  ,

  turnRate(0.1f)
  , turnSpeed(0.0f)
  , turnAccel(0.0f)
  ,

  accRate(0.01f)
  , decRate(0.01f)
  , myGravity(0.0f)
  ,

  maxReverseDist(0.0f)
  , minReverseAngle(0.0f)
  , maxReverseSpeed(0.0f)
  ,

  wantedSpeed(0.0f)
  , currentSpeed(0.0f)
  , deltaSpeed(0.0f)
  ,

  atGoal(false)
  , atEndOfPath(false)
  , wantRepath(false)
  ,

  currWayPointDist(0.0f)
  , prevWayPointDist(0.0f)
  , goalRadius(0.0f)
  ,

  reversing(false)
  , idling(false)
  , canReverse((owner != nullptr) && (owner->unitDef->rSpeed > 0.0f))
  , useMainHeading(false)
  , useRawMovement(false)
  ,

  skidRotSpeed(0.0f)
  , skidRotAccel(0.0f)
  ,

  pathID(0)
  ,

  nextObstacleAvoidanceFrame(0)
  ,

  numIdlingUpdates(0)
  , numIdlingSlowUpdates(0)
  ,

  wantedHeading(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CGroundMoveType::~CGroundMoveType()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::PostLoad()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroundMoveType::OwnerMoved(const short oldHeading,
                            const float3& posDif,
                            const float3& cmpEps)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroundMoveType::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::UpdateOwnerSpeedAndHeading()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::SlowUpdate()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::StartMovingRaw(const float3 moveGoalPos, float moveGoalRadius)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::StartMoving(float3 moveGoalPos, float moveGoalRadius)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::StopMoving(bool callScript, bool hardStop)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroundMoveType::FollowPath()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::ChangeSpeed(float newWantedSpeed,
                             bool wantReverse,
                             bool fpsMode)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
 * Changes the heading of the owner.
 * FIXME near-duplicate of HoverAirMoveType::UpdateHeading
 */
void
CGroundMoveType::ChangeHeading(short newHeading)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroundMoveType::CanApplyImpulse(const float3& impulse)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::UpdateSkid()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::UpdateControlledDrop()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::CheckCollisionSkid()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::CalcSkidRot()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
 * Dynamic obstacle avoidance, helps the unit to
 * follow the path even when it's not perfect.
 */
float3
CGroundMoveType::GetObstacleAvoidanceDir(const float3& desiredDir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#if 0
// Calculates an aproximation of the physical 2D-distance between given two objects.
// Old, no longer used since all separation tests are based on FOOTPRINT_RADIUS now.
float CGroundMoveType::Distance2D(CSolidObject* object1, CSolidObject* object2, float marginal)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
#endif

// Creates a path to the goal.
unsigned int
CGroundMoveType::GetNewPath()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::ReRequestPath(bool forceRequest)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroundMoveType::CanGetNextWayPoint()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::GetNextWayPoint()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
Gives the position this unit will end up at with full braking
from current velocity.
*/
float3
CGroundMoveType::Here()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::StartEngine(bool callScript)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::StopEngine(bool callScript, bool hardStop)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/* Called when the unit arrives at its goal. */
void
CGroundMoveType::Arrived(bool callScript)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
Makes the unit fail this action.
No more trials will be done before a new goal is given.
*/
void
CGroundMoveType::Fail(bool callScript)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::HandleObjectCollisions()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::HandleStaticObjectCollision(CUnit* collider,
                                             CSolidObject* collidee,
                                             const MoveDef* colliderMD,
                                             const float colliderRadius,
                                             const float collideeRadius,
                                             const float3& separationVector,
                                             bool canRequestPath,
                                             bool checkYardMap,
                                             bool checkTerrain)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::HandleUnitCollisions(CUnit* collider,
                                      const float colliderSpeed,
                                      const float colliderRadius,
                                      const UnitDef* colliderUD,
                                      const MoveDef* colliderMD)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::HandleFeatureCollisions(CUnit* collider,
                                         const float colliderSpeed,
                                         const float colliderRadius,
                                         const UnitDef* colliderUD,
                                         const MoveDef* colliderMD)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::LeaveTransport()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::KeepPointingTo(float3 pos, float distance, bool aggressive)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::KeepPointingTo(CUnit* unit, float distance, bool aggressive)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief Orients owner so that weapon[0]'s arc includes mainHeadingPos
 */
void
CGroundMoveType::SetMainHeading()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroundMoveType::OnSlope(float minSlideTolerance)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const float3&
CGroundMoveType::GetGroundNormal(const float3& p) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CGroundMoveType::GetGroundHeight(const float3& p) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::AdjustPosToWaterLine()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroundMoveType::UpdateDirectControl()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CGroundMoveType::GetNewSpeedVector(const float hAcc, const float vAcc) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundMoveType::UpdateOwnerPos(const float3& oldSpeedVector,
                                const float3& newSpeedVector)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroundMoveType::WantReverse(const float3& wpDir, const float3& ffDir) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroundMoveType::SetMemberValue(unsigned int memberHash, void* memberValue)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
