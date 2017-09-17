/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/* based on code from GlobalSynced.{cpp,h} */

#include "PlayerHandler.h"

#include "Player.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Game/GameSetup.h"
#include "Game/SelectedUnitsHandler.h"

CR_BIND(CPlayerHandler,)

CR_REG_METADATA(CPlayerHandler, (
	CR_MEMBER(players)
))


CPlayerHandler* playerHandler = NULL;

CPlayerHandler::~CPlayerHandler()
{
    //stub method
}


void CPlayerHandler::ResetState()
{
    //stub method
}

void CPlayerHandler::LoadFromSetup(const CGameSetup* setup)
{
    //stub method
}


int CPlayerHandler::Player(const std::string& name) const
{
    //stub method
}

void CPlayerHandler::PlayerLeft(int id, unsigned char reason)
{
    //stub method
}

std::vector<int> CPlayerHandler::ActivePlayersInTeam(int teamId) const
{
    //stub method
}

void CPlayerHandler::GameFrame(int frameNum)
{
    //stub method
}

void CPlayerHandler::AddPlayer(const CPlayer& player)
{
    //stub method
}

