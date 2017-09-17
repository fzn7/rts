#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "LuaPathFinder.h"
#include "LuaInclude.h"
#include "LuaHandle.h"
#include "LuaUtils.h"
#include "Sim/Path/IPathManager.h"
#include "Sim/MoveTypes/MoveDefHandler.h"

#include <stdlib.h>
#include <algorithm>
#include <vector>


struct NodeCostOverlay {
	NodeCostOverlay(): sizex(0), sizez(0) {}

	void Init(unsigned int sx, unsigned int sz) {
		costs.resize(sx * sz, 0.0f);
		sizex = sx;
		sizez = sz;
	}
	void Clear() { costs.clear(); }
	bool Empty() const { return costs.empty(); }
	unsigned int Size() const { return costs.size(); }

	std::vector<float> costs;

	unsigned int sizex;
	unsigned int sizez;
};

static std::map<unsigned int, NodeCostOverlay> costArrayMapSynced;
static std::map<unsigned int, NodeCostOverlay> costArrayMapUnsynced;

static void CreatePathMetatable(lua_State* L);


/******************************************************************************/
/******************************************************************************/

bool LuaPathFinder::PushEntries(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaPathFinder::PushPathNodes(lua_State* L, const int pathID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static int path_next(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static int path_nodes(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int path_index(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int path_newindex(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int path_gc(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static void CreatePathMetatable(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaPathFinder::RequestPath(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



int LuaPathFinder::InitPathNodeCostsArray(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaPathFinder::FreePathNodeCostsArray(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaPathFinder::SetPathNodeCosts(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaPathFinder::GetPathNodeCosts(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaPathFinder::SetPathNodeCost(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaPathFinder::GetPathNodeCost(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
