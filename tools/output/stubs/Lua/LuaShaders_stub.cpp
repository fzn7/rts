#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaShaders.h"

#include "LuaInclude.h"

#include "LuaHandle.h"
#include "LuaHashString.h"
#include "LuaOpenGL.h"
#include "LuaOpenGLUtils.h"
#include "LuaUtils.h"

#include "Game/Camera.h"
#include "Rendering/ShadowHandler.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#include <string>
#include <vector>
using std::string;
using std::vector;

int LuaShaders::activeShaderDepth = 0;

/******************************************************************************/
/******************************************************************************/

bool
LuaShaders::PushEntries(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

LuaShaders::LuaShaders()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaShaders::~LuaShaders()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

inline void
CheckDrawingEnabled(lua_State* L, const char* caller)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

GLuint
LuaShaders::GetProgramName(unsigned int progIdx) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

GLuint
LuaShaders::GetProgramName(lua_State* L, int index) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
LuaShaders::AddProgram(const Program& p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaShaders::RemoveProgram(unsigned int progIdx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaShaders::DeleteProgram(Program& p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
LuaShaders::GetShaderLog(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

enum
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
ParseUniformsTable(lua_State* L,
                   const char* fieldName,
                   int index,
                   int type,
                   GLuint progName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
ParseUniformSetupTables(lua_State* L, int index, GLuint progName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static GLuint
CompileObject(lua_State* L,
              const vector<string>& defs,
              const vector<string>& sources,
              const GLenum type,
              bool& success)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
ParseShaderTable(lua_State* L,
                 const int table,
                 const char* key,
                 std::vector<std::string>& data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
ApplyGeometryParameters(lua_State* L, int table, GLuint prog)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaShaders::CreateShader(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaShaders::DeleteShader(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaShaders::UseShader(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaShaders::ActiveShader(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static const char*
UniformTypeString(GLenum type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaShaders::GetActiveUniforms(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaShaders::GetUniformLocation(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
LuaShaders::Uniform(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaShaders::UniformInt(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaShaders::UniformArray(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaShaders::UniformMatrix(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaShaders::SetShaderParameter(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
