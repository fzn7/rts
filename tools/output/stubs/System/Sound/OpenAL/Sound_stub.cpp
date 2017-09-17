#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Sound.h"

#include <cstdlib>
#include <cmath>
#include <alc.h>

#ifndef ALC_ALL_DEVICES_SPECIFIER
#define ALC_ALL_DEVICES_SPECIFIER 0x1013
// needed for ALC_ALL_DEVICES_SPECIFIER on some special *nix
// #include <alext.h>
#endif

#include <boost/cstdint.hpp>
#include <boost/thread/thread.hpp>

#include "System/Sound/ISoundChannels.h"
#include "System/Sound/SoundLog.h"
#include "SoundSource.h"
#include "SoundBuffer.h"
#include "SoundItem.h"
#include "ALShared.h"
#include "EFX.h"
#include "EFXPresets.h"

#include "System/TimeProfiler.h"
#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileHandler.h"
#include "Lua/LuaParser.h"
#include "Map/Ground.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/myMath.h"
#include "System/Util.h"
#include "System/Platform/Threading.h"
#include "System/Platform/Watchdog.h"

#include "System/float3.h"


boost::recursive_mutex soundMutex;


CSound::CSound()
	: listenerNeedsUpdate(false)
	, soundThread(NULL)
	, soundThreadQuit(false)
	, canLoadDefs(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CSound::~CSound()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CSound::HasSoundItem(const std::string& name) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

size_t CSound::GetSoundId(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SoundItem* CSound::GetSoundItem(size_t id) const {
	// id==0 is a special id and invalid
	if (id == 0 || id >= sounds.size())
		return NULL;
	return sounds[id];
}

CSoundSource* CSound::GetNextBestSource(bool lock)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CSound::PitchAdjust(const float newPitch)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CSound::ConfigNotify(const std::string& key, const std::string& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CSound::Mute()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CSound::IsMuted() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CSound::Iconified(bool state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

__FORCE_ALIGN_STACK__
void CSound::StartThread(int maxSounds)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CSound::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

size_t CSound::MakeItemFromDef(const soundItemDef& itemDef)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CSound::UpdateListener(const float3& campos, const float3& camdir, const float3& camup)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSound::UpdateListenerReal()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSound::PrintDebugInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CSound::LoadSoundDefsImpl(const std::string& fileName, const std::string& modes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//! only used internally, locked in caller's scope
size_t CSound::LoadSoundBuffer(const std::string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CSound::NewFrame()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


// try to get the maximum number of supported sounds, this is similar to code CSound::StartThread
// but should be more safe
int CSound::GetMaxMonoSources(ALCdevice* device, int maxSounds)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

