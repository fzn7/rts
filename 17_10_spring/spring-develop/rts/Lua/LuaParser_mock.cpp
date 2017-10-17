#include "LuaParser.h"
#include <algorithm>
#include <limits.h>

#include "lib/streflop/streflop_cond.h"

#include "System/float3.h"
#include "System/float4.h"
#include "LuaInclude.h"

#include "LuaConstEngine.h"
#include "LuaIO.h"
#include "LuaUtils.h"

#include "Game/GameVersion.h"
#include "Sim/Misc/GlobalSynced.h" // gsRNG
#include "System/Log/ILog.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Misc/SpringTime.h"
#include "System/ContainerUtil.h"
#include "System/ScopedFPUSettings.h"
#include "System/StringUtil.h"

LuaTable::LuaTable()
: path(""),
  isValid(false),
  parser(NULL),
  L(NULL),
  refnum(LUA_NOREF)
{
}

LuaTable::LuaTable(LuaParser* _parser)
{
/*
	assert(_parser != NULL);

	isValid = _parser->IsValid();
	path    = "ROOT";
	parser  = _parser;
	L       = parser->L;
	refnum  = parser->rootRef;

	parser->AddTable(this);

	if (PushTable()) {
		lua_pushvalue(L, -1); // copy
		refnum = luaL_ref(L, LUA_REGISTRYINDEX);
	} else {
	 	refnum = LUA_NOREF;
	}
	isValid = (refnum != LUA_NOREF);
	*/
}


LuaTable::LuaTable(const LuaTable& tbl)
{
/*
	parser = tbl.parser;
	L      = tbl.L;
	path   = tbl.path;

	if (parser != nullptr)
		parser->AddTable(this);

	if (tbl.PushTable()) {
		lua_pushvalue(L, -1); // copy
		refnum = luaL_ref(L, LUA_REGISTRYINDEX);
	} else {
		refnum = LUA_NOREF;
	}
	isValid = (refnum != LUA_NOREF);
	*/
}




// TODO: Substitue CLuaParser with your actual class name
LuaTable& LuaTable::operator= (const LuaTable & tbl){}
LuaTable LuaTable::SubTable(int key) const{}
LuaTable LuaTable::SubTable(const string & mixedKey) const {}
LuaTable LuaTable::SubTableExpr(const string & expr) const {}
int LuaTable::GetLength() const {}
int LuaTable::GetLength(int key)const{}
int LuaTable::GetLength(const string & key)const{}
bool LuaTable::GetKeys(std::vector<int> & data)const{}
bool LuaTable::GetKeys(std::vector<string> & data)const{}
bool LuaTable::GetMap(spring::unordered_map<int,float> & data)const{}
bool LuaTable::GetMap(spring::unordered_map<int,string> & data)const{}
bool LuaTable::GetMap(spring::unordered_map<string,float> & data)const{}
bool LuaTable::GetMap(spring::unordered_map<string,string> & data)const{}
bool LuaTable::KeyExists(int key)const{}
bool LuaTable::KeyExists(const string & key)const{}
LuaTable::DataType LuaTable::GetType(int key)const{}
LuaTable::DataType LuaTable::GetType(const string & key)const{}
int LuaTable::Get(int key, int def)const{}
bool LuaTable::Get(int key, bool def)const{}
float LuaTable::Get(int key, float def)const{}
float3 LuaTable::Get(int key, const float3 & def)const{}
float4 LuaTable::Get(int key, const float4 & def)const{}
string LuaTable::Get(int key, const string & def)const{}
int LuaTable::Get(const string & key, int def)const{}
bool LuaTable::Get(const string & key, bool def)const{}
float LuaTable::Get(const string & key, float def)const{}
float3 LuaTable::Get(const string & key, const float3 & def)const{}
float4 LuaTable::Get(const string & key, const float4 & def)const{}
string LuaTable::Get(const string & key, const string & def)const{}
float3 LuaTable::GetFloat3(int key, const float3 & def)const{}
float4 LuaTable::GetFloat4(int key, const float4 & def)const{}
float3 LuaTable::GetFloat3(const string & key, const float3 & def)const{}
float4 LuaTable::GetFloat4(const string & key, const float4 & def)const{}
bool LuaTable::PushTable()const{}
bool LuaTable::PushValue(int key)const{}
bool LuaTable::PushValue(const string & key)const{}
//string LuaTable::path()const{}
//bool LuaTable::isValid()const{}
//LuaParser LuaTable::parser()const{}
//lua_State LuaTable::L()const{}
//int LuaTable::refnum()const{}
bool LuaParser::Execute(){}
LuaTable LuaParser::GetRoot(){}
void LuaParser::GetTable(int index, bool overwrite){}

void LuaParser::GetTable(const string & name, bool overwrite){}

void LuaParser::EndTable(){}
void LuaParser::AddFunc(int key, int (*func)(lua_State*)){}
void LuaParser::AddInt(int key, int value){}
void LuaParser::AddBool(int key, bool value){}
void LuaParser::AddFloat(int key, float value){}
void LuaParser::AddString(int key, const string & value){}
void LuaParser::AddFunc(const string & key, int (*func)(lua_State*)){}
void LuaParser::AddInt(const string & key, int value){}
void LuaParser::AddBool(const string & key, bool value){}
void LuaParser::AddFloat(const string & key, float value){}
void LuaParser::AddString(const string & key, const string & value){}
//q(const).string LuaParser::fileName(){}
//q(const).string LuaParser::fileModes(){}
//q(const).string LuaParser::textChunk(){}
//q(const).string LuaParser::accessModes(){}
void LuaParser::SetupEnv(bool synced){}
void LuaParser::PushParam(){}
void LuaParser::AddTable(LuaTable * tbl){}
void LuaParser::RemoveTable(LuaTable * tbl){}
/*
lua_State LuaParser::L(){}
luaContextData LuaParser::D(){}
std::vector<p.LuaTable> LuaParser::tables(){}
std::vector<string> LuaParser::accessedFiles(){}
int LuaParser::initDepth(){}
int LuaParser::rootRef(){}
int LuaParser::currentRef(){}
bool LuaParser::valid(){}
bool LuaParser::lowerKeys(){}
bool LuaParser::lowerCppKeys(){}
string LuaParser::errorLog(){}
*/
int LuaParser::DontMessWithMyCase(lua_State * L){}
int LuaParser::RandomSeed(lua_State * L){}
int LuaParser::Random(lua_State * L){}
int LuaParser::DummyRandomSeed(lua_State * L){}
int LuaParser::DummyRandom(lua_State * L){}
int LuaParser::TimeCheck(lua_State * L){}
int LuaParser::DirList(lua_State * L){}
int LuaParser::SubDirs(lua_State * L){}
int LuaParser::Include(lua_State * L){}
int LuaParser::LoadFile(lua_State * L){}
int LuaParser::FileExists(lua_State * L){}
