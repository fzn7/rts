#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "WaitCommandsAI.h"
#include "SelectedUnitsHandler.h"
#include "GameHelper.h"
#include "GlobalUnsynced.h"
#include "UI/CommandColors.h"
#include "Rendering/LineDrawer.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/CommandAI/CommandQueue.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/CommandAI/FactoryCAI.h"
#include "Sim/Units/UnitTypes/Factory.h"
#include "System/Object.h"
#include "System/Util.h"
#include "System/creg/STL_Map.h"
#include "System/creg/STL_List.h"
#include "System/creg/STL_Set.h"
#include <assert.h>

CWaitCommandsAI waitCommandsAI;


static const int maxNetDelay = 30;  // in seconds

static const int updatePeriod = 3;  // in GAME_SPEED, 100 ms


CR_BIND(CWaitCommandsAI, )
CR_REG_METADATA(CWaitCommandsAI, (
	CR_MEMBER(waitMap),
	CR_MEMBER(unackedMap)
))

CR_BIND_DERIVED_INTERFACE(CWaitCommandsAI::Wait, CObject)
CR_REG_METADATA_SUB(CWaitCommandsAI,Wait, (
	CR_MEMBER(code),
	CR_MEMBER(key),
	CR_MEMBER(valid),
	CR_MEMBER(deadTime),
	CR_POSTLOAD(PostLoad)
))

CR_BIND_DERIVED(CWaitCommandsAI::TimeWait, CWaitCommandsAI::Wait, (1,0))
CR_REG_METADATA_SUB(CWaitCommandsAI,TimeWait , (
	CR_MEMBER(unit),
	CR_MEMBER(enabled),
	CR_MEMBER(duration),
	CR_MEMBER(endFrame),
	CR_MEMBER(factory)
))

CR_BIND_DERIVED(CWaitCommandsAI::DeathWait, CWaitCommandsAI::Wait, (Command()))
CR_REG_METADATA_SUB(CWaitCommandsAI,DeathWait , (
	CR_MEMBER(waitUnits),
	CR_MEMBER(deathUnits),
	CR_MEMBER(unitPos)
))

CR_BIND_DERIVED(CWaitCommandsAI::SquadWait, CWaitCommandsAI::Wait, (Command()))
CR_REG_METADATA_SUB(CWaitCommandsAI,SquadWait , (
	CR_MEMBER(squadCount),
	CR_MEMBER(buildUnits),
	CR_MEMBER(waitUnits),
	CR_MEMBER(stateText)
))

CR_BIND_DERIVED(CWaitCommandsAI::GatherWait, CWaitCommandsAI::Wait, (Command()))
CR_REG_METADATA_SUB(CWaitCommandsAI,GatherWait , (
	CR_MEMBER(waitUnits)
))

/******************************************************************************/
/******************************************************************************/

CWaitCommandsAI::CWaitCommandsAI()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CWaitCommandsAI::~CWaitCommandsAI()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::DrawCommands() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::AddTimeWait(const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::AddDeathWait(const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::AddSquadWait(const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::AddGatherWait(const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::AcknowledgeCommand(const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::AddLocalUnit(CUnit* unit, const CUnit* builder)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::RemoveWaitCommand(CUnit* unit, const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::ClearUnitQueue(CUnit* unit, const CCommandQueue& queue)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CWaitCommandsAI::InsertWaitObject(Wait* wait)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::RemoveWaitObject(Wait* wait)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::AddIcon(const Command& cmd, const float3& pos) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  Wait Base Class
//

CWaitCommandsAI::KeyType CWaitCommandsAI::Wait::keySource = 0;

const string CWaitCommandsAI::Wait::noText = "";


// static
CWaitCommandsAI::KeyType CWaitCommandsAI::Wait::GetNewKey()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


// static
CWaitCommandsAI::KeyType CWaitCommandsAI::Wait::GetKeyFromFloat(float f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::Wait::PostLoad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// static
float CWaitCommandsAI::Wait::GetFloatFromKey(KeyType k)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CWaitCommandsAI::Wait::Wait(float _code)
	: code(_code),
	key(0),
	valid(false),
	deadTime(spring_gettime() + spring_secs(maxNetDelay))
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CWaitCommandsAI::Wait::~Wait()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CWaitCommandsAI::Wait::WaitState
	CWaitCommandsAI::Wait::GetWaitState(const CUnit* unit) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CWaitCommandsAI::Wait::IsWaitingOn(const CUnit* unit) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::Wait::SendCommand(const Command& cmd,
																				const CUnitSet& unitSet)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::Wait::SendWaitCommand(const CUnitSet& unitSet)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CUnitSet::iterator CWaitCommandsAI::Wait::RemoveUnitFromSet(CUnitSet::iterator it, CUnitSet& unitSet)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  TimeWait
//

CWaitCommandsAI::TimeWait*
	CWaitCommandsAI::TimeWait::New(const Command& cmd, CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CWaitCommandsAI::TimeWait*
	CWaitCommandsAI::TimeWait::New(int duration, CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CWaitCommandsAI::TimeWait::TimeWait(const Command& cmd, CUnit* _unit)
: Wait(CMD_WAITCODE_TIMEWAIT)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CWaitCommandsAI::TimeWait::TimeWait(int _duration, CUnit* _unit)
: Wait(CMD_WAITCODE_TIMEWAIT)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CWaitCommandsAI::TimeWait::~TimeWait()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::TimeWait::DependentDied(CObject* object)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::TimeWait::AddUnit(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::TimeWait::RemoveUnit(CUnit* _unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::TimeWait::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const string& CWaitCommandsAI::TimeWait::GetStateText() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::TimeWait::Draw() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  DeathWait
//

CWaitCommandsAI::DeathWait*
	CWaitCommandsAI::DeathWait::New(const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CWaitCommandsAI::DeathWait::DeathWait(const Command& cmd)
: Wait(CMD_WAITCODE_DEATHWAIT)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CWaitCommandsAI::DeathWait::~DeathWait()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::DeathWait::DependentDied(CObject* object)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::DeathWait::AddUnit(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::DeathWait::RemoveUnit(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::DeathWait::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::DeathWait::Draw() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::DeathWait::AddUnitPosition(const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::DeathWait::SelectAreaUnits(
	const float3& pos0, const float3& pos1, CUnitSet& units, bool enemies)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  SquadWait
//

CWaitCommandsAI::SquadWait*
	CWaitCommandsAI::SquadWait::New(const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CWaitCommandsAI::SquadWait::SquadWait(const Command& cmd)
: Wait(CMD_WAITCODE_SQUADWAIT)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CWaitCommandsAI::SquadWait::~SquadWait()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::SquadWait::DependentDied(CObject* object)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::SquadWait::AddUnit(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::SquadWait::RemoveUnit(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::SquadWait::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::SquadWait::UpdateText()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::SquadWait::Draw() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  GatherWait
//

CWaitCommandsAI::GatherWait*
	CWaitCommandsAI::GatherWait::New(const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CWaitCommandsAI::GatherWait::GatherWait(const Command& cmd)
: Wait(CMD_WAITCODE_GATHERWAIT)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CWaitCommandsAI::GatherWait::~GatherWait()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::GatherWait::DependentDied(CObject* object)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::GatherWait::AddUnit(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::GatherWait::RemoveUnit(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CWaitCommandsAI::GatherWait::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
