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
#include "System/myMath.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#include <cassert>
#define AUTO_GENERATE_ATTACK_ORDERS 1

// AirCAI is always assigned to StrafeAirMoveType aircraft
static CStrafeAirMoveType* GetStrafeAirMoveType(const CUnit* owner) {
	assert(owner->unitDef->IsAirUnit());

	if (owner->UsingScriptMoveType()) {
		return static_cast<CStrafeAirMoveType*>(owner->prevMoveType);
	}

	return static_cast<CStrafeAirMoveType*>(owner->moveType);
}



CR_BIND_DERIVED(CAirCAI, CMobileCAI, )
CR_REG_METADATA(CAirCAI, (
	CR_MEMBER(basePos),
	CR_MEMBER(baseDir),

	CR_MEMBER(activeCommand),
	CR_MEMBER(targetAge),

	CR_MEMBER(lastPC1),
	CR_MEMBER(lastPC2)
))

CAirCAI::CAirCAI()
	: CMobileCAI()
	, activeCommand(0)
	, targetAge(0)
	, lastPC1(-1)
	, lastPC2(-1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CAirCAI::GiveCommandReal(const Command& c, bool fromSynced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CAirCAI::SlowUpdate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CAirCAI::AirAutoGenerateTarget(AAirMoveType* myPlane) {
	assert(commandQue.empty());
	assert(myPlane->owner == owner);

	const UnitDef* ownerDef = owner->unitDef;
	const bool autoLand = !ownerDef->DontLand() && myPlane->autoLand;
	const bool autoAttack = ((owner->fireState >= FIRESTATE_FIREATWILL) && (owner->moveState != MOVESTATE_HOLDPOS));

	if (myPlane->aircraftState == AAirMoveType::AIRCRAFT_FLYING && autoLand) {
		StopMove();
	}

	if (ownerDef->canAttack && autoAttack && owner->maxRange > 0) {
		if (ownerDef->IsFighterAirUnit()) {
			const float3 P = owner->pos + (owner->speed * 10.0);
			const float R = 1000.0f * owner->moveState;
			const CUnit* enemy = CGameHelper::GetClosestEnemyAircraft(NULL, P, R, owner->allyteam);

			if (IsValidTarget(enemy)) {
				Command nc(CMD_ATTACK, INTERNAL_ORDER, enemy->id);
				commandQue.push_front(nc);
				inCommand = false;
				return true;
			}
		} else {
			const float3 P = owner->pos + (owner->speed * 20.0f);
			const float R = 500.0f * owner->moveState;
			const CUnit* enemy = CGameHelper::GetClosestValidTarget(P, R, owner->allyteam, this);

			if (enemy != NULL) {
				Command nc(CMD_ATTACK, INTERNAL_ORDER, enemy->id);
				commandQue.push_front(nc);
				inCommand = false;
				return true;
			}
		}
	}

	return false;
}


void CAirCAI::ExecuteMove(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CAirCAI::ExecuteFight(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CAirCAI::ExecuteAttack(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CAirCAI::ExecuteAreaAttack(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CAirCAI::ExecuteGuard(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int CAirCAI::GetDefaultCmd(const CUnit* pointed, const CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CAirCAI::IsValidTarget(const CUnit* enemy) const {
	if (!CMobileCAI::IsValidTarget(enemy)) return false;
	if (enemy->IsCrashing()) return false;
	return (GetStrafeAirMoveType(owner)->isFighter || !enemy->unitDef->canfly);
}



void CAirCAI::FinishCommand()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CAirCAI::BuggerOff(const float3& pos, float radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CAirCAI::SelectNewAreaAttackTargetOrPos(const Command& ac)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

