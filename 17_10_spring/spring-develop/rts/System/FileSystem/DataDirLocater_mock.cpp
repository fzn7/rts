// TODO: Substitue CDataDirLocater with your actual class name
std::string CDataDirLocater::path(){}
bool CDataDirLocater::writable(){}
DataDirLocater CDataDirLocater::GetInstance(){}
void CDataDirLocater::FreeInstance(){}
void CDataDirLocater::LocateDataDirs(){}
void CDataDirLocater::Check(){}
q(const).std::vector<(DataDir)> CDataDirLocater::GetDataDirs(){}
std::string CDataDirLocater::GetWriteDirPath(){}
std::vector<(std::string)> CDataDirLocater::GetDataDirPaths(){}
bool CDataDirLocater::IsPortableMode(){}
void CDataDirLocater::UpdateIsolationModeByEnvVar(){}
void CDataDirLocater::ChangeCwdToWriteDir(){}
void CDataDirLocater::AddCurWorkDir(){}
void CDataDirLocater::AddPortableDir(){}
void CDataDirLocater::AddHomeDirs(){}
void CDataDirLocater::AddEtcDirs(){}
void CDataDirLocater::AddShareDirs(){}
std::string CDataDirLocater::SubstEnvVars(const std::string & in){}
void CDataDirLocater::AddDirs(const std::string & dirs){}
void CDataDirLocater::AddDir(const std::string & dir){}
bool CDataDirLocater::DeterminePermissions(DataDir * dataDir){}
void CDataDirLocater::FilterUsableDataDirs(){}
bool CDataDirLocater::IsWriteableDir(DataDir * dataDir){}
void CDataDirLocater::FindWriteableDataDir(){}
bool CDataDirLocater::IsInstallDirDataDir(){}
bool CDataDirLocater::LooksLikeMultiVersionDataDir(const std::string & dirPath){}
bool CDataDirLocater::isolationMode(){}
std::string CDataDirLocater::isolationModeDir(){}
std::string CDataDirLocater::forcedWriteDir(){}
std::vector<(DataDir)> CDataDirLocater::dataDirs(){}
q(const).DataDir CDataDirLocater::writeDir(){}
