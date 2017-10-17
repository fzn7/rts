#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#if defined AVI_CAPTURING
#include "AVIGenerator.h"

#include "Game/GameVersion.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "System/Log/ILog.h"
#include "System/Platform/Threading.h"
#include "System/SpringApp.h"

#include <windows.h>

#include <boost/bind.hpp>
#include <cassert>

#if defined(_WIN32) && !defined(__MINGW32__)
#pragma message("Adding library: vfw32.lib")
#pragma comment(lib, "vfw32.lib")
#endif

bool
CAVIGenerator::initVFW()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CAVIGenerator::CAVIGenerator(const std::string& fileName,
                             int videoSizeX,
                             int videoSizeY,
                             DWORD videoFPS)
  : fileName(fileName)
  , videoFPS(videoFPS)
  , errorMsg("Ok")
  , quitAVIgen(false)
  , AVIThread(0)
  , readBuf(NULL)
  , m_lFrame(0)
  , m_pAVIFile(NULL)
  , m_pStream(NULL)
  , m_pStreamCompressed(NULL)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CAVIGenerator::~CAVIGenerator()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAVIGenerator::ReleaseAVICompressionEngine()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

HRESULT
CAVIGenerator::InitAVICompressionEngine()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CAVIGenerator::InitEngine()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

HRESULT
CAVIGenerator::AddFrame(unsigned char* pixelData)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CAVIGenerator::readOpenglPixelDataThreaded()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

__FORCE_ALIGN_STACK__
void
CAVIGenerator::AVIGeneratorThreadProc()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#endif // defined AVI_CAPTURING
