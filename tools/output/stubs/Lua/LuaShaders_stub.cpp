#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "LuaShaders.h"

#include "LuaInclude.h"

#include "LuaHashString.h"
#include "LuaHandle.h"
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

bool LuaShaders::PushEntries(lua_State* L)
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

inline void CheckDrawingEnabled(lua_State* L, const char* caller)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

GLuint LuaShaders::GetProgramName(unsigned int progIdx) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

GLuint LuaShaders::GetProgramName(lua_State* L, int index) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


unsigned int LuaShaders::AddProgram(const Program& p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool LuaShaders::RemoveProgram(unsigned int progIdx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool LuaShaders::DeleteProgram(Program& p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaShaders::GetShaderLog(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

enum {
	UNIFORM_TYPE_INT          = 0, // includes arrays
	UNIFORM_TYPE_FLOAT        = 1, // includes arrays
	UNIFORM_TYPE_FLOAT_MATRIX = 2,
};

static void ParseUniformType(lua_State* L, int loc, int type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool ParseUniformsTable(lua_State* L, const char* fieldName, int index, int type, GLuint progName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static bool ParseUniformSetupTables(lua_State* L, int index, GLuint progName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

static GLuint CompileObject(
	lua_State* L,
	const vector<string>& defs,
	const vector<string>& sources,
	const GLenum type,
	bool& success
) {
	if (sources.empty()) {
		success = true;
		return 0;
	}

	GLuint obj = glCreateShader(type);
	if (obj == 0) {
		LuaShaders& shaders = CLuaHandle::GetActiveShaders(L);
		shaders.errorLog = "Could not create shader object";
		return 0;
	}

	std::vector<const GLchar*> text(defs.size() + sources.size());

	for (unsigned int i = 0; i < defs.size(); i++)
		text[i] = defs[i].c_str();
	for (unsigned int i = 0; i < sources.size(); i++)
		text[defs.size() + i] = sources[i].c_str();

	glShaderSource(obj, text.size(), &text[0], NULL);
	glCompileShader(obj);

	GLint result;
	glGetShaderiv(obj, GL_COMPILE_STATUS, &result);
	GLchar log[4096];
	GLsizei logSize = sizeof(log);
	glGetShaderInfoLog(obj, logSize, &logSize, log);

	LuaShaders& shaders = CLuaHandle::GetActiveShaders(L);
	shaders.errorLog = log;
	if (result != GL_TRUE) {
		if (shaders.errorLog.empty()) {
			shaders.errorLog = "Empty error message:  code = "
							+ IntToString(result) + " (0x"
							+ IntToString(result, "%04X") + ")";
		}

		glDeleteShader(obj);

		success = false;
		return 0;
	}

	success = true;
	return obj;
}


static bool ParseShaderTable(
	lua_State* L,
	const int table,
	const char* key,
	std::vector<std::string>& data
) {
	lua_getfield(L, table, key);

	if (lua_isnil(L, -1)) {
		lua_pop(L, 1);
		return true;
	}

	if (lua_israwstring(L, -1)) {
		const std::string& txt = lua_tostring(L, -1);

		if (!txt.empty()) {
			data.push_back(txt);
		}

		lua_pop(L, 1);
		return true;
	}

	if (lua_istable(L, -1)) {
		const int subtable = lua_gettop(L);

		for (lua_pushnil(L); lua_next(L, subtable) != 0; lua_pop(L, 1)) {
			if (!lua_israwnumber(L, -2)) // key (idx)
				continue;
			if (!lua_israwstring(L, -1)) // val
				continue;

			const std::string& txt = lua_tostring(L, -1);

			if (!txt.empty()) {
				data.push_back(txt);
			}
		}

		lua_pop(L, 1);
		return true;
	}

	LuaShaders& shaders = CLuaHandle::GetActiveShaders(L);
	shaders.errorLog = "\"" + string(key) + "\" must be a string or a table value!";

	lua_pop(L, 1);
	return false;
}


static void ApplyGeometryParameters(lua_State* L, int table, GLuint prog)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaShaders::CreateShader(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaShaders::DeleteShader(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaShaders::UseShader(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaShaders::ActiveShader(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

static const char* UniformTypeString(GLenum type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaShaders::GetActiveUniforms(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaShaders::GetUniformLocation(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaShaders::Uniform(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaShaders::UniformInt(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaShaders::UniformArray(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaShaders::UniformMatrix(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaShaders::SetShaderParameter(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/
