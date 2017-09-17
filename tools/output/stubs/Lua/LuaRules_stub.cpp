#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaRules.h"

#include "LuaInclude.h"

#include "LuaUtils.h"
#include "LuaObjectRendering.h"
#include "LuaCallInCheck.h"

#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/Scripts/CobInstance.h" // for UNPACK{X,Z}
#include "System/Log/ILog.h"
#include "System/FileSystem/VFSModes.h" // for SPRING_VFS_*

#include <assert.h>
#include <mutex>
#include <boost/thread/mutex.hpp>

CLuaRules* luaRules = NULL;

static const char* LuaRulesSyncedFilename   = "LuaRules/main.lua";
static const char* LuaRulesUnsyncedFilename = "LuaRules/draw.lua";

const int* CLuaRules::currentCobArgs = NULL;


/******************************************************************************/
/******************************************************************************/

static boost::mutex m_singleton;

DECL_LOAD_HANDLER(CLuaRules, luaRules)
DECL_FREE_HANDLER(CLuaRules, luaRules)


/******************************************************************************/
/******************************************************************************/

CLuaRules::CLuaRules()
: CLuaHandleSynced("LuaRules", LUA_HANDLE_ORDER_RULES)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CLuaRules::~CLuaRules()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



bool CLuaRules::AddSyncedCode(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaRules::AddUnsyncedCode(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int CLuaRules::UnpackCobArg(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaRules::Cob2Lua(const LuaHashString& name, const CUnit* unit,
                        int& argsCount, int args[MAX_LUA_COB_ARGS])
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/
//
// LuaRules Call-Outs
//

int CLuaRules::PermitHelperAIs(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
