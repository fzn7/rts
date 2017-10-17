// TODO: Substitue CStringUtil with your actual class name
std::string CStringUtil::StringReplace(const std::string & text, const std::string & from, const std::string & to){}
std::string CStringUtil::StringStrip(const std::string & str, const std::string & chars){}
void CStringUtil::StringTrimInPlace(std::string & str, const std::string & ws){}
void CStringUtil::StringTrimInPlace(std::string & str){}
std::string CStringUtil::StringTrim(const std::string & str, const std::string & ws){}
std::string CStringUtil::StringTrim(const std::string & str){}
bool CStringUtil::StringToBool(std::string str){}
bool CStringUtil::StringStartsWith(const std::string & str, const char * prefix){}
bool CStringUtil::StringEndsWith(const std::string & str, const char * postfix){}
void CStringUtil::InverseOrSetBool(bool & b, const std::string & argValue, const bool inverseArg){}
void CStringUtil::InverseOrSetBool(bool & b, const std::string & argValue){}
char32_t CStringUtil::utf8::GetNextChar(const std::string & text, int & pos){}
std::string CStringUtil::utf8::FromUnicode(char32_t ch){}
std::vector<(std::uint8_t)> CStringUtil::zlib::deflate(const std::uint8_t * inflData, unsigned long inflSize){}
std::vector<(std::uint8_t)> CStringUtil::zlib::inflate(const std::uint8_t * deflData, unsigned long deflSize){}
std::vector<(std::uint8_t)> CStringUtil::zlib::deflate(const std::vector<(std::uint8_t)> & inflData){}
std::vector<(std::uint8_t)> CStringUtil::zlib::inflate(const std::vector<(std::uint8_t)> & deflData){}
