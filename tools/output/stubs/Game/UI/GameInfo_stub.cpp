/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "GameInfo.h"
#include "MouseHandler.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/Fonts/glFont.h"
#include "Game/GameSetup.h"
#include "Game/GameVersion.h"
#include "Sim/Misc/Team.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/Wind.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Path/IPathManager.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Util.h"

#include <SDL_keycode.h>
#include <cstdio>

using std::string;
using std::vector;



static const char* boolString(bool value)
{
    //stub method
}

static const char* floatString(float value)
{
    //stub method
}

static void StringListStats(
	const vector<CGameInfo::FontString>& list,
	float& maxWidth,
	float& maxHeight
) {
	maxWidth = 0.0f;
	maxHeight = 0.0f;

	for (int i = 0; i < (int)list.size(); i++) {
		const CGameInfo::FontString& fs = list[i];

		maxWidth = std::max(maxWidth, fs.width);
		maxHeight = std::max(maxHeight, fs.height);
	}
}



static CGameInfo* instance = NULL;

void CGameInfo::Enable()
{
    //stub method
}

void CGameInfo::Disable()
{
    //stub method
}

bool CGameInfo::IsActive()
{
    //stub method
}



CGameInfo::CGameInfo()
{
    //stub method
}

CGameInfo::~CGameInfo()
{
    //stub method
}



CGameInfo::FontString::FontString(const char* c): msg(c)        { CalcDimensions(); }
CGameInfo::FontString::FontString(const std::string& s): msg(s) { CalcDimensions(); }
CGameInfo::FontString::FontString(bool b): msg(boolString(b))   { CalcDimensions(); }
CGameInfo::FontString::FontString(float f): msg(floatString(f)) { CalcDimensions(); }

void CGameInfo::FontString::CalcDimensions() {
	width  = font->GetSize() * font->GetTextWidth(msg) * globalRendering->pixelX;
	height = font->GetSize() * font->GetLineHeight() * globalRendering->pixelY;
}



/******************************************************************************/

std::string CGameInfo::GetTooltip(int x,int y)
{
    //stub method
}


bool CGameInfo::IsAbove(int x, int y)
{
    //stub method
}


bool CGameInfo::MousePress(int x, int y, int button)
{
    //stub method
}


void CGameInfo::MouseRelease(int x, int y, int button)
{
    //stub method
}


bool CGameInfo::KeyPressed(int key, bool isRepeat)
{
    //stub method
}


void CGameInfo::Draw()
{
    //stub method
}
