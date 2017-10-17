// TODO: Substitue CVFSHandler with your actual class name
CVFSHandler::Section CVFSHandler::GetModeSection(char mode){}
CVFSHandler::Section CVFSHandler::GetModTypeSection(int modtype){}
bool CVFSHandler::FileExists(const std::string & filePath, CVFSHandler::Section section){}
bool CVFSHandler::LoadFile(const std::string & filePath, std::vector<(std::uint8_t)> & buffer, CVFSHandler::Section section){}
std::vector<(std::string)> CVFSHandler::GetFilesInDir(const std::string & dir, CVFSHandler::Section section){}
std::vector<(std::string)> CVFSHandler::GetDirsInDir(const std::string & dir, CVFSHandler::Section section){}
bool CVFSHandler::AddArchive(const std::string & archiveName, bool overwrite){}
bool CVFSHandler::AddArchiveWithDeps(const std::string & archiveName, bool overwrite){}
bool CVFSHandler::RemoveArchive(const std::string & archiveName){}
std::array<(std::map<(std::string,CVFSHandler::FileData)>,CVFSHandler::Section::Count)> CVFSHandler::files(){}
std::map<(std::string,p.IArchive)> CVFSHandler::archives(){}
std::string CVFSHandler::GetNormalizedPath(const std::string & rawPath){}
q(const).CVFSHandler::FileData CVFSHandler::GetFileData(const std::string & normalizedFilePath, CVFSHandler::Section section){}
CVFSHandler CVFSHandler::vfsHandler(){}
