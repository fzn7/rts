#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaBitOps.h"

#include "LuaInclude.h"

#include "LuaUtils.h"

// spring's lua uses FLOATS as its number type which can only represent
// integer values up to 1<<24 exactly
const int mask = 0x00FFFFFF; // 2^24

/******************************************************************************/
/******************************************************************************/

bool
LuaBitOps::PushEntries(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static inline unsigned int
luaL_checkuint(lua_State* L, int index)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaBitOps::bit_or(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaBitOps::bit_and(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaBitOps::bit_xor(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaBitOps::bit_inv(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaBitOps::bit_bits(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
