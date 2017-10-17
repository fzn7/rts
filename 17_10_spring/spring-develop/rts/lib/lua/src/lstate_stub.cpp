#include <iostream>
/*
** $Id: lstate.c,v 2.36.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
*/

#include <stddef.h>

#define lstate_c
#define LUA_CORE

#include "lua.h"

#include "ldebug.h"
#include "ldo.h"
#include "lfunc.h"
#include "lgc.h"
#include "llex.h"
#include "lmem.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "ltm.h"

#define state_size(x) (sizeof(x) + LUAI_EXTRASPACE)
#define fromstate(l) (cast(lu_byte*, (l)) - LUAI_EXTRASPACE)
#define tostate(l) (cast(lua_State*, cast(lu_byte*, l) + LUAI_EXTRASPACE))

/*
** Main thread combines a thread state and the global state
*/
typedef struct LG {
  lua_State l;
  global_State g;
} LG;

static void
freestack(lua_State* L, lua_State* L1)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
** open parts that may cause memory-allocation errors
*/
static void
f_luaopen(lua_State* L, void* ud)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
preinit_state(lua_State* L, global_State* g)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
close_state(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

lua_State*
luaE_newthread(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaE_freethread(lua_State* L, lua_State* L1)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUA_API lua_State*
lua_newstate(lua_Alloc f, void* ud)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
callallgcTM(lua_State* L, void* ud)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUA_API void
lua_close(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
