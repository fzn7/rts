#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "EFX.h"

#include "ALShared.h"
#include "EFXPresets.h"
#include "EFXfuncs.h"

#include "System/Config/ConfigHandler.h"
#include "System/Sound/SoundLog.h"
#include "System/myMath.h"

/******************************************************************************/
/******************************************************************************/

static std::string default_preset = "outdoors_valley"; //"bathroom";

/******************************************************************************/
/******************************************************************************/

CEFX* efx = NULL;
float CEFX::heightRolloffModifier = 1.f;

CEFX::CEFX(ALCdevice* device)
  : enabled(false)
  , supported(false)
  , sfxProperties(NULL)
  , sfxSlot(0)
  , sfxReverb(0)
  , sfxFilter(0)
  , updates(0)
  , maxSlots(0)
  , maxSlotsPerSource(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CEFX::~CEFX()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CEFX::Enable()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CEFX::Disable()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CEFX::SetPreset(std::string name, bool verbose, bool commit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CEFX::SetHeightRolloffModifer(const float& mod)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CEFX::CommitEffects()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CEFX::SetAirAbsorptionFactor(ALfloat value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CEFX::ConfigNotify(const std::string& key, const std::string& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
