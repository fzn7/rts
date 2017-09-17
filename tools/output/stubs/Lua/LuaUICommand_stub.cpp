/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "LuaUICommand.h"

#include "LuaInclude.h"

#include "LuaUtils.h"

#include "Game/UnsyncedActionExecutor.h"
#include "Game/SyncedActionExecutor.h"
#include "Game/UnsyncedGameCommands.h"
#include "Game/SyncedGameCommands.h"

/******************************************************************************/
/******************************************************************************/


bool LuaUICommand::PushEntries(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaUICommand::GetUICommands(lua_State* L) 
{
    //stub method
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