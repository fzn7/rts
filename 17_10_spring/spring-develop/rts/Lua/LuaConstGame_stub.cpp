#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaConstGame.h"

#include "LuaInclude.h"

#include "Game/Game.h"
#include "Game/GameSetup.h"
#include "Game/GameVersion.h"
#include "LuaHandle.h"
#include "LuaUtils.h"
#include "Map/MapDamage.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/CategoryHandler.h"
#include "Sim/Misc/DamageArrayHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/Wind.h"
#include "Sim/Units/CommandAI/Command.h"
#include "Sim/Units/UnitHandler.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/Util.h"

/******************************************************************************/
/******************************************************************************/

static void
LuaPushNamedColor(lua_State* L, const string& name, const float3& color)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
LuaConstGame::PushEntries(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
