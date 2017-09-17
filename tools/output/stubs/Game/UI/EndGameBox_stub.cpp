#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "EndGameBox.h"

#include "MouseHandler.h"
#include "Game/Game.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/VertexArray.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/TeamStatistics.h"
#include "System/Exceptions.h"

#include <cstdio>
#include <sstream>

using std::sprintf;


static std::string FloatToSmallString(float num, float mul = 1) {

	char c[50];

	if (num == 0) {
		sprintf(c, "0");
	} else if (math::fabs(num) < 10 * mul) {
		sprintf(c, "%.1f",  num);
	} else if (math::fabs(num) < 10000 * mul) {
		sprintf(c, "%.0f",  num);
	} else if (math::fabs(num) < 10000000 * mul) {
		sprintf(c, "%.0fk", num / 1000);
	} else {
		sprintf(c, "%.0fM", num / 1000000);
	}

	return c;
}


bool CEndGameBox::enabled = true;
CEndGameBox* CEndGameBox::endGameBox = NULL;

CEndGameBox::CEndGameBox(const std::vector<unsigned char>& winningAllyTeams)
	: CInputReceiver()
	, moveBox(false)
	, dispMode(0)
	, stat1(1)
	, stat2(-1)
	, winners(winningAllyTeams)
	, graphTex(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CEndGameBox::~CEndGameBox()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CEndGameBox::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CEndGameBox::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CEndGameBox::MouseRelease(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CEndGameBox::IsAbove(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CEndGameBox::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string CEndGameBox::GetTooltip(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CEndGameBox::FillTeamStats()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
