#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "OggStream.h"

#include "ALShared.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Sound/SoundLog.h"
#include "VorbisShared.h"
#include <string.h> //memset

namespace VorbisCallbacks {
size_t
VorbisStreamRead(void* ptr, size_t size, size_t nmemb, void* datasource)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
VorbisStreamClose(void* datasource)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
VorbisStreamSeek(void* datasource, ogg_int64_t offset, int whence)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

long
VorbisStreamTell(void* datasource)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}

COggStream::COggStream(ALuint _source)
  : vorbisInfo(NULL)
  , source(_source)
  , format(AL_FORMAT_MONO16)
  , stopped(true)
  , paused(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

COggStream::~COggStream()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// open an Ogg stream from a given file and start playing it
void
COggStream::Play(const std::string& path, float volume)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
COggStream::GetPlayTime() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
COggStream::GetTotalTime()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
COggStream::Valid() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
COggStream::IsFinished()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const COggStream::TagVector&
COggStream::VorbisTags() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// display Ogg info and comments
void
COggStream::DisplayInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// clean up the OpenAL resources
void
COggStream::ReleaseBuffers()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// returns true if both buffers were
// filled with data from the stream
bool
COggStream::StartPlaying()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// returns true if we're still playing
bool
COggStream::IsPlaying()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// stops the currently playing stream
void
COggStream::Stop()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
COggStream::TogglePause()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// pop the processed buffers from the queue,
// refill them, and push them back in line
bool
COggStream::UpdateBuffers()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
COggStream::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// read decoded data from audio stream into PCM buffer
bool
COggStream::DecodeStream(ALuint buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// dequeue any buffers pending on source
void
COggStream::EmptyBuffers()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
