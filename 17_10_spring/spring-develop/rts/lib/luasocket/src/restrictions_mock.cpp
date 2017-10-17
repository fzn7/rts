// TODO: Substitue Crestrictions with your actual class name
std::string Crestrictions::hostname(){}
unsigned int Crestrictions::port(){}
bool Crestrictions::allowed(){}
bool Crestrictions::isAllowed(CLuaSocketRestrictions::RestrictType type, const char * hostname, int port){}
bool Crestrictions::isAllowed(CLuaSocketRestrictions::RestrictType type, const char * hostname){}
void Crestrictions::addIP(const char * hostname, const char * ip){}
void Crestrictions::addRule(CLuaSocketRestrictions::RestrictType type, const std::string & hostname, int port, bool allowed){}
void Crestrictions::addRules(CLuaSocketRestrictions::RestrictType type, const std::string & configstr){}
void Crestrictions::addRule(CLuaSocketRestrictions::RestrictType type, const std::string & rule){}
q(const).TSocketRule Crestrictions::getRule(CLuaSocketRestrictions::RestrictType type, const char * hostname, int port){}
q(const).char Crestrictions::ruleToStr(CLuaSocketRestrictions::RestrictType type){}
std::list<(TSocketRule)> Crestrictions::restrictions(){}
CLuaSocketRestrictions Crestrictions::luaSocketRestrictions(){}
