#include <iostream>
/*=========================================================================*\
* Unix domain socket
* LuaSocket toolkit
*
* RCS ID: $Id: unix.c,v 1.13 2006/03/13 07:16:39 diego Exp $
\*=========================================================================*/
#include <string.h>

#include "lauxlib.h"
#include "lua.h"

#include "auxiliar.h"
#include "options.h"
#include "socket.h"
#include "unix.h"
#include <sys/un.h>

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
static int
meth_getstats(lua_State* L);
static int
meth_setstats(lua_State* L);

static const char*
unix_tryconnect(p_unix un, const char* path);
static const char*
unix_trybind(p_unix un, const char* path);

/* unix object methods */
static luaL_reg un[] = {
    { "__gc", meth_close },          { "__tostring", auxiliar_tostring },
    { "accept", meth_accept },       { "bind", meth_bind },
    { "close", meth_close },         { "connect", meth_connect },
    { "dirty", meth_dirty },         { "getfd", meth_getfd },
    { "getstats", meth_getstats },   { "setstats", meth_setstats },
    { "listen", meth_listen },       { "receive", meth_receive },
    { "send", meth_send },           { "setfd", meth_setfd },
    { "setoption", meth_setoption }, { "setpeername", meth_connect },
    { "setsockname", meth_bind },    { "settimeout", meth_settimeout },
    { "shutdown", meth_shutdown },   { NULL, NULL }
};

/* socket option handlers */
static t_opt opt[] = { { "keepalive", opt_keepalive },
                       { "reuseaddr", opt_reuseaddr },
                       { "linger", opt_linger },
                       { NULL, NULL } };

/* our socket creation function */
static luaL_reg func[] = { { "unix", global_create }, { NULL, NULL } };

/*-------------------------------------------------------------------------*\
* Initializes module
\*-------------------------------------------------------------------------*/
int
luaopen_socket_unix(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
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
    std::cout << __FUNCTION__ << std::endl;
}

static int
meth_receive(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
meth_getstats(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
meth_setstats(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Just call option handler
\*-------------------------------------------------------------------------*/
static int
meth_setoption(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Select support methods
\*-------------------------------------------------------------------------*/
static int
meth_getfd(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/* this is very dangerous, but can be handy for those that are brave enough */
static int
meth_setfd(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
meth_dirty(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Waits for and returns a client object attempting connection to the
* server object
\*-------------------------------------------------------------------------*/
static int
meth_accept(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Binds an object to an address
\*-------------------------------------------------------------------------*/
static const char*
unix_trybind(p_unix un, const char* path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
meth_bind(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Turns a master unix object into a client object.
\*-------------------------------------------------------------------------*/
static const char*
unix_tryconnect(p_unix un, const char* path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
meth_connect(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Closes socket used by object
\*-------------------------------------------------------------------------*/
static int
meth_close(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Puts the sockt in listen mode
\*-------------------------------------------------------------------------*/
static int
meth_listen(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Shuts the connection down partially
\*-------------------------------------------------------------------------*/
static int
meth_shutdown(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Just call tm methods
\*-------------------------------------------------------------------------*/
static int
meth_settimeout(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*=========================================================================*\
* Library functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Creates a master unix object
\*-------------------------------------------------------------------------*/
static int
global_create(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
