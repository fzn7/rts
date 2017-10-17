// TODO: Substitue CTextWrap with your actual class name
int CTextWrap::WrapInPlace(std::string & text, float fontSize, float maxWidth, float maxHeight){}
int CTextWrap::WrapInPlace(std::string & text, float fontSize, float maxWidth){}
std::string CTextWrap::Wrap(const std::string & text, float fontSize, float maxWidth, float maxHeight){}
std::string CTextWrap::Wrap(const std::string & text, float fontSize, float maxWidth){}
q(const).char8_t CTextWrap::ColorCodeIndicator(){}
q(const).char8_t CTextWrap::ColorResetIndicator(){}
float CTextWrap::GetTextWidth(const std::string & text){}
word CTextWrap::SplitWord(word & w, float wantedWidth, bool smart){}
word CTextWrap::SplitWord(word & w, float wantedWidth){}
void CTextWrap::SplitTextInWords(const std::u8string & text, std::list<(word)> * words, std::list<(colorcode)> * colorcodes){}
void CTextWrap::RemergeColorCodes(std::list<(word)> * words, std::list<(colorcode)> & colorcodes){}
void CTextWrap::AddEllipsis(std::list<(line)> & lines, std::list<(word)> & words, float maxWidth){}
void CTextWrap::WrapTextConsole(std::list<(word)> & words, float maxWidth, float maxHeight){}
int CTextWrap::WrapInPlace(std::u8string & text, float fontSize, float maxWidth, float maxHeight){}
int CTextWrap::WrapInPlace(std::u8string & text, float fontSize, float maxWidth){}
std::u8string CTextWrap::Wrap(const std::u8string & text, float fontSize, float maxWidth, float maxHeight){}
std::u8string CTextWrap::Wrap(const std::u8string & text, float fontSize, float maxWidth){}
