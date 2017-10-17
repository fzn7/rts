// TODO: Substitue CInfoConsole with your actual class name
void CInfoConsole::Update(){}
void CInfoConsole::Draw(){}
void CInfoConsole::PushNewLinesToEventHandler(){}
void CInfoConsole::RecordLogMessage(int level, const std::string & section, const std::string & text){}
void CInfoConsole::LastMessagePosition(const float3 & pos){}
q(const).float3 CInfoConsole::GetMsgPos(const float3 & defaultPos){}
q(const).float3 CInfoConsole::GetMsgPos(){}
bool CInfoConsole::enabled(){}
q(const).size_t CInfoConsole::maxLastMsgPos(){}
q(const).size_t CInfoConsole::maxRawLines(){}
int CInfoConsole::GetRawLines(std::deque<(CInfoConsole::RawLine)> & copy){}
std::list<(float3)> CInfoConsole::lastMsgPositions(){}
std::list<(float3)>::iterator CInfoConsole::lastMsgIter(){}
std::deque<(CInfoConsole::RawLine)> CInfoConsole::rawData(){}
std::deque<(InfoLine)> CInfoConsole::data(){}
size_t CInfoConsole::newLines(){}
int CInfoConsole::rawId(){}
spring::recursive_mutex CInfoConsole::infoConsoleMutex(){}
int CInfoConsole::lifetime(){}
float CInfoConsole::xpos(){}
float CInfoConsole::ypos(){}
float CInfoConsole::width(){}
float CInfoConsole::height(){}
float CInfoConsole::fontScale(){}
float CInfoConsole::fontSize(){}
size_t CInfoConsole::maxLines(){}
CInfoConsole CInfoConsole::infoConsole(){}
