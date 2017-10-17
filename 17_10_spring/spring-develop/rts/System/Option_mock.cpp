// TODO: Substitue COption with your actual class name
std::string COption::key(){}
std::string COption::name(){}
std::string COption::desc(){}
std::string COption::key(){}
std::string COption::scope(){}
std::string COption::name(){}
std::string COption::desc(){}
std::string COption::section(){}
std::string COption::style(){}
std::string COption::type(){}
OptionType COption::typeCode(){}
bool COption::boolDef(){}
float COption::numberDef(){}
float COption::numberMin(){}
float COption::numberMax(){}
float COption::numberStep(){}
std::string COption::stringDef(){}
int COption::stringMaxLen(){}
std::string COption::listDef(){}
std::vector<(OptionListItem)> COption::list(){}
std::string COption::option_getDefString(const Option & option){}
void COption::option_parseOptions(std::vector<(Option)> & options, const std::string & fileName, const std::string & fileModes, const std::string & accessModes, std::set<(std::string)> * optionsSet){}
void COption::option_parseOptions(std::vector<(Option)> & options, const std::string & fileName, const std::string & fileModes, const std::string & accessModes){}
void COption::option_parseOptions(std::vector<(Option)> & options, const std::string & fileName, const std::string & fileModes){}
void COption::option_parseOptions(std::vector<(Option)> & options, const std::string & fileName){}
void COption::option_parseOptionsLuaString(std::vector<(Option)> & options, const std::string & optionsLuaString, const std::string & accessModes, std::set<(std::string)> * optionsSet){}
void COption::option_parseOptionsLuaString(std::vector<(Option)> & options, const std::string & optionsLuaString, const std::string & accessModes){}
void COption::option_parseOptionsLuaString(std::vector<(Option)> & options, const std::string & optionsLuaString){}
void COption::option_parseMapOptions(std::vector<(Option)> & options, const std::string & fileName, const std::string & mapName, const std::string & fileModes, const std::string & accessModes, std::set<(std::string)> * optionsSet){}
void COption::option_parseMapOptions(std::vector<(Option)> & options, const std::string & fileName, const std::string & mapName, const std::string & fileModes, const std::string & accessModes){}
void COption::option_parseMapOptions(std::vector<(Option)> & options, const std::string & fileName, const std::string & mapName, const std::string & fileModes){}
void COption::option_parseMapOptions(std::vector<(Option)> & options, const std::string & fileName, const std::string & mapName){}
