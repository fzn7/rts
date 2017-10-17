#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "UriParser.h"
#include "Util.h"

static void
SplitString(const std::string& text,
            const char* sepChar,
            std::string& s1,
            std::string& s2,
            std::string& all)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
ParseSpringUri(const std::string& uri,
               std::string& username,
               std::string& password,
               std::string& host,
               int& port)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
ParseRapidUri(const std::string& uri, std::string& tag)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
