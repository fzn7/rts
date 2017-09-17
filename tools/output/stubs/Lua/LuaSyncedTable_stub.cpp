#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaSyncedTable.h"

#include "LuaInclude.h"

#include "LuaHandleSynced.h"
#include "LuaHashString.h"
#include "LuaUtils.h"


static int SyncTableIndex(lua_State* L);
static int SyncTableNewIndex(lua_State* L);
static int SyncTableMetatable(lua_State* L);


/******************************************************************************/
/******************************************************************************/

static bool PushSyncedTable(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static int SyncTableIndex(lua_State* dstL)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static int SyncTableNewIndex(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static int SyncTableMetatable(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

bool LuaSyncedTable::PushEntries(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/
