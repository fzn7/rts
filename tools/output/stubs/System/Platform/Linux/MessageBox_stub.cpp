#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "System/Platform/MessageBox.h"
#include "System/Platform/errorhandler.h"

namespace Platform {

/**
 * @brief X message box function
 *
 * X clone of the Windows' MessageBox() function, using the commandline
 * dialog creation tools zenity, kdialog or xmessage as a workhorse.
 *
 * If DESKTOP_SESSION is set to "gnome" or "kde", it attempts to use
 * zenity (Gnome) or kdialog (KDE).
 *
 * If DESKTOP_SESSION is not set, or if executing zenity or kdialog failed,
 * it attempts to use the generic (but ugly!) xmessage.
 *
 * As a last resort (if forking failed, none of the above mentioned programs
 * could be found, or the used program returned an error) the message is
 * written to stderr.
 */
void MsgBox(const std::string& message, const std::string& caption, const unsigned int& flags)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

} //namespace Platform
