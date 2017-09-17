/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "IArchive.h"

#include "System/CRC.h"
#include "System/Util.h"

IArchive::IArchive(const std::string& archiveName)
	: archiveFile(archiveName)
{
    //stub method
}

IArchive::~IArchive()
{
    //stub method
}

const std::string& IArchive::GetArchiveName() const
{
    //stub method
}

bool IArchive::FileExists(const std::string& normalizedFilePath) const
{
    //stub method
}

unsigned int IArchive::FindFile(const std::string& filePath) const
{
    //stub method
}

bool IArchive::HasLowReadingCost(unsigned int fid) const
{
    //stub method
}

unsigned int IArchive::GetCrc32(unsigned int fid)
{
    //stub method
}

bool IArchive::GetFile(const std::string& name, std::vector<boost::uint8_t>& buffer)
{
    //stub method
}
