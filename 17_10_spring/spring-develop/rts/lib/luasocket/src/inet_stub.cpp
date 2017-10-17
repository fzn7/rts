#include <iostream>
/*=========================================================================*\
* Internet domain functions
* LuaSocket toolkit
*
* RCS ID: $Id: inet.c,v 1.28 2005/10/07 04:40:59 diego Exp $
\*=========================================================================*/
#include <stdio.h>
#include <string.h>

#include "lauxlib.h"
#include "lua.h"

#include "inet.h"
// spring includes
#include "System/Log/ILog.h"
#include "restrictions.h"

/*=========================================================================*\
* Internal function prototypes.
\*=========================================================================*/
static int
inet_global_toip(lua_State* L);
static int
inet_global_tohostname(lua_State* L);
static void
inet_pushresolved(lua_State* L, struct hostent* hp);
static int
inet_global_gethostname(lua_State* L);

/* DNS functions */
static luaL_reg func[] = { { "toip", inet_global_toip },
                           { "tohostname", inet_global_tohostname },
                           { "gethostname", inet_global_gethostname },
                           { NULL, NULL } };

/*=========================================================================*\
* Exported functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Initializes module
\*-------------------------------------------------------------------------*/
int
inet_open(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*=========================================================================*\
* Global Lua functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Returns all information provided by the resolver given a host name
* or ip address
\*-------------------------------------------------------------------------*/
static int
inet_gethost(const char* address, struct hostent** hp)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Returns all information provided by the resolver given a host name
* or ip address
\*-------------------------------------------------------------------------*/
static int
inet_global_tohostname(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Returns all information provided by the resolver given a host name
* or ip address
\*-------------------------------------------------------------------------*/
static int
inet_global_toip(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Gets the host name
\*-------------------------------------------------------------------------*/
static int
inet_global_gethostname(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*=========================================================================*\
* Lua methods
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Retrieves socket peer name
\*-------------------------------------------------------------------------*/
int
inet_meth_getpeername(lua_State* L, p_socket ps)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Retrieves socket local name
\*-------------------------------------------------------------------------*/
int
inet_meth_getsockname(lua_State* L, p_socket ps)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*=========================================================================*\
* Internal functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Passes all resolver information to Lua as a table
\*-------------------------------------------------------------------------*/
static void
inet_pushresolved(lua_State* L, struct hostent* hp)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Tries to create a new inet socket
\*-------------------------------------------------------------------------*/
const char*
inet_trycreate(p_socket ps, int type)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
isAllowed(p_socket ps, const char* address, unsigned short port, bool connect)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Tries to connect to remote address (address, port)
\*-------------------------------------------------------------------------*/
const char*
inet_tryconnect(p_socket ps,
                const char* address,
                unsigned short port,
                p_timeout tm)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Tries to bind socket to (address, port)
\*-------------------------------------------------------------------------*/
const char*
inet_trybind(p_socket ps, const char* address, unsigned short port)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Some systems do not provide this so that we provide our own. It's not
* marvelously fast, but it works just fine.
\*-------------------------------------------------------------------------*/
#ifdef INET_ATON
int
inet_aton(const char* cp, struct in_addr* inp)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
#endif
