/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "TeamHandler.h"

#include <cstring>

#include "Game/GameSetup.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/GlobalSynced.h"
#include "System/Util.h"


CR_BIND(CTeamHandler, )

CR_REG_METADATA(CTeamHandler, (
	CR_MEMBER(gaiaTeamID),
	CR_MEMBER(gaiaAllyTeamID),
	CR_MEMBER(teams),
	CR_MEMBER(allyTeams)
))


CTeamHandler* teamHandler = NULL;


CTeamHandler::CTeamHandler():
	gaiaTeamID(-1),
	gaiaAllyTeamID(-1)
{
    //stub method
}

CTeamHandler::~CTeamHandler()
{
    //stub method
}


void CTeamHandler::ResetState()
{
    //stub method
}

void CTeamHandler::LoadFromSetup(const CGameSetup* setup)
{
    //stub method
}

void CTeamHandler::GameFrame(int frameNum)
{
    //stub method
}



unsigned int CTeamHandler::GetNumTeamsInAllyTeam(unsigned int allyTeamNum, bool countDeadTeams) const
{
    //stub method
}

void CTeamHandler::UpdateTeamUnitLimitsPreSpawn(int liveTeamNum)
{
    //stub method
}

void CTeamHandler::UpdateTeamUnitLimitsPreDeath(int deadTeamNum)
{
    //stub method
}

