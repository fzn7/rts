#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

//  TODO: replace 'WordProperties' with regex/glob expressions
//        ex: '/give [0-9]* [_0-9a-zA-Z]+'
//        or even create a domain specific language
//        ex: '/give <ammount> {unitname} <team-ID>'
//        user-input: '/give 10 armcom 1'

#include "WordCompletion.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#include <algorithm>
#include <stdexcept>

CWordCompletion* CWordCompletion::singleton = NULL;

void
CWordCompletion::CreateInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CWordCompletion::DestroyInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CWordCompletion::CWordCompletion()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CWordCompletion::Reset()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CWordCompletion::AddWord(const std::string& word,
                         bool startOfLine,
                         bool unitName,
                         bool miniMap)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CWordCompletion::RemoveWord(const std::string& word)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::vector<std::string>
CWordCompletion::Complete(std::string& msg) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
