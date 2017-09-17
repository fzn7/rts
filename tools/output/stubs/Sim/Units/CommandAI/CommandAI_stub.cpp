/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "CommandAI.h"

#include "BuilderCAI.h"
#include "FactoryCAI.h"
#include "ExternalAI/EngineOutHandler.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/WaitCommandsAI.h"
#include "Map/Ground.h"
#include "Map/MapDamage.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/MoveTypes/MoveType.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/EventHandler.h"
#include "System/myMath.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/creg/STL_Set.h"
#include "System/creg/STL_Deque.h"
#include <assert.h>

// number of SlowUpdate calls that a target (unit) must
// be out of radar (and hence LOS) contact before it is
// considered 'lost' and invalid (for attack orders etc)
//
// historically this value was 120, which meant that it
// took (120 * UNIT_SLOWUPDATE_RATE) / GAME_SPEED == 64
// seconds (!) before eg. aircraft would stop tracking a
// target that cloaked after flying over it --> obviously
// unreasonable
static const int TARGET_LOST_TIMER = 4;
static const float COMMAND_CANCEL_DIST = 17.0f;

void CCommandAI::InitCommandDescriptionCache() { commandDescriptionCache = new CCommandDescriptionCache(); }
void CCommandAI::KillCommandDescriptionCache() { SafeDelete(commandDescriptionCache); }

CR_BIND(CCommandQueue, )
CR_REG_METADATA(CCommandQueue, (
	CR_MEMBER(queue),
	CR_MEMBER(queueType),
	CR_MEMBER(tagCounter)
))

CR_BIND_DERIVED(CCommandAI, CObject, )
CR_REG_METADATA(CCommandAI, (
	CR_MEMBER(stockpileWeapon),

	CR_MEMBER(possibleCommands),
	CR_MEMBER(nonQueingCommands),
	CR_MEMBER(commandQue),
	CR_MEMBER(lastUserCommand),
	CR_MEMBER(selfDCountdown),
	CR_MEMBER(lastFinishCommand),

	CR_MEMBER(owner),

	CR_MEMBER(orderTarget),
	CR_MEMBER(targetDied),
	CR_MEMBER(inCommand),
	CR_MEMBER(repeatOrders),
	CR_MEMBER(lastSelectedCommandPage),
	CR_MEMBER(unimportantMove),
	CR_MEMBER(commandDeathDependences),
	CR_MEMBER(targetLostTimer)
))

CCommandAI::CCommandAI():
	stockpileWeapon(0),
	lastUserCommand(-1000),
	selfDCountdown(0),
	lastFinishCommand(0),
	owner(NULL),
	orderTarget(0),
	targetDied(false),
	inCommand(false),
	repeatOrders(false),
	lastSelectedCommandPage(0),
	unimportantMove(false),
	targetLostTimer(TARGET_LOST_TIMER)
{
    //stub method
}

CCommandAI::~CCommandAI()
{
    //stub method
}


void CCommandAI::UpdateCommandDescription(unsigned int cmdDescIdx, const Command& cmd) {
	SCommandDescription cd = *possibleCommands[cmdDescIdx];
	cd.params[0] = IntToString(int(cmd.GetParam(0)), "%d");
	commandDescriptionCache->DecRef(*possibleCommands[cmdDescIdx]);
	possibleCommands[cmdDescIdx] = commandDescriptionCache->GetPtr(cd);
}

void CCommandAI::UpdateCommandDescription(unsigned int cmdDescIdx, const SCommandDescription& modCmdDesc) {
	const SCommandDescription* curCmdDesc = possibleCommands[cmdDescIdx];

	// modCmdDesc should be a modified copy of curCmdDesc
	assert(&modCmdDesc != curCmdDesc);

	// erase in case we do not want it to be non-queueing anymore
	if (!curCmdDesc->queueing)
		nonQueingCommands.erase(curCmdDesc->id);

	// re-insert otherwise (possibly with a different cmdID!)
	if (!modCmdDesc.queueing)
		nonQueingCommands.insert(modCmdDesc.id);
	commandDescriptionCache->DecRef(*curCmdDesc);

	// update
	possibleCommands[cmdDescIdx] = commandDescriptionCache->GetPtr(modCmdDesc);

	selectedUnitsHandler.PossibleCommandChange(owner);
}

void CCommandAI::InsertCommandDescription(unsigned int cmdDescIdx, const SCommandDescription& cmdDesc)
{
    //stub method
}

bool CCommandAI::RemoveCommandDescription(unsigned int cmdDescIdx)
{
    //stub method
}


void CCommandAI::UpdateNonQueueingCommands()
{
    //stub method
}


void CCommandAI::ClearCommandDependencies() {
	while (!commandDeathDependences.empty()) {
		DeleteDeathDependence(*commandDeathDependences.begin(), DEPENDENCE_COMMANDQUE);
	}
}

void CCommandAI::AddCommandDependency(const Command& c) {
	int cpos;
	if (c.IsObjectCommand(cpos)) {
		int refId = c.params[cpos];
		CObject* ref = (refId < unitHandler->MaxUnits()) ?
				static_cast<CObject*>(unitHandler->GetUnit(refId)) :
				static_cast<CObject*>(featureHandler->GetFeature(refId - unitHandler->MaxUnits()));
		if (ref) {
			AddDeathDependence(ref, DEPENDENCE_COMMANDQUE);
		}
	}
}


bool CCommandAI::IsAttackCapable() const
{
    //stub method
}



static inline const CUnit* GetCommandUnit(const Command& c, int idx) {
	if (idx >= c.params.size()) {
		return NULL;
	}

	if (c.IsAreaCommand()) {
		return NULL;
	}

	const CUnit* unit = unitHandler->GetUnit(c.params[idx]);
	return unit;
}

static inline bool IsCommandInMap(const Command& c)
{
    //stub method
}

static inline bool AdjustGroundAttackCommand(const Command& c, bool fromSynced, bool aiOrder)
{
    //stub method
}



bool CCommandAI::AllowedCommand(const Command& c, bool fromSynced)
{
    //stub method
}


void CCommandAI::GiveCommand(const Command& c, bool fromSynced)
{
    //stub method
}


void CCommandAI::GiveCommandReal(const Command& c, bool fromSynced)
{
    //stub method
}


inline void CCommandAI::SetCommandDescParam0(const Command& c)
{
    //stub method
}


bool CCommandAI::ExecuteStateCommand(const Command& c)
{
    //stub method
}


void CCommandAI::ClearTargetLock(const Command &c) {
	if (((c.GetID() == CMD_ATTACK) || (c.GetID() == CMD_MANUALFIRE)) && (c.options & META_KEY) == 0) {
		// no meta-bit attack lock, clear the order
		owner->DropCurrentAttackTarget();
	}
}


void CCommandAI::GiveAllowedCommand(const Command& c, bool fromSynced)
{
    //stub method
}


void CCommandAI::GiveWaitCommand(const Command& c)
{
    //stub method
}


void CCommandAI::ExecuteInsert(const Command& c, bool fromSynced)
{
    //stub method
}


void CCommandAI::ExecuteRemove(const Command& c)
{
    //stub method
}


bool CCommandAI::WillCancelQueued(const Command& c)
{
    //stub method
}


CCommandQueue::iterator CCommandAI::GetCancelQueued(const Command& c, CCommandQueue& q)
{
    //stub method
}


int CCommandAI::CancelCommands(const Command &c, CCommandQueue& q, bool& first)
{
    //stub method
}


std::vector<Command> CCommandAI::GetOverlapQueued(const Command& c)
{
    //stub method
}


std::vector<Command> CCommandAI::GetOverlapQueued(const Command& c, CCommandQueue& q)
{
    //stub method
}


int CCommandAI::UpdateTargetLostTimer(int targetUnitID)
{
    //stub method
}


void CCommandAI::ExecuteAttack(Command& c)
{
    //stub method
}


void CCommandAI::ExecuteStop(Command &c)
{
    //stub method
}


void CCommandAI::SlowUpdate()
{
    //stub method
}


int CCommandAI::GetDefaultCmd(const CUnit* pointed, const CFeature* feature)
{
    //stub method
}


void CCommandAI::AddDeathDependence(CObject* o, DependenceType dep) {
	if (dep == DEPENDENCE_COMMANDQUE) {
		if (commandDeathDependences.insert(o).second) // prevent multiple dependencies for the same object
			CObject::AddDeathDependence(o, dep);
		return;
	}
	CObject::AddDeathDependence(o, dep);
}


void CCommandAI::DeleteDeathDependence(CObject* o, DependenceType dep) {
	if (dep == DEPENDENCE_COMMANDQUE) {
		if (commandDeathDependences.erase(o))
			CObject::DeleteDeathDependence(o, dep);
		return;
	}
	CObject::DeleteDeathDependence(o,dep);
}


void CCommandAI::DependentDied(CObject* o)
{
    //stub method
}



void CCommandAI::FinishCommand()
{
    //stub method
}

void CCommandAI::AddStockpileWeapon(CWeapon* weapon)
{
    //stub method
}

void CCommandAI::StockpileChanged(CWeapon* weapon)
{
    //stub method
}

void CCommandAI::UpdateStockpileIcon()
{
    //stub method
}

void CCommandAI::WeaponFired(CWeapon* weapon, const bool searchForNewTarget)
{
    //stub method
}

void CCommandAI::PushOrUpdateReturnFight(const float3& cmdPos1, const float3& cmdPos2)
{
    //stub method
}


bool CCommandAI::HasCommand(int cmdID) const {
	if (commandQue.empty())
		return false;
	if (cmdID < 0)
		return ((commandQue.front()).IsBuildCommand());

	return ((commandQue.front()).GetID() == cmdID);
}

bool CCommandAI::HasMoreMoveCommands(bool skipFirstCmd) const
{
    //stub method
}


bool CCommandAI::SkipParalyzeTarget(const CUnit* target)
{
    //stub method
}

bool CCommandAI::CanChangeFireState() {
	const UnitDef* ud = owner->unitDef;
	const bool b = (!ud->weapons.empty() || ud->canKamikaze || ud->IsFactoryUnit());

	return (ud->canFireControl && b);
}


void CCommandAI::StopAttackingAllyTeam(int ally)
{
    //stub method
}



void CCommandAI::SetScriptMaxSpeed(float speed, bool persistent) {
	if (!persistent) {
		// find the first CMD_SET_WANTED_MAX_SPEED and modify it
		// NOTE:
		//     this has no effect if the unit does not already have
		//     such an order, and only lasts until a new move-order
		//     is given (hence non-persistent)
		CCommandQueue::iterator it;

		for (it = commandQue.begin(); it != commandQue.end(); ++it) {
			Command& c = *it;

			if (c.GetID() != CMD_SET_WANTED_MAX_SPEED)
				continue;

			owner->moveType->SetWantedMaxSpeed(c.params[0] = speed);
			break;
		}
	} else {
		// permanently change the unit's speed
		owner->moveType->SetMaxSpeed(speed);
	}
}

void CCommandAI::SlowUpdateMaxSpeed() {
	if (commandQue.size() < 2)
		return;

	// grab the second command
	const CCommandQueue::const_iterator it = ++(commandQue.begin());
	const Command& c = *it;

	// treat any following CMD_SET_WANTED_MAX_SPEED commands as options
	// to the current command (and ignore them when it's their turn)
	if (c.GetID() != CMD_SET_WANTED_MAX_SPEED)
		return;

	assert(!c.params.empty());
	owner->moveType->SetWantedMaxSpeed(c.params[0]);
}

