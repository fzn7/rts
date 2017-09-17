/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "PoolArchive.h"

#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <string>
#include <cstring>
#include <iostream>
#include <assert.h>

#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Exceptions.h"
#include "System/Util.h"
#include "System/Log/ILog.h"
#include <boost/format.hpp>


CPoolArchiveFactory::CPoolArchiveFactory()
	: IArchiveFactory("sdp")
{
    //stub method
}

IArchive* CPoolArchiveFactory::DoCreateArchive(const std::string& filePath) const
{
    //stub method
}


static unsigned int parse_int32(unsigned char c[4])
{
    //stub method
}

static bool gz_really_read(gzFile file, voidp buf, unsigned int len)
{
    //stub method
}

CPoolArchive::CPoolArchive(const std::string& name)
	: CBufferedArchive(name)
	, isOpen(false)
{
    //stub method
}

CPoolArchive::~CPoolArchive()
{
    //stub method
}

bool CPoolArchive::IsOpen()
{
    //stub method
}

unsigned int CPoolArchive::NumFiles() const
{
    //stub method
}

void CPoolArchive::FileInfo(unsigned int fid, std::string& name, int& size) const
{
    //stub method
}

unsigned int CPoolArchive::GetCrc32(unsigned int fid)
{
    //stub method
}


bool CPoolArchive::GetFileImpl(unsigned int fid, std::vector<boost::uint8_t>& buffer)
{
    //stub method
}
