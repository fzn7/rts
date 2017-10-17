#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AirCAI.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/MoveTypes/StrafeAirMoveType.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/myMath.h"

#include <cassert>
#define AUTO_GENERATE_ATTACK_ORDERS 1

// AirCAI is always assigned to StrafeAirMoveType aircraft
static CStrafeAirMoveType*
GetStrafeAirMoveType(const CUnit* owner)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CR_BIND_DERIVED(CAirCAI, CMobileCAI, )
CR_REG_METADATA(CAirCAI,
                (CR_MEMBER(basePos),
                 CR_MEMBER(baseDir),

                 CR_MEMBER(activeCommand),
                 CR_MEMBER(targetAge),

                 CR_MEMBER(lastPC1),
                 CR_MEMBER(lastPC2)))

CAirCAI::CAirCAI()
  : CMobileCAI()
  , activeCommand(0)
  , targetAge(0)
  , lastPC1(-1)
  , lastPC2(-1)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAirCAI::GiveCommandReal(const Command& c, bool fromSynced)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAirCAI::SlowUpdate()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CAirCAI::AirAutoGenerateTarget(AAirMoveType* myPlane)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAirCAI::ExecuteMove(Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAirCAI::ExecuteFight(Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAirCAI::ExecuteAttack(Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAirCAI::ExecuteAreaAttack(Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAirCAI::ExecuteGuard(Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CAirCAI::GetDefaultCmd(const CUnit* pointed, const CFeature* feature)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CAirCAI::IsValidTarget(const CUnit* enemy) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAirCAI::FinishCommand()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAirCAI::BuggerOff(const float3& pos, float radius)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CAirCAI::SelectNewAreaAttackTargetOrPos(const Command& ac)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
