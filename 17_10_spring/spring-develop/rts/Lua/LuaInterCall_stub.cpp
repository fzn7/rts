#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaInterCall.h"

#include "LuaInclude.h"

#include "LuaGaia.h"
#include "LuaHandle.h"
#include "LuaRules.h"
#include "LuaUI.h"

enum
{
    LUA_UI,
    LUA_RULES,
    LUA_GAIA
};

/******************************************************************************/
/******************************************************************************/

static int
HandleXCall(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
IndexHook(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
CallHook(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
PushCallHandler(lua_State* L, int luaInstance, const string& name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
LuaInterCall::PushEntriesSynced(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
LuaInterCall::PushEntriesUnsynced(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
