#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "EngineOutHandler.h"

#include "ExternalAI/IAILibraryManager.h"
#include "ExternalAI/Interface/AISCommands.h"
#include "ExternalAI/SkirmishAIData.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "ExternalAI/SkirmishAIWrapper.h"
#include "Game/GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Net/Protocol/NetProtocol.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/Team.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/CommandAI/Command.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/Log/ILog.h"
#include "System/TimeProfiler.h"
#include "System/Util.h"

#include "System/creg/STL_Map.h"

CR_BIND_DERIVED(CEngineOutHandler, CObject, )
CR_REG_METADATA(
  CEngineOutHandler,
  (
    // FIXME:
    //   "constexpr std::pair<_T1, _T2>::pair(const std::pair<_T1, _T2>&)
    //   [with _T1 = const unsigned char; _T2 =
    //   std::unique_ptr<CSkirmishAIWrapper>]’ is implicitly deleted because the
    //   default definition would be ill-formed"
    CR_IGNORED(id_skirmishAI),
    CR_MEMBER(team_skirmishAIs)))

static inline bool
IsUnitInLosOrRadarOfAllyTeam(const CUnit& unit, const int allyTeamId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static CEngineOutHandler* singleton = NULL;
static unsigned int numInstances = 0;

CEngineOutHandler*
CEngineOutHandler::GetInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::Create()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::Destroy()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CEngineOutHandler::~CEngineOutHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// This macro should be insterted at the start of each method sending AI events
#define AI_EVT_MTH()                                                           \
    if (id_skirmishAI.empty())                                                 \
        return;                                                                \
    SCOPED_TIMER("AI Total");

#define DO_FOR_SKIRMISH_AIS(FUNC)                                              \
    for (auto& ai : id_skirmishAI) {                                           \
        (ai.second)->FUNC;                                                     \
    }

void
CEngineOutHandler::PostLoad()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::Load(std::istream* s)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::Save(std::ostream* s)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// Do only if the unit is not allied, in which case we know
// everything about it anyway, and do not need to be informed
#define DO_FOR_ALLIED_SKIRMISH_AIS(FUNC, ALLY_TEAM_ID, UNIT_ALLY_TEAM_ID)      \
    if (!teamHandler->Ally(ALLY_TEAM_ID, UNIT_ALLY_TEAM_ID)) {                 \
        for (auto& ai : id_skirmishAI) {                                       \
            const int aiAllyTeam =                                             \
              teamHandler->AllyTeam((ai.second)->GetTeamId());                 \
            if (teamHandler->Ally(aiAllyTeam, ALLY_TEAM_ID)) {                 \
                (ai.second)->FUNC;                                             \
            }                                                                  \
        }                                                                      \
    }

void
CEngineOutHandler::UnitEnteredLos(const CUnit& unit, int allyTeamId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::UnitLeftLos(const CUnit& unit, int allyTeamId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::UnitEnteredRadar(const CUnit& unit, int allyTeamId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::UnitLeftRadar(const CUnit& unit, int allyTeamId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#define DO_FOR_TEAM_SKIRMISH_AIS(FUNC, TEAM_ID)                                \
    if (team_skirmishAIs.find(TEAM_ID) == team_skirmishAIs.end())              \
        return;                                                                \
                                                                               \
    for (auto ai : team_skirmishAIs[TEAM_ID]) {                                \
        id_skirmishAI[ai]->FUNC;                                               \
    }

// Send to all teams which the unit is not allied to,
// and which have cheat-events enabled, or the unit in sensor range.
#define DO_FOR_ENEMY_SKIRMISH_AIS(FUNC, ALLY_TEAM_ID, UNIT)                    \
    for (auto& ai : id_skirmishAI) {                                           \
        CSkirmishAIWrapper* saw = (ai.second).get();                           \
                                                                               \
        const int aiAllyTeam = teamHandler->AllyTeam(saw->GetTeamId());        \
                                                                               \
        const bool alliedAI = teamHandler->Ally(aiAllyTeam, ALLY_TEAM_ID);     \
        const bool cheatingAI = saw->IsCheatEventsEnabled();                   \
                                                                               \
        if (alliedAI)                                                          \
            continue;                                                          \
        if (cheatingAI || IsUnitInLosOrRadarOfAllyTeam(UNIT, aiAllyTeam)) {    \
            saw->FUNC;                                                         \
        }                                                                      \
    }

void
CEngineOutHandler::UnitIdle(const CUnit& unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::UnitCreated(const CUnit& unit, const CUnit* builder)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::UnitFinished(const CUnit& unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::UnitMoveFailed(const CUnit& unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::UnitGiven(const CUnit& unit, int oldTeam, int newTeam)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::UnitCaptured(const CUnit& unit, int oldTeam, int newTeam)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::UnitDestroyed(const CUnit& destroyed, const CUnit* attacker)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::UnitDamaged(const CUnit& damaged,
                               const CUnit* attacker,
                               float damage,
                               int weaponDefID,
                               int projectileID,
                               bool paralyzer)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::SeismicPing(int allyTeamId,
                               const CUnit& unit,
                               const float3& pos,
                               float strength)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::WeaponFired(const CUnit& unit, const WeaponDef& def)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::PlayerCommandGiven(const std::vector<int>& selectedUnitIds,
                                      const Command& c,
                                      int playerId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::CommandFinished(const CUnit& unit, const Command& command)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::SendChatMessage(const char* msg, int fromPlayerId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CEngineOutHandler::SendLuaMessages(int aiTeam,
                                   const char* inData,
                                   std::vector<const char*>& outData)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::CreateSkirmishAI(const size_t skirmishAIId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::SetSkirmishAIDieing(const size_t skirmishAIId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
internal_aiErase(std::vector<unsigned char>& ais,
                 const unsigned char skirmishAIId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CEngineOutHandler::DestroySkirmishAI(const size_t skirmishAIId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
