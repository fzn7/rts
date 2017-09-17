#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

// TODO: move this out of Sim, this is rendering code!

#include "LineDrawer.h"

#include <cmath>

#include "Rendering/GlobalRendering.h"
#include "Game/UI/CommandColors.h"

CLineDrawer lineDrawer;


CLineDrawer::CLineDrawer()
	: lineStipple(false)
	, useColorRestarts(false)
	, useRestartColor(false)
	, restartAlpha(0.0f)
	, restartColor(NULL)
	, lastPos(ZeroVector)
	, lastColor(NULL)
	, stippleTimer(0.0f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLineDrawer::UpdateLineStipple()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLineDrawer::SetupLineStipple()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLineDrawer::DrawAll()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
