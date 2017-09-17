/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GLSLCopyState.h"
#include "Shader.h"
#include "Rendering/GL/myGL.h"
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

enum {
	FLOAT1 = 1,
	FLOAT2,
	FLOAT3,
	FLOAT4,
	INT1,
	INT2,
	INT3,
	INT4,
	UNSIGNED1,
	UNSIGNED2,
	UNSIGNED3,
	UNSIGNED4,
	FLOAT_MAT2,
	FLOAT_MAT3,
	FLOAT_MAT4,
	ATOMIC
};
std::map<GLenum, int> bindingType;

static void CreateBindingTypeMap()
{
    //stub method
}

DO_ONCE(CreateBindingTypeMap)


static void CopyShaderState_Uniforms(GLuint newProgID, GLuint oldProgID, std::unordered_map<std::size_t, Shader::UniformState, fast_hash>* uniformStates)
{
    //stub method
}


static void CopyShaderState_UniformBlocks(GLuint newProgID, GLuint oldProgID)
{
    //stub method
}


static void CopyShaderState_ShaderStorage(GLuint newProgID, GLuint oldProgID)
{
    //stub method
}


static void CopyShaderState_Attributes(GLuint newProgID, GLuint oldProgID)
{
    //stub method
}


static void CopyShaderState_TransformFeedback(GLuint newProgID, GLuint oldProgID)
{
    //stub method
}



static bool CopyShaderState_ContainsGeometryShader(GLuint oldProgID)
{
    //stub method
}

static void CopyShaderState_Geometry(GLuint newProgID, GLuint oldProgID)
{
    //stub method
}
#endif

namespace Shader {
	void GLSLCopyState(GLuint newProgID, GLuint oldProgID, std::unordered_map<std::size_t, UniformState, fast_hash>* uniformStates)
	{
	#if !defined(HEADLESS)
		CopyShaderState_Uniforms(newProgID, oldProgID, uniformStates);

		if (oldProgID != 0) {
			CopyShaderState_UniformBlocks(newProgID, oldProgID);
			CopyShaderState_ShaderStorage(newProgID, oldProgID);
			CopyShaderState_Attributes(newProgID, oldProgID);
			CopyShaderState_TransformFeedback(newProgID, oldProgID);
			CopyShaderState_Geometry(newProgID, oldProgID);
		}
	#endif
	}
}
