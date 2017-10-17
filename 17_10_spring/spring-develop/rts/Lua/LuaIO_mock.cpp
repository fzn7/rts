// TODO: Substitue CLuaIO with your actual class name
FILE CLuaIO::fopen(lua_State * L, const char * path, const char * mode){}
FILE CLuaIO::popen(lua_State * L, const char * command, const char * type){}
int CLuaIO::pclose(lua_State * L, FILE * stream){}
int CLuaIO::system(lua_State * L, const char * command){}
int CLuaIO::remove(lua_State * L, const char * pathname){}
int CLuaIO::rename(lua_State * L, const char * oldpath, const char * newpath){}
bool CLuaIO::IsSimplePath(const std::string & path){}
bool CLuaIO::SafeExecPath(const std::string & path){}
bool CLuaIO::SafeReadPath(const std::string & path){}
bool CLuaIO::SafeWritePath(const std::string & path){}
