#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "TeamHighlight.h"

#include "ExternalAI/SkirmishAIHandler.h"
#include "Game/GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/GlobalConfig.h"

#include <climits>

bool CTeamHighlight::highlight = false;
std::map<int, int> CTeamHighlight::oldColors;

void
CTeamHighlight::Enable(unsigned currentTime)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CTeamHighlight::Disable()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CTeamHighlight::Update(int frameNum)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
