/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "LuaRBOs.h"

#include "LuaInclude.h"

#include "LuaHandle.h"
#include "LuaHashString.h"
#include "LuaUtils.h"


/******************************************************************************/
/******************************************************************************/

LuaRBOs::LuaRBOs()
{
    //stub method
}


LuaRBOs::~LuaRBOs()
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

bool LuaRBOs::PushEntries(lua_State* L)
{
    //stub method
}


bool LuaRBOs::CreateMetatable(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

const LuaRBOs::RBO* LuaRBOs::GetLuaRBO(lua_State* L, int index)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

void LuaRBOs::RBO::Init()
{
    //stub method
}


void LuaRBOs::RBO::Free(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaRBOs::meta_gc(lua_State* L)
{
    //stub method
}


int LuaRBOs::meta_index(lua_State* L)
{
    //stub method
}


int LuaRBOs::meta_newindex(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaRBOs::CreateRBO(lua_State* L)
{
    //stub method
}


int LuaRBOs::DeleteRBO(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/
