/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "ZipArchive.h"

#include <algorithm>
#include <stdexcept>
#include <assert.h>

#include "System/Util.h"
#include "System/Log/ILog.h"


CZipArchiveFactory::CZipArchiveFactory()
	: IArchiveFactory("sdz")
{
    //stub method
}

IArchive* CZipArchiveFactory::DoCreateArchive(const std::string& filePath) const
{
    //stub method
}


CZipArchive::CZipArchive(const std::string& archiveName)
	: CBufferedArchive(archiveName)
{
    //stub method
}

CZipArchive::~CZipArchive()
{
    //stub method
}

bool CZipArchive::IsOpen()
{
    //stub method
}

unsigned int CZipArchive::NumFiles() const
{
    //stub method
}

void CZipArchive::FileInfo(unsigned int fid, std::string& name, int& size) const
{
    //stub method
}

unsigned int CZipArchive::GetCrc32(unsigned int fid)
{
    //stub method
}

// To simplify things, files are always read completely into memory from
// the zip-file, since zlib does not provide any way of reading more
// than one file at a time
bool CZipArchive::GetFileImpl(unsigned int fid, std::vector<boost::uint8_t>& buffer)
{
    //stub method
}
