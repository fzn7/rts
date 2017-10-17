#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaTextures.h"

#include "System/Util.h"

/******************************************************************************/
/******************************************************************************/

LuaTextures::LuaTextures()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LuaTextures::~LuaTextures()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

string
LuaTextures::Create(const Texture& tex)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
LuaTextures::Bind(const string& name) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
LuaTextures::Free(const string& name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
LuaTextures::FreeFBO(const string& name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LuaTextures::FreeAll()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const LuaTextures::Texture*
LuaTextures::GetInfo(const string& name) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
