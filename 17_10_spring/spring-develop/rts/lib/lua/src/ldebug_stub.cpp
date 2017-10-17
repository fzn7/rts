#include <iostream>
/*
** $Id: ldebug.c,v 2.29.1.6 2008/05/08 16:56:26 roberto Exp $
** Debug Interface
** See Copyright Notice in lua.h
*/

#include <stdarg.h>
#include <stddef.h>
#include <string.h>

#define ldebug_c
#define LUA_CORE

#include "lua.h"

#include "lapi.h"
#include "lcode.h"
#include "ldebug.h"
#include "ldo.h"
#include "lfunc.h"
#include "lobject.h"
#include "lopcodes.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "ltm.h"
#include "lvm.h"

static const char*
getfuncname(lua_State* L, CallInfo* ci, const char** name);

static int
currentpc(lua_State* L, CallInfo* ci)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
currentline(lua_State* L, CallInfo* ci)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
** this function can be called asynchronous (e.g. during a signal)
*/
LUA_API int
lua_sethook(lua_State* L, lua_Hook func, int mask, int count)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUA_API lua_Hook
lua_gethook(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUA_API int
lua_gethookmask(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUA_API int
lua_gethookcount(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUA_API int
lua_getstack(lua_State* L, int level, lua_Debug* ar)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static Proto*
getluaproto(CallInfo* ci)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const char*
findlocal(lua_State* L, CallInfo* ci, int n)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUA_API const char*
lua_getlocal(lua_State* L, const lua_Debug* ar, int n)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUA_API const char*
lua_setlocal(lua_State* L, const lua_Debug* ar, int n)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
funcinfo(lua_Debug* ar, Closure* cl)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
info_tailcall(lua_Debug* ar)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
collectvalidlines(lua_State* L, Closure* f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
auxgetinfo(lua_State* L,
           const char* what,
           lua_Debug* ar,
           Closure* f,
           CallInfo* ci)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUA_API int
lua_getinfo(lua_State* L, const char* what, lua_Debug* ar)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

    /*
    ** {======================================================
    ** Symbolic Execution and code checker
    ** =======================================================
    */

#define check(x)                                                               \
    if (!(x))                                                                  \
        return 0;

#define checkjump(pt, pc) check(0 <= pc && pc < pt->sizecode)

#define checkreg(pt, reg) check((reg) < (pt)->maxstacksize)

static int
precheck(const Proto* pt)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#define checkopenop(pt, pc) luaG_checkopenop((pt)->code[(pc) + 1])

int
luaG_checkopenop(Instruction i)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
checkArgMode(const Proto* pt, int r, enum OpArgMask mode)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static Instruction
symbexec(const Proto* pt, int lastpc, int reg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#undef check
#undef checkjump
#undef checkreg

/* }====================================================== */

int
luaG_checkcode(const Proto* pt)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const char*
kname(Proto* p, int c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const char*
getobjname(lua_State* L, CallInfo* ci, int stackpos, const char** name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const char*
getfuncname(lua_State* L, CallInfo* ci, const char** name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/* only ANSI way to check whether a pointer points to an array */
static int
isinstack(CallInfo* ci, const TValue* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaG_typeerror(lua_State* L, const TValue* o, const char* op)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaG_concaterror(lua_State* L, StkId p1, StkId p2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaG_aritherror(lua_State* L, const TValue* p1, const TValue* p2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
luaG_ordererror(lua_State* L, const TValue* p1, const TValue* p2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
addinfo(lua_State* L, const char* msg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaG_errormsg(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaG_runerror(lua_State* L, const char* fmt, ...)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
