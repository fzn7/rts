/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AudioChannel.h"

#include "ALShared.h"
#include "System/Sound/ISound.h"
#include "SoundItem.h"
#include "System/Sound/SoundLog.h"
#include "SoundSource.h"
#include "Sim/Misc/GuiSoundSet.h"
#include "Sim/Objects/WorldObject.h"

#include <climits>

extern boost::recursive_mutex soundMutex;

const size_t AudioChannel::MAX_STREAM_QUEUESIZE = 10;


AudioChannel::AudioChannel()
	: curStreamSrc(NULL)
{
    //stub method
}


void AudioChannel::SetVolume(float newVolume)
{
    //stub method
}


void AudioChannel::Enable(bool newState)
{
    //stub method
}


void AudioChannel::SoundSourceFinished(CSoundSource* sndSource)
{
    //stub method
}


void AudioChannel::FindSourceAndPlay(size_t id, const float3& pos, const float3& velocity, float volume, bool relative)
{
    //stub method
}

void AudioChannel::PlaySample(size_t id, float volume)
{
    //stub method
}

void AudioChannel::PlaySample(size_t id, const float3& pos, float volume)
{
    //stub method
}

void AudioChannel::PlaySample(size_t id, const float3& pos, const float3& velocity, float volume)
{
    //stub method
}


void AudioChannel::PlaySample(size_t id, const CWorldObject* obj, float volume)
{
    //stub method
}


void AudioChannel::PlayRandomSample(const GuiSoundSet& soundSet, const CWorldObject* obj)
{
    //stub method
}

void AudioChannel::PlayRandomSample(const GuiSoundSet& soundSet, const float3& pos)
{
    //stub method
}


void AudioChannel::StreamPlay(const std::string& filepath, float volume, bool enqueue)
{
    //stub method
}

void AudioChannel::StreamPause()
{
    //stub method
}

void AudioChannel::StreamStop()
{
    //stub method
}

float AudioChannel::StreamGetTime()
{
    //stub method
}

float AudioChannel::StreamGetPlayTime()
{
    //stub method
}
