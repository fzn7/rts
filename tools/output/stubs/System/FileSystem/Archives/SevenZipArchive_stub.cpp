/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SevenZipArchive.h"

#include <algorithm>
#include <boost/system/error_code.hpp>
#include <stdexcept>
#include <string.h> //memcpy

extern "C" {
#include "lib/7z/Types.h"
#include "lib/7z/7zAlloc.h"
#include "lib/7z/7zCrc.h"
}

#include "System/Util.h"
#include "System/Log/ILog.h"

static Byte kUtf8Limits[5] = { 0xC0, 0xE0, 0xF0, 0xF8, 0xFC };
static Bool Utf16_To_Utf8(char *dest, size_t *destLen, const UInt16 *src, size_t srcLen)
{
    //stub method
}

CSevenZipArchiveFactory::CSevenZipArchiveFactory()
	: IArchiveFactory("sd7")
{
    //stub method
}

int CSevenZipArchive::GetFileName(const CSzArEx* db, int i)
{
    //stub method
}

IArchive* CSevenZipArchiveFactory::DoCreateArchive(const std::string& filePath) const
{
    //stub method
}

const char* CSevenZipArchive::GetErrorStr(int err)
{
    //stub method
}


CSevenZipArchive::CSevenZipArchive(const std::string& name):
	CBufferedArchive(name, false),
	blockIndex(0xFFFFFFFF),
	outBuffer(NULL),
	outBufferSize(0),
	tempBuf(NULL),
	tempBufSize(0),
	isOpen(false)
{
    //stub method
}


CSevenZipArchive::~CSevenZipArchive()
{
    //stub method
}

bool CSevenZipArchive::IsOpen()
{
    //stub method
}

unsigned int CSevenZipArchive::NumFiles() const
{
    //stub method
}

bool CSevenZipArchive::GetFileImpl(unsigned int fid, std::vector<boost::uint8_t>& buffer)
{
    //stub method
}

void CSevenZipArchive::FileInfo(unsigned int fid, std::string& name, int& size) const
{
    //stub method
}


const size_t CSevenZipArchive::COST_LIMIT_UNPACK_OVERSIZE = 32 * 1024;
const size_t CSevenZipArchive::COST_LIMIT_DISC_READ       = 32 * 1024;

bool CSevenZipArchive::HasLowReadingCost(unsigned int fid) const
{
    //stub method
}

unsigned int CSevenZipArchive::GetCrc32(unsigned int fid)
{
    //stub method
}
