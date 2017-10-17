// TODO: Substitue CBufferedArchive with your actual class name
bool CBufferedArchive::GetFile(unsigned int fid, std::vector<(std::uint8_t)> & buffer){}
bool CBufferedArchive::GetFileImpl(unsigned int fid, std::vector<(std::uint8_t)> & buffer){}
spring::mutex CBufferedArchive::archiveLock(){}
std::vector<(CBufferedArchive::FileBuffer)> CBufferedArchive::cache(){}
bool CBufferedArchive::caching(){}
