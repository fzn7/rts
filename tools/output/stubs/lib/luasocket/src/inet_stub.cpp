#include <iostream>
/*=========================================================================*\
* Internet domain functions
* LuaSocket toolkit
*
* RCS ID: $Id: inet.c,v 1.28 2005/10/07 04:40:59 diego Exp $
\*=========================================================================*/
#include <stdio.h>
#include <string.h>

#include "lua.h"
#include "lauxlib.h"

#include "inet.h"
//spring includes
#include "restrictions.h"
#include "System/Log/ILog.h"

/*=========================================================================*\
* Internal function prototypes.
\*=========================================================================*/
static int inet_global_toip(lua_State *L);
static int inet_global_tohostname(lua_State *L);
static void inet_pushresolved(lua_State *L, struct hostent *hp);
static int inet_global_gethostname(lua_State *L);

/* DNS functions */
static luaL_reg func[] = {
    { "toip", inet_global_toip },
    { "tohostname", inet_global_tohostname },
    { "gethostname", inet_global_gethostname},
    { NULL, NULL}
};

/*=========================================================================*\
* Exported functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Initializes module
\*-------------------------------------------------------------------------*/
int inet_open(lua_State *L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*=========================================================================*\
* Global Lua functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Returns all information provided by the resolver given a host name
* or ip address
\*-------------------------------------------------------------------------*/
static int inet_gethost(const char *address, struct hostent **hp) {
    struct in_addr addr;
    if (inet_aton(address, &addr))
        return socket_gethostbyaddr((char *) &addr, sizeof(addr), hp);
    else 
        return socket_gethostbyname(address, hp);
}

/*-------------------------------------------------------------------------*\
* Returns all information provided by the resolver given a host name
* or ip address
\*-------------------------------------------------------------------------*/
static int inet_global_tohostname(lua_State *L) {
    const char *address = luaL_checkstring(L, 1);
    struct hostent *hp = NULL; 
    int err = inet_gethost(address, &hp);
    luaSocketRestrictions->addIP(address, hp->h_name); //add resolved ip to rules
    if (err != IO_DONE) {
        lua_pushnil(L);
        lua_pushstring(L, socket_hoststrerror(err));
        return 2;
    }
    lua_pushstring(L, hp->h_name);
    inet_pushresolved(L, hp);
    return 2;
}

/*-------------------------------------------------------------------------*\
* Returns all information provided by the resolver given a host name
* or ip address
\*-------------------------------------------------------------------------*/
static int inet_global_toip(lua_State *L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/*-------------------------------------------------------------------------*\
* Gets the host name
\*-------------------------------------------------------------------------*/
static int inet_global_gethostname(lua_State *L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/*=========================================================================*\
* Lua methods
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Retrieves socket peer name
\*-------------------------------------------------------------------------*/
int inet_meth_getpeername(lua_State *L, p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Retrieves socket local name
\*-------------------------------------------------------------------------*/
int inet_meth_getsockname(lua_State *L, p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*=========================================================================*\
* Internal functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Passes all resolver information to Lua as a table
\*-------------------------------------------------------------------------*/
static void inet_pushresolved(lua_State *L, struct hostent *hp)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Tries to create a new inet socket
\*-------------------------------------------------------------------------*/
const char *inet_trycreate(p_socket ps, int type) {
    return socket_strerror(socket_create(ps, AF_INET, type, 0));
}


bool isAllowed(p_socket ps, const char *address, unsigned short port, bool connect){
    int rawtype;
    socklen_t len = sizeof(rawtype);
    CLuaSocketRestrictions::RestrictType type;
    int res = getsockopt(*ps, SOL_SOCKET, SO_TYPE, (char*)&rawtype, &len);
    #ifdef WIN32
    if (res == SOCKET_ERROR) {
	LOG_L(L_ERROR, "Socket error (%d): %s", res, socket_strerror(WSAGetLastError()));
        return false;
    }
    #else
    if (res != 0) {
        LOG_L(L_ERROR, "Socket error (%d): %s", res, socket_strerror(errno));
        return false;
    }
    #endif
    if (rawtype == SOCK_STREAM)
	if (connect)
            type = CLuaSocketRestrictions::TCP_CONNECT;
        else
            type = CLuaSocketRestrictions::TCP_LISTEN;
    else //SOCK_DGRAM
        if (connect)
            type = CLuaSocketRestrictions::UDP_CONNECT;
        else
            type = CLuaSocketRestrictions::UDP_LISTEN;
    if (!luaSocketRestrictions->isAllowed(type, address, port)) {
        LOG_L(L_ERROR, "Access to '%s:%d' denied", address, port);
        return false;
    }
    return true;
}

/*-------------------------------------------------------------------------*\
* Tries to connect to remote address (address, port)
\*-------------------------------------------------------------------------*/
const char *inet_tryconnect(p_socket ps, const char *address, 
        unsigned short port, p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Tries to bind socket to (address, port)
\*-------------------------------------------------------------------------*/
const char *inet_trybind(p_socket ps, const char *address, unsigned short port)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Some systems do not provide this so that we provide our own. It's not
* marvelously fast, but it works just fine.
\*-------------------------------------------------------------------------*/
#ifdef INET_ATON
int inet_aton(const char *cp, struct in_addr *inp)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif


