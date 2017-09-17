#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <algorithm>
#include <string>
#include <vector>

#include "Action.h"
#include "System/FileSystem/SimpleParser.h"

Action::Action(const std::string& line)
  : rawline(line)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
