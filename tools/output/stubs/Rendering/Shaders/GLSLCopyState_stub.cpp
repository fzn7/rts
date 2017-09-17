#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GLSLCopyState.h"
#include "Rendering/GL/myGL.h"
#include "Shader.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include <map>

#define LOG_SECTION_SHADER "Shader"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_SHADER)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_SHADER

#if !defined(HEADLESS)

enum
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

DO_ONCE(CreateBindingTypeMap)

static void
CopyShaderState_Uniforms(
  GLuint newProgID,
  GLuint oldProgID,
  std::unordered_map<std::size_t, Shader::UniformState, fast_hash>*
    uniformStates)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
CopyShaderState_UniformBlocks(GLuint newProgID, GLuint oldProgID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
CopyShaderState_ShaderStorage(GLuint newProgID, GLuint oldProgID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
CopyShaderState_Attributes(GLuint newProgID, GLuint oldProgID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
CopyShaderState_TransformFeedback(GLuint newProgID, GLuint oldProgID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
CopyShaderState_ContainsGeometryShader(GLuint oldProgID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
CopyShaderState_Geometry(GLuint newProgID, GLuint oldProgID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

namespace Shader {
void
GLSLCopyState(
  GLuint newProgID,
  GLuint oldProgID,
  std::unordered_map<std::size_t, UniformState, fast_hash>* uniformStates)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
