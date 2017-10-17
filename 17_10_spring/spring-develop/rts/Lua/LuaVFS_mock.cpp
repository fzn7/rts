// TODO: Substitue CLuaVFS with your actual class name
bool CLuaVFS::PushSynced(lua_State * L){}
bool CLuaVFS::PushUnsynced(lua_State * L){}
q(const).string CLuaVFS::GetModes(lua_State * L, int index, bool synced){}
bool CLuaVFS::PushCommon(lua_State * L){}
int CLuaVFS::Include(lua_State * L, bool synced){}
int CLuaVFS::LoadFile(lua_State * L, bool synced){}
int CLuaVFS::FileExists(lua_State * L, bool synced){}
int CLuaVFS::DirList(lua_State * L, bool synced){}
int CLuaVFS::SubDirs(lua_State * L, bool synced){}
int CLuaVFS::SyncInclude(lua_State * L){}
int CLuaVFS::SyncLoadFile(lua_State * L){}
int CLuaVFS::SyncFileExists(lua_State * L){}
int CLuaVFS::SyncDirList(lua_State * L){}
int CLuaVFS::SyncSubDirs(lua_State * L){}
int CLuaVFS::UnsyncInclude(lua_State * L){}
int CLuaVFS::UnsyncLoadFile(lua_State * L){}
int CLuaVFS::UnsyncFileExists(lua_State * L){}
int CLuaVFS::UnsyncDirList(lua_State * L){}
int CLuaVFS::UnsyncSubDirs(lua_State * L){}
int CLuaVFS::UseArchive(lua_State * L){}
int CLuaVFS::CompressFolder(lua_State * L){}
int CLuaVFS::SevenZipFolder(lua_State * L, const string & folderPath, const string & zipFilePath, bool includeFolder, const string & modes){}
int CLuaVFS::MapArchive(lua_State * L){}
int CLuaVFS::UnmapArchive(lua_State * L){}
int CLuaVFS::ZlibCompress(lua_State * L){}
int CLuaVFS::ZlibDecompress(lua_State * L){}
int CLuaVFS::PackU8(lua_State * L){}
int CLuaVFS::PackU16(lua_State * L){}
int CLuaVFS::PackU32(lua_State * L){}
int CLuaVFS::PackS8(lua_State * L){}
int CLuaVFS::PackS16(lua_State * L){}
int CLuaVFS::PackS32(lua_State * L){}
int CLuaVFS::PackF32(lua_State * L){}
int CLuaVFS::UnpackU8(lua_State * L){}
int CLuaVFS::UnpackU16(lua_State * L){}
int CLuaVFS::UnpackU32(lua_State * L){}
int CLuaVFS::UnpackS8(lua_State * L){}
int CLuaVFS::UnpackS16(lua_State * L){}
int CLuaVFS::UnpackS32(lua_State * L){}
int CLuaVFS::UnpackF32(lua_State * L){}
int CLuaVFS::CalculateHash(lua_State * L){}
