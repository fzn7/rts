// TODO: Substitue CKeyCodes with your actual class name
void CKeyCodes::Reset(){}
int CKeyCodes::GetCode(const std::string & name){}
std::string CKeyCodes::GetName(int code){}
std::string CKeyCodes::GetDefaultName(int code){}
bool CKeyCodes::AddKeySymbol(const std::string & name, int code){}
bool CKeyCodes::IsModifier(int code){}
bool CKeyCodes::IsPrintable(int code){}
void CKeyCodes::PrintNameToCode(){}
void CKeyCodes::PrintCodeToName(){}
void CKeyCodes::SaveUserKeySymbols(FILE * file){}
bool CKeyCodes::IsValidLabel(const std::string & label){}
void CKeyCodes::AddPair(const std::string & name, const int code, const bool printable){}
void CKeyCodes::AddPair(const std::string & name, const int code){}
std::map<(std::string,int)> CKeyCodes::nameToCode(){}
std::map<(int,std::string)> CKeyCodes::codeToName(){}
std::map<(std::string,int)> CKeyCodes::defaultNameToCode(){}
std::map<(int,std::string)> CKeyCodes::defaultCodeToName(){}
std::set<(int)> CKeyCodes::printableCodes(){}
CKeyCodes CKeyCodes::keyCodes(){}
