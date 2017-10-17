// TODO: Substitue CConfigHandler with your actual class name
void CConfigHandler::Instantiate(const std::string configSource, const bool safemode){}
void CConfigHandler::Instantiate(const std::string configSource){}
void CConfigHandler::Instantiate(){}
void CConfigHandler::Deallocate(){}
void CConfigHandler::SetString(const std::string & key, const std::string & value, bool useOverlay){}
void CConfigHandler::SetString(const std::string & key, const std::string & value){}
std::string CConfigHandler::GetString(const std::string & key){}
bool CConfigHandler::IsSet(const std::string & key){}
bool CConfigHandler::IsReadOnly(const std::string & key){}
void CConfigHandler::Delete(const std::string & key){}
std::string CConfigHandler::GetConfigFile(){}
q(const).std::map<(std::string,std::string)> CConfigHandler::GetData(){}
std::map<(std::string,std::string)> CConfigHandler::GetDataWithoutDefaults(){}
void CConfigHandler::Update(){}
void CConfigHandler::EnableWriting(bool write){}
std::function<(f(r.q(const).std::string,r.q(const).std::string).void)> CConfigHandler::ConfigNotifyCallback(){}
void CConfigHandler::AddObserver(ConfigHandler::ConfigNotifyCallback callback, void * observer, const std::vector<(std::string)> & configs){}
void CConfigHandler::RemoveObserver(void * observer){}
bool CConfigHandler::Get(const std::string & key){}
ConfigHandler CConfigHandler::configHandler(){}
