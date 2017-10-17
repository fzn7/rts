#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SoundBuffer.h"

#include "ALShared.h"
#include "System/Platform/byteorder.h"
#include "System/Sound/SoundLog.h"
#include "VorbisShared.h"

#include <cstring>
#include <ogg/ogg.h>
#include <vorbis/vorbisfile.h>

namespace {
struct VorbisInputBuffer
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
VorbisClose(void* datasource)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}

SoundBuffer::bufferMapT SoundBuffer::bufferMap; // filename, index into Buffers
SoundBuffer::bufferVecT SoundBuffer::buffers;

SoundBuffer::SoundBuffer()
  : id(0)
  , channels(0)
  , length(0.0f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
SoundBuffer::LoadVorbis(const std::string& file,
                        std::vector<boost::uint8_t> buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
SoundBuffer::BufferSize() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SoundBuffer::Initialise()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SoundBuffer::Deinitialise()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

size_t
SoundBuffer::GetId(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::shared_ptr<SoundBuffer>
SoundBuffer::GetById(const size_t id)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

size_t
SoundBuffer::Count()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

size_t
SoundBuffer::AllocedSize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

size_t
SoundBuffer::Insert(boost::shared_ptr<SoundBuffer> buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
SoundBuffer::AlGenBuffer(const std::string& file,
                         ALenum format,
                         const boost::uint8_t* data,
                         size_t datalength,
                         int rate)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
