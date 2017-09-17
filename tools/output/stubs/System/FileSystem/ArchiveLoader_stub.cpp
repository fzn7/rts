#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "ArchiveLoader.h"

#include "Archives/ArchiveFactory.h"
#include "Archives/IArchive.h"
#include "Archives/PoolArchive.h"
#include "Archives/DirArchive.h"
#include "Archives/ZipArchive.h"
#include "Archives/SevenZipArchive.h"
#include "Archives/VirtualArchive.h"

#include "FileSystem.h"
#include "DataDirsAccess.h"

#include "System/Util.h"


CArchiveLoader::CArchiveLoader()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CArchiveLoader::~CArchiveLoader()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CArchiveLoader& CArchiveLoader::GetInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CArchiveLoader::IsArchiveFile(const std::string& fileName) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


IArchive* CArchiveLoader::OpenArchive(const std::string& fileName, const std::string& type) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CArchiveLoader::AddFactory(IArchiveFactory* archiveFactory)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
