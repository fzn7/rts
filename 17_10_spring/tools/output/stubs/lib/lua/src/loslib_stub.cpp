#include <iostream>
/*
** $Id: loslib.c,v 1.19.1.3 2008/01/18 16:38:18 roberto Exp $
** Standard Operating System library
** See Copyright Notice in lua.h
*/

#include <errno.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define loslib_c
#define LUA_LIB

#include "lua.h"

#include "lauxlib.h"
#include "lstate.h" /* SPRING */
#include "lualib.h"

static int
os_pushresult(lua_State* L, int i, const char* filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
os_execute(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
os_remove(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
os_rename(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
os_tmpname(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
os_getenv(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// SPRING
#ifndef BUILDING_AI
#include "System/Misc/SpringTime.h"
#endif

static int
os_clock(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** {======================================================
** Time/Date operations
** { year=%Y, month=%m, day=%d, hour=%H, min=%M, sec=%S,
**   wday=%w+1, yday=%j, isdst=? }
** =======================================================
*/

static void
setfield(lua_State* L, const char* key, int value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
setboolfield(lua_State* L, const char* key, int value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
getboolfield(lua_State* L, const char* key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
getfield(lua_State* L, const char* key, int d)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
os_date(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
os_time(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
os_difftime(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* }====================================================== */

static int
os_setlocale(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
os_exit(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const luaL_Reg syslib[] = {
    { "clock", os_clock },         { "date", os_date },
    { "difftime", os_difftime },   { "execute", os_execute },
    { "exit", os_exit },           { "getenv", os_getenv },
    { "remove", os_remove },       { "rename", os_rename },
    { "setlocale", os_setlocale }, { "time", os_time },
    { "tmpname", os_tmpname },     { NULL, NULL }
};

/* }====================================================== */

LUALIB_API int
luaopen_os(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
