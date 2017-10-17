#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <fstream>

#include "Game/Camera.h"
#include "Game/Camera/CameraController.h"
#include "Game/CameraHandler.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Map/Ground.h"
#include "MouseHandler.h"
#include "SelectionKeyHandler.h"
#include "Sim/Misc/CategoryHandler.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitTypes/Building.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include <boost/cstdint.hpp>

CSelectionKeyHandler* selectionKeys;

CSelectionKeyHandler::CSelectionKeyHandler()
  : selectNumber(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
CSelectionKeyHandler::ReadDelimiter(std::string& str)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

namespace {
struct Filter
{
    //stub method
    //std::cout << __FUNCTION__ << std::endl;
};

void
CSelectionKeyHandler::DoSelection(std::string selectString)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
