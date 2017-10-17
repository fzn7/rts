// TODO: Substitue CAILibraryManager with your actual class name
std::vector<(SkirmishAIKey)> CAILibraryManager::FittingSkirmishAIKeys(const SkirmishAIKey & skirmishAIKey){}
q(const).CSkirmishAILibrary CAILibraryManager::FetchSkirmishAILibrary(const SkirmishAIKey & skirmishAIKey){}
void CAILibraryManager::ReleaseSkirmishAILibrary(const SkirmishAIKey & skirmishAIKey){}
void CAILibraryManager::ReleaseEverything(){}
CAIInterfaceLibrary CAILibraryManager::FetchInterface(const AIInterfaceKey & interfaceKey){}
void CAILibraryManager::ReleaseInterface(const AIInterfaceKey & interfaceKey){}
void CAILibraryManager::GatherInterfaceLibrariesInfos(){}
void CAILibraryManager::GatherSkirmishAIsLibrariesInfos(){}
void CAILibraryManager::GatherSkirmishAIsLibrariesInfosFromLuaFiles(T_dupSkirm duplicateSkirmishAIInfoCheck){}
void CAILibraryManager::GatherSkirmishAIsLibrariesInfosFromInterfaceLibrary(T_dupSkirm duplicateSkirmishAIInfoCheck){}
void CAILibraryManager::StoreSkirmishAILibraryInfos(T_dupSkirm duplicateSkirmishAIInfoCheck, CSkirmishAILibraryInfo & skirmishAIInfo, const std::string & sourceDesc){}
void CAILibraryManager::FilterDuplicateSkirmishAILibrariesInfos(T_dupSkirm duplicateSkirmishAIInfoCheck){}
void CAILibraryManager::ClearAllInfos(){}
AIInterfaceKey CAILibraryManager::FindFittingInterfaceSpecifier(const std::string & shortName, const std::string & minVersion, const T_interfaceSpecs & specs){}
std::map<(q(const).AIInterfaceKey,std::unique_ptr<(CAIInterfaceLibrary)>)> CAILibraryManager::T_loadedInterfaces(){}
CAILibraryManager::T_loadedInterfaces CAILibraryManager::loadedAIInterfaceLibraries(){}
T_interfaceSpecs CAILibraryManager::interfaceKeys(){}
T_skirmishAIKeys CAILibraryManager::skirmishAIKeys(){}
T_interfaceInfos CAILibraryManager::interfaceInfos(){}
T_skirmishAIInfos CAILibraryManager::skirmishAIInfos(){}
T_dupInt CAILibraryManager::duplicateInterfaceInfos(){}
T_dupSkirm CAILibraryManager::duplicateSkirmishAIInfos(){}
