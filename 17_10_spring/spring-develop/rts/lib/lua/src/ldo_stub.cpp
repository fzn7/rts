#include <iostream>
/*
** $Id: ldo.c,v 2.38.1.4 2012/01/18 02:27:10 roberto Exp $
** Stack and Call structure of Lua
** See Copyright Notice in lua.h
*/

#include <setjmp.h>
#include <stdlib.h>
#include <string.h>

#define ldo_c
#define LUA_CORE

#include "lua.h"

#include "ldebug.h"
#include "ldo.h"
#include "lfunc.h"
#include "lgc.h"
#include "lmem.h"
#include "lobject.h"
#include "lopcodes.h"
#include "lparser.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "ltm.h"
#include "lundump.h"
#include "lvm.h"
#include "lzio.h"

/*
** {======================================================
** Error-recovery functions
** =======================================================
*/

/* chain list of long jump buffers */
struct lua_longjmp
{
    //stub method
    //std::cout << __FUNCTION__ << std::endl;
};

static void
restore_stack_limit(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
resetstack(lua_State* L, int status)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaD_throw(lua_State* L, int errcode)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
luaD_rawrunprotected(lua_State* L, Pfunc f, void* ud)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/* }====================================================== */

static void
correctstack(lua_State* L, TValue* oldstack)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaD_reallocstack(lua_State* L, int newsize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaD_reallocCI(lua_State* L, int newsize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaD_growstack(lua_State* L, int n)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static CallInfo*
growCI(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaD_callhook(lua_State* L, int event, int line)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static StkId
adjust_varargs(lua_State* L, Proto* p, int actual)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static StkId
tryfuncTM(lua_State* L, StkId func)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#define inc_ci(L)                                                              \
    ((L->ci == L->end_ci)                                                      \
       ? growCI(L)                                                             \
       : (condhardstacktests(luaD_reallocCI(L, L->size_ci)), ++L->ci))

int
luaD_precall(lua_State* L, StkId func, int nresults)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static StkId
callrethooks(lua_State* L, StkId firstResult)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
luaD_poscall(lua_State* L, StkId firstResult)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
** Call a function (C or Lua). The function to be called is at *func.
** The arguments are on the stack, right after the function.
** When returns, all the results are on the stack, starting at the original
** function position.
*/
void
luaD_call(lua_State* L, StkId func, int nResults)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
resume(lua_State* L, void* ud)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
resume_error(lua_State* L, const char* msg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUA_API int
lua_resume(lua_State* L, int nargs)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUA_API int
lua_yield(lua_State* L, int nresults)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
luaD_pcall(lua_State* L, Pfunc func, void* u, ptrdiff_t old_top, ptrdiff_t ef)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
** Execute a protected parser.
*/
struct SParser
{
    //stub method
    //std::cout << __FUNCTION__ << std::endl;
};

int
luaD_protectedparser(lua_State* L, ZIO* z, const char* name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
