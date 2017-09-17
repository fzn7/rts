/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "TextWrap.h"
#include "glFont.h"
#include "FontLogSection.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include "System/Util.h"


static const char32_t ellipsisUTF16 = 0x2026;
static const std::string ellipsisUTF8 = UnicodeToUtf8(ellipsisUTF16);
static const char32_t spaceUTF16    = 0x20;


/*******************************************************************************/
/*******************************************************************************/

template <typename T>
static inline int SkipColorCodes(const std::u8string& text, T* pos, SColor* color)
{
    //stub method
}


/*******************************************************************************/
/*******************************************************************************/

CTextWrap::CTextWrap(const std::string& fontfile, int size, int outlinewidth, float  outlineweight)
: CFontTexture(fontfile,size,outlinewidth,outlineweight)
{
    //stub method
}


/*******************************************************************************/
/*******************************************************************************/

/**
 * @brief IsUpperCase
 * @return true if the given char is an uppercase
 */
static inline bool IsUpperCase(const char32_t& c)
{
    //stub method
}

static inline bool IsLowerCase(const char32_t& c)
{
    //stub method
}


/**
 * @brief GetPenalty
 * @param c character at %strpos% in the word
 * @param strpos position of c in the word
 * @param strlen total length of the word
 * @return penalty (smaller is better) to split a word at that position
 */
static inline float GetPenalty(const char32_t& c, unsigned int strpos, unsigned int strlen)
{
    //stub method
}


CTextWrap::word CTextWrap::SplitWord(CTextWrap::word& w, float wantedWidth, bool smart)
{
    //stub method
}


void CTextWrap::AddEllipsis(std::list<line>& lines, std::list<word>& words, float maxWidth)
{
    //stub method
}


void CTextWrap::WrapTextConsole(std::list<word>& words, float maxWidth, float maxHeight)
{
    //stub method
}


void CTextWrap::SplitTextInWords(const std::u8string& text, std::list<word>* words, std::list<colorcode>* colorcodes)
{
    //stub method
}


void CTextWrap::RemergeColorCodes(std::list<word>* words, std::list<colorcode>& colorcodes) const
{
    //stub method
}


int CTextWrap::WrapInPlace(std::u8string& text, float _fontSize, float maxWidth, float maxHeight)
{
    //stub method
}


std::u8string CTextWrap::Wrap(const std::u8string& text, float _fontSize, float maxWidth, float maxHeight)
{
    //stub method
}

/*******************************************************************************/
/*******************************************************************************/
