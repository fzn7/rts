// TODO: Substitue CLuaUser with your actual class name
void CLuaUser::LuaCreateMutex(lua_State * L){}
void CLuaUser::LuaDestroyMutex(lua_State * L){}
void CLuaUser::LuaLinkMutex(lua_State * L_parent, lua_State * L_child){}
void CLuaUser::LuaMutexLock(lua_State * L){}
void CLuaUser::LuaMutexUnlock(lua_State * L){}
void CLuaUser::LuaMutexYield(lua_State * L){}
q(const).char CLuaUser::spring_lua_getHandleName(lua_State * L){}
std::atomic<(uint64_t)> CLuaUser::allocedBytes(){}
std::atomic<(uint64_t)> CLuaUser::numLuaAllocs(){}
std::atomic<(uint64_t)> CLuaUser::luaAllocTime(){}
std::atomic<(uint64_t)> CLuaUser::numLuaStates(){}
char CLuaUser::msgBuf(){}
char CLuaUser::msgPtr(){}
void CLuaUser::spring_lua_alloc(void * ud, void * ptr, size_t osize, size_t nsize){}
void CLuaUser::spring_lua_alloc_get_stats(SLuaAllocState * state){}
bool CLuaUser::spring_lua_alloc_get_error(SLuaAllocError * error){}
void CLuaUser::spring_lua_alloc_update_stats(int clearStatsFrame){}
void CLuaUser::spring_lua_ftoa(float f, char * buf, int precision){}
void CLuaUser::spring_lua_ftoa(float f, char * buf){}
void CLuaUser::spring_lua_format(float f, const char * fmt, char * buf){}
