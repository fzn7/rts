#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SmoothHeightMeshDrawer.h"
#include "Game/UnsyncedGameCommands.h"
#include "Rendering/GL/VertexArray.h"
#include "Sim/Misc/SmoothHeightMesh.h"
#include "System/float3.h"

namespace { // prevents linking problems in case of duplicate symbols

class AirMeshActionExecutor : public IUnsyncedActionExecutor
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SmoothHeightMeshDrawer::~SmoothHeightMeshDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SmoothHeightMeshDrawer*
SmoothHeightMeshDrawer::GetInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SmoothHeightMeshDrawer::Draw(float yoffset)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
