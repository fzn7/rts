#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaPathFinder.h"
#include "LuaHandle.h"
#include "LuaInclude.h"
#include "LuaUtils.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Path/IPathManager.h"

#include <algorithm>
#include <stdlib.h>
#include <vector>

struct NodeCostOverlay
{
    //stub method
    //std::cout << __FUNCTION__ << std::endl;
};

int
LuaPathFinder::PushPathNodes(lua_State* L, const int pathID)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

static int
path_next(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
path_nodes(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
path_index(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
path_newindex(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
path_gc(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
CreatePathMetatable(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
LuaPathFinder::RequestPath(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaPathFinder::InitPathNodeCostsArray(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaPathFinder::FreePathNodeCostsArray(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaPathFinder::SetPathNodeCosts(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaPathFinder::GetPathNodeCosts(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaPathFinder::SetPathNodeCost(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaPathFinder::GetPathNodeCost(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
