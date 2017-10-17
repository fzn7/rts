#include <iostream>
/*=========================================================================*\
* Input/Output interface for Lua programs
* LuaSocket toolkit
*
* RCS ID: $Id: buffer.c,v 1.28 2007/06/11 23:44:54 diego Exp $
\*=========================================================================*/
#include "lauxlib.h"
#include "lua.h"

#include "buffer.h"

/*=========================================================================*\
* Internal function prototypes
\*=========================================================================*/
static int
recvraw(p_buffer buf, size_t wanted, luaL_Buffer* b);
static int
recvline(p_buffer buf, luaL_Buffer* b);
static int
recvall(p_buffer buf, luaL_Buffer* b);
static int
buffer_get(p_buffer buf, const char** data, size_t* count);
static void
buffer_skip(p_buffer buf, size_t count);
static int
sendraw(p_buffer buf, const char* data, size_t count, size_t* sent);

/* min and max macros */
#ifndef MIN
#define MIN(x, y) ((x) < (y) ? x : y)
#endif
#ifndef MAX
#define MAX(x, y) ((x) > (y) ? x : y)
#endif

/*=========================================================================*\
* Exported functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Initializes module
\*-------------------------------------------------------------------------*/
int
buffer_open(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Initializes C structure
\*-------------------------------------------------------------------------*/
void
buffer_init(p_buffer buf, p_io io, p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* object:getstats() interface
\*-------------------------------------------------------------------------*/
int
buffer_meth_getstats(lua_State* L, p_buffer buf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* object:setstats() interface
\*-------------------------------------------------------------------------*/
int
buffer_meth_setstats(lua_State* L, p_buffer buf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* object:send() interface
\*-------------------------------------------------------------------------*/
int
buffer_meth_send(lua_State* L, p_buffer buf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* object:receive() interface
\*-------------------------------------------------------------------------*/
int
buffer_meth_receive(lua_State* L, p_buffer buf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Determines if there is any data in the read buffer
\*-------------------------------------------------------------------------*/
int
buffer_isempty(p_buffer buf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*=========================================================================*\
* Internal functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Sends a block of data (unbuffered)
\*-------------------------------------------------------------------------*/
#define STEPSIZE 8192
static int
sendraw(p_buffer buf, const char* data, size_t count, size_t* sent)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Reads a fixed number of bytes (buffered)
\*-------------------------------------------------------------------------*/
static int
recvraw(p_buffer buf, size_t wanted, luaL_Buffer* b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Reads everything until the connection is closed (buffered)
\*-------------------------------------------------------------------------*/
static int
recvall(p_buffer buf, luaL_Buffer* b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Reads a line terminated by a CR LF pair or just by a LF. The CR and LF
* are not returned by the function and are discarded from the buffer
\*-------------------------------------------------------------------------*/
static int
recvline(p_buffer buf, luaL_Buffer* b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Skips a given number of bytes from read buffer. No data is read from the
* transport layer
\*-------------------------------------------------------------------------*/
static void
buffer_skip(p_buffer buf, size_t count)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Return any data available in buffer, or get more data from transport layer
* if buffer is empty
\*-------------------------------------------------------------------------*/
static int
buffer_get(p_buffer buf, const char** data, size_t* count)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
