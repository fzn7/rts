#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "HUDDrawer.h"

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/MoveTypes/MoveType.h"
#include "Sim/Units/Unit.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/myMath.h"

HUDDrawer*
HUDDrawer::GetInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
HUDDrawer::PushState()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
HUDDrawer::PopState()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
HUDDrawer::DrawModel(const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
HUDDrawer::DrawUnitDirectionArrow(const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
HUDDrawer::DrawCameraDirectionArrow(const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
HUDDrawer::DrawWeaponStates(const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
HUDDrawer::DrawTargetReticle(const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
HUDDrawer::Draw(const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
