/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "BufferedArchive.h"


CBufferedArchive::CBufferedArchive(const std::string& name, bool cache)
	: IArchive(name)
{
    //stub method
}

CBufferedArchive::~CBufferedArchive()
{
    //stub method
}

bool CBufferedArchive::GetFile(unsigned int fid, std::vector<boost::uint8_t>& buffer)
{
    //stub method
}
