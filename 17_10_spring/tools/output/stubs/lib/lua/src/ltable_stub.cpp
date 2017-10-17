#include <iostream>
/*
** $Id: ltable.c,v 2.32.1.2 2007/12/28 15:32:23 roberto Exp $
** Lua tables (hash)
** See Copyright Notice in lua.h
*/

/*
** Implementation of tables (aka arrays, objects, or hash tables).
** Tables keep its elements in two parts: an array part and a hash part.
** Non-negative integer keys are all candidates to be kept in the array
** part. The actual size of the array is the largest `n' such that at
** least half the slots between 0 and n are in use.
** Hash uses a mix of chained scatter table with Brent's variation.
** A main invariant of these tables is that, if an element is not
** in its main position (i.e. the `original' position that its hash gives
** to it), then the colliding element is in its own main position.
** Hence even when the load factor reaches 100%, performance remains good.
*/

// SPRING#include <math.h>
#include "streflop_cond.h"
#include <string.h>

#define ltable_c
#define LUA_CORE

#include "lua.h"

#include "ldebug.h"
#include "ldo.h"
#include "lgc.h"
#include "lmem.h"
#include "lobject.h"
#include "lstate.h"
#include "ltable.h"

/*
** max size of array part is 2^MAXBITS
*/
#if LUAI_BITSINT > 26
#define MAXBITS 26
#else
#define MAXBITS (LUAI_BITSINT - 2)
#endif

#define MAXASIZE (1 << MAXBITS)

#define hashpow2(t, n) (gnode(t, lmod((n), sizenode(t))))

#define hashstr(t, str) hashpow2(t, (str)->tsv.hash)
#define hashboolean(t, p) hashpow2(t, p)

/*
** for some types, it is better to avoid modulus by power of 2, as
** they tend to have many 2 factors.
*/
#define hashmod(t, n) (gnode(t, ((n) % ((sizenode(t) - 1) | 1))))

#define hashpointer(t, p) hashmod(t, IntPoint(p))

/*
** number of ints inside a lua_Number
*/
#define numints cast_int(sizeof(lua_Number) / sizeof(int))

#define dummynode (&dummynode_)

static const Node dummynode_ = {
    { { NULL }, LUA_TNIL },          /* value */
    { { { NULL }, LUA_TNIL, NULL } } /* key */
};

/*
** hash for lua_Numbers
*/
static Node*
hashnum(const Table* t, lua_Number n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** returns the `main' position of an element in a table (that is, the index
** of its hash value)
*/
static Node*
mainposition(const Table* t, const TValue* key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** returns the index for `key' if `key' is an appropriate key to live in
** the array part of the table, -1 otherwise.
*/
static int
arrayindex(const TValue* key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** returns the index of a `key' for table traversals. First goes all
** elements in the array part, then elements in the hash part. The
** beginning of a traversal is signalled by -1.
*/
static int
findindex(lua_State* L, Table* t, StkId key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
luaH_next(lua_State* L, Table* t, StkId key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** {=============================================================
** Rehash
** ==============================================================
*/

static int
computesizes(int nums[], int* narray)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
countint(const TValue* key, int* nums)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
numusearray(const Table* t, int* nums)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
numusehash(const Table* t, int* nums, int* pnasize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
setarrayvector(lua_State* L, Table* t, int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
setnodevector(lua_State* L, Table* t, int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
resize(lua_State* L, Table* t, int nasize, int nhsize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
luaH_resizearray(lua_State* L, Table* t, int nasize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
rehash(lua_State* L, Table* t, const TValue* ek)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** }=============================================================
*/

Table*
luaH_new(lua_State* L, int narray, int nhash)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
luaH_free(lua_State* L, Table* t)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static Node*
getfreepos(Table* t)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** inserts a new key into a hash table; first, check whether key's main
** position is free. If not, check whether colliding node is in its main
** position or not: if it is not, move colliding node to an empty place and
** put new key in its main position; otherwise (colliding node is in its main
** position), new key goes to an empty position.
*/
static TValue*
newkey(lua_State* L, Table* t, const TValue* key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** search function for integers
*/
const TValue*
luaH_getnum(Table* t, int key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** search function for strings
*/
const TValue*
luaH_getstr(Table* t, TString* key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** main search function
*/
const TValue*
luaH_get(Table* t, const TValue* key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

TValue*
luaH_set(lua_State* L, Table* t, const TValue* key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

TValue*
luaH_setnum(lua_State* L, Table* t, int key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

TValue*
luaH_setstr(lua_State* L, Table* t, TString* key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
unbound_search(Table* t, unsigned int j)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** Try to find a boundary in table `t'. A `boundary' is an integer index
** such that t[i] is non-nil and t[i+1] is nil (and 0 if t[1] is nil).
*/
int
luaH_getn(Table* t)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#if defined(LUA_DEBUG)

Node*
luaH_mainposition(const Table* t, const TValue* key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
luaH_isdummy(Node* n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#endif
