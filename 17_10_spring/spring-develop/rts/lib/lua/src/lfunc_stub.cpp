#include <iostream>
/*
** $Id: lfunc.c,v 2.12.1.2 2007/12/28 14:58:43 roberto Exp $
** Auxiliary functions to manipulate prototypes and closures
** See Copyright Notice in lua.h
*/

#include <stddef.h>

#define lfunc_c
#define LUA_CORE

#include "lua.h"

#include "lfunc.h"
#include "lgc.h"
#include "lmem.h"
#include "lobject.h"
#include "lstate.h"

Closure*
luaF_newCclosure(lua_State* L, int nelems, Table* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Closure*
luaF_newLclosure(lua_State* L, int nelems, Table* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

UpVal*
luaF_newupval(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

UpVal*
luaF_findupval(lua_State* L, StkId level)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
unlinkupval(UpVal* uv)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaF_freeupval(lua_State* L, UpVal* uv)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaF_close(lua_State* L, StkId level)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Proto*
luaF_newproto(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaF_freeproto(lua_State* L, Proto* f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaF_freeclosure(lua_State* L, Closure* c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
** Look for n-th local variable at line `line' in function `func'.
** Returns NULL if not found.
*/
const char*
luaF_getlocalname(const Proto* f, int local_number, int pc)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
