#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaShaderContainer.h"
#include "Lua/LuaParser.h"
#include "Lua/LuaUnsyncedCtrl.h"
#include "Lua/LuaUnsyncedRead.h"
#include "Lua/LuaUtils.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include <sstream>

enum
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
ParseUniformSetupTables(Shader::IProgramObject* program, const LuaTable* root)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
CreateShaderObject(Shader::IProgramObject* program,
                   const std::string& definitions,
                   const std::string& sources,
                   const GLenum type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
ParseShaderTable(const LuaTable* root,
                 const std::string key,
                 std::stringstream& data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
LoadTextures(Shader::IProgramObject* program, const LuaTable* root)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

namespace Shader {
bool
LoadFromLua(Shader::IProgramObject* program, const std::string& filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
};
