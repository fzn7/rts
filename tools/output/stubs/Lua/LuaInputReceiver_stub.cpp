#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include <string>

#include "LuaInputReceiver.h"
#include "System/EventHandler.h"


LuaInputReceiver* luaInputReceiver = NULL;


LuaInputReceiver::LuaInputReceiver()
: CInputReceiver(FRONT)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


LuaInputReceiver::~LuaInputReceiver()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool LuaInputReceiver::KeyPressed(int key, bool isRepeat)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool LuaInputReceiver::KeyReleased(int key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool LuaInputReceiver::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaInputReceiver::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaInputReceiver::MouseRelease(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool LuaInputReceiver::IsAbove(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::string LuaInputReceiver::GetTooltip(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaInputReceiver::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
