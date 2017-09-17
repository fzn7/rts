#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <string>
#include <vector>

#include "DataDirsAccess.h"
#include "FileQueryFlags.h"
#include "System/Log/ILog.h"

#include <zlib.h>
#include <string.h> //strnlen

static const int bufsize = 4096;

class RapidEntry{
public:
	RapidEntry() {
		value.resize(entries);
	}

	RapidEntry(const std::string& line) {
		value.resize(entries);
		size_t pos = 0, start = 0;
		for(size_t i=0; i<entries; i++) {
			pos = line.find(delim, start);
			value[i] = (line.substr(start, pos - start));
			start = pos + 1;
		}
	}

	const std::string& GetTag() const
	{
		return value[0];
	}

	const std::string& GetPackageHash() const
	{
		return value[1];
	}

	const std::string& GetParentGameName() const
	{
		return value[2];
	}

	const std::string& GetName() const
	{
		return value[3];
	}
private:
	static const char delim = ',';
	static const size_t entries = 4;
	std::vector<std::string> value;

};



template <typename Lambda>
static bool GetRapidEntry(const std::string& file, RapidEntry* re, Lambda p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}




std::string GetRapidPackageFromTag(const std::string& tag)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string GetRapidTagFromPackage(const std::string& pkg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

