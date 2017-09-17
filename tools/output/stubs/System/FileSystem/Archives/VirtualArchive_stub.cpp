#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "VirtualArchive.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"

#include "minizip/zip.h"
#include <cassert>

CVirtualArchiveFactory* virtualArchiveFactory;

CVirtualArchiveFactory::CVirtualArchiveFactory()
  : IArchiveFactory("sva")
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CVirtualArchiveFactory::~CVirtualArchiveFactory()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CVirtualArchive*
CVirtualArchiveFactory::AddArchive(const std::string& fileName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

IArchive*
CVirtualArchiveFactory::DoCreateArchive(const std::string& fileName) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CVirtualArchiveOpen::CVirtualArchiveOpen(CVirtualArchive* archive,
                                         const std::string& fileName)
  : IArchive(fileName)
  , archive(archive)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CVirtualArchiveOpen::~CVirtualArchiveOpen() {}

bool
CVirtualArchiveOpen::IsOpen()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
CVirtualArchiveOpen::NumFiles() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CVirtualArchiveOpen::GetFile(unsigned int fid,
                             std::vector<boost::uint8_t>& buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CVirtualArchiveOpen::FileInfo(unsigned int fid,
                              std::string& name,
                              int& size) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CVirtualArchive::CVirtualArchive(const std::string& fileName)
  : fileName(fileName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CVirtualArchiveOpen*
CVirtualArchive::Open()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
CVirtualArchive::NumFiles() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CVirtualArchive::GetFile(unsigned int fid, std::vector<boost::uint8_t>& buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CVirtualArchive::FileInfo(unsigned int fid, std::string& name, int& size) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CVirtualFile*
CVirtualArchive::AddFile(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CVirtualArchive::WriteToFile()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CVirtualFile::CVirtualFile(int fid, const std::string& name)
  : name(name)
  , fid(fid)
{}

CVirtualFile::~CVirtualFile() {}
