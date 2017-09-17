#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "MobileCAI.h"
#include "ExternalAI/EngineOutHandler.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Map/Ground.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/MoveTypes/AAirMoveType.h"
#include "Sim/MoveTypes/HoverAirMoveType.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/Scripts/UnitScript.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include "System/Util.h"
#include <assert.h>

#define AUTO_GENERATE_ATTACK_ORDERS 1
#define BUGGER_OFF_TTL 200
#define MAX_CLOSE_IN_RETRY_TICKS 30
#define MAX_USERGOAL_TOLERANCE_DIST 100.0f

#define AIRTRANSPORT_DOCKING_RADIUS 16
#define AIRTRANSPORT_DOCKING_ANGLE 50
#define UNLOAD_LAND 0
#define UNLOAD_DROP 1
#define UNLOAD_LANDFLOOD 2

// MobileCAI is not always assigned to aircraft
static AAirMoveType* GetAirMoveType(const CUnit* owner) {
	assert(owner->unitDef->IsAirUnit());

	if (owner->UsingScriptMoveType()) {
		return static_cast<AAirMoveType*>(owner->prevMoveType);
	}

	return static_cast<AAirMoveType*>(owner->moveType);
}



CR_BIND_DERIVED(CMobileCAI ,CCommandAI , )
CR_REG_METADATA(CMobileCAI, (
	CR_MEMBER(lastBuggerGoalPos),
	CR_MEMBER(lastUserGoal),

	CR_MEMBER(lastIdleCheck),
	CR_MEMBER(tempOrder),

	CR_MEMBER(lastPC),

	CR_MEMBER(lastBuggerOffTime),
	CR_MEMBER(buggerOffPos),
	CR_MEMBER(buggerOffRadius),

	CR_MEMBER(repairBelowHealth),

	CR_MEMBER(commandPos1),
	CR_MEMBER(commandPos2),

	CR_MEMBER(lastCloseInTry),

	CR_MEMBER(cancelDistance),
	CR_MEMBER(slowGuard),
	CR_MEMBER(moveDir)
))

CMobileCAI::CMobileCAI():
	CCommandAI(),
	lastBuggerGoalPos(-1,0,-1),
	lastUserGoal(ZeroVector),
	lastIdleCheck(0),
	tempOrder(false),
	lastPC(-1),
	lastBuggerOffTime(-BUGGER_OFF_TTL),
	buggerOffPos(ZeroVector),
	buggerOffRadius(0),
	repairBelowHealth(0.0f),
	commandPos1(ZeroVector),
	commandPos2(ZeroVector),
	cancelDistance(1024),
	lastCloseInTry(-1),
	slowGuard(false),
	moveDir(gs->randFloat() > 0.5)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMobileCAI::~CMobileCAI()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMobileCAI::GiveCommandReal(const Command& c, bool fromSynced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMobileCAI::SlowUpdate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
* @brief Executes the first command in the commandQue
*/
void CMobileCAI::Execute()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
* @brief executes the set wanted max speed command
*/
void CMobileCAI::ExecuteSetWantedMaxSpeed(Command &c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
* @brief executes the move command
*/
void CMobileCAI::ExecuteMove(Command &c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMobileCAI::ExecuteLoadOnto(Command &c) {
	CUnit* unit = unitHandler->GetUnit(c.params[0]);

	if (unit == nullptr || !unit->unitDef->IsTransportUnit()) {
		StopMoveAndFinishCommand();
		return;
	}

	if (!inCommand) {
		inCommand = true;
		Command newCommand(CMD_LOAD_UNITS, INTERNAL_ORDER | SHIFT_KEY, owner->id);
		unit->commandAI->GiveCommandReal(newCommand);
	}
	if (owner->GetTransporter() != NULL) {
		if (!commandQue.empty())
			StopMoveAndFinishCommand();

		return;
	}

	if (unit == NULL)
		return;

	if ((owner->pos - unit->pos).SqLength2D() < cancelDistance) {
		StopMove();
	} else {
		SetGoal(unit->pos, owner->pos);
	}
}

/**
* @brief Executes the Patrol command c
*/
void CMobileCAI::ExecutePatrol(Command &c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
* @brief Executes the Fight command c
*/
void CMobileCAI::ExecuteFight(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CMobileCAI::IsValidTarget(const CUnit* enemy) const {
	if (!enemy)
		return false;

	if (enemy == owner)
		return false;

	if (owner->unitDef->noChaseCategory & enemy->category)
		return false;

	// don't _auto_ chase neutrals
	if (enemy->IsNeutral())
		return false;

	if (owner->weapons.empty())
		return false;

	// test if any weapon can target the enemy unit
	for (CWeapon* w: owner->weapons) {
		if (w->TestTarget(enemy->pos, SWeaponTarget(enemy)) &&
			(owner->moveState != MOVESTATE_HOLDPOS || w->TryTargetRotate(enemy, false, false))) {
			return true;
		}
	}

	return false;
}

/**
* @brief Executes the guard command c
*/
void CMobileCAI::ExecuteGuard(Command &c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMobileCAI::ExecuteStop(Command &c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CMobileCAI::ExecuteAttack(Command &c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}




int CMobileCAI::GetDefaultCmd(const CUnit* pointed, const CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMobileCAI::SetGoal(const float3& pos, const float3& /*curPos*/, float goalRadius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMobileCAI::SetGoal(const float3& pos, const float3& /*curPos*/, float goalRadius, float speed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CMobileCAI::SetFrontMoveCommandPos(const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMobileCAI::StopMove()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMobileCAI::StopMoveAndFinishCommand()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMobileCAI::StopMoveAndKeepPointing(const float3& p, const float r, bool b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMobileCAI::BuggerOff(const float3& pos, float radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMobileCAI::NonMoving()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMobileCAI::FinishCommand()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CMobileCAI::MobileAutoGenerateTarget()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CMobileCAI::GenerateAttackCmd()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CMobileCAI::CanWeaponAutoTarget(const CWeapon* weapon) const {
	return (!tempOrder) || //Check if the weapon actually targets the unit's order target
		weapon->GetCurrentTarget() != owner->curTarget;
}

void CMobileCAI::StopSlowGuard() {
	if (!slowGuard)
		return;

	slowGuard = false;

	// restore maxWantedSpeed to our current maxSpeed
	// (StartSlowGuard modifies maxWantedSpeed, so we
	// do not know its old value here)
	owner->moveType->SetWantedMaxSpeed(owner->moveType->GetMaxSpeed());
}

void CMobileCAI::StartSlowGuard(float speed) {
	if (slowGuard)
		return;

	slowGuard = true;

	if (speed <= 0.0f) { return; }
	if (commandQue.empty()) { return; }
	if (owner->moveType->GetMaxSpeed() < speed) { return; }

	const Command& c = (commandQue.size() > 1)? commandQue[1]: Command(CMD_STOP);

	// when guarding, temporarily adopt the maximum
	// (forward) speed of the guardee unit as our own
	// WANTED maximum
	if (c.GetID() == CMD_SET_WANTED_MAX_SPEED) {
		owner->moveType->SetWantedMaxSpeed(speed);
	}
}



void CMobileCAI::CalculateCancelDistance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/


void CMobileCAI::SetTransportee(CUnit* unit) {
	assert(unit == nullptr || owner->unitDef->IsTransportUnit());

	if (!owner->unitDef->IsTransportUnit()) {
		return;
	}

	if (orderTarget != nullptr && orderTarget->loadingTransportId == owner->id) {
		orderTarget->loadingTransportId = -1;
	}
	SetOrderTarget(unit);
	if (unit != nullptr) {
		CUnit* transport = (unit->loadingTransportId == -1) ? NULL : unitHandler->GetUnitUnsafe(unit->loadingTransportId);
		// let the closest transport be loadingTransportId, in case of multiple fighting transports
		if ((transport == NULL) || ((transport != owner) && (transport->pos.SqDistance(unit->pos) > owner->pos.SqDistance(unit->pos)))) {
			unit->loadingTransportId = owner->id;
		}
	}
}


void CMobileCAI::ExecuteLoadUnits(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMobileCAI::ExecuteUnloadUnits(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMobileCAI::ExecuteUnloadUnit(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CMobileCAI::AllowedCommand(const Command& c, bool fromSynced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CMobileCAI::FindEmptySpot(const float3& center, float radius, float spread, float3& found, const CUnit* unitToUnload, bool fromSynced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CUnit* CMobileCAI::FindUnitToTransport(float3 center, float radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CMobileCAI::LoadStillValid(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CMobileCAI::SpotIsClear(float3 pos, CUnit* unitToUnload)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CMobileCAI::SpotIsClearIgnoreSelf(float3 pos, CUnit* unitToUnload)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CMobileCAI::FindEmptyDropSpots(float3 startpos, float3 endpos, std::vector<float3>& dropSpots)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMobileCAI::UnloadUnits_Land(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMobileCAI::UnloadUnits_Drop(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMobileCAI::UnloadUnits_LandFlood(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMobileCAI::UnloadLand(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMobileCAI::UnloadDrop(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMobileCAI::UnloadLandFlood(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
