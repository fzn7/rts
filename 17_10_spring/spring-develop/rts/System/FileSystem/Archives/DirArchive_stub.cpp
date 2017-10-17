#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DirArchive.h"

#include <assert.h>
#include <fstream>

#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Util.h"

CDirArchiveFactory::CDirArchiveFactory()
  : IArchiveFactory("sdd")
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CDirArchive::CDirArchive(const std::string& archiveName)
  : IArchive(archiveName)
  , dirName(archiveName + '/')
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CDirArchive::~CDirArchive() {}

bool
CDirArchive::IsOpen()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
CDirArchive::NumFiles() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CDirArchive::GetFile(unsigned int fid, std::vector<boost::uint8_t>& buffer)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CDirArchive::FileInfo(unsigned int fid, std::string& name, int& size) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
