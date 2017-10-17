#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cstring>

#include "CommandColors.h"
#include "HwMouseCursor.h"
#include "MouseCursor.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/Bitmap.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/bitops.h"
#include "System/myMath.h"

using std::string;

//////////////////////////////////////////////////////////////////////
// CMouseCursor Class
//////////////////////////////////////////////////////////////////////

CMouseCursor*
CMouseCursor::New(const string& name, HotSpot hs)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CMouseCursor*
CMouseCursor::GetNullCursor()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
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
    std::cout << __FUNCTION__ << std::endl;
}

CMouseCursor::~CMouseCursor()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CMouseCursor::BuildFromSpecFile(const string& name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CMouseCursor::BuildFromFileNames(const string& name, int lastFrame)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CMouseCursor::LoadCursorImage(const string& name, ImageData& image)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMouseCursor::Draw(int x, int y, float scale) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMouseCursor::DrawQuad(int x, int y) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMouseCursor::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMouseCursor::BindTexture() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMouseCursor::BindHwCursor() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
