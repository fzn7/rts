// TODO: Substitue CTdfParser with your actual class name
spring::unordered_map<(std::string,std::string)> CTdfParser::valueMap_t(){}
spring::unordered_map<(std::string,p.TdfParser::TdfSection)> CTdfParser::sectionsMap_t(){}
void CTdfParser::print(std::ostream & out){}
void CTdfParser::LoadFile(const std::string & file){}
void CTdfParser::LoadBuffer(const char * buffer, size_t size){}
std::string CTdfParser::SGetValueDef(const std::string & defaultValue, const std::string & location){}
bool CTdfParser::SGetValue(std::string & value, const std::string & location){}
bool CTdfParser::GetValue(bool & val, const std::string & location){}
q(const).TdfParser::valueMap_t CTdfParser::GetAllValues(const std::string & location){}
std::vector<(std::string)> CTdfParser::GetSectionList(const std::string & location){}
bool CTdfParser::SectionExist(const std::string & location){}
TdfParser::TdfSection CTdfParser::root_section(){}
std::string CTdfParser::filename(){}
std::vector<(std::string)> CTdfParser::GetLocationVector(const std::string & location){}
void CTdfParser::ParseLuaTable(const LuaTable & table, TdfParser::TdfSection * currentSection){}
void CTdfParser::ParseBuffer(const char * buf, size_t size){}
float3 CTdfParser::GetFloat3(float3 def, const std::string & location){}
