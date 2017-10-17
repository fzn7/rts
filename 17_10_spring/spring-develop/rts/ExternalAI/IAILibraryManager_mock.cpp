// TODO: Substitue CIAILibraryManager with your actual class name
std::set<(AIInterfaceKey)> CIAILibraryManager::T_interfaceSpecs(){}
std::set<(SkirmishAIKey)> CIAILibraryManager::T_skirmishAIKeys(){}
q(const).IAILibraryManager::T_interfaceSpecs CIAILibraryManager::GetInterfaceKeys(){}
q(const).IAILibraryManager::T_skirmishAIKeys CIAILibraryManager::GetSkirmishAIKeys(){}
std::map<(q(const).AIInterfaceKey,CAIInterfaceLibraryInfo)> CIAILibraryManager::T_interfaceInfos(){}
std::map<(q(const).SkirmishAIKey,CSkirmishAILibraryInfo)> CIAILibraryManager::T_skirmishAIInfos(){}
q(const).IAILibraryManager::T_interfaceInfos CIAILibraryManager::GetInterfaceInfos(){}
q(const).IAILibraryManager::T_skirmishAIInfos CIAILibraryManager::GetSkirmishAIInfos(){}
std::map<(q(const).AIInterfaceKey,std::set<(std::string)>)> CIAILibraryManager::T_dupInt(){}
std::map<(q(const).SkirmishAIKey,std::set<(std::string)>)> CIAILibraryManager::T_dupSkirm(){}
q(const).IAILibraryManager::T_dupInt CIAILibraryManager::GetDuplicateInterfaceInfos(){}
q(const).IAILibraryManager::T_dupSkirm CIAILibraryManager::GetDuplicateSkirmishAIInfos(){}
SkirmishAIKey CIAILibraryManager::ResolveSkirmishAIKey(const SkirmishAIKey & skirmishAIKey){}
q(const).CSkirmishAILibrary CIAILibraryManager::FetchSkirmishAILibrary(const SkirmishAIKey & skirmishAIKey){}
void CIAILibraryManager::ReleaseSkirmishAILibrary(const SkirmishAIKey & skirmishAIKey){}
IAILibraryManager CIAILibraryManager::GetInstance(){}
void CIAILibraryManager::Destroy(){}
void CIAILibraryManager::OutputAIInterfacesInfo(){}
void CIAILibraryManager::OutputSkirmishAIInfo(){}
std::vector<(SkirmishAIKey)> CIAILibraryManager::FittingSkirmishAIKeys(const SkirmishAIKey & skirmishAIKey){}
int CIAILibraryManager::VersionCompare(const std::string & version1, const std::string & version2){}
IAILibraryManager CIAILibraryManager::gAILibraryManager(){}
