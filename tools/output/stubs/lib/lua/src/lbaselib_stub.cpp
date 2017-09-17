#include <iostream>
/*
** $Id: lbaselib.c,v 1.191.1.6 2008/02/14 16:46:22 roberto Exp $
** Basic library
** See Copyright Notice in lua.h
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lbaselib_c
#define LUA_LIB

#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

/*
** If your system does not support `stdout', you can just remove this function.
** If you need, you can define your own `print' function, following this
** model but changing `fputs' to put the strings at a proper place
** (a console window or a log file, for instance).
*/
static int
luaB_print(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_tonumber(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_error(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_getmetatable(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_setmetatable(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
getfunc(lua_State* L, int opt)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_getfenv(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_setfenv(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_rawequal(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_rawget(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_rawset(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_gcinfo(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_collectgarbage(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_type(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_next(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_pairs(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
ipairsaux(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_ipairs(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
load_aux(lua_State* L, int status)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_loadstring(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_loadfile(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** Reader for generic `load' function: `lua_load' uses the
** stack for internal stuff, so the reader cannot change the
** stack top. Instead, it keeps its resulting string in a
** reserved slot inside the stack.
*/
static const char*
generic_reader(lua_State* L, void* ud, size_t* size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_load(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_dofile(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_assert(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_unpack(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_select(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_pcall(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_xpcall(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_tostring(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_newproxy(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const luaL_Reg base_funcs[] = { { "assert", luaB_assert },
                                       { "collectgarbage",
                                         luaB_collectgarbage },
                                       { "dofile", luaB_dofile },
                                       { "error", luaB_error },
                                       { "gcinfo", luaB_gcinfo },
                                       { "getfenv", luaB_getfenv },
                                       { "getmetatable", luaB_getmetatable },
                                       { "loadfile", luaB_loadfile },
                                       { "load", luaB_load },
                                       { "loadstring", luaB_loadstring },
                                       { "next", luaB_next },
                                       { "pcall", luaB_pcall },
                                       { "print", luaB_print },
                                       { "rawequal", luaB_rawequal },
                                       { "rawget", luaB_rawget },
                                       { "rawset", luaB_rawset },
                                       { "select", luaB_select },
                                       { "setfenv", luaB_setfenv },
                                       { "setmetatable", luaB_setmetatable },
                                       { "tonumber", luaB_tonumber },
                                       { "tostring", luaB_tostring },
                                       { "type", luaB_type },
                                       { "unpack", luaB_unpack },
                                       { "xpcall", luaB_xpcall },
                                       { NULL, NULL } };

/*
** {======================================================
** Coroutine library
** =======================================================
*/

#define CO_RUN 0 /* running */
#define CO_SUS 1 /* suspended */
#define CO_NOR 2 /* 'normal' (it resumed another coroutine) */
#define CO_DEAD 3

static const char* const statnames[] = { "running",
                                         "suspended",
                                         "normal",
                                         "dead" };

static int
costatus(lua_State* L, lua_State* co)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_costatus(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
auxresume(lua_State* L, lua_State* co, int narg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_coresume(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_auxwrap(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_cocreate(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_cowrap(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_yield(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
luaB_corunning(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const luaL_Reg co_funcs[] = { { "create", luaB_cocreate },
                                     { "resume", luaB_coresume },
                                     { "running", luaB_corunning },
                                     { "status", luaB_costatus },
                                     { "wrap", luaB_cowrap },
                                     { "yield", luaB_yield },
                                     { NULL, NULL } };

/* }====================================================== */

static void
auxopen(lua_State* L, const char* name, lua_CFunction f, lua_CFunction u)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
base_open(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUALIB_API int
luaopen_base(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
