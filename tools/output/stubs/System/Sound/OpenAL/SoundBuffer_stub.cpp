/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SoundBuffer.h"


#include "System/Sound/SoundLog.h"
#include "ALShared.h"
#include "VorbisShared.h"
#include "System/Platform/byteorder.h"

#include <vorbis/vorbisfile.h>
#include <ogg/ogg.h>
#include <cstring>

namespace
{
    //stub method
}

int	VorbisClose(void* datasource)
{
    //stub method
}
}

SoundBuffer::bufferMapT SoundBuffer::bufferMap; // filename, index into Buffers
SoundBuffer::bufferVecT SoundBuffer::buffers;

SoundBuffer::SoundBuffer() : id(0), channels(0), length(0.0f)
{
    //stub method
}

SoundBuffer::~SoundBuffer()
{
    //stub method
}

#pragma pack(push, 1)
// Header copied from WavLib by Michael McTernan
struct WAVHeader
{
    //stub method
}

bool SoundBuffer::LoadVorbis(const std::string& file, std::vector<boost::uint8_t> buffer)
{
    //stub method
}

int SoundBuffer::BufferSize() const
{
    //stub method
}

void SoundBuffer::Initialise()
{
    //stub method
}

void SoundBuffer::Deinitialise()
{
    //stub method
}

size_t SoundBuffer::GetId(const std::string& name)
{
    //stub method
}

boost::shared_ptr<SoundBuffer> SoundBuffer::GetById(const size_t id)
{
    //stub method
}

size_t SoundBuffer::Count()
{
    //stub method
}

size_t SoundBuffer::AllocedSize()
{
    //stub method
}

size_t SoundBuffer::Insert(boost::shared_ptr<SoundBuffer> buffer)
{
    //stub method
}

bool SoundBuffer::AlGenBuffer(const std::string& file, ALenum format, const boost::uint8_t* data, size_t datalength, int rate)
{
    //stub method
}
