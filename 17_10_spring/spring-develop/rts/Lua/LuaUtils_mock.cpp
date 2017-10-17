// TODO: Substitue CLuaUtils with your actual class name
int CLuaUtils::exportedDataSize(){}
int CLuaUtils::Backup(std::vector<(LuaUtils::DataDump)> & backup, lua_State * src, int count){}
int CLuaUtils::Restore(const std::vector<(LuaUtils::DataDump)> & backup, lua_State * dst){}
int CLuaUtils::CopyData(lua_State * dst, lua_State * src, int count){}
int CLuaUtils::PushDebugTraceback(lua_State * L){}
bool CLuaUtils::LowerKeys(lua_State * L, int tableIndex){}
bool CLuaUtils::CheckTableForNaNs(lua_State * L, int table, const std::string & name){}
int CLuaUtils::PushModelHeight(lua_State * L, const SolidObjectDef * def, bool isUnitDef){}
int CLuaUtils::PushModelRadius(lua_State * L, const SolidObjectDef * def, bool isUnitDef){}
int CLuaUtils::PushFeatureModelDrawType(lua_State * L, const FeatureDef * def){}
int CLuaUtils::PushModelName(lua_State * L, const SolidObjectDef * def){}
int CLuaUtils::PushModelType(lua_State * L, const SolidObjectDef * def){}
int CLuaUtils::PushModelPath(lua_State * L, const SolidObjectDef * def){}
int CLuaUtils::PushModelTable(lua_State * L, const SolidObjectDef * def){}
int CLuaUtils::PushColVolTable(lua_State * L, const CollisionVolume * vol){}
int CLuaUtils::PushColVolData(lua_State * L, const CollisionVolume * vol){}
int CLuaUtils::ParseColVolData(lua_State * L, int idx, CollisionVolume * vol){}
void CLuaUtils::PushCommandParamsTable(lua_State * L, const Command & cmd, bool subtable){}
void CLuaUtils::PushCommandOptionsTable(lua_State * L, const Command & cmd, bool subtable){}
void CLuaUtils::PushUnitAndCommand(lua_State * L, const CUnit * unit, const Command & cmd){}
void CLuaUtils::ParseCommandOptions(lua_State * L, Command & cmd, const char * caller, int index){}
Command CLuaUtils::ParseCommand(lua_State * L, const char * caller, int idIndex){}
Command CLuaUtils::ParseCommandTable(lua_State * L, const char * caller, int table){}
void CLuaUtils::ParseCommandArray(lua_State * L, const char * caller, int table, vector<(Command)> & commands){}
int CLuaUtils::ParseFacing(lua_State * L, const char * caller, int index){}
void CLuaUtils::PushCurrentFuncEnv(lua_State * L, const char * caller){}
void CLuaUtils::GetUserData(lua_State * L, int index, const string & type){}
void CLuaUtils::PrintStack(lua_State * L){}
int CLuaUtils::Next(const ParamMap & paramMap, lua_State * L){}
int CLuaUtils::Echo(lua_State * L){}
int CLuaUtils::Log(lua_State * L){}
bool CLuaUtils::PushLogEntries(lua_State * L){}
bool CLuaUtils::PushCustomBaseFunctions(lua_State * L){}
int CLuaUtils::ParseIntArray(lua_State * L, int tableIndex, int * array, int arraySize){}
int CLuaUtils::ParseFloatArray(lua_State * L, int tableIndex, float * array, int arraySize){}
int CLuaUtils::ParseStringArray(lua_State * L, int tableIndex, string * array, int arraySize){}
int CLuaUtils::ParseIntVector(lua_State * L, int tableIndex, vector<(int)> & vec){}
int CLuaUtils::ParseFloatVector(lua_State * L, int tableIndex, vector<(float)> & vec){}
int CLuaUtils::ParseStringVector(lua_State * L, int tableIndex, vector<(string)> & vec){}
void CLuaUtils::PushStringVector(lua_State * L, const vector<(string)> & vec){}
void CLuaUtils::PushCommandDesc(lua_State * L, const SCommandDescription & cd){}
