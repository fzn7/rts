/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/Util.h"
#if defined(_MSC_VER) && (_MSC_VER >= 1310)
	#include <intrin.h>
#endif
#include <cstring>
#include <boost/cstdint.hpp>


std::string StringReplace(const std::string& text,
                          const std::string& from,
                          const std::string& to)
{
    //stub method
}

std::string StringStrip(const std::string& str, const std::string& chars)
{
    //stub method
}



/// @see http://www.codeproject.com/KB/stl/stdstringtrim.aspx
void StringTrimInPlace(std::string& str, const std::string& ws)
{
    //stub method
}

std::string StringTrim(const std::string& str, const std::string& ws)
{
    //stub method
}

bool StringToBool(std::string str)
{
    //stub method
}

bool StringStartsWith(const std::string& str, const char* prefix)
{
    //stub method
}

bool StringEndsWith(const std::string& str, const char* postfix)
{
    //stub method
}


void InverseOrSetBool(bool& container, const std::string& argValue, const bool inverseArg)
{
    //stub method
}



static inline unsigned count_leading_ones(boost::uint8_t x)
{
    //stub method
}


char32_t Utf8GetNextChar(const std::string& text, int& pos)
{
    //stub method
}


std::string UnicodeToUtf8(char32_t ch)
{
    //stub method
}
