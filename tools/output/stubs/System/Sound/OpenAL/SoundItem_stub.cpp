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
}

bool SoundItem::PlayNow()
{
    //stub method
}

void SoundItem::StopPlay()
{
    //stub method
}

float SoundItem::GetGain() const
{
    //stub method
}

float SoundItem::GetPitch() const
{
    //stub method
}
