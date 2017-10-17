#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cctype>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "LuaUnitDefs.h"

#include "LuaConfig.h"
#include "LuaDefs.h"
#include "LuaHandle.h"
#include "LuaInclude.h"
#include "LuaUtils.h"
#include "Map/MapInfo.h"
#include "Rendering/IconHandler.h"
#include "Sim/Misc/CategoryHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/Wind.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Weapons/WeaponDef.h"
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
UnitDefIndex(lua_State* L);
static int
UnitDefNewIndex(lua_State* L);
static int
UnitDefMetatable(lua_State* L);

// special access functions
static int
UnitDefToID(lua_State* L, const void* data);
static int
WeaponDefToID(lua_State* L, const void* data);
static int
CustomParamsTable(lua_State* L, const void* data);
static int
BuildOptions(lua_State* L, const void* data);
static int
SoundsTable(lua_State* L, const void* data);
static int
WeaponsTable(lua_State* L, const void* data);
static int
CategorySetFromBits(lua_State* L, const void* data);
static int
CategorySetFromString(lua_State* L, const void* data);

/******************************************************************************/
/******************************************************************************/

bool
LuaUnitDefs::PushEntries(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

static int
UnitDefIndex(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
UnitDefNewIndex(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
UnitDefMetatable(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

static int
Next(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
Pairs(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static int
UnitDefToID(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
WeaponDefToID(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
WeaponDefToName(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
SafeIconType(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
CustomParamsTable(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
BuildOptions(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline int
BuildCategorySet(lua_State* L, const vector<string>& cats)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
CategorySetFromBits(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
CategorySetFromString(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
WeaponsTable(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
PushGuiSoundSet(lua_State* L, const string& name, const GuiSoundSet& soundSet)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
SoundsTable(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
MoveDefTable(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
TotalEnergyOut(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#define TYPE_FUNC(FuncName, LuaType)                                           \
    static int FuncName(lua_State* L, const void* data)                        \
    {                                                                          \
        const UnitDef* ud = static_cast<const UnitDef*>(data);                 \
        lua_push##LuaType(L, ud->FuncName());                                  \
        return 1;                                                              \
    }

static int
ModelTable(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
ModelName(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
ModelHeight(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
ModelRadius(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
ColVolTable(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

TYPE_FUNC(IsTransportUnit, boolean)
TYPE_FUNC(IsImmobileUnit, boolean)
TYPE_FUNC(IsBuildingUnit, boolean)
TYPE_FUNC(IsBuilderUnit, boolean)
TYPE_FUNC(IsMobileBuilderUnit, boolean)
TYPE_FUNC(IsStaticBuilderUnit, boolean)
TYPE_FUNC(IsFactoryUnit, boolean)
TYPE_FUNC(IsExtractorUnit, boolean)
TYPE_FUNC(IsGroundUnit, boolean)
TYPE_FUNC(IsAirUnit, boolean)
TYPE_FUNC(IsStrafingAirUnit, boolean)
TYPE_FUNC(IsHoveringAirUnit, boolean)
TYPE_FUNC(IsFighterAirUnit, boolean)
TYPE_FUNC(IsBomberAirUnit, boolean)

static int
ReturnEmptyString(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
ReturnFalse(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
ReturnMinusOne(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
ReturnNil(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static bool
InitParamMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
