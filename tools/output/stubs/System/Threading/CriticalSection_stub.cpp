#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CriticalSection.h"


CriticalSection::CriticalSection() noexcept
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CriticalSection::~CriticalSection()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CriticalSection::lock()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CriticalSection::try_lock() noexcept
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CriticalSection::unlock()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
