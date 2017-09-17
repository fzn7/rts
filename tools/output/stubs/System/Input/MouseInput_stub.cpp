#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/*
	This workaround fixes the windows slow mouse movement problem
	(happens on full-screen mode + pressing keys).
	The code hacks around the mouse input from DirectInput,
	which SDL uses in full-screen mode.
	Instead it installs a window message proc and reads input from WM_MOUSEMOVE.
	On non-windows, the normal SDL events are used for mouse input

	new:
	It also workarounds a issue with SDL+windows and hardware cursors
	(->it has to block WM_SETCURSOR),
	so it is used now always even in window mode!

	newer:
	SDL_Event struct is used for new input handling.
	Several people confirmed its working.
*/


#include "MouseInput.h"
#include "InputHandler.h"

#include "Game/GlobalUnsynced.h"
#include "Game/UI/MouseHandler.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/GL/FBO.h"
#include "System/maindefines.h"

#include <boost/bind.hpp>
#include <SDL_events.h>
#include <SDL_syswm.h>


IMouseInput* mouseInput = NULL;


IMouseInput::IMouseInput()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool IMouseInput::HandleSDLMouseEvent(const SDL_Event& event)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////

#if defined(WIN32) && !defined (HEADLESS)

class CWin32MouseInput : public IMouseInput
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



IMouseInput* IMouseInput::GetInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void IMouseInput::FreeInstance(IMouseInput* mouseInp) {
	delete mouseInp; mouseInput = NULL;
}
