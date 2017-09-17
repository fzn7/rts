#include <iostream>
/*
** $Id: lstring.c,v 2.8.1.1 2007/12/27 13:02:25 roberto Exp $
** String table (keeps all strings handled by Lua)
** See Copyright Notice in lua.h
*/

#include <string.h>

#define lstring_c
#define LUA_CORE

#include "lua.h"

#include "lmem.h"
#include "lobject.h"
#include "lstate.h"
#include "lstring.h"

void
luaS_resize(lua_State* L, int newsize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static TString*
newlstr(lua_State* L, const char* str, size_t l, unsigned int h)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// SPRING
static inline lua_Hash
calchash(const char* str, size_t l)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// SPRING
LUA_API lua_Hash
lua_calchash(const char* str, size_t l)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

TString*
luaS_newhstr(lua_State* L, lua_Hash h, const char* str, size_t l)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// SPRING
TString*
luaS_newlstr(lua_State* L, const char* str, size_t l)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Udata*
luaS_newudata(lua_State* L, size_t s, Table* e)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
