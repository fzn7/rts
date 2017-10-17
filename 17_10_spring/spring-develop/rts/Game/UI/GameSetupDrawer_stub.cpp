#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GameSetupDrawer.h"

#include "Game/CameraHandler.h"
#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "KeyBindings.h"
#include "Net/GameServer.h"
#include "Net/Protocol/NetProtocol.h"
#include "Rendering/Fonts/glFont.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "StartPosSelecter.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"

#include <cassert>
#include <map>
#include <string>

GameSetupDrawer* GameSetupDrawer::instance = NULL;

void
GameSetupDrawer::Enable()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
GameSetupDrawer::Disable()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
GameSetupDrawer::StartCountdown(unsigned time)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

GameSetupDrawer::GameSetupDrawer()
  : readyCountdown(spring_notime)
  , lastTick(spring_notime)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

GameSetupDrawer::~GameSetupDrawer() {}

void
GameSetupDrawer::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
