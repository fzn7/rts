#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GameSetupDrawer.h"

#include "KeyBindings.h"
#include "StartPosSelecter.h"
#include "Game/CameraHandler.h"
#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Net/GameServer.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Rendering/Fonts/glFont.h"
#include "Net/Protocol/NetProtocol.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"

#include <cassert>
#include <string>
#include <map>


GameSetupDrawer* GameSetupDrawer::instance = NULL;


void GameSetupDrawer::Enable()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void GameSetupDrawer::Disable()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void GameSetupDrawer::StartCountdown(unsigned time)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


GameSetupDrawer::GameSetupDrawer():
	readyCountdown(spring_notime),
	lastTick(spring_notime)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

GameSetupDrawer::~GameSetupDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void GameSetupDrawer::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
