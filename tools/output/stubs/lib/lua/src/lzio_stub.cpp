#include <iostream>
/*
** $Id: lzio.c,v 1.31.1.1 2007/12/27 13:02:25 roberto Exp $
** a generic input stream interface
** See Copyright Notice in lua.h
*/

#include <string.h>

#define lzio_c
#define LUA_CORE

#include "lua.h"

#include "llimits.h"
#include "lmem.h"
#include "lstate.h"
#include "lzio.h"

int
luaZ_fill(ZIO* z)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
luaZ_lookahead(ZIO* z)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
luaZ_init(lua_State* L, ZIO* z, lua_Reader reader, void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* --------------------------------------------------------------- read --- */
size_t
luaZ_read(ZIO* z, void* b, size_t n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* ------------------------------------------------------------------------ */
char*
luaZ_openspace(lua_State* L, Mbuffer* buff, size_t n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
