/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SoundSource.h"

#include <climits>
#include <alc.h>

#include "ALShared.h"
#include "EFX.h"
#include "System/Sound/IAudioChannel.h"
#include "OggStream.h"
#include "System/Sound/SoundLog.h"
#include "SoundBuffer.h"
#include "SoundItem.h"

#include "Sound.h" //remove when unified ElmoInMeters

#include "Sim/Misc/GlobalConstants.h"
#include "System/float3.h"
#include "System/Util.h"
#include "System/myMath.h"

float CSoundSource::referenceDistance = 200.0f;
float CSoundSource::globalPitch = 1.0;
float CSoundSource::heightRolloffModifier = 1.0f;
static const float ROLLOFF_FACTOR = 5.f;

CSoundSource::CSoundSource()
	: curPlaying(NULL)
	, curChannel(NULL)
	, curStream(NULL)
	, curVolume(1.f)
	, loopStop(1e9)
	, in3D(false)
	, efxEnabled(false)
	, efxUpdates(0)
	, curHeightRolloffModifier(1)
{
    //stub method
}

CSoundSource::~CSoundSource()
{
    //stub method
}

void CSoundSource::Update()
{
    //stub method
}

int CSoundSource::GetCurrentPriority() const
{
    //stub method
}

bool CSoundSource::IsPlaying(const bool checkOpenAl) const
{
    //stub method
}

void CSoundSource::Stop()
{
    //stub method
}

void CSoundSource::Play(IAudioChannel* channel, SoundItem* item, float3 pos, float3 velocity, float volume, bool relative)
{
    //stub method
}


void CSoundSource::PlayAsync(IAudioChannel* channel, SoundItem* buffer, float3 pos, float3 velocity, float volume, bool relative)
{
    //stub method
}


void CSoundSource::PlayStream(IAudioChannel* channel, const std::string& file, float volume)
{
    //stub method
}

void CSoundSource::StreamStop()
{
    //stub method
}

void CSoundSource::StreamPause()
{
    //stub method
}

float CSoundSource::GetStreamTime()
{
    //stub method
}

float CSoundSource::GetStreamPlayTime()
{
    //stub method
}

void CSoundSource::UpdateVolume()
{
    //stub method
}
