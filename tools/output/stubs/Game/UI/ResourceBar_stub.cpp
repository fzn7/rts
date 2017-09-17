#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "ResourceBar.h"
#include "MouseHandler.h"
#include "GuiHandler.h"
#include "Game/GlobalUnsynced.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/Fonts/glFont.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Net/Protocol/NetProtocol.h"
#include "System/TimeProfiler.h"
#include "System/myMath.h"

CResourceBar* resourceBar = NULL;


CResourceBar::CResourceBar()
	: moveBox(false)
	, enabled(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CResourceBar::~CResourceBar()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static std::string FloatToSmallString(float num, float mul = 1) {

	char c[50];

	if (num == 0)
		sprintf(c, "0");
	if (       math::fabs(num) < (10       * mul)) {
		sprintf(c, "%.1f",  num);
	} else if (math::fabs(num) < (10000    * mul)) {
		sprintf(c, "%.0f",  num);
	} else if (math::fabs(num) < (10000000 * mul)) {
		sprintf(c, "%.0fk", num / 1000);
	} else {
		sprintf(c, "%.0fM", num / 1000000);
	}

	return c;
}


void CResourceBar::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CResourceBar::IsAbove(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::string CResourceBar::GetTooltip(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CResourceBar::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CResourceBar::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
