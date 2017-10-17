// TODO: Substitue CDefaultIOSystem with your actual class name
bool CDefaultIOSystem::Exists(const char * pFile){}
char CDefaultIOSystem::getOsSeparator(){}
IOStream CDefaultIOSystem::Open(const char * pFile, const char * pMode){}
IOStream CDefaultIOSystem::Open(const char * pFile){}
void CDefaultIOSystem::Close(IOStream * pFile){}
bool CDefaultIOSystem::ComparePaths(const char * one, const char * second){}
std::string CDefaultIOSystem::fileName(const std::string & path){}
std::string CDefaultIOSystem::completeBaseName(const std::string & path){}
std::string CDefaultIOSystem::absolutePath(const std::string & path){}
