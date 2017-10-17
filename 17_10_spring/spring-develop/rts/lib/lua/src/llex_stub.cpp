#include <iostream>
/*
** $Id: llex.c,v 2.20.1.2 2009/11/23 14:58:22 roberto Exp $
** Lexical Analyzer
** See Copyright Notice in lua.h
*/

#include <ctype.h>
#include <locale.h>
#include <string.h>

#define llex_c
#define LUA_CORE

#include "lua.h"

#include "ldo.h"
#include "llex.h"
#include "lobject.h"
#include "lparser.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "lzio.h"

#define next(ls) (ls->current = zgetc(ls->z))

#define currIsNewline(ls) (ls->current == '\n' || ls->current == '\r')

/* ORDER RESERVED */
const char* const luaX_tokens[] = {
    "and",    "break",    "do",     "else", "elseif", "end",   "false",
    "for",    "function", "if",     "in",   "local",  "nil",   "not",
    "or",     "repeat",   "return", "then", "true",   "until", "while",
    "..",     "...",      "==",     ">=",   "<=",     "~=",    "<number>",
    "<name>", "<string>", "<eof>",  NULL
};

#define save_and_next(ls) (save(ls, ls->current), next(ls))

static void
save(LexState* ls, int c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaX_init(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#define MAXSRC 80

const char*
luaX_token2str(LexState* ls, int token)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const char*
txtToken(LexState* ls, int token)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaX_lexerror(LexState* ls, const char* msg, int token)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaX_syntaxerror(LexState* ls, const char* msg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

TString*
luaX_newstring(LexState* ls, const char* str, size_t l)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
inclinenumber(LexState* ls)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaX_setinput(lua_State* L, LexState* ls, ZIO* z, TString* source)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
** =======================================================
** LEXICAL ANALYZER
** =======================================================
*/

static int
check_next(LexState* ls, const char* set)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
buffreplace(LexState* ls, char from, char to)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
trydecpoint(LexState* ls, SemInfo* seminfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/* LUA_NUMBER */
static void
read_numeral(LexState* ls, SemInfo* seminfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
skip_sep(LexState* ls)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
read_long_string(LexState* ls, SemInfo* seminfo, int sep)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
read_string(LexState* ls, int del, SemInfo* seminfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
llex(LexState* ls, SemInfo* seminfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaX_next(LexState* ls)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
luaX_lookahead(LexState* ls)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
