/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "PoolArchive.h"

#include <algorithm>
#include <assert.h>
#include <cstring>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "System/Exceptions.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include <boost/format.hpp>

CPoolArchiveFactory::CPoolArchiveFactory()
  : IArchiveFactory("sdp")
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static unsigned int
parse_int32(unsigned char c[4])
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
gz_really_read(gzFile file, voidp buf, unsigned int len)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CPoolArchive::CPoolArchive(const std::string& name)
  : CBufferedArchive(name)
  , isOpen(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CPoolArchive::~CPoolArchive()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CPoolArchive::IsOpen()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
CPoolArchive::NumFiles() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPoolArchive::FileInfo(unsigned int fid, std::string& name, int& size) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
CPoolArchive::GetCrc32(unsigned int fid)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CPoolArchive::GetFileImpl(unsigned int fid, std::vector<boost::uint8_t>& buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
