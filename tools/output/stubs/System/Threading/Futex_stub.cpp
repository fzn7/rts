/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Futex.h"
#include <sys/syscall.h>
#include <linux/futex.h>


spring_futex::spring_futex() noexcept
{
    //stub method
}


spring_futex::~spring_futex()
{
    //stub method
}


void spring_futex::lock()
{
    //stub method
}


bool spring_futex::try_lock() noexcept
{
    //stub method
}


void spring_futex::unlock()
{
    //stub method
}



/*
recursive_futex::recursive_futex() noexcept
{
    //stub method
}


recursive_futex::~recursive_futex()
{
    //stub method
}


void recursive_futex::lock()
{
    //stub method
}


bool recursive_futex::try_lock() noexcept
{
    //stub method
}


void recursive_futex::unlock()
{
    //stub method
}
*/

