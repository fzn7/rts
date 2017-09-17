#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SoundItem.h"

#include <sstream>
#include <stdexcept>
#include <cfloat>

#include "SoundBuffer.h"
#include "System/UnsyncedRNG.h"

namespace
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SoundItem::SoundItem(boost::shared_ptr<SoundBuffer> _buffer, const std::map<std::string, std::string>& items)
	: buffer(_buffer)
	, gain(1.0)
	, gainMod(0)
	, pitch(1.0)
	, pitchMod(0)
	, dopplerScale(1.0)
	, maxDist(FLT_MAX)
	, rolloff(1.0f)
	, priority(0)
	, maxConcurrent(16)
	, currentlyPlaying(0)
	, loopTime(0)
	, in3D(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool SoundItem::PlayNow()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void SoundItem::StopPlay()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float SoundItem::GetGain() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float SoundItem::GetPitch() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
