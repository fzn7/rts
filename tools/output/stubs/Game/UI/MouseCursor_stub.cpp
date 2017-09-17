/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include <cstring>

#include "System/bitops.h"
#include "CommandColors.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/Textures/Bitmap.h"
#include "MouseCursor.h"
#include "HwMouseCursor.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include "System/Util.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/SimpleParser.h"

using std::string;

//////////////////////////////////////////////////////////////////////
// CMouseCursor Class
//////////////////////////////////////////////////////////////////////

CMouseCursor* CMouseCursor::New(const string &name, HotSpot hs)
{
    //stub method
}


CMouseCursor* CMouseCursor::GetNullCursor()
{
    //stub method
}


CMouseCursor::CMouseCursor(const string& name, HotSpot hs)
 : animated(false)
 , hwValid(false)
 , animTime(0.0f)
 , animPeriod(0.0f)
 , currentFrame(0)
 , xmaxsize(0)
 , ymaxsize(0)
 , xofs(0)
 , yofs(0)
{
    //stub method
}


CMouseCursor::~CMouseCursor()
{
    //stub method
}


bool CMouseCursor::BuildFromSpecFile(const string& name)
{
    //stub method
}


bool CMouseCursor::BuildFromFileNames(const string& name, int lastFrame)
{
    //stub method
}


bool CMouseCursor::LoadCursorImage(const string& name, ImageData& image)
{
    //stub method
}


void CMouseCursor::Draw(int x, int y, float scale) const
{
    //stub method
}


void CMouseCursor::DrawQuad(int x, int y) const
{
    //stub method
}


void CMouseCursor::Update()
{
    //stub method
}


void CMouseCursor::BindTexture() const
{
    //stub method
}

void CMouseCursor::BindHwCursor() const
{
    //stub method
}
