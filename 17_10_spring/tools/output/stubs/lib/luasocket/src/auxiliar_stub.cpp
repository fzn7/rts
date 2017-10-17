#include <iostream>
/*=========================================================================*\
* Auxiliar routines for class hierarchy manipulation
* LuaSocket toolkit
*
* RCS ID: $Id: auxiliar.c,v 1.14 2005/10/07 04:40:59 diego Exp $
\*=========================================================================*/
#include <stdio.h>
#include <string.h>

#include "auxiliar.h"

/*=========================================================================*\
* Exported functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Initializes the module
\*-------------------------------------------------------------------------*/
int
auxiliar_open(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Creates a new class with given methods
* Methods whose names start with __ are passed directly to the metatable.
\*-------------------------------------------------------------------------*/
void
auxiliar_newclass(lua_State* L, const char* classname, luaL_reg* func)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Prints the value of a class in a nice way
\*-------------------------------------------------------------------------*/
int
auxiliar_tostring(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Insert class into group
\*-------------------------------------------------------------------------*/
void
auxiliar_add2group(lua_State* L, const char* classname, const char* groupname)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Make sure argument is a boolean
\*-------------------------------------------------------------------------*/
int
auxiliar_checkboolean(lua_State* L, int objidx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Return userdata pointer if object belongs to a given class, abort with
* error otherwise
\*-------------------------------------------------------------------------*/
void*
auxiliar_checkclass(lua_State* L, const char* classname, int objidx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Return userdata pointer if object belongs to a given group, abort with
* error otherwise
\*-------------------------------------------------------------------------*/
void*
auxiliar_checkgroup(lua_State* L, const char* groupname, int objidx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Set object class
\*-------------------------------------------------------------------------*/
void
auxiliar_setclass(lua_State* L, const char* classname, int objidx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Get a userdata pointer if object belongs to a given group. Return NULL
* otherwise
\*-------------------------------------------------------------------------*/
void*
auxiliar_getgroupudata(lua_State* L, const char* groupname, int objidx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Get a userdata pointer if object belongs to a given class. Return NULL
* otherwise
\*-------------------------------------------------------------------------*/
void*
auxiliar_getclassudata(lua_State* L, const char* classname, int objidx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
