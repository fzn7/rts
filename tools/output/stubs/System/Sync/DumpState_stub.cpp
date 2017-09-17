#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <string>
#include <fstream>
#include <vector>
#include <list>

#include "DumpState.h"

#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Net/GameServer.h"
#include "Rendering/Models/3DModel.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/MoveTypes/MoveType.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/Util.h"
#include "System/Log/ILog.h"


void DumpState(int newMinFrameNum, int newMaxFrameNum, int newFramePeriod)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
