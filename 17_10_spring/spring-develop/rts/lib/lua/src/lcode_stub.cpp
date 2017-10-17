#include <iostream>
/*
** $Id: lcode.c,v 2.25.1.5 2011/01/31 14:53:16 roberto Exp $
** Code generator for Lua
** See Copyright Notice in lua.h
*/

#include <stdlib.h>

#define lcode_c
#define LUA_CORE

#include "lua.h"

#include "lcode.h"
#include "ldebug.h"
#include "ldo.h"
#include "lgc.h"
#include "llex.h"
#include "lmem.h"
#include "lobject.h"
#include "lopcodes.h"
#include "lparser.h"
#include "ltable.h"

#define hasjumps(e) ((e)->t != (e)->f)

static int
isnumeral(expdesc* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_nil(FuncState* fs, int from, int n)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
luaK_jump(FuncState* fs)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_ret(FuncState* fs, int first, int nret)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
condjump(FuncState* fs, OpCode op, int A, int B, int C)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
fixjump(FuncState* fs, int pc, int dest)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
** returns current `pc' and marks it as a jump target (to avoid wrong
** optimizations with consecutive instructions not in the same basic block).
*/
int
luaK_getlabel(FuncState* fs)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
getjump(FuncState* fs, int pc)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static Instruction*
getjumpcontrol(FuncState* fs, int pc)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
** check whether list has any jump that do not produce a value
** (or produce an inverted value)
*/
static int
need_value(FuncState* fs, int list)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
patchtestreg(FuncState* fs, int node, int reg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
removevalues(FuncState* fs, int list)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
patchlistaux(FuncState* fs, int list, int vtarget, int reg, int dtarget)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
dischargejpc(FuncState* fs)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_patchlist(FuncState* fs, int list, int target)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_patchtohere(FuncState* fs, int list)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_concat(FuncState* fs, int* l1, int l2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_checkstack(FuncState* fs, int n)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_reserveregs(FuncState* fs, int n)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
freereg(FuncState* fs, int reg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
freeexp(FuncState* fs, expdesc* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
addk(FuncState* fs, TValue* k, TValue* v)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
luaK_stringK(FuncState* fs, TString* s)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
luaK_numberK(FuncState* fs, lua_Number r)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
boolK(FuncState* fs, int b)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
nilK(FuncState* fs)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_setreturns(FuncState* fs, expdesc* e, int nresults)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_setoneret(FuncState* fs, expdesc* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_dischargevars(FuncState* fs, expdesc* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
code_label(FuncState* fs, int A, int b, int jump)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
discharge2reg(FuncState* fs, expdesc* e, int reg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
discharge2anyreg(FuncState* fs, expdesc* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
exp2reg(FuncState* fs, expdesc* e, int reg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_exp2nextreg(FuncState* fs, expdesc* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
luaK_exp2anyreg(FuncState* fs, expdesc* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_exp2val(FuncState* fs, expdesc* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
luaK_exp2RK(FuncState* fs, expdesc* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_storevar(FuncState* fs, expdesc* var, expdesc* ex)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_self(FuncState* fs, expdesc* e, expdesc* key)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
invertjump(FuncState* fs, expdesc* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
jumponcond(FuncState* fs, expdesc* e, int cond)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_goiftrue(FuncState* fs, expdesc* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
luaK_goiffalse(FuncState* fs, expdesc* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
codenot(FuncState* fs, expdesc* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_indexed(FuncState* fs, expdesc* t, expdesc* k)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
constfolding(OpCode op, expdesc* e1, expdesc* e2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
codearith(FuncState* fs, OpCode op, expdesc* e1, expdesc* e2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
codecomp(FuncState* fs, OpCode op, int cond, expdesc* e1, expdesc* e2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_prefix(FuncState* fs, UnOpr op, expdesc* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_infix(FuncState* fs, BinOpr op, expdesc* v)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_posfix(FuncState* fs, BinOpr op, expdesc* e1, expdesc* e2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_fixline(FuncState* fs, int line)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
luaK_code(FuncState* fs, Instruction i, int line)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
luaK_codeABC(FuncState* fs, OpCode o, int a, int b, int c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
luaK_codeABx(FuncState* fs, OpCode o, int a, unsigned int bc)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaK_setlist(FuncState* fs, int base, int nelems, int tostore)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
