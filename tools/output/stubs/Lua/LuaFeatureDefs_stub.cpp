#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include <set>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cctype>

#include "LuaFeatureDefs.h"

#include "LuaInclude.h"
#include "LuaDefs.h"
#include "LuaHandle.h"
#include "LuaUtils.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureDefHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/GlobalSynced.h"
#include "System/Log/ILog.h"


static ParamMap paramMap;

static bool InitParamMap();

//static void PushFeatureDef(lua_State* L, const FeatureDef* featureDef, int index);

// iteration routines
static int Next(lua_State* L);
static int Pairs(lua_State* L);

// FeatureDef
static int FeatureDefIndex(lua_State* L);
static int FeatureDefNewIndex(lua_State* L);
static int FeatureDefMetatable(lua_State* L);

// special access functions
static int CustomParamsTable(lua_State* L, const void* data);


/******************************************************************************/
/******************************************************************************/

bool LuaFeatureDefs::PushEntries(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

/*static void PushFeatureDef(lua_State* L, const FeatureDef* fd, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static int FeatureDefNewIndex(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static int FeatureDefMetatable(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static int Next(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static int Pairs(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/



static int CustomParamsTable(lua_State* L, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



static int ModelTable(lua_State* L, const void* data) {
	return (LuaUtils::PushModelTable(L, static_cast<const SolidObjectDef*>(data)));
}

static int ModelName(lua_State* L, const void* data) {
	return (LuaUtils::PushModelName(L, static_cast<const SolidObjectDef*>(data)));
}

static int ModelHeight(lua_State* L, const void* data) {
	return (LuaUtils::PushModelHeight(L, static_cast<const SolidObjectDef*>(data), false));
}

static int ModelRadius(lua_State* L, const void* data) {
	return (LuaUtils::PushModelRadius(L, static_cast<const SolidObjectDef*>(data), false));
}

static int ModelDrawType(lua_State* L, const void* data) {
	return (LuaUtils::PushFeatureModelDrawType(L, static_cast<const FeatureDef*>(data)));
}

static int ColVolTable(lua_State* L, const void* data) {
	return (LuaUtils::PushColVolTable(L, static_cast<const CollisionVolume*>(data)));
}



/******************************************************************************/
/******************************************************************************/

static bool InitParamMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/
