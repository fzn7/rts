#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <assert.h>
#include <deque>

#include "Game/GlobalUnsynced.h"
#include "InputReceiver.h"
#include "ProfileDrawer.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Sim/Misc/GlobalConstants.h" // for GAME_SPEED
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Path/IPathManager.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "System/EventHandler.h"
#include "System/Rectangle.h"
#include "System/ThreadPool.h"
#include "System/TimeProfiler.h"
#include "lib/lua/include/LuaUser.h"

ProfileDrawer* ProfileDrawer::instance = NULL;

static const float start_x = 0.6f;
static const float end_x = 0.99f;
static const float start_y = 0.95f;
static const float lineHeight = 0.017f;

static const auto DBG_FONT_FLAGS = (FONT_SCALE | FONT_NORM | FONT_SHADOW);

typedef std::pair<spring_time, spring_time> TimeSlice;
static std::deque<TimeSlice> vidFrames;
static std::deque<TimeSlice> simFrames;
static std::deque<TimeSlice> lgcFrames;
static std::deque<TimeSlice> swpFrames;
static std::deque<TimeSlice> uusFrames;

ProfileDrawer::ProfileDrawer()
  : CEventClient("[ProfileDrawer]", 199991, false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

ProfileDrawer::~ProfileDrawer() {}

void
ProfileDrawer::SetEnabled(bool enable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
ProfileDrawer::IsEnabled()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
DrawTimeSlice(std::deque<TimeSlice>& frames,
              const spring_time curTime,
              const spring_time maxHist,
              const float drawArea[4])
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
DrawThreadBarcode()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
DrawFrameBarcode()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
DrawProfiler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
DrawInfoText()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ProfileDrawer::DrawScreen()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
ProfileDrawer::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
ProfileDrawer::IsAbove(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ProfileDrawer::DbgTimingInfo(DbgTimingInfoType type,
                             const spring_time start,
                             const spring_time end)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
