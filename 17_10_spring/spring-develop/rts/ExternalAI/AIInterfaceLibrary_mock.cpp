// TODO: Substitue CAIInterfaceLibrary with your actual class name
AIInterfaceKey CAIInterfaceLibrary::GetKey(){}
LevelOfSupport CAIInterfaceLibrary::GetLevelOfSupportFor(const std::string & engineVersionString, int engineVersionNumber){}
int CAIInterfaceLibrary::GetSkirmishAICount(){}
std::map<(std::string,std::string)> CAIInterfaceLibrary::GetSkirmishAIInfos(int aiIndex){}
std::string CAIInterfaceLibrary::GetSkirmishAIOptions(int aiIndex){}
int CAIInterfaceLibrary::GetLoadCount(){}
q(const).CSkirmishAILibrary CAIInterfaceLibrary::FetchSkirmishAILibrary(const CSkirmishAILibraryInfo & aiInfo){}
int CAIInterfaceLibrary::ReleaseSkirmishAILibrary(const SkirmishAIKey & sAISpecifier){}
int CAIInterfaceLibrary::GetSkirmishAILibraryLoadCount(const SkirmishAIKey & sAISpecifier){}
int CAIInterfaceLibrary::ReleaseAllSkirmishAILibraries(){}
void CAIInterfaceLibrary::InitStatic(){}
void CAIInterfaceLibrary::ReleaseStatic(){}
void CAIInterfaceLibrary::reportInterfaceFunctionError(const std::string & libFileName, const std::string & functionName){}
int CAIInterfaceLibrary::InitializeFromLib(const std::string & libFilePath){}
std::string CAIInterfaceLibrary::FindLibFile(){}
std::string CAIInterfaceLibrary::libFilePath(){}
SSkirmishAILibrary CAIInterfaceLibrary::EmptyInterfaceLib(){}
int CAIInterfaceLibrary::interfaceId(){}
bool CAIInterfaceLibrary::initialized(){}
SharedLib CAIInterfaceLibrary::sharedLib(){}
SAIInterfaceCallback CAIInterfaceLibrary::callback(){}
SAIInterfaceLibrary CAIInterfaceLibrary::sAIInterfaceLibrary(){}
q(const).CAIInterfaceLibraryInfo CAIInterfaceLibrary::info(){}
std::map<(q(const).SkirmishAIKey,CSkirmishAILibrary)> CAIInterfaceLibrary::loadedSkirmishAILibraries(){}
std::map<(q(const).SkirmishAIKey,int)> CAIInterfaceLibrary::skirmishAILoadCount(){}
q(const).int CAIInterfaceLibrary::MAX_INFOS(){}
