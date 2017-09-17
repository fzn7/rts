#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Rendering/Shaders/Shader.h"
#include "Lua/LuaMaterial.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/GLSLCopyState.h"
#include "Rendering/Shaders/LuaShaderContainer.h"
#include "Rendering/Shaders/ShaderHandler.h"

#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"
#include "System/Sync/HsiehHash.h"
#include "System/Util.h"

#include "System/Config/ConfigHandler.h"

#include <algorithm>
#ifdef DEBUG
#include <string.h> // strncmp
#endif

/*****************************************************************/

#define LOG_SECTION_SHADER "Shader"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_SHADER)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_SHADER

/*****************************************************************/

CONFIG(bool, UseShaderCache)
  .defaultValue(true)
  .description("If already compiled shaders should be shared via a cache, "
               "reducing compiles of already compiled shaders.");

/*****************************************************************/

static bool
glslIsValid(GLuint obj)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static std::string
glslGetLog(GLuint obj)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static std::string
GetShaderSource(const std::string& fileName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
ExtractGlslVersion(std::string* src, std::string* version)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*****************************************************************/

namespace Shader {
static NullShaderObject nullShaderObject_(0, "");
static NullProgramObject nullProgramObject_("NullProgram");

NullShaderObject* nullShaderObject = &nullShaderObject_;
NullProgramObject* nullProgramObject = &nullProgramObject_;

/*****************************************************************/

unsigned int
IShaderObject::GetHash() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
IShaderObject::ReloadFromDisk()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*****************************************************************/

ARBShaderObject::ARBShaderObject(unsigned int shType,
                                 const std::string& shSrc,
                                 const std::string& shSrcDefs)
  : IShaderObject(shType, shSrc)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ARBShaderObject::Compile()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ARBShaderObject::Release()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*****************************************************************/

GLSLShaderObject::GLSLShaderObject(unsigned int shType,
                                   const std::string& shSrcFile,
                                   const std::string& shSrcDefs)
  : IShaderObject(shType, shSrcFile, shSrcDefs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

GLSLShaderObject::CompiledShaderObjectUniquePtr
GLSLShaderObject::CompileShaderObject()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*****************************************************************/

IProgramObject::IProgramObject(const std::string& poName)
  : name(poName)
  , objID(0)
  , curFlagsHash(0)
  , valid(false)
  , bound(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IProgramObject::Disable()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
IProgramObject::IsBound() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IProgramObject::Release()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
IProgramObject::LoadFromLua(const std::string& filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IProgramObject::RecompileIfNeeded(bool validate)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IProgramObject::PrintDebugInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

UniformState*
IProgramObject::GetNewUniformState(const std::string name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IProgramObject::AddTextureBinding(const int index,
                                  const std::string& luaTexName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IProgramObject::BindTextures() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*****************************************************************/

ARBProgramObject::ARBProgramObject(const std::string& poName)
  : IProgramObject(poName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ARBProgramObject::SetUniformTarget(int target)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
int
ARBProgramObject::GetUnitformTarget()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ARBProgramObject::Enable()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
ARBProgramObject::Disable()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ARBProgramObject::Link()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
ARBProgramObject::Release()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
ARBProgramObject::Reload(bool reloadFromDisk, bool validate)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
ARBProgramObject::GetUniformLoc(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ARBProgramObject::SetUniform1i(int idx, int v0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
ARBProgramObject::SetUniform2i(int idx, int v0, int v1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
ARBProgramObject::SetUniform3i(int idx, int v0, int v1, int v2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
ARBProgramObject::SetUniform4i(int idx, int v0, int v1, int v2, int v3)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
ARBProgramObject::SetUniform1f(int idx, float v0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
ARBProgramObject::SetUniform2f(int idx, float v0, float v1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
ARBProgramObject::SetUniform3f(int idx, float v0, float v1, float v2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
ARBProgramObject::SetUniform4f(int idx, float v0, float v1, float v2, float v3)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ARBProgramObject::SetUniform2iv(int idx, const int* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
ARBProgramObject::SetUniform3iv(int idx, const int* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
ARBProgramObject::SetUniform4iv(int idx, const int* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
ARBProgramObject::SetUniform2fv(int idx, const float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
ARBProgramObject::SetUniform3fv(int idx, const float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
ARBProgramObject::SetUniform4fv(int idx, const float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*****************************************************************/

GLSLProgramObject::GLSLProgramObject(const std::string& poName)
  : IProgramObject(poName)
  , curSrcHash(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

GLSLProgramObject::~GLSLProgramObject()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLSLProgramObject::Enable()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLSLProgramObject::Disable()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLSLProgramObject::Link()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
GLSLProgramObject::Validate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLSLProgramObject::Release()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLSLProgramObject::Reload(bool reloadFromDisk, bool validate)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
GLSLProgramObject::GetUniformType(const int loc)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
GLSLProgramObject::GetUniformLoc(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLSLProgramObject::SetUniformLocation(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLSLProgramObject::SetUniform(UniformState* uState, int v0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform(UniformState* uState, float v0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform(UniformState* uState, int v0, int v1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform(UniformState* uState, float v0, float v1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform(UniformState* uState, int v0, int v1, int v2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform(UniformState* uState,
                              float v0,
                              float v1,
                              float v2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform(UniformState* uState,
                              int v0,
                              int v1,
                              int v2,
                              int v3)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform(UniformState* uState,
                              float v0,
                              float v1,
                              float v2,
                              float v3)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLSLProgramObject::SetUniform2v(UniformState* uState, const int* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform2v(UniformState* uState, const float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform3v(UniformState* uState, const int* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform3v(UniformState* uState, const float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform4v(UniformState* uState, const int* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform4v(UniformState* uState, const float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLSLProgramObject::SetUniformMatrix2x2(UniformState* uState,
                                       bool transp,
                                       const float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniformMatrix3x3(UniformState* uState,
                                       bool transp,
                                       const float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniformMatrix4x4(UniformState* uState,
                                       bool transp,
                                       const float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLSLProgramObject::SetUniform1i(int idx, int v0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform2i(int idx, int v0, int v1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform3i(int idx, int v0, int v1, int v2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform4i(int idx, int v0, int v1, int v2, int v3)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform1f(int idx, float v0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform2f(int idx, float v0, float v1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform3f(int idx, float v0, float v1, float v2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform4f(int idx, float v0, float v1, float v2, float v3)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLSLProgramObject::SetUniform2iv(int idx, const int* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform3iv(int idx, const int* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform4iv(int idx, const int* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform2fv(int idx, const float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform3fv(int idx, const float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniform4fv(int idx, const float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLSLProgramObject::SetUniformMatrix2fv(int idx, bool transp, const float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniformMatrix3fv(int idx, bool transp, const float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
GLSLProgramObject::SetUniformMatrix4fv(int idx, bool transp, const float* v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
