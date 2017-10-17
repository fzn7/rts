#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "TerrainVertexBuffer.h"
#include "TerrainBase.h"

using namespace terrain;

int VertexBuffer::totalBufferSize = 0;

VertexBuffer::VertexBuffer()
  : data(NULL)
  , id(0)
  , size(0)
  , type(GL_ARRAY_BUFFER_ARB)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

VertexBuffer::~VertexBuffer()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
VertexBuffer::Free()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void*
VertexBuffer::LockData()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
VertexBuffer::UnlockData()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void*
VertexBuffer::Bind()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
VertexBuffer::Unbind()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

IndexBuffer::IndexBuffer()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
