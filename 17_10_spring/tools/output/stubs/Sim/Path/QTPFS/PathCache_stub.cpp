#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cassert>

#include "PathCache.hpp"
#include "PathDefines.hpp"

#include "Sim/Misc/CollisionHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Rectangle.h"

static void
GetRectangleCollisionVolume(const SRectangle& r, CollisionVolume& v, float3& rm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const QTPFS::IPath*
QTPFS::PathCache::GetConstPath(unsigned int pathID, unsigned int pathType) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

QTPFS::IPath*
QTPFS::PathCache::GetPath(unsigned int pathID, unsigned int pathType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathCache::AddTempPath(IPath* path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathCache::AddLivePath(IPath* path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathCache::DelPath(unsigned int pathID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
QTPFS::PathCache::MarkDeadPaths(const SRectangle& r)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathCache::KillDeadPaths()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
