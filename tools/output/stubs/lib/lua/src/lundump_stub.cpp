/*
** $Id: lundump.c,v 2.7.1.4 2008/04/04 19:51:41 roberto Exp $
** load precompiled Lua chunks
** See Copyright Notice in lua.h
*/

#include <string.h>

#define lundump_c
#define LUA_CORE

#include "lua.h"

#include "ldebug.h"
#include "ldo.h"
#include "lfunc.h"
#include "lmem.h"
#include "lobject.h"
#include "lstring.h"
#include "lundump.h"
#include "lzio.h"

typedef struct {
 lua_State* L;
 ZIO* Z;
 Mbuffer* b;
 const char* name;
} LoadState;

#ifdef LUAC_TRUST_BINARIES
#define IF(c,s)
#define error(S,s)
#else
#define IF(c,s)		if (c) error(S,s)

static void error(LoadState* S, const char* why)
{
    //stub method
}
#endif

#define LoadMem(S,b,n,size)	LoadBlock(S,b,(n)*(size))
#define	LoadByte(S)		(lu_byte)LoadChar(S)
#define LoadVar(S,x)		LoadMem(S,&x,1,sizeof(x))
#define LoadVector(S,b,n,size)	LoadMem(S,b,n,size)

static void LoadBlock(LoadState* S, void* b, size_t size)
{
    //stub method
}

static int LoadChar(LoadState* S)
{
    //stub method
}

static int LoadInt(LoadState* S)
{
    //stub method
}

static lua_Number LoadNumber(LoadState* S)
{
    //stub method
}

static TString* LoadString(LoadState* S)
{
    //stub method
}

static void LoadCode(LoadState* S, Proto* f)
{
    //stub method
}

static Proto* LoadFunction(LoadState* S, TString* p);

static void LoadConstants(LoadState* S, Proto* f)
{
    //stub method
}

static void LoadDebug(LoadState* S, Proto* f)
{
    //stub method
}

static Proto* LoadFunction(LoadState* S, TString* p)
{
    //stub method
}

static void LoadHeader(LoadState* S)
{
    //stub method
}

/*
** load precompiled chunk
*/
Proto* luaU_undump (lua_State* L, ZIO* Z, Mbuffer* buff, const char* name)
{
    //stub method
}

/*
* make header
*/
void luaU_header (char* h)
{
    //stub method
}
