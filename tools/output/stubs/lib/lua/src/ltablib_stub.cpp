#include <iostream>
/*
** $Id: ltablib.c,v 1.38.1.3 2008/02/14 16:46:58 roberto Exp $
** Library for Table Manipulation
** See Copyright Notice in lua.h
*/

#include <stddef.h>

#define ltablib_c
#define LUA_LIB

#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

#define aux_getn(L, n) (luaL_checktype(L, n, LUA_TTABLE), luaL_getn(L, n))

static int
foreachi(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int foreach (lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
maxn(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
getn(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
setn(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
tinsert(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
tremove(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
addfield(lua_State* L, luaL_Buffer* b, int i)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
tconcat(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** {======================================================
** Quicksort
** (based on `Algorithms in MODULA-3', Robert Sedgewick;
**  Addison-Wesley, 1993.)
*/

static void
set2(lua_State* L, int i, int j)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
sort_comp(lua_State* L, int a, int b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
auxsort(lua_State* L, int l, int u)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
sort(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* }====================================================== */

static const luaL_Reg tab_funcs[] = {
    { "concat", tconcat }, { "foreach", foreach }, { "foreachi", foreachi },
    { "getn", getn },      { "maxn", maxn },       { "insert", tinsert },
    { "remove", tremove }, { "setn", setn },       { "sort", sort },
    { NULL, NULL }
};

LUALIB_API int
luaopen_table(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
