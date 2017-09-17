#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cassert>

#include "Map/Ground.h"
#include "MoveType.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "System/Sync/HsiehHash.h"
#include "System/myMath.h"

CR_BIND_DERIVED_INTERFACE(AMoveType, CObject)
CR_REG_METADATA(AMoveType,
                (CR_MEMBER(owner),
                 CR_MEMBER(goalPos),
                 CR_MEMBER(oldPos),
                 CR_MEMBER(oldSlowUpdatePos),

                 CR_MEMBER(maxSpeed),
                 CR_MEMBER(maxSpeedDef),
                 CR_MEMBER(maxWantedSpeed),
                 CR_MEMBER(maneuverLeash),

                 CR_MEMBER(useHeading),
                 CR_MEMBER(progressState)))

AMoveType::AMoveType(CUnit* owner)
  : owner(owner)
  ,

  goalPos(owner ? owner->pos : ZeroVector)
  , oldPos(owner ? owner->pos : ZeroVector)
  , oldSlowUpdatePos(oldPos)
  ,

  useHeading(true)
  ,

  progressState(Done)
  ,

  maxSpeed(owner ? owner->unitDef->speed / GAME_SPEED : 0.0f)
  , maxSpeedDef(owner ? owner->unitDef->speed / GAME_SPEED : 0.0f)
  , maxWantedSpeed(owner ? owner->unitDef->speed / GAME_SPEED : 0.0f)
  ,

  maneuverLeash(500.0f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
AMoveType::KeepPointingTo(CUnit* unit, float distance, bool aggressive)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
AMoveType::CalcStaticTurnRadius() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
AMoveType::SetMemberValue(unsigned int memberHash, void* memberValue)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
