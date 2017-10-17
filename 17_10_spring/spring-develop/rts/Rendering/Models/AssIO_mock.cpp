// TODO: Substitue CAssIO with your actual class name
CFileHandler CAssIO::file(){}
size_t CAssIO::Read(void * pvBuffer, size_t pSize, size_t pCount){}
size_t CAssIO::Write(const void * pvBuffer, size_t pSize, size_t pCount){}
aiReturn CAssIO::Seek(size_t pOffset, aiOrigin pOrigin){}
size_t CAssIO::Tell(){}
size_t CAssIO::FileSize(){}
void CAssIO::Flush(){}
bool CAssIO::Exists(const char * pFile){}
char CAssIO::getOsSeparator(){}
bool CAssIO::ComparePaths(const std::string & one, const std::string & second){}
Assimp::IOStream CAssIO::Open(const char * pFile, const char * pMode){}
Assimp::IOStream CAssIO::Open(const char * pFile){}
void CAssIO::Close(Assimp::IOStream * pFile){}
