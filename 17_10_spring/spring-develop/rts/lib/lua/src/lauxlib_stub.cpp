#include <iostream>
/*
** $Id: lauxlib.c,v 1.159.1.3 2008/01/21 13:20:51 roberto Exp $
** Auxiliary functions for building Lua libraries
** See Copyright Notice in lua.h
*/

#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This file uses only the official API of Lua.
** Any function declared here could be written as an application function.
*/

#define lauxlib_c
#define LUA_LIB

#include "lauxlib.h"
#include "lua.h"

#include "streflop_cond.h" // SPRING

#define FREELIST_REF 0 /* free list of references */

/* convert a stack index to positive */
#define abs_index(L, i)                                                        \
    ((i) > 0 || (i) <= LUA_REGISTRYINDEX ? (i) : lua_gettop(L) + (i) + 1)

/*
** {======================================================
** Error-report functions
** =======================================================
*/

LUALIB_API int
luaL_argerror(lua_State* L, int narg, const char* extramsg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API int
luaL_typerror(lua_State* L, int narg, const char* tname)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
tag_error(lua_State* L, int narg, int tag)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API void
luaL_where(lua_State* L, int level)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API int
luaL_error(lua_State* L, const char* fmt, ...)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/* }====================================================== */

LUALIB_API int
luaL_checkoption(lua_State* L,
                 int narg,
                 const char* def,
                 const char* const lst[])
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API int
luaL_newmetatable(lua_State* L, const char* tname)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API void*
luaL_checkudata(lua_State* L, int ud, const char* tname)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API void
luaL_checkstack(lua_State* L, int space, const char* mes)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API void
luaL_checktype(lua_State* L, int narg, int t)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API void
luaL_checkany(lua_State* L, int narg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API const char*
luaL_checklstring(lua_State* L, int narg, size_t* len)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API const char*
luaL_optlstring(lua_State* L, int narg, const char* def, size_t* len)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API lua_Number
luaL_checknumber(lua_State* L, int narg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API lua_Number
luaL_checknumber_noassert(lua_State* L, int narg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API lua_Number
luaL_optnumber(lua_State* L, int narg, lua_Number def)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API lua_Integer
luaL_checkinteger(lua_State* L, int narg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API lua_Integer
luaL_optinteger(lua_State* L, int narg, lua_Integer def)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API int
luaL_getmetafield(lua_State* L, int obj, const char* event)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API int
luaL_callmeta(lua_State* L, int obj, const char* event)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API void(luaL_register)(lua_State* L,
                               const char* libname,
                               const luaL_Reg* l)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
libsize(const luaL_Reg* l)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API void
luaI_openlib(lua_State* L, const char* libname, const luaL_Reg* l, int nup)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

    /*
    ** {======================================================
    ** getn-setn: size for arrays
    ** =======================================================
    */

#if defined(LUA_COMPAT_GETN)

static int
checkint(lua_State* L, int topop)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
getsizes(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API void
luaL_setn(lua_State* L, int t, int n)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API int
luaL_getn(lua_State* L, int t)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#endif

/* }====================================================== */

LUALIB_API const char*
luaL_gsub(lua_State* L, const char* s, const char* p, const char* r)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API const char*
luaL_findtable(lua_State* L, int idx, const char* fname, int szhint)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

    /*
    ** {======================================================
    ** Generic Buffer manipulation
    ** =======================================================
    */

#define bufflen(B) ((B)->p - (B)->buffer)
#define bufffree(B) ((size_t)(LUAL_BUFFERSIZE - bufflen(B)))

#define LIMIT (LUA_MINSTACK / 2)

static int
emptybuffer(luaL_Buffer* B)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
adjuststack(luaL_Buffer* B)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API char*
luaL_prepbuffer(luaL_Buffer* B)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API void
luaL_addlstring(luaL_Buffer* B, const char* s, size_t l)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API void
luaL_addstring(luaL_Buffer* B, const char* s)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API void
luaL_pushresult(luaL_Buffer* B)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API void
luaL_addvalue(luaL_Buffer* B)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API void
luaL_buffinit(lua_State* L, luaL_Buffer* B)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/* }====================================================== */

LUALIB_API int
luaL_ref(lua_State* L, int t)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API void
luaL_unref(lua_State* L, int t, int ref)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
** {======================================================
** Load functions
** =======================================================
*/

typedef struct LoadF
{
  int extraline;
  FILE *f;
  char buff[LUAL_BUFFERSIZE];
} LoadF;

static int
errfile(lua_State* L, const char* what, int fnameindex)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API int
luaL_loadfile(lua_State* L, const char* filename)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

typedef struct LoadS
{
  const char *s;
  size_t size;
} LoadS;

LUALIB_API int
luaL_loadbuffer(lua_State* L, const char* buff, size_t size, const char* name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API int(luaL_loadstring)(lua_State* L, const char* s)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/* }====================================================== */

static void*
l_alloc(void* ud, void* ptr, size_t osize, size_t nsize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
panic(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LUALIB_API lua_State*
luaL_newstate(void)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
