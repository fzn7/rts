#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
 * @brief ARB_vertex_buffer_object implementation
 * ARB_vertex_buffer_object class implementation
 */

#include <assert.h>
#include <vector>

#include "VBO.h"

#include "Rendering/GlobalRendering.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"

CONFIG(bool, UseVBO).defaultValue(true).safemodeValue(false);
CONFIG(bool, UsePBO).defaultValue(true).safemodeValue(false).headlessValue(false);


/**
 * Returns if the current gpu drivers support VertexBufferObjects
 */
bool VBO::IsVBOSupported()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/**
 * Returns if the current gpu drivers support PixelBufferObjects
 */
bool VBO::IsPBOSupported()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool VBO::IsSupported() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


VBO::VBO(GLenum _defTarget, const bool storage) : vboId(0), VBOused(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


VBO::~VBO()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


VBO& VBO::operator=(VBO&& other)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void VBO::Bind(GLenum target) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void VBO::Unbind() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void VBO::Resize(GLsizeiptr _size, GLenum usage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void VBO::New(GLsizeiptr _size, GLenum usage, const void* data_)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


GLubyte* VBO::MapBuffer(GLbitfield access)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


GLubyte* VBO::MapBuffer(GLintptr offset, GLsizeiptr _size, GLbitfield access)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void VBO::UnmapBuffer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void VBO::Invalidate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const GLvoid* VBO::GetPtr(GLintptr offset) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
