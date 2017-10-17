// TODO: Substitue CArchiveLoader with your actual class name
CArchiveLoader CArchiveLoader::GetInstance(){}
bool CArchiveLoader::IsArchiveFile(const std::string & fileName){}
IArchive CArchiveLoader::OpenArchive(const std::string & fileName, const std::string & type){}
IArchive CArchiveLoader::OpenArchive(const std::string & fileName){}
void CArchiveLoader::AddFactory(IArchiveFactory * archiveFactory){}
std::map<(std::string,p.IArchiveFactory)> CArchiveLoader::archiveFactories(){}
