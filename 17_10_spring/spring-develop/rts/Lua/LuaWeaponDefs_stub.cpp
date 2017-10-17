#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cctype>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "LuaWeaponDefs.h"

#include "LuaInclude.h"

#include "Game/TraceRay.h"
#include "LuaDefs.h"
#include "LuaHandle.h"
#include "LuaUtils.h"
#include "Rendering/Models/IModelParser.h"
#include "Sim/Misc/CategoryHandler.h"
#include "Sim/Misc/DamageArrayHandler.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

static ParamMap paramMap;

static bool
InitParamMap();

// iteration routines
static int
Next(lua_State* L);
static int
Pairs(lua_State* L);

// meta-table calls
static int
WeaponDefIndex(lua_State* L);
static int
WeaponDefNewIndex(lua_State* L);
static int
WeaponDefMetatable(lua_State* L);

// special access functions
static int
NoFeatureCollide(lua_State* L, const void* data);
static int
NoFriendlyCollide(lua_State* L, const void* data);
static int
NoNeutralCollide(lua_State* L, const void* data);

static int
VisualsTable(lua_State* L, const void* data);
static int
DamagesArray(lua_State* L, const void* data);
static int
CustomParamsTable(lua_State* L, const void* data);
static int
GuiSoundSetTable(lua_State* L, const void* data);
// static int CategorySetFromBits(lua_State* L, const void* data);

/******************************************************************************/
/******************************************************************************/

bool
LuaWeaponDefs::PushEntries(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

static int
WeaponDefIndex(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
WeaponDefNewIndex(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
WeaponDefMetatable(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

static int
Next(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
Pairs(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static int
DamagesArray(lua_State* L, const void* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
VisualsTable(lua_State* L, const void* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
NoEnemyCollide(lua_State* L, const void* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
NoFriendlyCollide(lua_State* L, const void* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
NoFeatureCollide(lua_State* L, const void* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
NoNeutralCollide(lua_State* L, const void* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
NoGroundCollide(lua_State* L, const void* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline int
BuildCategorySet(lua_State* L, const vector<string>& cats)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
static int CategorySetFromBits(lua_State* L, const void* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
*/

/*static int CategorySetFromString(lua_State* L, const void* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
GuiSoundSetTable(lua_State* L, const void* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static bool
InitParamMap()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
