#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

//#include "System/Platform/Win/win32.h"

#include <boost/cstdint.hpp>

#include <string.h>
#include <map>

#include "LuaUtils.h"
#include "LuaConfig.h"

#include "Rendering/Models/IModelParser.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Objects/SolidObjectDef.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/CommandAI/CommandDescription.h"
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


static bool CopyPushData(lua_State* dst, lua_State* src, int index, int depth, std::map<const void*, int>& alreadyCopied);
static bool CopyPushTable(lua_State* dst, lua_State* src, int index, int depth, std::map<const void*, int>& alreadyCopied);


static inline int PosAbsLuaIndex(lua_State* src, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static bool CopyPushData(lua_State* dst, lua_State* src, int index, int depth, std::map<const void*, int>& alreadyCopied)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static bool CopyPushTable(lua_State* dst, lua_State* src, int index, int depth, std::map<const void*, int>& alreadyCopied)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUtils::CopyData(lua_State* dst, lua_State* src, int count)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static bool BackupData(LuaUtils::DataDump &d, lua_State* src, int index, int depth);
static bool RestoreData(const LuaUtils::DataDump &d, lua_State* dst, int depth);
static bool BackupTable(LuaUtils::DataDump &d, lua_State* src, int index, int depth);
static bool RestoreTable(const LuaUtils::DataDump &d, lua_State* dst, int depth);


static bool BackupData(LuaUtils::DataDump &d, lua_State* src, int index, int depth) {
	++LuaUtils::exportedDataSize;
	const int type = lua_type(src, index);
	d.type = type;
	switch (type) {
		case LUA_TBOOLEAN: {
			d.bol = lua_toboolean(src, index);
			break;
		}
		case LUA_TNUMBER: {
			d.num = lua_tonumber(src, index);
			break;
		}
		case LUA_TSTRING: {
			size_t len = 0;
			const char* data = lua_tolstring(src, index, &len);
			if (len > 0) {
				d.str.resize(len);
				memcpy(&d.str[0], data, len);
			}
			break;
		}
		case LUA_TTABLE: {
			if(!BackupTable(d, src, index, depth))
				d.type = LUA_TNIL;
			break;
		}
		default: {
			d.type = LUA_TNIL;
			break;
		}
	}
	return true;
}

static bool RestoreData(const LuaUtils::DataDump &d, lua_State* dst, int depth) {
	--LuaUtils::exportedDataSize;
	const int type = d.type;
	switch (type) {
		case LUA_TBOOLEAN: {
			lua_pushboolean(dst, d.bol);
			break;
		}
		case LUA_TNUMBER: {
			lua_pushnumber(dst, d.num);
			break;
		}
		case LUA_TSTRING: {
			lua_pushlstring(dst, d.str.c_str(), d.str.size());
			break;
		}
		case LUA_TTABLE: {
			RestoreTable(d, dst, depth);
			break;
		}
		default: {
			lua_pushnil(dst);
			break;
		}
	}
	return true;
}

static bool BackupTable(LuaUtils::DataDump &d, lua_State* src, int index, int depth) {
	if (depth++ > maxDepth)
		return false;

	const int table = PosAbsLuaIndex(src, index);
	for (lua_pushnil(src); lua_next(src, table) != 0; lua_pop(src, 1)) {
		LuaUtils::DataDump dk, dv;
		BackupData(dk, src, -2, depth);
		BackupData(dv, src, -1, depth);
		d.table.push_back(std::pair<LuaUtils::DataDump, LuaUtils::DataDump>(dk ,dv));
	}

	return true;
}

static bool RestoreTable(const LuaUtils::DataDump &d, lua_State* dst, int depth) {
	if (depth++ > maxDepth) {
		lua_pushnil(dst);
		return false;
	}

	lua_newtable(dst);
	for (std::vector<std::pair<LuaUtils::DataDump, LuaUtils::DataDump> >::const_iterator i = d.table.begin(); i != d.table.end(); ++i) {
		RestoreData((*i).first, dst, depth);
		RestoreData((*i).second, dst, depth);
		lua_rawset(dst, -3);
	}

	return true;
}


int LuaUtils::Backup(std::vector<LuaUtils::DataDump> &backup, lua_State* src, int count) {
	const int srcTop = lua_gettop(src);
	if (srcTop < count)
		return 0;

	const int startIndex = (srcTop - count + 1);
	const int endIndex   = srcTop;
	for (int i = startIndex; i <= endIndex; i++) {
		backup.push_back(DataDump());
		BackupData(backup.back(), src, i, 0);
	}

	return count;
}


int LuaUtils::Restore(const std::vector<LuaUtils::DataDump> &backup, lua_State* dst) {
	const int dstTop = lua_gettop(dst);
	int count = backup.size();
	lua_checkstack(dst, count + 3);

	for (std::vector<DataDump>::const_iterator i = backup.begin(); i != backup.end(); ++i) {
		RestoreData(*i, dst, 0);
	}
	lua_settop(dst, dstTop + count);

	return count;
}


/******************************************************************************/
/******************************************************************************/

static void PushCurrentFunc(lua_State* L, const char* caller)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static void PushFunctionEnv(lua_State* L, const char* caller, int funcIndex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaUtils::PushCurrentFuncEnv(lua_State* L, const char* caller)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/


static bool LowerKeysCheck(lua_State* L, int table, int alreadyCheckTable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static bool LowerKeysReal(lua_State* L, int alreadyCheckTable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool LuaUtils::LowerKeys(lua_State* L, int table)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static bool CheckForNaNsReal(lua_State* L, const std::string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool LuaUtils::CheckTableForNaNs(lua_State* L, int table, const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

// copied from lua/src/lauxlib.cpp:luaL_checkudata()
void* LuaUtils::GetUserData(lua_State* L, int index, const string& type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

void LuaUtils::PrintStack(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaUtils::ParseIntArray(lua_State* L, int index, int* array, int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUtils::ParseFloatArray(lua_State* L, int index, float* array, int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUtils::ParseStringArray(lua_State* L, int index, string* array, int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUtils::ParseIntVector(lua_State* L, int index, vector<int>& vec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUtils::ParseFloatVector(lua_State* L, int index, vector<float>& vec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUtils::ParseStringVector(lua_State* L, int index, vector<string>& vec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


#if !defined UNITSYNC && !defined DEDICATED && !defined BUILDING_AI


int LuaUtils::PushModelHeight(lua_State* L, const SolidObjectDef* def, bool isUnitDef)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUtils::PushModelRadius(lua_State* L, const SolidObjectDef* def, bool isUnitDef)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUtils::PushFeatureModelDrawType(lua_State* L, const FeatureDef* def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUtils::PushModelName(lua_State* L, const SolidObjectDef* def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUtils::PushModelTable(lua_State* L, const SolidObjectDef* def) {
	const std::string& modelPath = modelLoader.FindModelPath(def->modelName);
	const std::string& modelType = StringToLower(FileSystem::GetExtension(modelPath));

	const S3DModel* model = def->LoadModel();

	lua_newtable(L);
	HSTR_PUSH_STRING(L, "type", modelType);
	HSTR_PUSH_STRING(L, "path", modelPath);
	HSTR_PUSH_STRING(L, "name", def->modelName);

	if (model != nullptr) {
		// unit, or non-tree feature
		HSTR_PUSH_NUMBER(L, "minx", model->mins.x);
		HSTR_PUSH_NUMBER(L, "miny", model->mins.y);
		HSTR_PUSH_NUMBER(L, "minz", model->mins.z);
		HSTR_PUSH_NUMBER(L, "maxx", model->maxs.x);
		HSTR_PUSH_NUMBER(L, "maxy", model->maxs.y);
		HSTR_PUSH_NUMBER(L, "maxz", model->maxs.z);

		HSTR_PUSH_NUMBER(L, "midx", model->relMidPos.x);
		HSTR_PUSH_NUMBER(L, "midy", model->relMidPos.y);
		HSTR_PUSH_NUMBER(L, "midz", model->relMidPos.z);
	} else {
		HSTR_PUSH_NUMBER(L, "minx", 0.0f);
		HSTR_PUSH_NUMBER(L, "miny", 0.0f);
		HSTR_PUSH_NUMBER(L, "minz", 0.0f);
		HSTR_PUSH_NUMBER(L, "maxx", 0.0f);
		HSTR_PUSH_NUMBER(L, "maxy", 0.0f);
		HSTR_PUSH_NUMBER(L, "maxz", 0.0f);

		HSTR_PUSH_NUMBER(L, "midx", 0.0f);
		HSTR_PUSH_NUMBER(L, "midy", 0.0f);
		HSTR_PUSH_NUMBER(L, "midz", 0.0f);
	}

	HSTR_PUSH(L, "textures");
	lua_newtable(L);

	if (model != nullptr) {
		LuaPushNamedString(L, "tex1", model->texs[0]);
		LuaPushNamedString(L, "tex2", model->texs[1]);
	} else {
		// just leave these nil
	}

	// model["textures"] = {}
	lua_rawset(L, -3);

	return 1;
}

int LuaUtils::PushColVolTable(lua_State* L, const CollisionVolume* vol) {
	assert(vol != nullptr);

	lua_newtable(L);
	switch (vol->GetVolumeType()) {
		case CollisionVolume::COLVOL_TYPE_ELLIPSOID:
			HSTR_PUSH_STRING(L, "type", "ellipsoid");
			break;
		case CollisionVolume::COLVOL_TYPE_CYLINDER:
			HSTR_PUSH_STRING(L, "type", "cylinder");
			break;
		case CollisionVolume::COLVOL_TYPE_BOX:
			HSTR_PUSH_STRING(L, "type", "box");
			break;
		case CollisionVolume::COLVOL_TYPE_SPHERE:
			HSTR_PUSH_STRING(L, "type", "sphere");
			break;
	}

	LuaPushNamedNumber(L, "scaleX", vol->GetScales().x);
	LuaPushNamedNumber(L, "scaleY", vol->GetScales().y);
	LuaPushNamedNumber(L, "scaleZ", vol->GetScales().z);
	LuaPushNamedNumber(L, "offsetX", vol->GetOffsets().x);
	LuaPushNamedNumber(L, "offsetY", vol->GetOffsets().y);
	LuaPushNamedNumber(L, "offsetZ", vol->GetOffsets().z);
	LuaPushNamedNumber(L, "boundingRadius", vol->GetBoundingRadius());
	LuaPushNamedBool(L, "defaultToSphere",    vol->DefaultToSphere());
	LuaPushNamedBool(L, "defaultToFootPrint", vol->DefaultToFootPrint());
	LuaPushNamedBool(L, "defaultToPieceTree", vol->DefaultToPieceTree());
	return 1;
}


#endif //!defined UNITSYNC && !defined DEDICATED && !defined BUILDING_AI


void LuaUtils::PushCommandParamsTable(lua_State* L, const Command& cmd, bool subtable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaUtils::PushCommandOptionsTable(lua_State* L, const Command& cmd, bool subtable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaUtils::PushUnitAndCommand(lua_State* L, const CUnit* unit, const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaUtils::ParseCommandOptions(
	lua_State* L,
	Command& cmd,
	const char* caller,
	const int idx
) {
	if (lua_isnumber(L, idx)) {
		cmd.options = (unsigned char)lua_tonumber(L, idx);
	} else if (lua_istable(L, idx)) {
		for (lua_pushnil(L); lua_next(L, idx) != 0; lua_pop(L, 1)) {
			// "key" = value (table format of CommandNotify)
			if (lua_israwstring(L, -2)) {
				const std::string key = lua_tostring(L, -2);

				// we do not care about the "coded" key (not a boolean value)
				if (!lua_isboolean(L, -1))
					continue;

				const bool value = lua_toboolean(L, -1);

				if (key == "right") {
					cmd.options |= (RIGHT_MOUSE_KEY * value);
				} else if (key == "alt") {
					cmd.options |= (ALT_KEY * value);
				} else if (key == "ctrl") {
					cmd.options |= (CONTROL_KEY * value);
				} else if (key == "shift") {
					cmd.options |= (SHIFT_KEY * value);
				} else if (key == "meta") {
					cmd.options |= (META_KEY * value);
				}

				continue;
			}

			// [idx] = "value", avoid 'n'
			if (lua_israwnumber(L, -2)) {
				//const int idx = lua_tonumber(L, -2);

				if (!lua_isstring(L, -1))
					continue;

				const std::string value = lua_tostring(L, -1);

				if (value == "right") {
					cmd.options |= RIGHT_MOUSE_KEY;
				} else if (value == "alt") {
					cmd.options |= ALT_KEY;
				} else if (value == "ctrl") {
					cmd.options |= CONTROL_KEY;
				} else if (value == "shift") {
					cmd.options |= SHIFT_KEY;
				} else if (value == "meta") {
					cmd.options |= META_KEY;
				}
			}
		}
	} else {
		luaL_error(L, "%s(): bad options-argument type", caller);
	}
}


Command LuaUtils::ParseCommand(lua_State* L, const char* caller, int idIndex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


Command LuaUtils::ParseCommandTable(lua_State* L, const char* caller, int table)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaUtils::ParseCommandArray(lua_State* L, const char* caller,
                                 int table, vector<Command>& commands)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUtils::ParseFacing(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/


int LuaUtils::Next(const ParamMap& paramMap, lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

static std::string getprintf_msg(lua_State* L, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUtils::Echo(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool LuaUtils::PushLogEntries(lua_State* L)
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
int LuaUtils::Log(lua_State* L)
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

LuaUtils::ScopedStackChecker::~ScopedStackChecker() {
	const int curTop = lua_gettop(luaState); // use var so you can print it in gdb
	assert(curTop == prevTop + returnVars);
}

/******************************************************************************/
/******************************************************************************/

#define DEBUG_TABLE "debug"
#define DEBUG_FUNC "traceback"

/// this function always leaves one item on the stack
/// and returns its index if valid and zero otherwise
int LuaUtils::PushDebugTraceback(lua_State* L)
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

LuaUtils::ScopedDebugTraceBack::~ScopedDebugTraceBack() {
	// make sure we are at same position on the stack
	const int curTop = lua_gettop(L);
	assert(errFuncIdx == 0 || curTop == errFuncIdx);

	lua_pop(L, 1);
}

/******************************************************************************/
/******************************************************************************/

void LuaUtils::PushStringVector(lua_State* L, const vector<string>& vec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void LuaUtils::PushCommandDesc(lua_State* L, const SCommandDescription& cd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

