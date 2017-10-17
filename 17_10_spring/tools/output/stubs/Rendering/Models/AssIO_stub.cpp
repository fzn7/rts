#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AssIO.h"
#include <string>

#include "System/FileSystem/FileHandler.h"

AssVFSStream::AssVFSStream(const std::string& pFile, const std::string& pMode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

AssVFSStream::~AssVFSStream(void)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

size_t
AssVFSStream::Read(void* pvBuffer, size_t pSize, size_t pCount)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

size_t
AssVFSStream::Write(const void* pvBuffer, size_t pSize, size_t pCount)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

aiReturn
AssVFSStream::Seek(size_t pOffset, aiOrigin pOrigin)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

size_t
AssVFSStream::Tell() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

size_t
AssVFSStream::FileSize() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
AssVFSStream::Flush() // FAKE
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Get the path delimiter character we'd like to get
char
AssVFSSystem::getOsSeparator() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
AssVFSSystem::ComparePaths(const std::string& one,
                           const std::string& second) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// open a custom stream
Assimp::IOStream*
AssVFSSystem::Open(const char* pFile, const char* pMode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
AssVFSSystem::Close(Assimp::IOStream* pFile)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
