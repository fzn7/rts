// TODO: Substitue CKeySet with your actual class name
void CKeySet::Reset(){}
void CKeySet::SetAnyBit(){}
void CKeySet::ClearModifiers(){}
bool CKeySet::Parse(const std::string & token, bool showerror){}
bool CKeySet::Parse(const std::string & token){}
std::string CKeySet::GetString(bool useDefaultKeysym){}
bool CKeySet::IsPureModifier(){}
bool CKeySet::ParseModifier(std::string & s, const std::string & token, const std::string & abbr){}
int CKeySet::key(){}
unsigned char CKeySet::modifiers(){}
std::deque<(spring_time)> CKeySet::times(){}
void CKeySet::push_back(const int key, const spring_time t, const bool isRepeat){}
