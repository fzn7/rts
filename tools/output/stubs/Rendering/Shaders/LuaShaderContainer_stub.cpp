#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaShaderContainer.h"
#include "Lua/LuaParser.h"
#include "Lua/LuaUtils.h"
#include "Lua/LuaUnsyncedCtrl.h"
#include "Lua/LuaUnsyncedRead.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "System/Util.h"
#include "System/Log/ILog.h"
#include <sstream>


enum {
	UNIFORM_TYPE_INT          = 0, // includes arrays
	UNIFORM_TYPE_FLOAT        = 1, // includes arrays
	UNIFORM_TYPE_FLOAT_MATRIX = 2,
};


static void ParseUniformsTable(Shader::IProgramObject* program, const LuaTable* root, const std::string& fieldName, int type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static void ParseUniformSetupTables(Shader::IProgramObject* program, const LuaTable* root)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static void CreateShaderObject(
	Shader::IProgramObject* program,
	const std::string& definitions,
	const std::string& sources,
	const GLenum type
) {
	if (sources.empty())
		return;

	program->AttachShaderObject(shaderHandler->CreateShaderObject(sources, definitions, type));
}


static void ParseShaderTable(
	const LuaTable* root,
	const std::string key,
	std::stringstream& data
) {
	const auto keyType = root->GetType(key);

	switch (keyType) {
		case LuaTable::STRING: {
			data << root->GetString(key, "");
		} break;
		case LuaTable::TABLE: {
			const LuaTable shaderCode = root->SubTable(key);
			for (int i = 1; shaderCode.KeyExists(i); ++i) {
				data << shaderCode.GetString(i, "");
			}
		} break;
		default:
			if (root->KeyExists(key)) {
				//FIXME shaders.errorLog = "\"" + string(key) + "\" must be a string or a table value!";
			}
	};
}


static void LoadTextures(Shader::IProgramObject* program, const LuaTable* root)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


namespace Shader {
bool LoadFromLua(Shader::IProgramObject* program, const std::string& filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
};
