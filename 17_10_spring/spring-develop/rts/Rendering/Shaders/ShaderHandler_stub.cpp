#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Rendering/GL/myGL.h"

#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#include <cassert>

// not extern'ed, so static
static CShaderHandler* gShaderHandler = nullptr;
static unsigned int gNumInstances = 0;

CShaderHandler*
CShaderHandler::GetInstance(unsigned int instanceValue)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShaderHandler::FreeInstance(CShaderHandler* sh)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CShaderHandler::~CShaderHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShaderHandler::ReloadAll()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CShaderHandler::ReleaseProgramObjects(const std::string& poClass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShaderHandler::ReleaseProgramObjectsMap(ProgramObjMap& poMap)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Shader::IProgramObject*
CShaderHandler::GetProgramObject(const std::string& poClass,
                                 const std::string& poName)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Shader::IProgramObject*
CShaderHandler::CreateProgramObject(const std::string& poClass,
                                    const std::string& poName,
                                    bool arbProgram)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Shader::IShaderObject*
CShaderHandler::CreateShaderObject(const std::string& soName,
                                   const std::string& soDefs,
                                   int soType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
