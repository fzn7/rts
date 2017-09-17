#include <iostream>
/*
** $Id: print.c,v 1.55a 2006/05/31 13:30:05 lhf Exp $
** print bytecodes
** See Copyright Notice in lua.h
*/

#include <ctype.h>
#include <stdio.h>

#define luac_c
#define LUA_CORE

#include "ldebug.h"
#include "lobject.h"
#include "lopcodes.h"
#include "lundump.h"

#define PrintFunction	luaU_print

#define Sizeof(x)	((int)sizeof(x))
#define VOID(p)		((const void*)(p))

static void PrintString(const TString* ts)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void PrintConstant(const Proto* f, int i)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void PrintCode(const Proto* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#define SS(x)	(x==1)?"":"s"
#define S(x)	x,SS(x)

static void PrintHeader(const Proto* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void PrintConstants(const Proto* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void PrintLocals(const Proto* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void PrintUpvalues(const Proto* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void PrintFunction(const Proto* f, int full)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
