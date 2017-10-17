#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ZipArchive.h"

#include <algorithm>
#include <assert.h>
#include <stdexcept>

#include "System/Log/ILog.h"
#include "System/Util.h"

CZipArchiveFactory::CZipArchiveFactory()
  : IArchiveFactory("sdz")
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CZipArchive::CZipArchive(const std::string& archiveName)
  : CBufferedArchive(archiveName)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CZipArchive::~CZipArchive()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CZipArchive::IsOpen()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
CZipArchive::NumFiles() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CZipArchive::FileInfo(unsigned int fid, std::string& name, int& size) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
CZipArchive::GetCrc32(unsigned int fid)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// To simplify things, files are always read completely into memory from
// the zip-file, since zlib does not provide any way of reading more
// than one file at a time
bool
CZipArchive::GetFileImpl(unsigned int fid, std::vector<boost::uint8_t>& buffer)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
