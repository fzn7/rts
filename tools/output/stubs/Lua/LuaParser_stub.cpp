#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaParser.h"

#include <algorithm>
#include <boost/regex.hpp>
#include <limits.h>

#include "lib/streflop/streflop_cond.h"

#include "LuaInclude.h"
#include "System/float3.h"
#include "System/float4.h"

#include "LuaIO.h"
#include "LuaUtils.h"

#include "Game/GameVersion.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/Log/ILog.h"
#include "System/Misc/SpringTime.h"
#include "System/ScopedFPUSettings.h"
#include "System/Util.h"

LuaParser* LuaParser::currentParser = NULL;

/******************************************************************************/
/******************************************************************************/
//
//  LuaParser
//

LuaParser::LuaParser(const string& _fileName,
                     const string& _fileModes,
                     const string& _accessModes)
  : fileName(_fileName)
  , fileModes(_fileModes)
  , textChunk("")
  , accessModes(_accessModes)
  , valid(false)
  , initDepth(0)
  , rootRef(LUA_NOREF)
  , currentRef(LUA_NOREF)
  , lowerKeys(true)
  , lowerCppKeys(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaParser::LuaParser(const string& _textChunk, const string& _accessModes)
  : fileName("")
  , fileModes("")
  , textChunk(_textChunk)
  , accessModes(_accessModes)
  , valid(false)
  , initDepth(0)
  , rootRef(LUA_NOREF)
  , currentRef(LUA_NOREF)
  , lowerKeys(true)
  , lowerCppKeys(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaParser::~LuaParser()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaParser::SetupEnv()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

bool
LuaParser::Execute()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaParser::AddTable(LuaTable* tbl)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaParser::RemoveTable(LuaTable* tbl)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaTable
LuaParser::GetRoot()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void
LuaParser::PushParam()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaParser::GetTable(const string& name, bool overwrite)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaParser::GetTable(int index, bool overwrite)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaParser::EndTable()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void
LuaParser::AddFunc(const string& key, int (*func)(lua_State*))
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaParser::AddInt(const string& key, int value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaParser::AddBool(const string& key, bool value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaParser::AddFloat(const string& key, float value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaParser::AddString(const string& key, const string& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void
LuaParser::AddFunc(int key, int (*func)(lua_State*))
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaParser::AddInt(int key, int value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaParser::AddBool(int key, bool value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaParser::AddFloat(int key, float value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaParser::AddString(int key, const string& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  call-outs
//

int
LuaParser::TimeCheck(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int
LuaParser::DirList(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaParser::SubDirs(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int
LuaParser::Include(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int
LuaParser::LoadFile(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaParser::FileExists(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaParser::DontMessWithMyCase(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  LuaTable
//

LuaTable::LuaTable()
  : path("")
  , isValid(false)
  , parser(NULL)
  , L(NULL)
  , refnum(LUA_NOREF)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaTable::LuaTable(const LuaTable& tbl)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaTable&
LuaTable::operator=(const LuaTable& tbl)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaTable
LuaTable::SubTable(int key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaTable
LuaTable::SubTable(const string& mixedKey) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaTable
LuaTable::SubTableExpr(const string& expr) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaTable::~LuaTable()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

bool
LuaTable::PushTable() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaTable::PushValue(int key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaTable::PushValue(const string& mixedKey) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  Key existance testing
//

bool
LuaTable::KeyExists(int key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaTable::KeyExists(const string& key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  Value types
//

LuaTable::DataType
LuaTable::GetType(int key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaTable::DataType
LuaTable::GetType(const string& key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  Object lengths
//

int
LuaTable::GetLength() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaTable::GetLength(int key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaTable::GetLength(const string& key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  Key list functions
//

bool
LuaTable::GetKeys(vector<int>& data) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaTable::GetKeys(vector<string>& data) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  Map functions
//

bool
LuaTable::GetMap(map<int, float>& data) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaTable::GetMap(map<int, string>& data) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaTable::GetMap(map<string, float>& data) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaTable::GetMap(map<string, string>& data) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  Parsing utilities
//

static bool
ParseTableFloat(lua_State* L, int tableIndex, int index, float& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
ParseFloat3(lua_State* L, int index, float3& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
ParseFloat4(lua_State* L, int index, float4& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
ParseBoolean(lua_State* L, int index, bool& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  String key functions
//

int
LuaTable::Get(const string& key, int def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaTable::Get(const string& key, bool def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
LuaTable::Get(const string& key, float def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
LuaTable::Get(const string& key, const float3& def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float4
LuaTable::Get(const string& key, const float4& def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

string
LuaTable::Get(const string& key, const string& def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  Number key functions
//

int
LuaTable::Get(int key, int def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaTable::Get(int key, bool def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
LuaTable::Get(int key, float def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
LuaTable::Get(int key, const float3& def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float4
LuaTable::Get(int key, const float4& def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

string
LuaTable::Get(int key, const string& def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  Number key functions
//

float3
LuaTable::GetFloat3(int key, const float3& def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float4
LuaTable::GetFloat4(int key, const float4& def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
LuaTable::GetFloat3(const string& key, const float3& def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float4
LuaTable::GetFloat4(const string& key, const float4& def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
