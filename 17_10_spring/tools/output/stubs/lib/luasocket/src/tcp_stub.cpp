#include <iostream>
/*=========================================================================*\
* TCP object
* LuaSocket toolkit
*
* RCS ID: $Id: tcp.c,v 1.41 2005/10/07 04:40:59 diego Exp $
\*=========================================================================*/
#include <string.h>

#include "lauxlib.h"
#include "lua.h"

#include "auxiliar.h"
#include "inet.h"
#include "options.h"
#include "socket.h"
#include "tcp.h"

/*=========================================================================*\
* Internal function prototypes
\*=========================================================================*/
static int
global_create(lua_State* L);
static int
meth_connect(lua_State* L);
static int
meth_listen(lua_State* L);
static int
meth_bind(lua_State* L);
static int
meth_send(lua_State* L);
static int
meth_getstats(lua_State* L);
static int
meth_setstats(lua_State* L);
static int
meth_getsockname(lua_State* L);
static int
meth_getpeername(lua_State* L);
static int
meth_shutdown(lua_State* L);
static int
meth_receive(lua_State* L);
static int
meth_accept(lua_State* L);
static int
meth_close(lua_State* L);
static int
meth_setoption(lua_State* L);
static int
meth_settimeout(lua_State* L);
static int
meth_getfd(lua_State* L);
static int
meth_setfd(lua_State* L);
static int
meth_dirty(lua_State* L);

/* tcp object methods */
static luaL_reg tcp[] = { { "__gc", meth_close },
                          { "__tostring", auxiliar_tostring },
                          { "accept", meth_accept },
                          { "bind", meth_bind },
                          { "close", meth_close },
                          { "connect", meth_connect },
                          { "dirty", meth_dirty },
                          { "getfd", meth_getfd },
                          { "getpeername", meth_getpeername },
                          { "getsockname", meth_getsockname },
                          { "getstats", meth_getstats },
                          { "setstats", meth_setstats },
                          { "listen", meth_listen },
                          { "receive", meth_receive },
                          { "send", meth_send },
                          { "setfd", meth_setfd },
                          { "setoption", meth_setoption },
                          { "setpeername", meth_connect },
                          { "setsockname", meth_bind },
                          { "settimeout", meth_settimeout },
                          { "shutdown", meth_shutdown },
                          { NULL, NULL } };

/* socket option handlers */
static t_opt opt[] = { { "keepalive", opt_keepalive },
                       { "reuseaddr", opt_reuseaddr },
                       { "tcp-nodelay", opt_tcp_nodelay },
                       { "linger", opt_linger },
                       { NULL, NULL } };

/* functions in library namespace */
static luaL_reg func[] = { { "tcp", global_create }, { NULL, NULL } };

/*-------------------------------------------------------------------------*\
* Initializes module
\*-------------------------------------------------------------------------*/
int
tcp_open(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*=========================================================================*\
* Lua methods
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Just call buffered IO methods
\*-------------------------------------------------------------------------*/
static int
meth_send(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
meth_receive(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
meth_getstats(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
meth_setstats(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Just call option handler
\*-------------------------------------------------------------------------*/
static int
meth_setoption(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Select support methods
\*-------------------------------------------------------------------------*/
static int
meth_getfd(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* this is very dangerous, but can be handy for those that are brave enough */
static int
meth_setfd(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
meth_dirty(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Waits for and returns a client object attempting connection to the
* server object
\*-------------------------------------------------------------------------*/
static int
meth_accept(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Binds an object to an address
\*-------------------------------------------------------------------------*/
static int
meth_bind(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Turns a master tcp object into a client object.
\*-------------------------------------------------------------------------*/
static int
meth_connect(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Closes socket used by object
\*-------------------------------------------------------------------------*/
static int
meth_close(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Puts the sockt in listen mode
\*-------------------------------------------------------------------------*/
static int
meth_listen(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Shuts the connection down partially
\*-------------------------------------------------------------------------*/
static int
meth_shutdown(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Just call inet methods
\*-------------------------------------------------------------------------*/
static int
meth_getpeername(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
meth_getsockname(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Just call tm methods
\*-------------------------------------------------------------------------*/
static int
meth_settimeout(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*=========================================================================*\
* Library functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Creates a master tcp object
\*-------------------------------------------------------------------------*/
static int
global_create(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
