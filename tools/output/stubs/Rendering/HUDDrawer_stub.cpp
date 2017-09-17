/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "HUDDrawer.h"

#include "Rendering/Fonts/glFont.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/GL/myGL.h"
#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Sim/MoveTypes/MoveType.h"
#include "Sim/Units/Unit.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDef.h"
#include "Sim/Misc/GlobalSynced.h"
#include "System/myMath.h"


HUDDrawer* HUDDrawer::GetInstance()
{
    //stub method
}

void HUDDrawer::PushState()
{
    //stub method
}
void HUDDrawer::PopState()
{
    //stub method
}

void HUDDrawer::DrawModel(const CUnit* unit)
{
    //stub method
}

void HUDDrawer::DrawUnitDirectionArrow(const CUnit* unit)
{
    //stub method
}
void HUDDrawer::DrawCameraDirectionArrow(const CUnit* unit)
{
    //stub method
}

void HUDDrawer::DrawWeaponStates(const CUnit* unit)
{
    //stub method
}

void HUDDrawer::DrawTargetReticle(const CUnit* unit)
{
    //stub method
}

void HUDDrawer::Draw(const CUnit* unit)
{
    //stub method
}
