/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include <string>
#include "AssIO.h"

#include "System/FileSystem/FileHandler.h"

AssVFSStream::AssVFSStream(const std::string& pFile, const std::string& pMode)
{
    //stub method
}

AssVFSStream::~AssVFSStream(void)
{
    //stub method
}

size_t AssVFSStream::Read( void* pvBuffer, size_t pSize, size_t pCount)
{
    //stub method
}

size_t AssVFSStream::Write( const void* pvBuffer, size_t pSize, size_t pCount)
{
    //stub method
}

aiReturn AssVFSStream::Seek( size_t pOffset, aiOrigin pOrigin)
{
    //stub method
}

size_t AssVFSStream::Tell() const
{
    //stub method
}


size_t AssVFSStream::FileSize() const
{
    //stub method
}

void AssVFSStream::Flush () // FAKE
{
    //stub method
}


// Check whether a specific file exists
bool AssVFSSystem::Exists( const char* pFile) const
{
    //stub method
}

// Get the path delimiter character we'd like to get
char AssVFSSystem::getOsSeparator() const
{
    //stub method
}

bool AssVFSSystem::ComparePaths (const std::string& one, const std::string& second) const
{
    //stub method
}

// open a custom stream
Assimp::IOStream* AssVFSSystem::Open( const char* pFile, const char* pMode)
{
    //stub method
}

void AssVFSSystem::Close( Assimp::IOStream* pFile)
{
    //stub method
}
