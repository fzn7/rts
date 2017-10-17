// TODO: Substitue CInfo with your actual class name
std::string CInfo::key(){}
std::string CInfo::desc(){}
InfoValueType CInfo::valueType(){}
InfoItem::Value CInfo::value(){}
std::string CInfo::valueTypeString(){}
std::string CInfo::GetValueAsString(const bool convBooltoInt){}
std::string CInfo::GetValueAsString(){}
void CInfo::info_convertToStringValue(InfoItem * infoItem){}
q(const).char CInfo::info_convertTypeToString(InfoValueType infoValueType){}
void CInfo::info_parseInfo(std::vector<(InfoItem)> & options, const std::string & fileName, const std::string & fileModes, const std::string & accessModes, std::set<(std::string)> * infoSet){}
void CInfo::info_parseInfo(std::vector<(InfoItem)> & options, const std::string & fileName, const std::string & fileModes, const std::string & accessModes){}
void CInfo::info_parseInfo(std::vector<(InfoItem)> & options, const std::string & fileName, const std::string & fileModes){}
void CInfo::info_parseInfo(std::vector<(InfoItem)> & options, const std::string & fileName){}
std::vector<(InfoItem)> CInfo::info_parseInfo(const std::string & fileName, const std::string & fileModes, const std::string & accessModes, std::set<(std::string)> * infoSet){}
std::vector<(InfoItem)> CInfo::info_parseInfo(const std::string & fileName, const std::string & fileModes, const std::string & accessModes){}
std::vector<(InfoItem)> CInfo::info_parseInfo(const std::string & fileName, const std::string & fileModes){}
std::vector<(InfoItem)> CInfo::info_parseInfo(const std::string & fileName){}
