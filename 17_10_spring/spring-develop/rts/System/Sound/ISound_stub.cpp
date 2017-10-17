#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ISound.h"

#ifndef NO_SOUND
#include "OpenAL/Sound.h"
#endif // NO_SOUND
#include "Null/NullSound.h"

#include "SoundLog.h"
#include "System/Config/ConfigHandler.h"

#include "ISoundChannels.h"
#include "Null/NullAudioChannel.h"
#ifndef NO_SOUND
#include "OpenAL/AudioChannel.h"
#endif
#include "System/Misc/SpringTime.h" //FIXME: remove this
#include <list>

CONFIG(bool, Sound)
  .defaultValue(true)
  .description("Select the Sound driver, true = OpenAL, false = NullAudio");

// defined here so spring-headless contains them, too (default & headless should
// contain the same set of configtags!)
CONFIG(int, MaxSounds)
  .defaultValue(128)
  .headlessValue(1)
  .minimumValue(1)
  .description("Maximum parallel played sounds.");
CONFIG(bool, PitchAdjust)
  .defaultValue(false)
  .description("When enabled adjust sound speed/pitch to game speed.");
CONFIG(int, snd_volmaster)
  .defaultValue(60)
  .minimumValue(0)
  .maximumValue(200)
  .description("Master sound volume.");
CONFIG(int, snd_volgeneral)
  .defaultValue(100)
  .minimumValue(0)
  .maximumValue(200)
  .description("Volume for \"general\" sound channel.");
CONFIG(int, snd_volunitreply)
  .defaultValue(100)
  .minimumValue(0)
  .maximumValue(200)
  .description("Volume for \"unit reply\" sound channel.");
CONFIG(int, snd_volbattle)
  .defaultValue(100)
  .minimumValue(0)
  .maximumValue(200)
  .description("Volume for \"battle\" sound channel.");
CONFIG(int, snd_volui)
  .defaultValue(100)
  .minimumValue(0)
  .maximumValue(200)
  .description("Volume for \"ui\" sound channel.");
CONFIG(int, snd_volmusic)
  .defaultValue(100)
  .minimumValue(0)
  .maximumValue(200)
  .description("Volume for \"music\" sound channel.");
CONFIG(std::string, snd_device)
  .defaultValue("")
  .description("Sets the used output device. See \"Available Devices\" section "
               "in infolog.txt.");

CONFIG(float, snd_airAbsorption).defaultValue(0.1f);
CONFIG(bool, UseEFX).defaultValue(true).safemodeValue(false);

ISound* ISound::singleton = NULL;

ISound::ISound()
  : numEmptyPlayRequests(0)
  , numAbortedPlays(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#define SafeDelete(var)                                                        \
    delete var;                                                                \
    var = NULL;

void
ISound::Shutdown()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
ISound::IsNullAudio()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
ISound::ChangeOutput(bool forceNullSound)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
ISound::LoadSoundDefs(const std::string& filename, const std::string& modes)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
