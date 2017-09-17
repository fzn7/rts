#include <iostream>
/*=========================================================================*\
* UDP object
* LuaSocket toolkit
*
* RCS ID: $Id: udp.c,v 1.29 2005/10/07 04:40:59 diego Exp $
\*=========================================================================*/
#include <string.h>

#include "lauxlib.h"
#include "lua.h"

#include "auxiliar.h"
#include "inet.h"
#include "options.h"
#include "restrictions.h"
#include "socket.h"
#include "udp.h"

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
global_create(lua_State* L);
static int
meth_send(lua_State* L);
static int
meth_sendto(lua_State* L);
static int
meth_receive(lua_State* L);
static int
meth_receivefrom(lua_State* L);
static int
meth_getsockname(lua_State* L);
static int
meth_getpeername(lua_State* L);
static int
meth_setsockname(lua_State* L);
static int
meth_setpeername(lua_State* L);
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

/* udp object methods */
static luaL_reg udp[] = { { "__gc", meth_close },
                          { "__tostring", auxiliar_tostring },
                          { "close", meth_close },
                          { "dirty", meth_dirty },
                          { "getfd", meth_getfd },
                          { "getpeername", meth_getpeername },
                          { "getsockname", meth_getsockname },
                          { "receive", meth_receive },
                          { "receivefrom", meth_receivefrom },
                          { "send", meth_send },
                          { "sendto", meth_sendto },
                          { "setfd", meth_setfd },
                          { "setoption", meth_setoption },
                          { "setpeername", meth_setpeername },
                          { "setsockname", meth_setsockname },
                          { "settimeout", meth_settimeout },
                          { NULL, NULL } };

/* socket options */
static t_opt opt[] = { { "dontroute", opt_dontroute },
                       { "broadcast", opt_broadcast },
                       { "reuseaddr", opt_reuseaddr },
                       { "ip-multicast-ttl", opt_ip_multicast_ttl },
                       { "ip-multicast-loop", opt_ip_multicast_loop },
                       { "ip-add-membership", opt_ip_add_membership },
                       { "ip-drop-membership", opt_ip_drop_membersip },
                       { NULL, NULL } };

/* functions in library namespace */
static luaL_reg func[] = { { "udp", global_create }, { NULL, NULL } };

/*-------------------------------------------------------------------------*\
* Initializes module
\*-------------------------------------------------------------------------*/
int
udp_open(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*=========================================================================*\
* Lua methods
\*=========================================================================*/
const char*
udp_strerror(int err)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Send data through connected udp socket
\*-------------------------------------------------------------------------*/
static int
meth_send(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Send data through unconnected udp socket
\*-------------------------------------------------------------------------*/
static int
meth_sendto(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Receives data from a UDP socket
\*-------------------------------------------------------------------------*/
static int
meth_receive(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Receives data and sender from a UDP socket
\*-------------------------------------------------------------------------*/
static int
meth_receivefrom(lua_State* L)
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
* Just call option handler
\*-------------------------------------------------------------------------*/
static int
meth_setoption(lua_State* L)
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

/*-------------------------------------------------------------------------*\
* Turns a master udp object into a client object.
\*-------------------------------------------------------------------------*/
static int
meth_setpeername(lua_State* L)
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
* Turns a master object into a server object
\*-------------------------------------------------------------------------*/
static int
meth_setsockname(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*=========================================================================*\
* Library functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Creates a master udp object
\*-------------------------------------------------------------------------*/
static int
global_create(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
