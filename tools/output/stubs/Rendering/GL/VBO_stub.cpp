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
}


/**
 * Returns if the current gpu drivers support PixelBufferObjects
 */
bool VBO::IsPBOSupported()
{
    //stub method
}


bool VBO::IsSupported() const
{
    //stub method
}


VBO::VBO(GLenum _defTarget, const bool storage) : vboId(0), VBOused(true)
{
    //stub method
}


VBO::~VBO()
{
    //stub method
}


VBO& VBO::operator=(VBO&& other)
{
    //stub method
}


void VBO::Bind(GLenum target) const
{
    //stub method
}


void VBO::Unbind() const
{
    //stub method
}


void VBO::Resize(GLsizeiptr _size, GLenum usage)
{
    //stub method
}


void VBO::New(GLsizeiptr _size, GLenum usage, const void* data_)
{
    //stub method
}


GLubyte* VBO::MapBuffer(GLbitfield access)
{
    //stub method
}


GLubyte* VBO::MapBuffer(GLintptr offset, GLsizeiptr _size, GLbitfield access)
{
    //stub method
}


void VBO::UnmapBuffer()
{
    //stub method
}


void VBO::Invalidate()
{
    //stub method
}


const GLvoid* VBO::GetPtr(GLintptr offset) const
{
    //stub method
}
