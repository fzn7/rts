// TODO: Substitue CLoadScreen with your actual class name
void CLoadScreen::SetLoadMessage(const std::string & text, bool replace_lastline){}
void CLoadScreen::SetLoadMessage(const std::string & text){}
bool CLoadScreen::Init(){}
void CLoadScreen::Kill(){}
void CLoadScreen::CreateInstance(const std::string & mapName, const std::string & modName, ILoadSaveHandler * saveFile){}
void CLoadScreen::DeleteInstance(){}
bool CLoadScreen::Draw(){}
bool CLoadScreen::Update(){}
void CLoadScreen::ResizeEvent(){}
int CLoadScreen::KeyReleased(int k){}
int CLoadScreen::KeyPressed(int k, bool isRepeat){}
void CLoadScreen::RandomStartPicture(const std::string & sidePref){}
void CLoadScreen::LoadStartPicture(const std::string & picture){}
void CLoadScreen::UnloadStartPicture(){}
CLoadScreen CLoadScreen::singleton(){}
std::string CLoadScreen::oldLoadMessages(){}
std::string CLoadScreen::curLoadMessage(){}
std::string CLoadScreen::mapName(){}
std::string CLoadScreen::modName(){}
ILoadSaveHandler CLoadScreen::saveFile(){}
spring::recursive_mutex CLoadScreen::mutex(){}
spring::thread CLoadScreen::netHeartbeatThread(){}
COffscreenGLThread CLoadScreen::gameLoadThread(){}
bool CLoadScreen::mtLoading(){}
bool CLoadScreen::showMessages(){}
unsigned int CLoadScreen::startupTexture(){}
float CLoadScreen::aspectRatio(){}
spring_time CLoadScreen::last_draw(){}
