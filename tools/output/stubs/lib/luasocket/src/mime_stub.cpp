#include <iostream>
/*=========================================================================*\
* MIME support functions
* LuaSocket toolkit
*
* RCS ID: $Id: mime.c,v 1.28 2005/11/20 07:20:23 diego Exp $
\*=========================================================================*/
#include <string.h>

#include "lua.h"
#include "lauxlib.h"

#if !defined(LUA_VERSION_NUM) || (LUA_VERSION_NUM < 501)
#include "compat-5.1.h"
#endif

#include "mime.h"

/*=========================================================================*\
* Don't want to trust escape character constants
\*=========================================================================*/
typedef unsigned char UC;
static const char CRLF[] = "\r\n";
static const char EQCRLF[] = "=\r\n";

/*=========================================================================*\
* Internal function prototypes.
\*=========================================================================*/
static int mime_global_wrp(lua_State *L);
static int mime_global_b64(lua_State *L);
static int mime_global_unb64(lua_State *L);
static int mime_global_qp(lua_State *L);
static int mime_global_unqp(lua_State *L);
static int mime_global_qpwrp(lua_State *L);
static int mime_global_eol(lua_State *L);
static int mime_global_dot(lua_State *L);

static size_t dot(int c, size_t state, luaL_Buffer *buffer);
static void b64setup(UC *b64unbase);
static size_t b64encode(UC c, UC *input, size_t size, luaL_Buffer *buffer);
static size_t b64pad(const UC *input, size_t size, luaL_Buffer *buffer);
static size_t b64decode(UC c, UC *input, size_t size, luaL_Buffer *buffer);

static void qpsetup(UC *qpclass, UC *qpunbase);
static void qpquote(UC c, luaL_Buffer *buffer);
static size_t qpdecode(UC c, UC *input, size_t size, luaL_Buffer *buffer);
static size_t qpencode(UC c, UC *input, size_t size, 
        const char *marker, luaL_Buffer *buffer);
static size_t qppad(UC *input, size_t size, luaL_Buffer *buffer);

/* code support functions */
static luaL_reg func[] = {
    { "dot", mime_global_dot },
    { "b64", mime_global_b64 },
    { "eol", mime_global_eol },
    { "qp", mime_global_qp },
    { "qpwrp", mime_global_qpwrp },
    { "unb64", mime_global_unb64 },
    { "unqp", mime_global_unqp },
    { "wrp", mime_global_wrp },
    { NULL, NULL }
};

/*-------------------------------------------------------------------------*\
* Quoted-printable globals
\*-------------------------------------------------------------------------*/
static UC qpclass[256];
static UC qpbase[] = "0123456789ABCDEF";
static UC qpunbase[256];
enum {QP_PLAIN, QP_QUOTED, QP_CR, QP_IF_LAST};

/*-------------------------------------------------------------------------*\
* Base64 globals
\*-------------------------------------------------------------------------*/
static const UC b64base[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static UC b64unbase[256];

/*=========================================================================*\
* Exported functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Initializes module
\*-------------------------------------------------------------------------*/
MIME_API int luaopen_mime_core(lua_State *L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*=========================================================================*\
* Global Lua functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Incrementaly breaks a string into lines. The string can have CRLF breaks.
* A, n = wrp(l, B, length)
* A is a copy of B, broken into lines of at most 'length' bytes. 
* 'l' is how many bytes are left for the first line of B. 
* 'n' is the number of bytes left in the last line of A. 
\*-------------------------------------------------------------------------*/
static int mime_global_wrp(lua_State *L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Fill base64 decode map. 
\*-------------------------------------------------------------------------*/
static void b64setup(UC *b64unbase) 
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Acumulates bytes in input buffer until 3 bytes are available. 
* Translate the 3 bytes into Base64 form and append to buffer.
* Returns new number of bytes in buffer.
\*-------------------------------------------------------------------------*/
static size_t b64encode(UC c, UC *input, size_t size, 
        luaL_Buffer *buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Encodes the Base64 last 1 or 2 bytes and adds padding '=' 
* Result, if any, is appended to buffer.
* Returns 0.
\*-------------------------------------------------------------------------*/
static size_t b64pad(const UC *input, size_t size, 
        luaL_Buffer *buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Acumulates bytes in input buffer until 4 bytes are available. 
* Translate the 4 bytes from Base64 form and append to buffer.
* Returns new number of bytes in buffer.
\*-------------------------------------------------------------------------*/
static size_t b64decode(UC c, UC *input, size_t size, 
        luaL_Buffer *buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Incrementally applies the Base64 transfer content encoding to a string
* A, B = b64(C, D)
* A is the encoded version of the largest prefix of C .. D that is
* divisible by 3. B has the remaining bytes of C .. D, *without* encoding.
* The easiest thing would be to concatenate the two strings and 
* encode the result, but we can't afford that or Lua would dupplicate
* every chunk we received.
\*-------------------------------------------------------------------------*/
static int mime_global_b64(lua_State *L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Incrementally removes the Base64 transfer content encoding from a string
* A, B = b64(C, D)
* A is the encoded version of the largest prefix of C .. D that is
* divisible by 4. B has the remaining bytes of C .. D, *without* encoding.
\*-------------------------------------------------------------------------*/
static int mime_global_unb64(lua_State *L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Quoted-printable encoding scheme
* all (except CRLF in text) can be =XX
* CLRL in not text must be =XX=XX
* 33 through 60 inclusive can be plain
* 62 through 126 inclusive can be plain
* 9 and 32 can be plain, unless in the end of a line, where must be =XX
* encoded lines must be no longer than 76 not counting CRLF
* soft line-break are =CRLF
* To encode one byte, we need to see the next two. 
* Worst case is when we see a space, and wonder if a CRLF is comming
\*-------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------*\
* Split quoted-printable characters into classes
* Precompute reverse map for encoding
\*-------------------------------------------------------------------------*/
static void qpsetup(UC *qpclass, UC *qpunbase)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Output one character in form =XX
\*-------------------------------------------------------------------------*/
static void qpquote(UC c, luaL_Buffer *buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Accumulate characters until we are sure about how to deal with them.
* Once we are sure, output to the buffer, in the correct form. 
\*-------------------------------------------------------------------------*/
static size_t qpencode(UC c, UC *input, size_t size, 
        const char *marker, luaL_Buffer *buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Deal with the final characters 
\*-------------------------------------------------------------------------*/
static size_t qppad(UC *input, size_t size, luaL_Buffer *buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Incrementally converts a string to quoted-printable
* A, B = qp(C, D, marker)
* Marker is the text to be used to replace CRLF sequences found in A.
* A is the encoded version of the largest prefix of C .. D that 
* can be encoded without doubts. 
* B has the remaining bytes of C .. D, *without* encoding.
\*-------------------------------------------------------------------------*/
static int mime_global_qp(lua_State *L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Accumulate characters until we are sure about how to deal with them.
* Once we are sure, output the to the buffer, in the correct form. 
\*-------------------------------------------------------------------------*/
static size_t qpdecode(UC c, UC *input, size_t size, luaL_Buffer *buffer) {
    int d;
    input[size++] = c;
    /* deal with all characters we can deal */
    switch (input[0]) {
        /* if we have an escape character */
        case '=': 
            if (size < 3) return size; 
            /* eliminate soft line break */
            if (input[1] == '\r' && input[2] == '\n') return 0;
            /* decode quoted representation */
            c = qpunbase[input[1]]; d = qpunbase[input[2]];
            /* if it is an invalid, do not decode */
            if (c > 15 || d > 15) luaL_addlstring(buffer, (char *)input, 3);
            else luaL_putchar(buffer, (c << 4) + d);
            return 0;
        case '\r':
            if (size < 2) return size; 
            if (input[1] == '\n') luaL_addlstring(buffer, (char *)input, 2);
            return 0;
        default:
            if (input[0] == '\t' || (input[0] > 31 && input[0] < 127))
                luaL_putchar(buffer, input[0]);
            return 0;
    }
}

/*-------------------------------------------------------------------------*\
* Incrementally decodes a string in quoted-printable
* A, B = qp(C, D)
* A is the decoded version of the largest prefix of C .. D that 
* can be decoded without doubts. 
* B has the remaining bytes of C .. D, *without* decoding.
\*-------------------------------------------------------------------------*/
static int mime_global_unqp(lua_State *L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Incrementally breaks a quoted-printed string into lines
* A, n = qpwrp(l, B, length)
* A is a copy of B, broken into lines of at most 'length' bytes. 
* 'l' is how many bytes are left for the first line of B. 
* 'n' is the number of bytes left in the last line of A. 
* There are two complications: lines can't be broken in the middle
* of an encoded =XX, and there might be line breaks already
\*-------------------------------------------------------------------------*/
static int mime_global_qpwrp(lua_State *L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Here is what we do: \n, and \r are considered candidates for line
* break. We issue *one* new line marker if any of them is seen alone, or
* followed by a different one. That is, \n\n and \r\r will issue two
* end of line markers each, but \r\n, \n\r etc will only issue *one*
* marker.  This covers Mac OS, Mac OS X, VMS, Unix and DOS, as well as
* probably other more obscure conventions.
*
* c is the current character being processed
* last is the previous character
\*-------------------------------------------------------------------------*/
#define eolcandidate(c) (c == '\r' || c == '\n')
static int eolprocess(int c, int last, const char *marker, 
        luaL_Buffer *buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Converts a string to uniform EOL convention. 
* A, n = eol(o, B, marker)
* A is the converted version of the largest prefix of B that can be
* converted unambiguously. 'o' is the context returned by the previous 
* call. 'n' is the new context.
\*-------------------------------------------------------------------------*/
static int mime_global_eol(lua_State *L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Takes one byte and stuff it if needed. 
\*-------------------------------------------------------------------------*/
static size_t dot(int c, size_t state, luaL_Buffer *buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Incrementally applies smtp stuffing to a string
* A, n = dot(l, D)
\*-------------------------------------------------------------------------*/
static int mime_global_dot(lua_State *L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

