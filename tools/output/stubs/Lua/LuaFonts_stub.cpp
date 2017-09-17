/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "LuaFonts.h"

#include "LuaInclude.h"

#include "LuaHandle.h"
#include "LuaHashString.h"
#include "LuaUtils.h"

#include "LuaOpenGL.h"

#include "Rendering/GL/myGL.h"
#include "Rendering/Fonts/glFont.h"
#include "System/Exceptions.h"


/******************************************************************************/
/******************************************************************************/

LuaFonts::LuaFonts()
{
    //stub method
}


LuaFonts::~LuaFonts()
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

#define REGISTER_LUA_CFUNC(x)    \
	lua_pushstring(L, #x);   \
	lua_pushcfunction(L, x); \
	lua_rawset(L, -3)

bool LuaFonts::PushEntries(lua_State* L)
{
    //stub method
}


bool LuaFonts::CreateMetatable(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

inline void CheckDrawingEnabled(lua_State* L, const char* caller)
{
    //stub method
}


inline CglFont* tofont(lua_State* L, int idx)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaFonts::meta_gc(lua_State* L)
{
    //stub method
}


int LuaFonts::meta_index(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaFonts::LoadFont(lua_State* L)
{
    //stub method
}


int LuaFonts::DeleteFont(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaFonts::Print(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaFonts::Begin(lua_State* L)
{
    //stub method
}


int LuaFonts::End(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaFonts::WrapText(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

int LuaFonts::GetTextWidth(lua_State* L)
{
    //stub method
}


int LuaFonts::GetTextHeight(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaFonts::SetTextColor(lua_State* L)
{
    //stub method
}


int LuaFonts::SetOutlineColor(lua_State* L)
{
    //stub method
}


int LuaFonts::SetAutoOutlineColor(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaFonts::BindTexture(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/
