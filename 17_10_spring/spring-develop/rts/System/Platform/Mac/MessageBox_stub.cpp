#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/Platform/MessageBox.h"

#if !defined(DEDICATED) && !defined(HEADLESS)
#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFString.h>
#include <CoreFoundation/CFUserNotification.h>
#endif

namespace Platform {

/**
 * @brief message box function
 *
 * MacOSX clone of the Windows' MessageBox() function.
 */
void
MsgBox(const std::string& message,
       const std::string& caption,
       const unsigned int& flags)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

}; // namespace Platform
