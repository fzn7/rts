#include <iostream>
/*
** $Id: lmem.c,v 1.70.1.1 2007/12/27 13:02:25 roberto Exp $
** Interface to Memory Manager
** See Copyright Notice in lua.h
*/

#include <stddef.h>

// SPRING

#define lmem_c
#define LUA_CORE

#include "lua.h"

#include "ldebug.h"
#include "ldo.h"
#include "lmem.h"
#include "lobject.h"
#include "lstate.h"

/*
** About the realloc function:
** void * frealloc (void *ud, void *ptr, size_t osize, size_t nsize);
** (`osize' is the old size, `nsize' is the new size)
**
** Lua ensures that (ptr == NULL) iff (osize == 0).
**
** * frealloc(ud, NULL, 0, x) creates a new block of size `x'
**
** * frealloc(ud, p, x, 0) frees the block `p'
** (in this specific case, frealloc must return NULL).
** particularly, frealloc(ud, NULL, 0, 0) does nothing
** (which is equivalent to free(NULL) in ANSI C)
**
** frealloc returns NULL if it cannot create or reallocate the area
** (any reallocation to an equal or smaller size cannot fail!)
*/

#define MINSIZEARRAY 4

void*
luaM_growaux_(lua_State* L,
              void* block,
              int* size,
              size_t size_elems,
              int limit,
              const char* errormsg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void*
luaM_toobig(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
** generic allocation routine.
*/
void*
luaM_realloc_(lua_State* L, void* block, size_t osize, size_t nsize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
