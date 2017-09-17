#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/* based on code from GlobalSynced.{cpp,h} */

#include "PlayerHandler.h"

#include "Game/GameSetup.h"
#include "Game/SelectedUnitsHandler.h"
#include "Player.h"
#include "Sim/Misc/GlobalConstants.h"

CR_BIND(CPlayerHandler, )

CR_REG_METADATA(CPlayerHandler, (CR_MEMBER(players)))

CPlayerHandler* playerHandler = NULL;

CPlayerHandler::~CPlayerHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPlayerHandler::ResetState()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPlayerHandler::LoadFromSetup(const CGameSetup* setup)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CPlayerHandler::Player(const std::string& name) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPlayerHandler::PlayerLeft(int id, unsigned char reason)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::vector<int>
CPlayerHandler::ActivePlayersInTeam(int teamId) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPlayerHandler::GameFrame(int frameNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPlayerHandler::AddPlayer(const CPlayer& player)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
