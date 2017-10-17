// TODO: Substitue CTimeProfiler with your actual class name
spring_time CTimeProfiler::GetDuration(){}
q(const).unsigned int CTimeProfiler::nameHash(){}
q(const).spring_time CTimeProfiler::startTime(){}
std::string CTimeProfiler::name(){}
q(const).bool CTimeProfiler::autoShowGraph(){}
q(const).bool CTimeProfiler::specialTimer(){}
q(const).bool CTimeProfiler::autoShowGraph(){}
spring_time CTimeProfiler::GetDuration(){}
q(const).spring_time CTimeProfiler::startTime(){}
std::string CTimeProfiler::name(){}
CTimeProfiler CTimeProfiler::GetInstance(){}
float CTimeProfiler::GetPercent(const char * name){}
void CTimeProfiler::ResetState(){}
void CTimeProfiler::Update(){}
void CTimeProfiler::UpdateRaw(){}
void CTimeProfiler::ResortProfilesRaw(){}
void CTimeProfiler::RefreshProfiles(){}
void CTimeProfiler::RefreshProfilesRaw(){}
void CTimeProfiler::PrintProfilingInfo(){}
void CTimeProfiler::AddTime(const std::string & name, const spring_time startTime, const spring_time deltaTime, const bool showGraph, const bool specialTimer, const bool threadTimer){}
void CTimeProfiler::AddTime(const std::string & name, const spring_time startTime, const spring_time deltaTime, const bool showGraph, const bool specialTimer){}
void CTimeProfiler::AddTime(const std::string & name, const spring_time startTime, const spring_time deltaTime, const bool showGraph){}
void CTimeProfiler::AddTime(const std::string & name, const spring_time startTime, const spring_time deltaTime){}
void CTimeProfiler::AddTimeRaw(const std::string & name, const spring_time startTime, const spring_time deltaTime, const bool showGraph, const bool threadTimer){}
spring::unordered_map<(std::string,CTimeProfiler::TimeRecord)> CTimeProfiler::profile(){}
std::vector<(std::pair<(std::string,CTimeProfiler::TimeRecord)>)> CTimeProfiler::sortedProfile(){}
std::vector<(std::deque<(std::pair<(spring_time,spring_time)>)>)> CTimeProfiler::profileCore(){}
spring_time CTimeProfiler::lastBigUpdate(){}
unsigned int CTimeProfiler::currentPosition(){}
unsigned int CTimeProfiler::resortProfiles(){}
std::atomic<(bool)> CTimeProfiler::enabled(){}
