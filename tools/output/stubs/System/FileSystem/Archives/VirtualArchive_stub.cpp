/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "VirtualArchive.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/Log/ILog.h"

#include "minizip/zip.h"
#include <cassert>

CVirtualArchiveFactory* virtualArchiveFactory;

CVirtualArchiveFactory::CVirtualArchiveFactory() : IArchiveFactory("sva")
{
    //stub method
}

CVirtualArchiveFactory::~CVirtualArchiveFactory()
{
    //stub method
}

CVirtualArchive* CVirtualArchiveFactory::AddArchive(const std::string& fileName)
{
    //stub method
}

IArchive* CVirtualArchiveFactory::DoCreateArchive(const std::string& fileName) const
{
    //stub method
}

CVirtualArchiveOpen::CVirtualArchiveOpen(CVirtualArchive* archive, const std::string& fileName) : IArchive(fileName), archive(archive)
{
    //stub method
}

CVirtualArchiveOpen::~CVirtualArchiveOpen()
{
    //stub method
}

bool CVirtualArchiveOpen::IsOpen()
{
    //stub method
}

unsigned int CVirtualArchiveOpen::NumFiles() const
{
    //stub method
}

bool CVirtualArchiveOpen::GetFile( unsigned int fid, std::vector<boost::uint8_t>& buffer )
{
    //stub method
}

void CVirtualArchiveOpen::FileInfo( unsigned int fid, std::string& name, int& size ) const
{
    //stub method
}

CVirtualArchive::CVirtualArchive(const std::string& fileName) : fileName(fileName)
{
    //stub method
}

CVirtualArchive::~CVirtualArchive()
{
    //stub method
}

CVirtualArchiveOpen* CVirtualArchive::Open()
{
    //stub method
}

unsigned int CVirtualArchive::NumFiles() const
{
    //stub method
}

bool CVirtualArchive::GetFile( unsigned int fid, std::vector<boost::uint8_t>& buffer )
{
    //stub method
}

void CVirtualArchive::FileInfo( unsigned int fid, std::string& name, int& size ) const
{
    //stub method
}

CVirtualFile* CVirtualArchive::AddFile(const std::string& name)
{
    //stub method
}

void CVirtualArchive::WriteToFile()
{
    //stub method
}

CVirtualFile::CVirtualFile(int fid, const std::string& name) : name(name), fid(fid)
{
    //stub method
}

CVirtualFile::~CVirtualFile()
{
    //stub method
}
