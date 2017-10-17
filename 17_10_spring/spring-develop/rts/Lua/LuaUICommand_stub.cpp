#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaUICommand.h"

#include "LuaInclude.h"

#include "LuaUtils.h"

#include "Game/SyncedActionExecutor.h"
#include "Game/SyncedGameCommands.h"
#include "Game/UnsyncedActionExecutor.h"
#include "Game/UnsyncedGameCommands.h"

/******************************************************************************/
/******************************************************************************/

bool
LuaUICommand::PushEntries(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
LuaUICommand::GetUICommands(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// // TODO: FUTURE
// int LuaUICommand::RegisterUICommand(lua_State* L)
// {
// 	return 0;
// }
//
// int LuaUICommand::DeregisterUICommand(lua_State* L)
// {
// 	return 0;
// }