#include <iostream>
/*
** $Id: lstrlib.c,v 1.132.1.5 2010/05/14 15:34:19 roberto Exp $
** Standard library for string operations and pattern-matching
** See Copyright Notice in lua.h
*/

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lstrlib_c
#define LUA_LIB

#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

/* macro to `unsign' a character */
#define uchar(c) ((unsigned char)(c))

static int
str_len(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static ptrdiff_t
posrelat(ptrdiff_t pos, size_t len)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
str_sub(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
str_reverse(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
str_lower(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
str_upper(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
str_rep(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
str_byte(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
str_char(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
writer(lua_State* L, const void* b, size_t size, void* B)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
str_dump(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

    /*
    ** {======================================================
    ** PATTERN MATCHING
    ** =======================================================
    */

#define CAP_UNFINISHED (-1)
#define CAP_POSITION (-2)

typedef struct MatchState {
  const char *src_init;  /* init of source string */
  const char *src_end;  /* end (`\0') of source string */
  lua_State *L;
  int level;  /* total number of captures (finished or unfinished) */
  struct {
    const char *init;
    ptrdiff_t len;
  } capture[LUA_MAXCAPTURES];
} MatchState;

static int
capture_to_close(MatchState* ms)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const char*
classend(MatchState* ms, const char* p)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
match_class(int c, int cl)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
matchbracketclass(int c, const char* p, const char* ec)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
singlematch(int c, const char* p, const char* ep)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const char*
match(MatchState* ms, const char* s, const char* p);

static const char*
matchbalance(MatchState* ms, const char* s, const char* p)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const char*
max_expand(MatchState* ms, const char* s, const char* p, const char* ep)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const char*
min_expand(MatchState* ms, const char* s, const char* p, const char* ep)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const char*
start_capture(MatchState* ms, const char* s, const char* p, int what)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const char*
end_capture(MatchState* ms, const char* s, const char* p)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const char*
match_capture(MatchState* ms, const char* s, int l)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const char*
match(MatchState* ms, const char* s, const char* p)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const char*
lmemfind(const char* s1, size_t l1, const char* s2, size_t l2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
push_onecapture(MatchState* ms, int i, const char* s, const char* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
push_captures(MatchState* ms, const char* s, const char* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
str_find_aux(lua_State* L, int find)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
str_find(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
str_match(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
gmatch_aux(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
gmatch(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
gfind_nodef(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
add_s(MatchState* ms, luaL_Buffer* b, const char* s, const char* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
add_value(MatchState* ms, luaL_Buffer* b, const char* s, const char* e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
str_gsub(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/* }====================================================== */

/* maximum size of each formatted item (> len(format('%99.99f', -1e308))) */
#define MAX_ITEM 512
/* valid flags in a format specification */
#define FLAGS "-+ #0"
/*
** maximum size of each format specification (such as '%-099.99d')
** (+10 accounts for %99.99x plus margin of error)
*/
#define MAX_FORMAT (sizeof(FLAGS) + sizeof(LUA_INTFRMLEN) + 10)

static void
addquoted(lua_State* L, luaL_Buffer* b, int arg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const char*
scanformat(lua_State* L, const char* strfrmt, char* form)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
addintlen(char* form)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
str_format(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const luaL_Reg strlib[] = {
    { "byte", str_byte },       { "char", str_char },
    { "dump", str_dump },       { "find", str_find },
    { "format", str_format },   { "gfind", gfind_nodef },
    { "gmatch", gmatch },       { "gsub", str_gsub },
    { "len", str_len },         { "lower", str_lower },
    { "match", str_match },     { "rep", str_rep },
    { "reverse", str_reverse }, { "sub", str_sub },
    { "upper", str_upper },     { NULL, NULL }
};

static void
createmetatable(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
** Open string library
*/
LUALIB_API int
luaopen_string(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
