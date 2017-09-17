#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/EventHandler.h"

#include "LuaVFSDownload.h"
#include "System/EventHandler.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/Platform/Threading.h"
#include "System/Threading/SpringMutex.h"
#include "System/Util.h"

#include <queue>

#include "../tools/pr-downloader/src/pr-downloader.h"
#include "LuaInclude.h"

/******************************************************************************/
/******************************************************************************/
#define REGISTER_LUA_CFUNC(x)                                                  \
    lua_pushstring(L, #x);                                                     \
    lua_pushcfunction(L, x);                                                   \
    lua_rawset(L, -3)

LuaVFSDownload* luavfsdownload = nullptr;

struct dlEvent
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QueueDownloadStarted(int ID) // queue from other thread download started event
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QueueDownloadFinished(int ID) // queue from other thread download started event
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QueueDownloadFailed(
  int ID,
  int errorID) // queue from other thread download started event
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QueueDownloadProgress(
  int ID,
  long downloaded,
  long total) // queue from other thread download started event
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaVFSDownload::LuaVFSDownload()
  : CEventClient("[LuaVFSDownload]", 314161, false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaVFSDownload::~LuaVFSDownload()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaVFSDownload::PushEntries(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

struct DownloadItem
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

__FORCE_ALIGN_STACK__
int
Download(int ID, const std::string& filename, DownloadEnum::Category cat)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
StartDownload()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int
LuaVFSDownload::DownloadArchive(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaVFSDownload::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
