#include <iostream>
/*
** $Id: lobject.c,v 2.22.1.1 2007/12/27 13:02:25 roberto Exp $
** Some generic functions over Lua objects
** See Copyright Notice in lua.h
*/

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lobject_c
#define LUA_CORE

#include "lua.h"

#include "ldo.h"
#include "lmem.h"
#include "lobject.h"
#include "lstate.h"
#include "lstring.h"
#include "lvm.h"

const TValue luaO_nilobject_ = { { NULL }, LUA_TNIL };

/*
** converts an integer to a "floating point byte", represented as
** (eeeeexxx), where the real value is (1xxx) * 2^(eeeee - 1) if
** eeeee != 0 and (xxx) otherwise.
*/
int
luaO_int2fb(unsigned int x)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* converts back */
int
luaO_fb2int(int x)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
luaO_log2(unsigned int x)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
luaO_rawequalObj(const TValue* t1, const TValue* t2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
luaO_str2d(const char* s, lua_Number* result)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
pushstr(lua_State* L, const char* str)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* this function handles only `%d', `%c', %f, %p, and `%s' formats */
const char*
luaO_pushvfstring(lua_State* L, const char* fmt, va_list argp)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const char*
luaO_pushfstring(lua_State* L, const char* fmt, ...)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
luaO_chunkid(char* out, const char* source, size_t bufflen)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
