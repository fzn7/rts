// TODO: Substitue CSharedLib with your actual class name
SharedLib CSharedLib::Instantiate(const char * fileName){}
SharedLib CSharedLib::Instantiate(const std::string & fileName){}
void CSharedLib::Unload(){}
bool CSharedLib::LoadFailed(){}
q(const).char CSharedLib::GetLibExtension(){}
void CSharedLib::FindAddress(const char * symbol){}
void CSharedLib::reportError(const char * errorMsg, const char * fileName, int lineNumber, const char * function){}
void CSharedLib::reportError(const char * errorMsg, const char * fileName, int lineNumber){}
void CSharedLib::reportError(const char * errorMsg, const char * fileName){}
void CSharedLib::reportError(const char * errorMsg){}
