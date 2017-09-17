#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "StrafeAirMoveType.h"
#include "Game/Players/Player.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/Env/Particles/Classes/SmokeProjectile.h"
#include "Sim/Misc/GeometricObjects.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/SmoothHeightMesh.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/Scripts/UnitScript.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Weapons/Weapon.h"
#include "System/Sync/HsiehHash.h"
#include "System/myMath.h"

CR_BIND_DERIVED(CStrafeAirMoveType, AAirMoveType, (nullptr))

CR_REG_METADATA(CStrafeAirMoveType,
                (CR_MEMBER(maneuverState),
                 CR_MEMBER(maneuverSubState),

                 CR_MEMBER(loopbackAttack),
                 CR_MEMBER(isFighter),

                 CR_MEMBER(wingDrag),
                 CR_MEMBER(wingAngle),
                 CR_MEMBER(invDrag),
                 CR_MEMBER(crashDrag),
                 CR_MEMBER(frontToSpeed),
                 CR_MEMBER(speedToFront),
                 CR_MEMBER(myGravity),

                 CR_MEMBER(maxBank),
                 CR_MEMBER(maxPitch),
                 CR_MEMBER(turnRadius),

                 CR_MEMBER(maxAileron),
                 CR_MEMBER(maxElevator),
                 CR_MEMBER(maxRudder),
                 CR_MEMBER(attackSafetyDistance),

                 CR_MEMBER(crashAileron),
                 CR_MEMBER(crashElevator),
                 CR_MEMBER(crashRudder),

                 CR_MEMBER(lastRudderPos),
                 CR_MEMBER(lastElevatorPos),
                 CR_MEMBER(lastAileronPos)))

static float
TurnRadius(const float rawRadius, const float rawSpeed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static float
GetAileronDeflection(const CUnit* owner,
                     const CUnit* collidee,
                     const float3& pos,
                     const float4& spd,
                     const SyncedFloat3& rightdir,
                     const SyncedFloat3& updir,
                     const SyncedFloat3& frontdir,
                     const float3& goalDir,
                     float groundHeight,
                     float wantedHeight,
                     float maxAileron,
                     float maxBank,
                     float goalDotRight,
                     float aGoalDotFront,
                     bool avoidCollision,
                     bool attacking)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static float
GetRudderDeflection(const CUnit* owner,
                    const CUnit* collidee,
                    const float3& pos,
                    const float4& spd,
                    const SyncedFloat3& rightdir,
                    const SyncedFloat3& updir,
                    const SyncedFloat3& frontdir,
                    const float3& goalDir,
                    float groundHeight,
                    float wantedHeight,
                    float maxRudder,
                    float,
                    float goalDotRight,
                    float aGoalDotFront,
                    bool avoidCollision,
                    bool attacking)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static float
GetElevatorDeflection(const CUnit* owner,
                      const CUnit* collidee,
                      const float3& pos,
                      const float4& spd,
                      const SyncedFloat3& rightdir,
                      const SyncedFloat3& updir,
                      const SyncedFloat3& frontdir,
                      const float3& goalDir,
                      float groundHeight,
                      float wantedHeight,
                      float maxElevator,
                      float maxPitch,
                      float goalDotRight,
                      float aGoalDotFront,
                      bool avoidCollision,
                      bool attacking)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
SelectLoopBackManeuver(const SyncedFloat3& frontdir,
                       const SyncedFloat3& rightdir,
                       const float4& spd,
                       float turnRadius,
                       float groundDist)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CStrafeAirMoveType::CStrafeAirMoveType(CUnit* owner)
  : AAirMoveType(owner)
  , maneuverState(MANEUVER_FLY_STRAIGHT)
  , maneuverSubState(0)
  , loopbackAttack(false)
  , isFighter(false)
  , wingDrag(0.07f)
  , wingAngle(0.1f)
  , invDrag(0.995f)
  , crashDrag(0.995f)
  , frontToSpeed(0.04f)
  , speedToFront(0.01f)
  , myGravity(0.8f)
  , maxBank(0.55f)
  , maxPitch(0.35f)
  , turnRadius(150)
  , maxAileron(0.04f)
  , maxElevator(0.02f)
  , maxRudder(0.01f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CStrafeAirMoveType::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CStrafeAirMoveType::HandleCollisions(bool checkCollisions)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStrafeAirMoveType::SlowUpdate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStrafeAirMoveType::UpdateManeuver()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStrafeAirMoveType::UpdateAttack()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CStrafeAirMoveType::UpdateFlying(float wantedHeight, float engine)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static float
GetVTOLAccelerationSign(float h, float wh, float speedy, bool ascending)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStrafeAirMoveType::UpdateTakeOff()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStrafeAirMoveType::UpdateLanding()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStrafeAirMoveType::UpdateAirPhysics(float rudder,
                                     float aileron,
                                     float elevator,
                                     float engine,
                                     const float3& engineThrustVector)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStrafeAirMoveType::SetState(AAirMoveType::AircraftState newState)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CStrafeAirMoveType::FindLandingPos()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CStrafeAirMoveType::BrakingDistance(float speed, float rate) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStrafeAirMoveType::SetMaxSpeed(float speed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStrafeAirMoveType::StartMoving(float3 gpos, float goalRadius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStrafeAirMoveType::StartMoving(float3 pos, float goalRadius, float speed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStrafeAirMoveType::StopMoving(bool callScript, bool hardStop)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CStrafeAirMoveType::Takeoff()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CStrafeAirMoveType::SetMemberValue(unsigned int memberHash, void* memberValue)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
