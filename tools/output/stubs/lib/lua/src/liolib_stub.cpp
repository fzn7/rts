#include <iostream>
/*
** $Id: liolib.c,v 2.73.1.4 2010/05/14 15:33:51 roberto Exp $
** Standard I/O (and system) library
** See Copyright Notice in lua.h
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define liolib_c
#define LUA_LIB

#include "lua.h"

#include "lauxlib.h"
#include "lstate.h" /* SPRING */
#include "lualib.h"

#define IO_INPUT 1
#define IO_OUTPUT 2

static const char* const fnames[] = { "input", "output" };

/* SPRING */
static FILE*
lua_fopen(lua_State* L, const char* filename, const char* mode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
pushresult(lua_State* L, int i, const char* filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
fileerror(lua_State* L, int arg, const char* filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#define tofilep(L) ((FILE**)luaL_checkudata(L, 1, LUA_FILEHANDLE))

static int
io_type(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static FILE*
tofile(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** When creating file handles, always creates a `closed' file handle
** before opening the actual file; so, if there is a memory error, the
** file is not left opened.
*/
static FILE**
newfile(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** function to (not) close the standard files stdin, stdout, and stderr
*/
static int
io_noclose(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** function to close 'popen' files
*/
static int
io_pclose(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** function to close regular files
*/
static int
io_fclose(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
aux_close(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
io_close(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
io_gc(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
io_tostring(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
io_open(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** this function has a separated environment, which defines the
** correct __close for 'popen' files
*/
static int
io_popen(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
io_tmpfile(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static FILE*
getiofile(lua_State* L, int findex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
g_iofile(lua_State* L, int f, const char* mode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
io_input(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
io_output(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
io_readline(lua_State* L);

static void
aux_lines(lua_State* L, int idx, int toclose)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
f_lines(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
io_lines(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** {======================================================
** READ
** =======================================================
*/

static int
read_number(lua_State* L, FILE* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
test_eof(lua_State* L, FILE* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
read_line(lua_State* L, FILE* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
read_chars(lua_State* L, FILE* f, size_t n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
g_read(lua_State* L, FILE* f, int first)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
io_read(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
f_read(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
io_readline(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* }====================================================== */

static int
g_write(lua_State* L, FILE* f, int arg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
io_write(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
f_write(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
f_seek(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
f_setvbuf(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
io_flush(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
f_flush(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const luaL_Reg iolib[] = {
    { "close", io_close }, { "flush", io_flush }, { "input", io_input },
    { "lines", io_lines }, { "open", io_open },   { "output", io_output },
    { "popen", io_popen }, { "read", io_read },   { "tmpfile", io_tmpfile },
    { "type", io_type },   { "write", io_write }, { NULL, NULL }
};

static const luaL_Reg flib[] = {
    { "close", io_close }, { "flush", f_flush }, { "lines", f_lines },
    { "read", f_read },    { "seek", f_seek },   { "setvbuf", f_setvbuf },
    { "write", f_write },  { "__gc", io_gc },    { "__tostring", io_tostring },
    { NULL, NULL }
};

static void
createmeta(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
createstdfile(lua_State* L, FILE* f, int k, const char* fname)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
newfenv(lua_State* L, lua_CFunction cls)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LUALIB_API int
luaopen_io(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
