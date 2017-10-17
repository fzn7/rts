#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GameController.h"
#include "System/Platform/Clipboard.h"

CGameController* activeController = NULL;

CGameController::CGameController()
  : userWriting(false)
  , writingPos(0)
  , ignoreNextChar(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGameController::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGameController::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CGameController::KeyPressed(int key, bool isRepeat)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CGameController::KeyReleased(int key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGameController::PasteClipboard()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
