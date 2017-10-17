#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SyncedGameCommands.h"

#include "Action.h"
#include "Game.h"
#include "GlobalUnsynced.h"
#include "InMapDraw.h"
#include "SelectedUnitsHandler.h"
#include "SyncedActionExecutor.h"
#ifdef _WIN32
#include "winerror.h" // TODO someone on windows (MinGW? VS?) please check if this is required
#endif

#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Lua/LuaGaia.h"
#include "Lua/LuaRules.h"
#include "Lua/LuaUI.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitLoader.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#include <stdexcept>
#include <string>
#include <vector>

namespace { // prevents linking problems in case of duplicate symbols

class CheatActionExecutor : public ISyncedActionExecutor
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

class LuaRulesActionExecutor : public ISyncedActionExecutor
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

SyncedGameCommands* SyncedGameCommands::singleton = NULL;

void
SyncedGameCommands::CreateInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SyncedGameCommands::DestroyInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
