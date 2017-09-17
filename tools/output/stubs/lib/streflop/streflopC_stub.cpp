#include <iostream>
/* Copyright (C) 2009 Tobi Vollebregt */

#include "streflopC.h"

#include "streflop_cond.h"

#ifdef __cplusplus
extern "C" {
#endif

void
streflop_init_Simple()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
streflop_init_Double()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#if defined(Extended)
void
streflop_init_Extended()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif // defined(Extended)

#ifdef __cplusplus
} // extern "C"
#endif
