/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "LuaFBOs.h"

#include "LuaInclude.h"

#include "LuaHandle.h"
#include "LuaHashString.h"
#include "LuaUtils.h"

#include "LuaOpenGL.h"
#include "LuaRBOs.h"
#include "LuaTextures.h"

#include "System/Log/ILog.h"

#include <map>


/******************************************************************************/
/******************************************************************************/

LuaFBOs::LuaFBOs()
{
    //stub method
}


LuaFBOs::~LuaFBOs()
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

bool LuaFBOs::PushEntries(lua_State* L)
{
    //stub method
}


bool LuaFBOs::CreateMetatable(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

inline void CheckDrawingEnabled(lua_State* L, const char* caller)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

const LuaFBOs::FBO* LuaFBOs::GetLuaFBO(lua_State* L, int index)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

void LuaFBOs::FBO::Init(lua_State* L)
{
    //stub method
}


void LuaFBOs::FBO::Free(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaFBOs::meta_gc(lua_State* L)
{
    //stub method
}


int LuaFBOs::meta_index(lua_State* L)
{
    //stub method
}


int LuaFBOs::meta_newindex(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

static GLenum GetBindingEnum(GLenum target)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

GLenum LuaFBOs::ParseAttachment(const std::string& name)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

bool LuaFBOs::AttachObject(lua_State* L, int index,
		                       FBO* fbo, GLenum attachID,
		                       GLenum attachTarget, GLenum attachLevel)
{
    //stub method
}


bool LuaFBOs::ApplyAttachment(lua_State* L, int index,
                              FBO* fbo, const GLenum attachID)
{
    //stub method
}


bool LuaFBOs::ApplyDrawBuffers(lua_State* L, int index)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaFBOs::CreateFBO(lua_State* L)
{
    //stub method
}


int LuaFBOs::DeleteFBO(lua_State* L)
{
    //stub method
}


int LuaFBOs::IsValidFBO(lua_State* L)
{
    //stub method
}


int LuaFBOs::ActiveFBO(lua_State* L)
{
    //stub method
}


int LuaFBOs::UnsafeSetFBO(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaFBOs::BlitFBO(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/
