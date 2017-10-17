#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cstring>

#include "VertexArray.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVertexArray::CVertexArray(unsigned int maxVerts)
  : maxVertices(maxVerts)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CVertexArray::~CVertexArray()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

void
CVertexArray::Initialize()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CVertexArray::IsReady() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CVertexArray::EndStrip()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

static inline bool
IsPrimitiveSplitable(GLenum mode)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline int
GetPrimitiveRestartEach(GLenum mode)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline int
GetStripStartOffset(GLenum mode)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CVertexArray::DrawArrays(const GLenum mode, const unsigned int stride)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CVertexArray::DrawArraysCallback(const GLenum mode,
                                 const unsigned int stride,
                                 StripCallback callback,
                                 void* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

void
CVertexArray::DrawArray0(const int drawType, unsigned int stride)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CVertexArray::DrawArray2d0(const int drawType, unsigned int stride)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CVertexArray::DrawArrayN(const int drawType, unsigned int stride)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CVertexArray::DrawArrayC(const int drawType, unsigned int stride)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CVertexArray::DrawArrayT(const int drawType, unsigned int stride)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CVertexArray::DrawArray2dT(const int drawType, unsigned int stride)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CVertexArray::DrawArray2dTC(const int drawType, unsigned int stride)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CVertexArray::DrawArray2dT(const int drawType,
                           StripCallback callback,
                           void* data,
                           unsigned int stride)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CVertexArray::DrawArrayTN(const int drawType, unsigned int stride)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CVertexArray::DrawArrayTNT(const int drawType, unsigned int stride)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CVertexArray::DrawArrayTC(const int drawType, unsigned int stride)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

void
CVertexArray::EnlargeDrawArray()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CVertexArray::EnlargeStripArray()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
