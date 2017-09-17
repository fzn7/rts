/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cstring>

#include "VertexArray.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVertexArray::CVertexArray(unsigned int maxVerts): maxVertices(maxVerts)
{
    //stub method
}

CVertexArray::~CVertexArray()
{
    //stub method
}


//////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////

void CVertexArray::Initialize()
{
    //stub method
}

bool CVertexArray::IsReady() const
{
    //stub method
}

void CVertexArray::EndStrip()
{
    //stub method
}


//////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////


static inline bool IsPrimitiveSplitable(GLenum mode)
{
    //stub method
}


static inline int GetPrimitiveRestartEach(GLenum mode)
{
    //stub method
}


static inline int GetStripStartOffset(GLenum mode)
{
    //stub method
}


void CVertexArray::DrawArrays(const GLenum mode, const unsigned int stride)
{
    //stub method
}


void CVertexArray::DrawArraysCallback(const GLenum mode, const unsigned int stride, StripCallback callback, void* data)
{
    //stub method
}




//////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////

void CVertexArray::DrawArray0(const int drawType, unsigned int stride)
{
    //stub method
}

void CVertexArray::DrawArray2d0(const int drawType, unsigned int stride)
{
    //stub method
}

void CVertexArray::DrawArrayN(const int drawType, unsigned int stride)
{
    //stub method
}


void CVertexArray::DrawArrayC(const int drawType, unsigned int stride)
{
    //stub method
}


void CVertexArray::DrawArrayT(const int drawType, unsigned int stride)
{
    //stub method
}


void CVertexArray::DrawArray2dT(const int drawType, unsigned int stride)
{
    //stub method
}


void CVertexArray::DrawArray2dTC(const int drawType, unsigned int stride)
{
    //stub method
}


void CVertexArray::DrawArray2dT(const int drawType, StripCallback callback, void* data, unsigned int stride)
{
    //stub method
}


void CVertexArray::DrawArrayTN(const int drawType, unsigned int stride)
{
    //stub method
}

void CVertexArray::DrawArrayTNT(const int drawType, unsigned int stride)
{
    //stub method
}


void CVertexArray::DrawArrayTC(const int drawType, unsigned int stride)
{
    //stub method
}




//////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////

void CVertexArray::EnlargeDrawArray()
{
    //stub method
}

void CVertexArray::EnlargeStripArray()
{
    //stub method
}
