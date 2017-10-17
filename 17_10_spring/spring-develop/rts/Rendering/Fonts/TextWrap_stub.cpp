#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "TextWrap.h"
#include "FontLogSection.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/myMath.h"
#include "glFont.h"

static const char32_t ellipsisUTF16 = 0x2026;
static const std::string ellipsisUTF8 = UnicodeToUtf8(ellipsisUTF16);
static const char32_t spaceUTF16 = 0x20;

/*******************************************************************************/
/*******************************************************************************/

template<typename T>
static inline int
SkipColorCodes(const std::u8string& text, T* pos, SColor* color)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*******************************************************************************/
/*******************************************************************************/

CTextWrap::CTextWrap(const std::string& fontfile,
                     int size,
                     int outlinewidth,
                     float outlineweight)
  : CFontTexture(fontfile, size, outlinewidth, outlineweight)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline bool
IsLowerCase(const char32_t& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief GetPenalty
 * @param c character at %strpos% in the word
 * @param strpos position of c in the word
 * @param strlen total length of the word
 * @return penalty (smaller is better) to split a word at that position
 */
static inline float
GetPenalty(const char32_t& c, unsigned int strpos, unsigned int strlen)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CTextWrap::word
CTextWrap::SplitWord(CTextWrap::word& w, float wantedWidth, bool smart)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CTextWrap::AddEllipsis(std::list<line>& lines,
                       std::list<word>& words,
                       float maxWidth)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CTextWrap::WrapTextConsole(std::list<word>& words,
                           float maxWidth,
                           float maxHeight)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CTextWrap::SplitTextInWords(const std::u8string& text,
                            std::list<word>* words,
                            std::list<colorcode>* colorcodes)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CTextWrap::RemergeColorCodes(std::list<word>* words,
                             std::list<colorcode>& colorcodes) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CTextWrap::WrapInPlace(std::u8string& text,
                       float _fontSize,
                       float maxWidth,
                       float maxHeight)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::u8string
CTextWrap::Wrap(const std::u8string& text,
                float _fontSize,
                float maxWidth,
                float maxHeight)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*******************************************************************************/
/*******************************************************************************/
