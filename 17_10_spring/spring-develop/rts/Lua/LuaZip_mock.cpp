// TODO: Substitue CLuaZip with your actual class name
void CLuaZip::zipFile(){}
bool CLuaZip::PushSynced(lua_State * L){}
bool CLuaZip::PushUnsynced(lua_State * L){}
bool CLuaZip::PushNew(lua_State * L, const std::string & filename, zipFile zip){}
bool CLuaZip::CreateMetatable(lua_State * L){}
int CLuaZip::open(lua_State * L){}
int CLuaZip::meta_gc(lua_State * L){}
int CLuaZip::meta_open(lua_State * L){}
int CLuaZip::meta_write(lua_State * L){}
bool CLuaZip::PushSynced(lua_State * L){}
bool CLuaZip::PushUnsynced(lua_State * L){}
bool CLuaZip::PushNew(lua_State * L, const std::string & filename, IArchive * archive){}
bool CLuaZip::CreateMetatable(lua_State * L){}
int CLuaZip::open(lua_State * L){}
int CLuaZip::meta_gc(lua_State * L){}
int CLuaZip::meta_open(lua_State * L){}
int CLuaZip::meta_read(lua_State * L){}
int CLuaZip::ZipFolder(lua_State * L, const std::string & folderPath, const std::string & zipFilePath, bool includeFolder, const std::string & modes){}
