#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <mutex>
#include <boost/thread/mutex.hpp>

#include "LuaIntro.h"

#include "LuaInclude.h"
#include "LuaArchive.h"
#include "LuaUnsyncedCtrl.h"
#include "LuaCallInCheck.h"
#include "LuaConstGL.h"
#include "LuaConstCMD.h"
#include "LuaConstCMDTYPE.h"
#include "LuaConstGame.h"
#include "LuaInterCall.h"
#include "LuaUnsyncedRead.h"
#include "LuaScream.h"
#include "LuaSyncedRead.h"
#include "LuaOpenGL.h"
#include "LuaUtils.h"
#include "LuaVFS.h"
#include "LuaIO.h"
#include "LuaZip.h"
#include "Rendering/IconHandler.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Util.h"


CLuaIntro* LuaIntro = NULL;

/******************************************************************************/
/******************************************************************************/

static boost::mutex m_singleton;

DECL_LOAD_HANDLER(CLuaIntro, LuaIntro)
DECL_FREE_HANDLER(CLuaIntro, LuaIntro)


/******************************************************************************/

CLuaIntro::CLuaIntro()
: CLuaHandle("LuaIntro", LUA_HANDLE_ORDER_INTRO, true, false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CLuaIntro::~CLuaIntro()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaIntro::RemoveSomeOpenGLFunctions(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaIntro::LoadUnsyncedCtrlFunctions(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaIntro::LoadUnsyncedReadFunctions(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaIntro::LoadSyncedReadFunctions(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


string CLuaIntro::LoadFile(const string& filename) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

void CLuaIntro::DrawLoadScreen()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaIntro::LoadProgress(const std::string& msg, const bool replace_lastline)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
