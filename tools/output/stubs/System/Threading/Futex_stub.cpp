#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Futex.h"
#include <sys/syscall.h>
#include <linux/futex.h>


spring_futex::spring_futex() noexcept
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


spring_futex::~spring_futex()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void spring_futex::lock()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool spring_futex::try_lock() noexcept
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void spring_futex::unlock()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/*
recursive_futex::recursive_futex() noexcept
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


recursive_futex::~recursive_futex()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void recursive_futex::lock()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool recursive_futex::try_lock() noexcept
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void recursive_futex::unlock()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
*/

