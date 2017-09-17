#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "glFont.h"
#include "FontLogSection.h"
#include <stdarg.h>
#include <stdexcept>

#include "Game/Camera.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "System/Color.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/myMath.h"

#undef GetCharWidth // winapi.h

bool CglFont::threadSafety = false;

/*******************************************************************************/
/*******************************************************************************/

CglFont* font = nullptr;
CglFont* smallFont = nullptr;

static const unsigned char nullChar = 0;
static const float4 white(1.00f, 1.00f, 1.00f, 0.95f);
static const float4 darkOutline(0.05f, 0.05f, 0.05f, 0.95f);
static const float4 lightOutline(0.95f, 0.95f, 0.95f, 0.8f);

static const float darkLuminosity = 0.05 +
                                    0.2126f * std::pow(darkOutline[0], 2.2) +
                                    0.7152f * std::pow(darkOutline[1], 2.2) +
                                    0.0722f * std::pow(darkOutline[2], 2.2);

/*******************************************************************************/
/*******************************************************************************/

CglFont::CglFont(const std::string& fontfile,
                 int size,
                 int _outlinewidth,
                 float _outlineweight)
  : CTextWrap(fontfile, size, _outlinewidth, _outlineweight)
  , fontPath(fontfile)
  , inBeginEnd(false)
  , autoOutlineColor(true)
  , setColor(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CglFont*
CglFont::LoadFont(const std::string& fontFile,
                  int size,
                  int outlinewidth,
                  float outlineweight)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CglFont::~CglFont() {}

/*******************************************************************************/
/*******************************************************************************/

template<typename T>
static inline int
SkipColorCodes(const std::u8string& text, T pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

template<typename T>
static inline bool
SkipColorCodesAndNewLines(const std::u8string& text,
                          T* pos,
                          float4* color,
                          bool* colorChanged,
                          int* skippedLines,
                          float4* colorReset)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline void
TextStripCallback(void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*******************************************************************************/
/*******************************************************************************/

std::string
CglFont::StripColorCodes_(const std::u8string& text)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CglFont::GetCharacterWidth(const char32_t c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CglFont::GetTextWidth_(const std::u8string& text)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CglFont::GetTextHeight_(const std::u8string& text,
                        float* descender,
                        int* numLines)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CglFont::GetTextNumLines_(const std::u8string& text)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::list<std::string>
CglFont::SplitIntoLines(const std::u8string& text)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*******************************************************************************/
/*******************************************************************************/

void
CglFont::SetAutoOutlineColor(bool enable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CglFont::SetTextColor(const float4* color)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CglFont::SetOutlineColor(const float4* color)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CglFont::SetColors(const float4* _textColor, const float4* _outlineColor)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const float4*
CglFont::ChooseOutlineColor(const float4& textColor)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*******************************************************************************/
/*******************************************************************************/

void
CglFont::Begin(const bool immediate, const bool resetColors)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CglFont::End()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*******************************************************************************/
/*******************************************************************************/

void
CglFont::RenderString(float x,
                      float y,
                      const float& scaleX,
                      const float& scaleY,
                      const std::string& str)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CglFont::RenderStringShadow(float x,
                            float y,
                            const float& scaleX,
                            const float& scaleY,
                            const std::string& str)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CglFont::RenderStringOutlined(float x,
                              float y,
                              const float& scaleX,
                              const float& scaleY,
                              const std::string& str)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CglFont::glWorldPrint(const float3& p, const float size, const std::string& str)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CglFont::glPrint(float x,
                 float y,
                 float s,
                 const int options,
                 const std::string& text)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CglFont::glPrintTable(float x,
                      float y,
                      float s,
                      const int options,
                      const std::string& text)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CglFont::glFormat(float x,
                  float y,
                  float s,
                  const int options,
                  const char* fmt,
                  ...)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
