#include <iostream>
/*
** $Id: ldblib.c,v 1.104.1.4 2009/08/04 18:50:18 roberto Exp $
** Interface from Lua to its debug API
** See Copyright Notice in lua.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ldblib_c
#define LUA_LIB

#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

static int
db_getregistry(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
db_getmetatable(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
db_setmetatable(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
db_getfenv(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
db_setfenv(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
settabss(lua_State* L, const char* i, const char* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
settabsi(lua_State* L, const char* i, int v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static lua_State*
getthread(lua_State* L, int* arg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
treatstackoption(lua_State* L, lua_State* L1, const char* fname)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
db_getinfo(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
db_getlocal(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
db_setlocal(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
auxupvalue(lua_State* L, int get)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
db_getupvalue(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
db_setupvalue(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const char KEY_HOOK = 'h';

static void
hookf(lua_State* L, lua_Debug* ar)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
makemask(const char* smask, int count)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static char*
unmakemask(int mask, char* smask)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
gethooktable(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
db_sethook(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
db_gethook(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
db_debug(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#define LEVELS1 12 /* size of the first part of the stack */
#define LEVELS2 10 /* size of the second part of the stack */

static int
db_errorfb(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const luaL_Reg dblib[] = { { "debug", db_debug },
                                  { "getfenv", db_getfenv },
                                  { "gethook", db_gethook },
                                  { "getinfo", db_getinfo },
                                  { "getlocal", db_getlocal },
                                  { "getregistry", db_getregistry },
                                  { "getmetatable", db_getmetatable },
                                  { "getupvalue", db_getupvalue },
                                  { "setfenv", db_setfenv },
                                  { "sethook", db_sethook },
                                  { "setlocal", db_setlocal },
                                  { "setmetatable", db_setmetatable },
                                  { "setupvalue", db_setupvalue },
                                  { "traceback", db_errorfb },
                                  { NULL, NULL } };

LUALIB_API int
luaopen_debug(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
