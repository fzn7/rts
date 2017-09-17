#include <iostream>
/*
** $Id: lvm.c,v 2.63.1.5 2011/08/17 20:43:11 roberto Exp $
** Lua virtual machine
** See Copyright Notice in lua.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// SPRING
#include "streflop_cond.h"

#define lvm_c
#define LUA_CORE

#include "lua.h"

#include "ldebug.h"
#include "ldo.h"
#include "lfunc.h"
#include "lgc.h"
#include "lobject.h"
#include "lopcodes.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "ltm.h"
#include "lvm.h"

/* limit for table tag-method chains (to avoid loops) */
#define MAXTAGLOOP 100

const TValue*
luaV_tonumber(const TValue* obj, TValue* n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
luaV_tostring(lua_State* L, StkId obj)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
traceexec(lua_State* L, const Instruction* pc)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
callTMres(lua_State* L,
          StkId res,
          const TValue* f,
          const TValue* p1,
          const TValue* p2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
callTM(lua_State* L,
       const TValue* f,
       const TValue* p1,
       const TValue* p2,
       const TValue* p3)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
luaV_gettable(lua_State* L, const TValue* t, TValue* key, StkId val)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
luaV_settable(lua_State* L, const TValue* t, TValue* key, StkId val)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
call_binTM(lua_State* L,
           const TValue* p1,
           const TValue* p2,
           StkId res,
           TMS event)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const TValue*
get_compTM(lua_State* L, Table* mt1, Table* mt2, TMS event)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
call_orderTM(lua_State* L, const TValue* p1, const TValue* p2, TMS event)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
l_strcmp(const TString* ls, const TString* rs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
luaV_lessthan(lua_State* L, const TValue* l, const TValue* r)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
lessequal(lua_State* L, const TValue* l, const TValue* r)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
luaV_equalval(lua_State* L, const TValue* t1, const TValue* t2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
luaV_concat(lua_State* L, int total, int last)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
Arith(lua_State* L, StkId ra, const TValue* rb, const TValue* rc, TMS op)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

    /*
    ** some macros for common tasks in `luaV_execute'
    */

#define runtime_check(L, c)                                                    \
    {                                                                          \
        if (!(c))                                                              \
            break;                                                             \
    }

#define RA(i) (base + GETARG_A(i))
/* to be used after possible stack reallocation */
#define RB(i) check_exp(getBMode(GET_OPCODE(i)) == OpArgR, base + GETARG_B(i))
#define RC(i) check_exp(getCMode(GET_OPCODE(i)) == OpArgR, base + GETARG_C(i))
#define RKB(i)                                                                 \
    check_exp(getBMode(GET_OPCODE(i)) == OpArgK,                               \
              ISK(GETARG_B(i)) ? k + INDEXK(GETARG_B(i)) : base + GETARG_B(i))
#define RKC(i)                                                                 \
    check_exp(getCMode(GET_OPCODE(i)) == OpArgK,                               \
              ISK(GETARG_C(i)) ? k + INDEXK(GETARG_C(i)) : base + GETARG_C(i))
#define KBx(i) check_exp(getBMode(GET_OPCODE(i)) == OpArgK, k + GETARG_Bx(i))

#define dojump(L, pc, i)                                                       \
    {                                                                          \
        (pc) += (i);                                                           \
        luai_threadyield(L);                                                   \
    }

#define Protect(x)                                                             \
    {                                                                          \
        L->savedpc = pc;                                                       \
        {                                                                      \
            x;                                                                 \
        };                                                                     \
        base = L->base;                                                        \
    }

#define arith_op(op, tm)                                                       \
    {                                                                          \
        TValue* rb = RKB(i);                                                   \
        TValue* rc = RKC(i);                                                   \
        if (ttisnumber(rb) && ttisnumber(rc)) {                                \
            lua_Number nb = nvalue(rb), nc = nvalue(rc);                       \
            setnvalue(ra, op(nb, nc));                                         \
        } else                                                                 \
            Protect(Arith(L, ra, rb, rc, tm));                                 \
    }

void
luaV_execute(lua_State* L, int nexeccalls)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
