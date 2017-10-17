#include <iostream>
/*=========================================================================*\
* Select implementation
* LuaSocket toolkit
*
* RCS ID: $Id: select.c,v 1.22 2005/11/20 07:20:23 diego Exp $
\*=========================================================================*/
#include <string.h>

#include "lauxlib.h"
#include "lua.h"

#include "select.h"
#include "socket.h"
#include "timeout.h"

/*=========================================================================*\
* Internal function prototypes.
\*=========================================================================*/
static t_socket
getfd(lua_State* L);
static int
dirty(lua_State* L);
static t_socket
collect_fd(lua_State* L, int tab, t_socket max_fd, int itab, fd_set* set);
static int
check_dirty(lua_State* L, int tab, int dtab, fd_set* set);
static void
return_fd(lua_State* L,
          fd_set* set,
          t_socket max_fd,
          int itab,
          int tab,
          int start);
static void
make_assoc(lua_State* L, int tab);
static int
global_select(lua_State* L);

/* functions in library namespace */
static luaL_reg func[] = { { "select", global_select }, { NULL, NULL } };

/*=========================================================================*\
* Exported functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Initializes module
\*-------------------------------------------------------------------------*/
int
select_open(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*=========================================================================*\
* Global Lua functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Waits for a set of sockets until a condition is met or timeout.
\*-------------------------------------------------------------------------*/
static int
global_select(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*=========================================================================*\
* Internal functions
\*=========================================================================*/
static t_socket
getfd(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
dirty(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static t_socket
collect_fd(lua_State* L, int tab, t_socket max_fd, int itab, fd_set* set)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
check_dirty(lua_State* L, int tab, int dtab, fd_set* set)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
return_fd(lua_State* L,
          fd_set* set,
          t_socket max_fd,
          int itab,
          int tab,
          int start)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
make_assoc(lua_State* L, int tab)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
