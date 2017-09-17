/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "TerrainBase.h"
#include "TerrainVertexBuffer.h"

using namespace terrain;

int VertexBuffer::totalBufferSize = 0;

VertexBuffer::VertexBuffer()
	: data(NULL)
	, id(0)
	, size(0)
	, type(GL_ARRAY_BUFFER_ARB)
{
    //stub method
}

void VertexBuffer::Init(int bytesize)
{
    //stub method
}

VertexBuffer::~VertexBuffer()
{
    //stub method
}

void VertexBuffer::Free()
{
    //stub method
}

void* VertexBuffer::LockData()
{
    //stub method
}

void VertexBuffer::UnlockData()
{
    //stub method
}

void* VertexBuffer::Bind()
{
    //stub method
}


void VertexBuffer::Unbind()
{
    //stub method
}


IndexBuffer::IndexBuffer()
{
    //stub method
}
