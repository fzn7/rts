/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Team.h"

#include "TeamHandler.h"
#include "GlobalSynced.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Map/ReadMap.h"
#include "Net/Protocol/NetProtocol.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/MsgStrings.h"
#include "System/Util.h"
#include "System/creg/STL_Set.h"
#include "System/creg/STL_List.h"
#include "System/creg/STL_Map.h"
#include "System/creg/STL_Set.h"


CR_BIND_DERIVED(CTeam, TeamBase, )
CR_REG_METADATA(CTeam, (
	CR_MEMBER(teamNum),
	CR_MEMBER(maxUnits),
	CR_MEMBER(isDead),
	CR_MEMBER(gaia),
	CR_MEMBER(origColor),
	CR_MEMBER(units),
	CR_MEMBER(res),
	CR_MEMBER(resStorage),
	CR_MEMBER(resPull),
	CR_MEMBER(resPrevPull),
	CR_MEMBER(resIncome),
	CR_MEMBER(resPrevIncome),
	CR_MEMBER(resExpense),
	CR_MEMBER(resPrevExpense),
	CR_MEMBER(resShare),
	CR_MEMBER(resDelayedShare),
	CR_MEMBER(resSent),
	CR_MEMBER(resPrevSent),
	CR_MEMBER(resReceived),
	CR_MEMBER(resPrevReceived),
	CR_MEMBER(resPrevExcess),
	CR_MEMBER(nextHistoryEntry),
	CR_MEMBER(statHistory),
	CR_MEMBER(modParams),
	CR_IGNORED(highlight)
))


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTeam::CTeam():
	teamNum(-1),
	maxUnits(0),
	isDead(false),
	gaia(false),
	removeUnits(true),
	resStorage(1000000, 1000000),
	resShare(0.99f, 0.95f),
	nextHistoryEntry(0),
	origColor(0, 0, 0, 0),
	highlight(0.0f)
{
    //stub method
}

void CTeam::SetDefaultStartPos()
{
    //stub method
}

void CTeam::ClampStartPosInStartBox(float3* pos) const
{
    //stub method
}


bool CTeam::UseMetal(float amount)
{
    //stub method
}

bool CTeam::UseEnergy(float amount)
{
    //stub method
}



void CTeam::AddMetal(float amount, bool useIncomeMultiplier)
{
    //stub method
}

void CTeam::AddEnergy(float amount, bool useIncomeMultiplier)
{
    //stub method
}


bool CTeam::HaveResources(const SResourcePack& amount) const
{
    //stub method
}


void CTeam::AddResources(SResourcePack amount, bool useIncomeMultiplier)
{
    //stub method
}


bool CTeam::UseResources(const SResourcePack& amount)
{
    //stub method
}


void CTeam::GiveEverythingTo(const unsigned toTeam)
{
    //stub method
}


void CTeam::Died(bool normalDeath)
{
    //stub method
}

void CTeam::AddPlayer(int playerNum)
{
    //stub method
}

void CTeam::KillAIs()
{
    //stub method
}



void CTeam::ResetResourceState()
{
    //stub method
}

void CTeam::SlowUpdate()
{
    //stub method
}


void CTeam::AddUnit(CUnit* unit, AddType type)
{
    //stub method
}


void CTeam::RemoveUnit(CUnit* unit, RemoveType type)
{
    //stub method
}

std::string CTeam::GetControllerName() const {
	std::string s;

	// "Joe, AI: ABCAI 0.1 (nick: Killer), AI: DEFAI 1.2 (nick: Slayer), ..."
	if (HasLeader()) {
		const CPlayer* leadPlayer = playerHandler->Player(leader);

		if (leadPlayer->team != this->teamNum) {
			const CTeam*   realLeadPlayerTeam = teamHandler->Team(leadPlayer->team);
			const CPlayer* realLeadPlayer     = NULL;

			if (realLeadPlayerTeam->HasLeader()) {
				realLeadPlayer = playerHandler->Player(realLeadPlayerTeam->GetLeader());
				s = realLeadPlayer->name;
			} else {
				s = "N/A"; // weird
			}
		} else {
			s = leadPlayer->name;
		}

		for (const auto& aiId: skirmishAIHandler.GetSkirmishAIsInTeam(this->teamNum)) {
			const SkirmishAIData* aiData = skirmishAIHandler.GetSkirmishAI(aiId);
			const std::string prefix = "AI: " + aiData->shortName + " " + aiData->version + " ";
			const std::string pstfix = "(nick: " + aiData->name + ")";
			s += ", " + prefix + pstfix;
		}
	} else {
		s = UncontrolledPlayerName;
	}

	return s;
}
