/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ConsoleHistory.h"


const unsigned int CConsoleHistory::MAX_LINES = 256;


CConsoleHistory::CConsoleHistory()
{
    //stub method
}


CConsoleHistory::~CConsoleHistory()
{
    //stub method
}


void CConsoleHistory::ResetPosition()
{
    //stub method
}


bool CConsoleHistory::AddLine(const std::string& msg)
{
    //stub method
}

	
bool CConsoleHistory::AddLineRaw(const std::string& msg)
{
    //stub method
}


std::string CConsoleHistory::NextLine(const std::string& current)
{
    //stub method
}


std::string CConsoleHistory::PrevLine(const std::string& current)
{
    //stub method
}
