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
}


CGameController::~CGameController()
{
    //stub method
}


bool CGameController::Draw()
{
    //stub method
}


bool CGameController::Update()
{
    //stub method
}


int CGameController::KeyPressed(int key, bool isRepeat)
{
    //stub method
}


int CGameController::KeyReleased(int key)
{
    //stub method
}


void CGameController::PasteClipboard()
{
    //stub method
}
