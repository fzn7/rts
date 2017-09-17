#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaUI.h"

#include "LuaInclude.h"

#include "LuaUnsyncedCtrl.h"
#include "LuaArchive.h"
#include "LuaCallInCheck.h"
#include "LuaConstGL.h"
#include "LuaConstCMD.h"
#include "LuaConstCMDTYPE.h"
#include "LuaConstGame.h"
#include "LuaSyncedRead.h"
#include "LuaInterCall.h"
#include "LuaUnsyncedRead.h"
#include "LuaUICommand.h"
#include "LuaFeatureDefs.h"
#include "LuaUnitDefs.h"
#include "LuaWeaponDefs.h"
#include "LuaScream.h"
#include "LuaOpenGL.h"
#include "LuaUtils.h"
#include "LuaVFS.h"
#include "LuaVFSDownload.h"
#include "LuaIO.h"
#include "LuaZip.h"
#include "Game/Camera.h"
#include "Game/Camera/CameraController.h"
#include "Game/Game.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/UI/CommandColors.h"
#include "Game/UI/InfoConsole.h"
#include "Game/UI/KeyCodes.h"
#include "Game/UI/KeySet.h"
#include "Game/UI/KeyBindings.h"
#include "Game/UI/MiniMap.h"
#include "Game/UI/MouseHandler.h"
#include "Map/ReadMap.h"
#include "Rendering/IconHandler.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Units/CommandAI/CommandDescription.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Util.h"
#include "lib/luasocket/src/luasocket.h"

#include <mutex>
#include <boost/thread/mutex.hpp>
#include <stdio.h>
#include <set>
#include <cctype>

CONFIG(bool, LuaSocketEnabled)
	.defaultValue(true)
	.description("Enable LuaSocket support, allows a lua-widget to make TCP/UDP Connections")
	.readOnly(true)
;

using std::max;


CLuaUI* luaUI = NULL;

const int CMD_INDEX_OFFSET = 1; // starting index for command descriptions

static const char* GetVFSMode(bool lockedAccess)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static boost::mutex m_singleton;

DECL_LOAD_HANDLER(CLuaUI, luaUI)
DECL_FREE_HANDLER(CLuaUI, luaUI)


/******************************************************************************/

CLuaUI::CLuaUI()
: CLuaHandle("LuaUI", LUA_HANDLE_ORDER_UI, true, false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CLuaUI::~CLuaUI()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CLuaUI::InitLuaSocket(lua_State* L) {
	std::string code;
	std::string filename = "socket.lua";
	CFileHandler f(filename);

	LUA_OPEN_LIB(L, luaopen_socket_core);

	if (f.LoadStringData(code)) {
		LoadCode(L, code, filename);
	} else {
		LOG_L(L_ERROR, "Error loading %s", filename.c_str());
	}
}

string CLuaUI::LoadFile(const string& name, const std::string& mode) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static bool IsDisallowedCallIn(const string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaUI::HasCallIn(lua_State* L, const string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUI::UpdateTeams()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

bool CLuaUI::LoadCFunctions(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

bool CLuaUI::ConfigCommand(const string& command) //FIXME rename to fit event name
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



static inline float fuzzRand(float fuzz)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUI::ShockFront(const float3& pos, float power, float areaOfEffect, const float* distMod)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

bool CLuaUI::LayoutButtons(int& xButtons, int& yButtons,
                           const vector<SCommandDescription>& cmds,
                           vector<int>& removeCmds,
                           vector<SCommandDescription>& customCmds,
                           vector<int>& onlyTextureCmds,
                           vector<ReStringPair>& reTextureCmds,
                           vector<ReStringPair>& reNamedCmds,
                           vector<ReStringPair>& reTooltipCmds,
                           vector<ReParamsPair>& reParamsCmds,
                           map<int, int>& buttonList,
                           string& menuName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaUI::BuildCmdDescTable(lua_State* L,
                               const vector<SCommandDescription>& cmds)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaUI::GetLuaIntMap(lua_State* L, int index, map<int, int>& intMap)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaUI::GetLuaIntList(lua_State* L, int index, vector<int>& intList)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaUI::GetLuaReStringList(lua_State* L, int index,
                                vector<ReStringPair>& reStringList)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaUI::GetLuaReParamsList(lua_State* L, int index,
                                vector<ReParamsPair>& reParamsCmds)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaUI::GetLuaCmdDescList(lua_State* L, int index,
                               vector<SCommandDescription>& cmdDescs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/
//
// Lua Callbacks
//

int CLuaUI::SetShockFrontFactors(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
