#include <iostream>
/*
** $Id: ltm.c,v 2.8.1.1 2007/12/27 13:02:25 roberto Exp $
** Tag methods
** See Copyright Notice in lua.h
*/

#include <string.h>

#define ltm_c
#define LUA_CORE

#include "lua.h"

#include "lobject.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "ltm.h"

const char* const luaT_typenames[] = { "nil",      "boolean",  "userdata",
                                       "number",   "string",   "table",
                                       "function", "userdata", "thread",
                                       "proto",    "upval" };

void
luaT_init(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** function to be used with macro "fasttm": optimized for absence of
** tag methods
*/
const TValue*
luaT_gettm(Table* events, TMS event, TString* ename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const TValue*
luaT_gettmbyobj(lua_State* L, const TValue* o, TMS event)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
