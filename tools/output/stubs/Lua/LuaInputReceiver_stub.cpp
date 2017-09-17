/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include <string>

#include "LuaInputReceiver.h"
#include "System/EventHandler.h"


LuaInputReceiver* luaInputReceiver = NULL;


LuaInputReceiver::LuaInputReceiver()
: CInputReceiver(FRONT)
{
    //stub method
}


LuaInputReceiver::~LuaInputReceiver()
{
    //stub method
}


bool LuaInputReceiver::KeyPressed(int key, bool isRepeat)
{
    //stub method
}


bool LuaInputReceiver::KeyReleased(int key)
{
    //stub method
}


bool LuaInputReceiver::MousePress(int x, int y, int button)
{
    //stub method
}


void LuaInputReceiver::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
}


void LuaInputReceiver::MouseRelease(int x, int y, int button)
{
    //stub method
}


bool LuaInputReceiver::IsAbove(int x, int y)
{
    //stub method
}


std::string LuaInputReceiver::GetTooltip(int x, int y)
{
    //stub method
}


void LuaInputReceiver::Draw()
{
    //stub method
}
