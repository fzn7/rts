#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SimpleParser.h"
#include "FileHandler.h"

#include <sstream>

CSimpleParser::CSimpleParser(CFileHandler& fh)
  : curPos(0)
  , lineNumber(0)
//	, inComment(false) // /* text */ comments are not implemented
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CSimpleParser::CSimpleParser(const std::string& filecontent)
  : file(filecontent)
  , curPos(0)
  , lineNumber(0)
//	, inComment(false) // /* text */ comments are not implemented
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
CSimpleParser::GetLine()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
CSimpleParser::GetCleanLine()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::vector<std::string>
CSimpleParser::Tokenize(const std::string& line, int minWords)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::vector<std::string>
CSimpleParser::Split(const std::string& str, const std::string& delimitters)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
