// TODO: Substitue CPreGame with your actual class name
void CPreGame::LoadSetupscript(const std::string & script){}
void CPreGame::LoadDemo(const std::string & demo){}
void CPreGame::LoadSavefile(const std::string & save, bool usecreg){}
bool CPreGame::Draw(){}
bool CPreGame::Update(){}
int CPreGame::KeyPressed(int k, bool isRepeat){}
void CPreGame::AddGameSetupArchivesToVFS(const CGameSetup * setup, bool mapOnly){}
void CPreGame::StartServer(const std::string & setupscript){}
void CPreGame::StartServerForDemo(const std::string & demoName){}
void CPreGame::ReadDataFromDemo(const std::string & demoName){}
void CPreGame::UpdateClientNet(){}
void CPreGame::GameDataReceived(netcode::RawPacket)> packet){}
std::shared_ptr<(GameData)> CPreGame::gameData(){}
std::shared_ptr<(ClientSetup)> CPreGame::clientSetup(){}
std::string CPreGame::modArchive(){}
ILoadSaveHandler CPreGame::savefile(){}
spring_time CPreGame::connectTimer(){}
bool CPreGame::wantDemo(){}
CPreGame CPreGame::pregame(){}
