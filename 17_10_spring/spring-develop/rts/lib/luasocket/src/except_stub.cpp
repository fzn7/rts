#include <iostream>
/*=========================================================================*\
* Simple exception support
* LuaSocket toolkit
*
* RCS ID: $Id: except.c,v 1.8 2005/09/29 06:11:41 diego Exp $
\*=========================================================================*/
#include <stdio.h>

#include "lauxlib.h"
#include "lua.h"

#include "except.h"

/*=========================================================================*\
* Internal function prototypes.
\*=========================================================================*/
static int
global_protect(lua_State* L);
static int
global_newtry(lua_State* L);
static int
protected_(lua_State* L);
static int
finalize(lua_State* L);
static int
do_nothing(lua_State* L);

/* except functions */
static luaL_reg func[] = { { "newtry", global_newtry },
                           { "protect", global_protect },
                           { NULL, NULL } };

/*-------------------------------------------------------------------------*\
* Try factory
\*-------------------------------------------------------------------------*/
static void
wrap(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
finalize(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
do_nothing(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
global_newtry(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Protect factory
\*-------------------------------------------------------------------------*/
static int
unwrap(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
protected_(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
global_protect(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Init module
\*-------------------------------------------------------------------------*/
int
except_open(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
