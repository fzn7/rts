/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Rendering/GL/myGL.h"

#include "InfoConsole.h"
#include "InputReceiver.h"
#include "GuiHandler.h"
#include "Rendering/Fonts/glFont.h"
#include "System/EventHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/LogSinkHandler.h"

#define border 7

CONFIG(int, InfoMessageTime).defaultValue(10).description("Timeout till old messages disappear from the ingame console.");
CONFIG(std::string, InfoConsoleGeometry).defaultValue("0.26 0.96 0.41 0.205");

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const size_t CInfoConsole::maxRawLines   = 1024;
const size_t CInfoConsole::maxLastMsgPos = 10;

CInfoConsole::CInfoConsole()
	: CEventClient("InfoConsole", 999, false)
	, enabled(true)
	, lastMsgIter(lastMsgPositions.begin())
	, newLines(0)
	, rawId(0)
	, fontScale(1.0f)
	, maxLines(1)
{
    //stub method
}

CInfoConsole::~CInfoConsole()
{
    //stub method
}

void CInfoConsole::Draw()
{
    //stub method
}


void CInfoConsole::Update()
{
    //stub method
}

void CInfoConsole::PushNewLinesToEventHandler()
{
    //stub method
}


int CInfoConsole::GetRawLines(std::deque<RawLine>& lines)
{
    //stub method
}


void CInfoConsole::RecordLogMessage(const std::string& section, int level,
			const std::string& text)
{
    //stub method
}


void CInfoConsole::LastMessagePosition(const float3& pos)
{
    //stub method
}

const float3& CInfoConsole::GetMsgPos(const float3& defaultPos)
{
    //stub method
}
