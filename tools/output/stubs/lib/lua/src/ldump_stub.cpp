#include <iostream>
/*
** $Id: ldump.c,v 2.8.1.1 2007/12/27 13:02:25 roberto Exp $
** save precompiled Lua chunks
** See Copyright Notice in lua.h
*/

#include <stddef.h>

#define ldump_c
#define LUA_CORE

#include "lua.h"

#include "lobject.h"
#include "lstate.h"
#include "lundump.h"

typedef struct {
 lua_State* L;
 lua_Writer writer;
 void* data;
 int strip;
 int status;
} DumpState;

#define DumpMem(b,n,size,D)	DumpBlock(b,(n)*(size),D)
#define DumpVar(x,D)	 	DumpMem(&x,1,sizeof(x),D)

static void DumpBlock(const void* b, size_t size, DumpState* D)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void DumpChar(int y, DumpState* D)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void DumpInt(int x, DumpState* D)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void DumpNumber(lua_Number x, DumpState* D)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void DumpVector(const void* b, int n, size_t size, DumpState* D)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void DumpString(const TString* s, DumpState* D)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#define DumpCode(f,D)	 DumpVector(f->code,f->sizecode,sizeof(Instruction),D)

static void DumpFunction(const Proto* f, const TString* p, DumpState* D);

static void DumpConstants(const Proto* f, DumpState* D)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void DumpDebug(const Proto* f, DumpState* D)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void DumpFunction(const Proto* f, const TString* p, DumpState* D)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void DumpHeader(DumpState* D)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** dump Lua function as precompiled chunk
*/
int luaU_dump (lua_State* L, const Proto* f, lua_Writer w, void* data, int strip)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
