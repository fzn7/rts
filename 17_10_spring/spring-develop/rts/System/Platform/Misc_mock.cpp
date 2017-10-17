// TODO: Substitue CMisc with your actual class name
q(const).std::string CMisc::Platform::GetOrigCWD(){}
q(const).std::string CMisc::Platform::SetOrigCWD(){}
std::string CMisc::Platform::GetUserDir(){}
std::string CMisc::Platform::GetProcessExecutableFile(){}
std::string CMisc::Platform::GetProcessExecutablePath(){}
std::string CMisc::Platform::GetModuleFile(std::string moduleName){}
std::string CMisc::Platform::GetModuleFile(){}
std::string CMisc::Platform::GetModulePath(const std::string & moduleName){}
std::string CMisc::Platform::GetModulePath(){}
std::string CMisc::Platform::GetOS(){}
std::string CMisc::Platform::GetOSFamily(){}
std::string CMisc::Platform::GetWordSizeStr(){}
bool CMisc::Platform::Is64Bit(){}
bool CMisc::Platform::Is32BitEmulation(){}
bool CMisc::Platform::IsRunningInGDB(){}
unsigned int CMisc::Platform::NativeWordSize(){}
unsigned int CMisc::Platform::SystemWordSize(){}
unsigned int CMisc::Platform::DequeChunkSize(){}
std::string CMisc::Platform::ExecuteProcess(const std::string & file, std::vector<(std::string)> args, bool asSubprocess){}
std::string CMisc::Platform::ExecuteProcess(const std::string & file, std::vector<(std::string)> args){}
