#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/SafeVector.h"

#ifdef USE_SAFE_VECTOR
#include "System/Log/ILog.h"
#include "System/Platform/CrashHandler.h"
#include "System/maindefines.h"

template<>
const float&
safe_vector<float>::safe_element(size_type idx) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

template<>
float&
safe_vector<float>::safe_element(size_type idx)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#endif // USE_SAFE_VECTOR
