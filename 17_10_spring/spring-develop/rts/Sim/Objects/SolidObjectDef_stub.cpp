#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SolidObjectDef.h"
#include "Lua/LuaParser.h"
#include "Rendering/Models/IModelParser.h"
#include "Sim/Misc/CollisionVolume.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"

SolidObjectDecalDef::SolidObjectDecalDef()
  : useGroundDecal(false)
  , groundDecalType(-1)
  , groundDecalSizeX(-1)
  , groundDecalSizeY(-1)
  , groundDecalDecaySpeed(0.0f)

  , leaveTrackDecals(false)
  , trackDecalType(-1)
  , trackDecalWidth(0.0f)
  , trackDecalOffset(0.0f)
  , trackDecalStrength(0.0f)
  , trackDecalStretch(0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

SolidObjectDef::SolidObjectDef()
  : id(-1)

  , xsize(0)
  , zsize(0)

  , metal(0.0f)
  , energy(0.0f)
  , health(0.0f)
  , mass(0.0f)
  , crushResistance(0.0f)

  , collidable(false)
  , selectable(true)
  , upright(false)
  , reclaimable(true)

  , model(nullptr)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

S3DModel*
SolidObjectDef::LoadModel() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
SolidObjectDef::GetModelRadius() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SolidObjectDef::ParseCollisionVolume(const LuaTable& table)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
