#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef _WIN32
#include <fcntl.h>
#include <unistd.h>
#endif
#include "ScopedFileLock.h"

/**
 * @brief lock fd
 *
 * Lock file descriptor fd for reading (write == false) or writing
 * (write == true).
 */
ScopedFileLock::ScopedFileLock(int fd, bool write)
  : filedes(fd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @brief unlock fd
 */
ScopedFileLock::~ScopedFileLock()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
