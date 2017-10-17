#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

//#include <boost/functional/hash.hpp>
#include "Rendering/Shaders/ShaderStates.h"
#include "System/Sync/HsiehHash.h"
#include <unordered_set>

static std::unordered_set<int> samplerTypes{
#ifndef HEADLESS
    GL_SAMPLER_1D,
    GL_SAMPLER_2D,
    GL_SAMPLER_3D,
    GL_SAMPLER_CUBE,
    GL_SAMPLER_1D_SHADOW,
    GL_SAMPLER_2D_SHADOW,
    GL_SAMPLER_1D_ARRAY,
    GL_SAMPLER_2D_ARRAY,
    GL_SAMPLER_1D_ARRAY_SHADOW,
    GL_SAMPLER_2D_ARRAY_SHADOW,
    GL_SAMPLER_2D_MULTISAMPLE,
    GL_SAMPLER_2D_MULTISAMPLE_ARRAY,
    GL_SAMPLER_CUBE_SHADOW,
    GL_SAMPLER_BUFFER,
    GL_SAMPLER_2D_RECT,
    GL_SAMPLER_2D_RECT_SHADOW,

    GL_INT_SAMPLER_1D,
    GL_INT_SAMPLER_2D,
    GL_INT_SAMPLER_3D,
    GL_INT_SAMPLER_CUBE,
    GL_INT_SAMPLER_1D_ARRAY,
    GL_INT_SAMPLER_2D_ARRAY,
    GL_INT_SAMPLER_2D_MULTISAMPLE,
    GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
    GL_INT_SAMPLER_BUFFER,
    GL_INT_SAMPLER_2D_RECT,

    GL_UNSIGNED_INT_SAMPLER_1D,
    GL_UNSIGNED_INT_SAMPLER_2D,
    GL_UNSIGNED_INT_SAMPLER_3D,
    GL_UNSIGNED_INT_SAMPLER_CUBE,
    GL_UNSIGNED_INT_SAMPLER_1D_ARRAY,
    GL_UNSIGNED_INT_SAMPLER_2D_ARRAY,
    GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE,
    GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
    GL_UNSIGNED_INT_SAMPLER_BUFFER,
    GL_UNSIGNED_INT_SAMPLER_2D_RECT,
#endif
};

namespace Shader {
int
UniformState::Hash(const int v0, const int v1, const int v2, const int v3) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
UniformState::Hash(const int* v, int count) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
UniformState::IsLocationValid() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifdef DEBUG
void
UniformState::AssertType(int type) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

unsigned int
SShaderFlagState::GetHash()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
