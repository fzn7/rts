#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaScream.h"

#include "LuaInclude.h"

#include "LuaHashString.h"

#include "System/Log/ILog.h"

/******************************************************************************/
/******************************************************************************/

LuaScream::LuaScream() {}

LuaScream::~LuaScream() {}

/******************************************************************************/
/******************************************************************************/

bool
LuaScream::PushEntries(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

bool
LuaScream::CreateMetatable(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaScream::meta_gc(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaScream::meta_index(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaScream::meta_newindex(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
LuaScream::CreateScream(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
