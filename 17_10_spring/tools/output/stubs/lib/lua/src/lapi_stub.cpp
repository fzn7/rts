#include <iostream>
/*
** $Id: lapi.c,v 2.55.1.5 2008/07/04 18:41:18 roberto Exp $
** Lua API
** See Copyright Notice in lua.h
*/

#include <assert.h>
// SPRING#include <math.h>
#include "streflop_cond.h"
#include <stdarg.h>
#include <string.h>

#define lapi_c
#define LUA_CORE

#include "lua.h"

#include "lapi.h"
#include "ldebug.h"
#include "ldo.h"
#include "lfunc.h"
#include "lgc.h"
#include "lmem.h"
#include "lobject.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "ltm.h"
#include "lundump.h"
#include "lvm.h"

const char lua_ident[] = "$Lua: " LUA_RELEASE " " LUA_COPYRIGHT " $\n"
                         "$Authors: " LUA_AUTHORS " $\n"
                         "$URL: www.lua.org $\n";

#define api_checknelems(L, n) api_check(L, (n) <= (L->top - L->base))

#define api_checkvalidindex(L, i) api_check(L, (i) != luaO_nilobject)

#define api_incr_top(L)                                                        \
    {                                                                          \
        api_check(L, L->top < L->ci->top);                                     \
        L->top++;                                                              \
    }

static TValue*
index2adr(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static Table*
getcurrenv(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
luaA_pushobject(lua_State* L, const TValue* o)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_checkstack(lua_State* L, int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_xmove(lua_State* from, lua_State* to, int n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_setlevel(lua_State* from, lua_State* to)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API lua_CFunction
lua_atpanic(lua_State* L, lua_CFunction panicf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API lua_State*
lua_newthread(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** basic stack manipulation
*/

LUA_API int
lua_gettop(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_settop(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_remove(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_insert(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_replace(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_pushvalue(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** access functions (stack -> C)
*/

LUA_API int
lua_type(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API const char*
lua_typename(lua_State* L, int t)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_iscfunction(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_isnumber(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_isstring(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_isuserdata(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_rawequal(lua_State* L, int index1, int index2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_equal(lua_State* L, int index1, int index2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_lessthan(lua_State* L, int index1, int index2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API lua_Number
lua_tonumber(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API lua_Integer
lua_tointeger(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API bool
lua_toboolean(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API const char*
lua_tolstring(lua_State* L, int idx, size_t* len)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API size_t
lua_objlen(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API lua_CFunction
lua_tocfunction(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void*
lua_touserdata(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API lua_State*
lua_tothread(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API const void*
lua_topointer(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** push functions (C -> stack)
*/

LUA_API void
lua_pushnil(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_pushnumber(lua_State* L, lua_Number n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_pushinteger(lua_State* L, lua_Integer n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_pushlstring(lua_State* L, const char* s, size_t len)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// SPRING
LUA_API void
lua_pushhstring(lua_State* L, lua_Hash h, const char* s, size_t len)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_pushstring(lua_State* L, const char* s)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API const char*
lua_pushvfstring(lua_State* L, const char* fmt, va_list argp)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API const char*
lua_pushfstring(lua_State* L, const char* fmt, ...)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_pushcclosure(lua_State* L, lua_CFunction fn, int n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_pushboolean(lua_State* L, int b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_pushlightuserdata(lua_State* L, void* p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_pushthread(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** get functions (Lua -> stack)
*/

LUA_API void
lua_gettable(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_getfield(lua_State* L, int idx, const char* k)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_rawget(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_rawgeti(lua_State* L, int idx, int n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_createtable(lua_State* L, int narray, int nrec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_getmetatable(lua_State* L, int objindex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_getfenv(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** set functions (stack -> Lua)
*/

LUA_API void
lua_settable(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_setfield(lua_State* L, int idx, const char* k)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_rawset(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_rawseti(lua_State* L, int idx, int n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_setmetatable(lua_State* L, int objindex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_setfenv(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

    /*
    ** `load' and `call' functions (run Lua code)
    */

#define adjustresults(L, nres)                                                 \
    {                                                                          \
        if (nres == LUA_MULTRET && L->top >= L->ci->top)                       \
            L->ci->top = L->top;                                               \
    }

#define checkresults(L, na, nr)                                                \
    api_check(L, (nr) == LUA_MULTRET || (L->ci->top - L->top >= (nr) - (na)))

LUA_API void
lua_call(lua_State* L, int nargs, int nresults)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** Execute a protected call.
*/
struct CallS
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_pcall(lua_State* L, int nargs, int nresults, int errfunc)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** Execute a protected C call.
*/
struct CCallS
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_cpcall(lua_State* L, lua_CFunction func, void* ud)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_load(lua_State* L, lua_Reader reader, void* data, const char* chunkname)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_dump(lua_State* L, lua_Writer writer, void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_status(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** Garbage-collection function
*/

LUA_API int
lua_gc(lua_State* L, int what, int data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** miscellaneous functions
*/

LUA_API int
lua_error(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API int
lua_next(lua_State* L, int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_concat(lua_State* L, int n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API lua_Alloc
lua_getallocf(lua_State* L, void** ud)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_setallocf(lua_State* L, lua_Alloc f, void* ud)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void*
lua_newuserdata(lua_State* L, size_t size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const char*
aux_upvalue(StkId fi, int n, TValue** val)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API const char*
lua_getupvalue(lua_State* L, int funcindex, int n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API const char*
lua_setupvalue(lua_State* L, int funcindex, int n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* SPRING syscall additions */
LUA_API void
lua_set_fopen(lua_State* L, lua_Func_fopen func)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_set_popen(lua_State* L,
              lua_Func_popen popen_func,
              lua_Func_pclose pclose_func)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_set_system(lua_State* L, lua_Func_system func)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_set_remove(lua_State* L, lua_Func_remove func)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUA_API void
lua_set_rename(lua_State* L, lua_Func_rename func)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
/* END SPRING syscall additions */
