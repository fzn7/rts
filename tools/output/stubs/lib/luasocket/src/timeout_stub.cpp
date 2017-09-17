#include <iostream>
/*=========================================================================*\
* Timeout management functions
* LuaSocket toolkit
*
* RCS ID: $Id: timeout.c,v 1.30 2005/10/07 04:40:59 diego Exp $
\*=========================================================================*/
#include <stdio.h>

#include "lauxlib.h"
#include "lua.h"

#include "auxiliar.h"
#include "timeout.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#include <time.h>
#endif

/* min and max macros */
#ifndef MIN
#define MIN(x, y) ((x) < (y) ? x : y)
#endif
#ifndef MAX
#define MAX(x, y) ((x) > (y) ? x : y)
#endif

/*=========================================================================*\
* Internal function prototypes
\*=========================================================================*/
static int
timeout_lua_gettime(lua_State* L);
static int
timeout_lua_sleep(lua_State* L);

static luaL_reg func[] = { { "gettime", timeout_lua_gettime },
                           { "sleep", timeout_lua_sleep },
                           { NULL, NULL } };

/*=========================================================================*\
* Exported functions.
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Initialize structure
\*-------------------------------------------------------------------------*/
void
timeout_init(p_timeout tm, double block, double total)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Determines how much time we have left for the next system call,
* if the previous call was successful
* Input
*   tm: timeout control structure
* Returns
*   the number of ms left or -1 if there is no time limit
\*-------------------------------------------------------------------------*/
double
timeout_get(p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Returns time since start of operation
* Input
*   tm: timeout control structure
* Returns
*   start field of structure
\*-------------------------------------------------------------------------*/
double
timeout_getstart(p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Determines how much time we have left for the next system call,
* if the previous call was a failure
* Input
*   tm: timeout control structure
* Returns
*   the number of ms left or -1 if there is no time limit
\*-------------------------------------------------------------------------*/
double
timeout_getretry(p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Marks the operation start time in structure
* Input
*   tm: timeout control structure
\*-------------------------------------------------------------------------*/
p_timeout
timeout_markstart(p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Gets time in s, relative to January 1, 1970 (UTC)
* Returns
*   time in s.
\*-------------------------------------------------------------------------*/
#ifdef _WIN32
double
timeout_gettime(void)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#else
double
timeout_gettime(void)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

/*-------------------------------------------------------------------------*\
* Initializes module
\*-------------------------------------------------------------------------*/
int
timeout_open(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Sets timeout values for IO operations
* Lua Input: base, time [, mode]
*   time: time out value in seconds
*   mode: "b" for block timeout, "t" for total timeout. (default: b)
\*-------------------------------------------------------------------------*/
int
timeout_meth_settimeout(lua_State* L, p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*=========================================================================*\
* Test support functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Returns the time the system has been up, in secconds.
\*-------------------------------------------------------------------------*/
static int
timeout_lua_gettime(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Sleep for n seconds.
\*-------------------------------------------------------------------------*/
int
timeout_lua_sleep(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
