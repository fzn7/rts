#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SoundSource.h"

#include <alc.h>
#include <climits>

#include "ALShared.h"
#include "EFX.h"
#include "OggStream.h"
#include "SoundBuffer.h"
#include "SoundItem.h"
#include "System/Sound/IAudioChannel.h"
#include "System/Sound/SoundLog.h"

#include "Sound.h" //remove when unified ElmoInMeters

#include "Sim/Misc/GlobalConstants.h"
#include "System/Util.h"
#include "System/float3.h"
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
    std::cout << __FUNCTION__ << std::endl;
}

CSoundSource::~CSoundSource()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSoundSource::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CSoundSource::GetCurrentPriority() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CSoundSource::IsPlaying(const bool checkOpenAl) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSoundSource::Stop()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSoundSource::Play(IAudioChannel* channel,
                   SoundItem* item,
                   float3 pos,
                   float3 velocity,
                   float volume,
                   bool relative)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSoundSource::PlayAsync(IAudioChannel* channel,
                        SoundItem* buffer,
                        float3 pos,
                        float3 velocity,
                        float volume,
                        bool relative)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSoundSource::PlayStream(IAudioChannel* channel,
                         const std::string& file,
                         float volume)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSoundSource::StreamStop()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSoundSource::StreamPause()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CSoundSource::GetStreamTime()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CSoundSource::GetStreamPlayTime()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSoundSource::UpdateVolume()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
