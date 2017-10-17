#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GeometryBuffer.h"
#include "Rendering/GlobalRendering.h"
#include <cstring> //memset

void
GL::GeometryBuffer::Init(bool ctor)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
GL::GeometryBuffer::Kill(bool dtor)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
GL::GeometryBuffer::Clear() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
GL::GeometryBuffer::DetachTextures(const bool init)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
GL::GeometryBuffer::DrawDebug(const unsigned int texID,
                              const float2 texMins,
                              const float2 texMaxs) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
GL::GeometryBuffer::Create(const int2 size)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
GL::GeometryBuffer::Update(const bool init)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int2
GL::GeometryBuffer::GetWantedSize(bool allowed) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
