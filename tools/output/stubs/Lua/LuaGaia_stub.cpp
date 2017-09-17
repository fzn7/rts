#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include <set>
#include <mutex>
#include <boost/thread/mutex.hpp>

#include "LuaGaia.h"

#include "LuaInclude.h"

#include "LuaUtils.h"
#include "LuaSyncedCtrl.h"
#include "LuaSyncedRead.h"
#include "LuaUnitDefs.h"
#include "LuaWeaponDefs.h"
#include "LuaOpenGL.h"

#include "Rendering/UnitDrawer.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/CommandAI/Command.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Util.h"


CLuaGaia* luaGaia = NULL;

static const char* LuaGaiaSyncedFilename   = "LuaGaia/main.lua";
static const char* LuaGaiaUnsyncedFilename = "LuaGaia/draw.lua";


/******************************************************************************/
/******************************************************************************/

static boost::mutex m_singleton;

DECL_LOAD_HANDLER(CLuaGaia, luaGaia)
DECL_FREE_HANDLER(CLuaGaia, luaGaia)


/******************************************************************************/
/******************************************************************************/

CLuaGaia::CLuaGaia()
: CLuaHandleSynced("LuaGaia", LUA_HANDLE_ORDER_GAIA)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CLuaGaia::~CLuaGaia()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaGaia::AddSyncedCode(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaGaia::AddUnsyncedCode(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
