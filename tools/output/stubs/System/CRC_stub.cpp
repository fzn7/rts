#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CRC.h"

extern "C" {
#include "lib/7z/7zCrc.h"
}


static bool crcTableInitialized;


CRC::CRC()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


unsigned int CRC::GetDigest() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


unsigned int CRC::GetCRC(const void* data, unsigned int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CRC& CRC::Update(const void* data, unsigned int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CRC& CRC::Update(unsigned int data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
