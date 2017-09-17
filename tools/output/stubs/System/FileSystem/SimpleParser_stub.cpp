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
    std::cout << _FUNCTION_ << std::endl;
}

CSimpleParser::CSimpleParser(const std::string& filecontent)
	: file(filecontent)
	, curPos(0)
	, lineNumber(0)
//	, inComment(false) // /* text */ comments are not implemented
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



int CSimpleParser::GetLineNumber() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::string CSimpleParser::GetLine()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::string CSimpleParser::GetCleanLine()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::vector<std::string> CSimpleParser::Tokenize(const std::string& line, int minWords)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::vector<std::string> CSimpleParser::Split(const std::string& str, const std::string& delimitters) {

	std::vector<std::string> tokens;

	// Skip delimiters at beginning.
	std::string::size_type lastPos = str.find_first_not_of(delimitters, 0);
	// Find first "non-delimiter".
	std::string::size_type pos     = str.find_first_of(delimitters, lastPos);

	while (std::string::npos != pos || std::string::npos != lastPos) {
		// Found a token, add it to the vector.
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters. Note the "not_of"
		lastPos = str.find_first_not_of(delimitters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimitters, lastPos);
	}

	return tokens;
}
