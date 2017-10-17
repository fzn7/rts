#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CommandAI.h"

#include "BuilderCAI.h"
#include "ExternalAI/EngineOutHandler.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "FactoryCAI.h"
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
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/creg/STL_Deque.h"
#include "System/creg/STL_Set.h"
#include "System/myMath.h"
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

void
CCommandAI::InitCommandDescriptionCache()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
CCommandAI::KillCommandDescriptionCache()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CR_BIND(CCommandQueue, )
CR_REG_METADATA(CCommandQueue,
                (CR_MEMBER(queue), CR_MEMBER(queueType), CR_MEMBER(tagCounter)))

CR_BIND_DERIVED(CCommandAI, CObject, )
CR_REG_METADATA(CCommandAI,
                (CR_MEMBER(stockpileWeapon),

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
                 CR_MEMBER(targetLostTimer)))

CCommandAI::CCommandAI()
  : stockpileWeapon(0)
  , lastUserCommand(-1000)
  , selfDCountdown(0)
  , lastFinishCommand(0)
  , owner(NULL)
  , orderTarget(0)
  , targetDied(false)
  , inCommand(false)
  , repeatOrders(false)
  , lastSelectedCommandPage(0)
  , unimportantMove(false)
  , targetLostTimer(TARGET_LOST_TIMER)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CCommandAI::~CCommandAI()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::UpdateCommandDescription(unsigned int cmdDescIdx,
                                     const Command& cmd)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::UpdateCommandDescription(unsigned int cmdDescIdx,
                                     const SCommandDescription& modCmdDesc)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::InsertCommandDescription(unsigned int cmdDescIdx,
                                     const SCommandDescription& cmdDesc)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCommandAI::RemoveCommandDescription(unsigned int cmdDescIdx)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::UpdateNonQueueingCommands()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::ClearCommandDependencies()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::AddCommandDependency(const Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCommandAI::IsAttackCapable() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline const CUnit*
GetCommandUnit(const Command& c, int idx)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline bool
IsCommandInMap(const Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline bool
AdjustGroundAttackCommand(const Command& c, bool fromSynced, bool aiOrder)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCommandAI::AllowedCommand(const Command& c, bool fromSynced)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::GiveCommand(const Command& c, bool fromSynced)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::GiveCommandReal(const Command& c, bool fromSynced)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline void
CCommandAI::SetCommandDescParam0(const Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCommandAI::ExecuteStateCommand(const Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::ClearTargetLock(const Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::GiveAllowedCommand(const Command& c, bool fromSynced)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::GiveWaitCommand(const Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::ExecuteInsert(const Command& c, bool fromSynced)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::ExecuteRemove(const Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCommandAI::WillCancelQueued(const Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CCommandQueue::iterator
CCommandAI::GetCancelQueued(const Command& c, CCommandQueue& q)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CCommandAI::CancelCommands(const Command& c, CCommandQueue& q, bool& first)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::vector<Command>
CCommandAI::GetOverlapQueued(const Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::vector<Command>
CCommandAI::GetOverlapQueued(const Command& c, CCommandQueue& q)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CCommandAI::UpdateTargetLostTimer(int targetUnitID)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::ExecuteAttack(Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::ExecuteStop(Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::SlowUpdate()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CCommandAI::GetDefaultCmd(const CUnit* pointed, const CFeature* feature)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::AddDeathDependence(CObject* o, DependenceType dep)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::DeleteDeathDependence(CObject* o, DependenceType dep)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::DependentDied(CObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::FinishCommand()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::AddStockpileWeapon(CWeapon* weapon)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::StockpileChanged(CWeapon* weapon)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::UpdateStockpileIcon()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::WeaponFired(CWeapon* weapon, const bool searchForNewTarget)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::PushOrUpdateReturnFight(const float3& cmdPos1,
                                    const float3& cmdPos2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCommandAI::HasCommand(int cmdID) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCommandAI::HasMoreMoveCommands(bool skipFirstCmd) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCommandAI::SkipParalyzeTarget(const CUnit* target)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCommandAI::CanChangeFireState()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::StopAttackingAllyTeam(int ally)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::SetScriptMaxSpeed(float speed, bool persistent)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCommandAI::SlowUpdateMaxSpeed()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
