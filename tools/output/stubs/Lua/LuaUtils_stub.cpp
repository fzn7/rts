#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

//#include "System/Platform/Win/win32.h"

#include <boost/cstdint.hpp>

#include <map>
#include <string.h>

#include "LuaConfig.h"
#include "LuaUtils.h"

#include "Rendering/Models/IModelParser.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Objects/SolidObjectDef.h"
#include "Sim/Units/CommandAI/CommandDescription.h"
#include "Sim/Units/UnitDef.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#if !defined UNITSYNC && !defined DEDICATED && !defined BUILDING_AI
#include "System/TimeProfiler.h"
#else
#define SCOPED_TIMER(x)
#endif

static const int maxDepth = 16;
int LuaUtils::exportedDataSize = 0;

/******************************************************************************/
/******************************************************************************/

static bool
CopyPushData(lua_State* dst,
             lua_State* src,
             int index,
             int depth,
             std::map<const void*, int>& alreadyCopied);
static bool
CopyPushTable(lua_State* dst,
              lua_State* src,
              int index,
              int depth,
              std::map<const void*, int>& alreadyCopied);

static inline int
PosAbsLuaIndex(lua_State* src, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
CopyPushData(lua_State* dst,
             lua_State* src,
             int index,
             int depth,
             std::map<const void*, int>& alreadyCopied)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
CopyPushTable(lua_State* dst,
              lua_State* src,
              int index,
              int depth,
              std::map<const void*, int>& alreadyCopied)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaUtils::CopyData(lua_State* dst, lua_State* src, int count)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static bool
BackupData(LuaUtils::DataDump& d, lua_State* src, int index, int depth);
static bool
RestoreData(const LuaUtils::DataDump& d, lua_State* dst, int depth);
static bool
BackupTable(LuaUtils::DataDump& d, lua_State* src, int index, int depth);
static bool
RestoreTable(const LuaUtils::DataDump& d, lua_State* dst, int depth);

static bool
BackupData(LuaUtils::DataDump& d, lua_State* src, int index, int depth)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
RestoreData(const LuaUtils::DataDump& d, lua_State* dst, int depth)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
BackupTable(LuaUtils::DataDump& d, lua_State* src, int index, int depth)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
RestoreTable(const LuaUtils::DataDump& d, lua_State* dst, int depth)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaUtils::Backup(std::vector<LuaUtils::DataDump>& backup,
                 lua_State* src,
                 int count)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaUtils::Restore(const std::vector<LuaUtils::DataDump>& backup, lua_State* dst)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static void
PushCurrentFunc(lua_State* L, const char* caller)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
PushFunctionEnv(lua_State* L, const char* caller, int funcIndex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaUtils::PushCurrentFuncEnv(lua_State* L, const char* caller)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static bool
LowerKeysCheck(lua_State* L, int table, int alreadyCheckTable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
LowerKeysReal(lua_State* L, int alreadyCheckTable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaUtils::LowerKeys(lua_State* L, int table)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
CheckForNaNsReal(lua_State* L, const std::string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaUtils::CheckTableForNaNs(lua_State* L, int table, const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

// copied from lua/src/lauxlib.cpp:luaL_checkudata()
void*
LuaUtils::GetUserData(lua_State* L, int index, const string& type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void
LuaUtils::PrintStack(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
LuaUtils::ParseIntArray(lua_State* L, int index, int* array, int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaUtils::ParseFloatArray(lua_State* L, int index, float* array, int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaUtils::ParseStringArray(lua_State* L, int index, string* array, int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaUtils::ParseIntVector(lua_State* L, int index, vector<int>& vec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaUtils::ParseFloatVector(lua_State* L, int index, vector<float>& vec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaUtils::ParseStringVector(lua_State* L, int index, vector<string>& vec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#if !defined UNITSYNC && !defined DEDICATED && !defined BUILDING_AI

int
LuaUtils::PushModelHeight(lua_State* L,
                          const SolidObjectDef* def,
                          bool isUnitDef)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaUtils::PushModelRadius(lua_State* L,
                          const SolidObjectDef* def,
                          bool isUnitDef)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaUtils::PushFeatureModelDrawType(lua_State* L, const FeatureDef* def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaUtils::PushModelName(lua_State* L, const SolidObjectDef* def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaUtils::PushModelTable(lua_State* L, const SolidObjectDef* def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaUtils::PushColVolTable(lua_State* L, const CollisionVolume* vol)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#endif //! defined UNITSYNC && !defined DEDICATED && !defined BUILDING_AI

void
LuaUtils::PushCommandParamsTable(lua_State* L,
                                 const Command& cmd,
                                 bool subtable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaUtils::PushCommandOptionsTable(lua_State* L,
                                  const Command& cmd,
                                  bool subtable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaUtils::PushUnitAndCommand(lua_State* L,
                             const CUnit* unit,
                             const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaUtils::ParseCommandOptions(lua_State* L,
                              Command& cmd,
                              const char* caller,
                              const int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Command
LuaUtils::ParseCommand(lua_State* L, const char* caller, int idIndex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Command
LuaUtils::ParseCommandTable(lua_State* L, const char* caller, int table)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaUtils::ParseCommandArray(lua_State* L,
                            const char* caller,
                            int table,
                            vector<Command>& commands)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaUtils::ParseFacing(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
LuaUtils::Next(const ParamMap& paramMap, lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static std::string
getprintf_msg(lua_State* L, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaUtils::Echo(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaUtils::PushLogEntries(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-
        Logs a msg to the logfile / console
        @param loglevel loglevel that will be used for the message
        @param msg string to be logged
        @fn Spring.Log(string logsection, int loglevel, ...)
        @fn Spring.Log(string logsection, string loglevel, ...)
*/
int
LuaUtils::Log(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

LuaUtils::ScopedStackChecker::ScopedStackChecker(lua_State* L, int _returnVars)
  : luaState(L)
  , prevTop(lua_gettop(luaState))
  , returnVars(_returnVars)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

    /******************************************************************************/
    /******************************************************************************/

#define DEBUG_TABLE "debug"
#define DEBUG_FUNC "traceback"

/// this function always leaves one item on the stack
/// and returns its index if valid and zero otherwise
int
LuaUtils::PushDebugTraceback(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaUtils::ScopedDebugTraceBack::ScopedDebugTraceBack(lua_State* _L)
  : L(_L)
  , errFuncIdx(PushDebugTraceback(_L))
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaUtils::ScopedDebugTraceBack::~ScopedDebugTraceBack()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void
LuaUtils::PushStringVector(lua_State* L, const vector<string>& vec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void
LuaUtils::PushCommandDesc(lua_State* L, const SCommandDescription& cd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
