#include <iostream>
/*
** $Id: loadlib.c,v 1.52.1.4 2009/09/09 13:17:16 roberto Exp $
** Dynamic library loader for Lua
** See Copyright Notice in lua.h
**
** This module contains an implementation of loadlib for Unix systems
** that have dlfcn, an implementation for Darwin (Mac OS X), an
** implementation for Windows, and a stub for other systems.
*/

#include <stdlib.h>
#include <string.h>

#define loadlib_c
#define LUA_LIB

#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

/* prefix for open functions in C libraries */
#define LUA_POF "luaopen_"

/* separator for open functions in C libraries */
#define LUA_OFSEP "_"

#define LIBPREFIX "LOADLIB: "

#define POF LUA_POF
#define LIB_FAIL "open"

/* error codes for ll_loadfunc */
#define ERRLIB 1
#define ERRFUNC 2

#define setprogdir(L) ((void)0)

static void
ll_unloadlib(void* lib);
static void*
ll_load(lua_State* L, const char* path);
static lua_CFunction
ll_sym(lua_State* L, void* lib, const char* sym);

#if defined(LUA_DL_DLOPEN)
/*
** {========================================================================
** This is an implementation of loadlib based on the dlfcn interface.
** The dlfcn interface is available in Linux, SunOS, Solaris, IRIX, FreeBSD,
** NetBSD, AIX 4.2, HPUX 11, and  probably most other Unix flavors, at least
** as an emulation layer on top of native functions.
** =========================================================================
*/

#include <dlfcn.h>

static void
ll_unloadlib(void* lib)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void*
ll_load(lua_State* L, const char* path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static lua_CFunction
ll_sym(lua_State* L, void* lib, const char* sym)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

    /* }====================================================== */

#elif defined(LUA_DL_DLL)
/*
** {======================================================================
** This is an implementation of loadlib for Windows using native functions.
** =======================================================================
*/

#include <windows.h>

#undef setprogdir

static void
setprogdir(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
pusherror(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
ll_unloadlib(void* lib)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void*
ll_load(lua_State* L, const char* path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static lua_CFunction
ll_sym(lua_State* L, void* lib, const char* sym)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

    /* }====================================================== */

#elif defined(LUA_DL_DYLD)
/*
** {======================================================================
** Native Mac OS X / Darwin Implementation
** =======================================================================
*/

#include <mach-o/dyld.h>

/* Mac appends a `_' before C function names */
#undef POF
#define POF "_" LUA_POF

static void
pusherror(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const char*
errorfromcode(NSObjectFileImageReturnCode ret)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
ll_unloadlib(void* lib)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void*
ll_load(lua_State* L, const char* path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static lua_CFunction
ll_sym(lua_State* L, void* lib, const char* sym)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

    /* }====================================================== */

#else
/*
** {======================================================
** Fallback for other systems
** =======================================================
*/

#undef LIB_FAIL
#define LIB_FAIL "absent"

#define DLMSG "dynamic libraries not enabled; check your Lua installation"

static void
ll_unloadlib(void* lib)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void*
ll_load(lua_State* L, const char* path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static lua_CFunction
ll_sym(lua_State* L, void* lib, const char* sym)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* }====================================================== */
#endif

static void**
ll_register(lua_State* L, const char* path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** __gc tag method: calls library's `ll_unloadlib' function with the lib
** handle
*/
static int
gctm(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
ll_loadfunc(lua_State* L, const char* path, const char* sym)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
ll_loadlib(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** {======================================================
** 'require' function
** =======================================================
*/

static int
readable(const char* filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const char*
pushnexttemplate(lua_State* L, const char* path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const char*
findfile(lua_State* L, const char* name, const char* pname)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
loaderror(lua_State* L, const char* filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
loader_Lua(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const char*
mkfuncname(lua_State* L, const char* modname)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
loader_C(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
loader_Croot(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
loader_preload(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const int sentinel_ = 0;
#define sentinel ((void*)&sentinel_)

static int
ll_require(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* }====================================================== */

/*
** {======================================================
** 'module' function
** =======================================================
*/

static void
setfenv(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
dooptions(lua_State* L, int n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
modinit(lua_State* L, const char* modname)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
ll_module(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
ll_seeall(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* }====================================================== */

/* auxiliary mark (for internal use) */
#define AUXMARK "\1"

static void
setpath(lua_State* L,
        const char* fieldname,
        const char* envname,
        const char* def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const luaL_Reg pk_funcs[] = { { "loadlib", ll_loadlib },
                                     { "seeall", ll_seeall },
                                     { NULL, NULL } };

static const luaL_Reg ll_funcs[] = { { "module", ll_module },
                                     { "require", ll_require },
                                     { NULL, NULL } };

static const lua_CFunction loaders[] = { loader_preload,
                                         loader_Lua,
                                         loader_C,
                                         loader_Croot,
                                         NULL };

LUALIB_API int
luaopen_package(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
