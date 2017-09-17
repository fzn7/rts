/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "OggStream.h"

#include <string.h> //memset
#include "System/FileSystem/FileHandler.h"
#include "System/Sound/SoundLog.h"
#include "ALShared.h"
#include "VorbisShared.h"


namespace VorbisCallbacks {
	size_t VorbisStreamRead(void* ptr, size_t size, size_t nmemb, void* datasource)
	{
		CFileHandler* buffer = static_cast<CFileHandler*>(datasource);
		return buffer->Read(ptr, size * nmemb);
	}

	int VorbisStreamClose(void* datasource)
	{
		CFileHandler* buffer = static_cast<CFileHandler*>(datasource);
		delete buffer;
		return 0;
	}

	int VorbisStreamSeek(void* datasource, ogg_int64_t offset, int whence)
	{
		CFileHandler* buffer = static_cast<CFileHandler*>(datasource);
		if (whence == SEEK_SET)
		{
			buffer->Seek(offset, std::ios_base::beg);
		}
		else if (whence == SEEK_CUR)
		{
			buffer->Seek(offset, std::ios_base::cur);
		}
		else if (whence == SEEK_END)
		{
			buffer->Seek(offset, std::ios_base::end);
		}

		return 0;
	}

	long VorbisStreamTell(void* datasource)
	{
		CFileHandler* buffer = static_cast<CFileHandler*>(datasource);
		return buffer->GetPos();
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
}

COggStream::~COggStream()
{
    //stub method
}

// open an Ogg stream from a given file and start playing it
void COggStream::Play(const std::string& path, float volume)
{
    //stub method
}

float COggStream::GetPlayTime() const
{
    //stub method
}

float COggStream::GetTotalTime()
{
    //stub method
}

bool COggStream::Valid() const
{
    //stub method
}

bool COggStream::IsFinished()
{
    //stub method
}

const COggStream::TagVector& COggStream::VorbisTags() const
{
    //stub method
}

// display Ogg info and comments
void COggStream::DisplayInfo()
{
    //stub method
}


// clean up the OpenAL resources
void COggStream::ReleaseBuffers()
{
    //stub method
}


// returns true if both buffers were
// filled with data from the stream
bool COggStream::StartPlaying()
{
    //stub method
}


// returns true if we're still playing
bool COggStream::IsPlaying()
{
    //stub method
}

// stops the currently playing stream
void COggStream::Stop()
{
    //stub method
}

bool COggStream::TogglePause()
{
    //stub method
}


// pop the processed buffers from the queue,
// refill them, and push them back in line
bool COggStream::UpdateBuffers()
{
    //stub method
}


void COggStream::Update()
{
    //stub method
}


// read decoded data from audio stream into PCM buffer
bool COggStream::DecodeStream(ALuint buffer)
{
    //stub method
}


// dequeue any buffers pending on source
void COggStream::EmptyBuffers()
{
    //stub method
}
