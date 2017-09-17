#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ConsoleHistory.h"


const unsigned int CConsoleHistory::MAX_LINES = 256;


CConsoleHistory::CConsoleHistory()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CConsoleHistory::~CConsoleHistory()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CConsoleHistory::ResetPosition()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CConsoleHistory::AddLine(const std::string& msg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

	
bool CConsoleHistory::AddLineRaw(const std::string& msg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::string CConsoleHistory::NextLine(const std::string& current)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::string CConsoleHistory::PrevLine(const std::string& current)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
