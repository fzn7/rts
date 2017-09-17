#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <vector>
#include <cstdio>

#include "Benchmark.h"

#include "Game.h"
#include "GlobalUnsynced.h"
#include "UI/GuiHandler.h"
#include "Rendering/GlobalRendering.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Features/FeatureHandler.h"
#include "System/TimeProfiler.h"

bool CBenchmark::enabled = false;
int CBenchmark::startFrame = 0;
int CBenchmark::endFrame = 5 * 60 * GAME_SPEED;


CBenchmark::CBenchmark()
	: CEventClient("[CBenchmark]", 271990, false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CBenchmark::~CBenchmark()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CBenchmark::GameFrame(int gameFrame)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CBenchmark::DrawWorld()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
