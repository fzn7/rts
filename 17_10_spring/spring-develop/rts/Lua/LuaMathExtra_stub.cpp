#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaMathExtra.h"
#include "LuaInclude.h"
#include "LuaUtils.h"
#include "System/myMath.h"
#include "lib/streflop/streflop_cond.h"

static const lua_Number POWERS_OF_TEN[] = { 1.0f,       10.0f,      100.0f,
                                            1000.0f,    10000.0f,   100000.0f,
                                            1000000.0f, 10000000.0f };

/******************************************************************************/
/******************************************************************************/

bool
LuaMathExtra::PushEntries(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
LuaMathExtra::hypot(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaMathExtra::diag(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaMathExtra::clamp(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaMathExtra::sgn(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaMathExtra::mix(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaMathExtra::round(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaMathExtra::erf(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaMathExtra::smoothstep(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
