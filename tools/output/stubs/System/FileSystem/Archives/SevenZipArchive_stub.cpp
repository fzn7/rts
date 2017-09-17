#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SevenZipArchive.h"

#include <algorithm>
#include <boost/system/error_code.hpp>
#include <stdexcept>
#include <string.h> //memcpy

extern "C" {
#include "lib/7z/7zAlloc.h"
#include "lib/7z/7zCrc.h"
#include "lib/7z/Types.h"
}

#include "System/Log/ILog.h"
#include "System/Util.h"

static Byte kUtf8Limits[5] = { 0xC0, 0xE0, 0xF0, 0xF8, 0xFC };
static Bool
Utf16_To_Utf8(char* dest, size_t* destLen, const UInt16* src, size_t srcLen)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CSevenZipArchiveFactory::CSevenZipArchiveFactory()
  : IArchiveFactory("sd7")
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

IArchive*
CSevenZipArchiveFactory::DoCreateArchive(const std::string& filePath) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const char*
CSevenZipArchive::GetErrorStr(int err)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CSevenZipArchive::CSevenZipArchive(const std::string& name)
  : CBufferedArchive(name, false)
  , blockIndex(0xFFFFFFFF)
  , outBuffer(NULL)
  , outBufferSize(0)
  , tempBuf(NULL)
  , tempBufSize(0)
  , isOpen(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CSevenZipArchive::~CSevenZipArchive()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CSevenZipArchive::IsOpen()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
CSevenZipArchive::NumFiles() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CSevenZipArchive::GetFileImpl(unsigned int fid,
                              std::vector<boost::uint8_t>& buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSevenZipArchive::FileInfo(unsigned int fid, std::string& name, int& size) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const size_t CSevenZipArchive::COST_LIMIT_UNPACK_OVERSIZE = 32 * 1024;
const size_t CSevenZipArchive::COST_LIMIT_DISC_READ = 32 * 1024;

bool
CSevenZipArchive::HasLowReadingCost(unsigned int fid) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
CSevenZipArchive::GetCrc32(unsigned int fid)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
