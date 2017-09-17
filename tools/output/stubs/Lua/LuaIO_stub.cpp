/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include <stdio.h>
#include <errno.h>

#ifndef _MSC_VER	// this header file does not exist for the microsoft compiler
 #include <unistd.h>
#endif

#include <string>
using std::string;

#include "LuaIO.h"

#if !defined UNITSYNC && !defined DEDICATED && !defined BUILDING_AI
#include "LuaHandle.h"
#endif // !defined UNITSYNC && !defined DEDICATED && !defined BUILDING_AI
#include "LuaInclude.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Util.h"


/******************************************************************************/
/******************************************************************************/

static bool IsSafePath(const string& path)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

bool LuaIO::IsSimplePath(const string& path)
{
    //stub method
}


bool LuaIO::SafeExecPath(const string& path)
{
    //stub method
}


bool LuaIO::SafeReadPath(const string& path)
{
    //stub method
}


bool LuaIO::SafeWritePath(const string& path)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

FILE* LuaIO::fopen(lua_State* L, const char* path, const char* mode)
{
    //stub method
}


FILE* LuaIO::popen(lua_State* L, const char* command, const char* type)
{
    //stub method
}


int LuaIO::pclose(lua_State* L, FILE* stream)
{
    //stub method
}


int LuaIO::system(lua_State* L, const char* command)
{
    //stub method
}


int LuaIO::remove(lua_State* L, const char* pathname)
{
    //stub method
}


int LuaIO::rename(lua_State* L, const char* oldpath, const char* newpath)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/
