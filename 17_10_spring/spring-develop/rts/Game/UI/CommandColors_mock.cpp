// TODO: Substitue CCommandColors with your actual class name
bool CCommandColors::LoadConfigFromFile(const std::string & filename){}
bool CCommandColors::LoadConfigFromString(const std::string & cfg){}
void CCommandColors::SetCustomCmdData(int cmdID, int cmdIconID, const float color, bool showArea){}
void CCommandColors::ClearCustomCmdData(int cmdID){}
q(const).CCommandColors::DrawData CCommandColors::GetCustomCmdData(int cmdID){}
q(const).float CCommandColors::unitBox(){}
q(const).float CCommandColors::buildBox(){}
q(const).float CCommandColors::allyBuildBox(){}
q(const).float CCommandColors::mouseBox(){}
q(const).float CCommandColors::start(){}
q(const).float CCommandColors::restart(){}
q(const).float CCommandColors::stop(){}
q(const).float CCommandColors::wait(){}
q(const).float CCommandColors::build(){}
q(const).float CCommandColors::move(){}
q(const).float CCommandColors::attack(){}
q(const).float CCommandColors::fight(){}
q(const).float CCommandColors::guard(){}
q(const).float CCommandColors::patrol(){}
q(const).float CCommandColors::capture(){}
q(const).float CCommandColors::repair(){}
q(const).float CCommandColors::reclaim(){}
q(const).float CCommandColors::restore(){}
q(const).float CCommandColors::resurrect(){}
q(const).float CCommandColors::load(){}
q(const).float CCommandColors::unload(){}
q(const).float CCommandColors::deathWait(){}
q(const).float CCommandColors::rangeAttack(){}
q(const).float CCommandColors::rangeBuild(){}
q(const).float CCommandColors::rangeRadar(){}
q(const).float CCommandColors::rangeSonar(){}
q(const).float CCommandColors::rangeSeismic(){}
q(const).float CCommandColors::rangeJammer(){}
q(const).float CCommandColors::rangeSonarJammer(){}
q(const).float CCommandColors::rangeShield(){}
q(const).float CCommandColors::rangeDecloak(){}
q(const).float CCommandColors::rangeExtract(){}
q(const).float CCommandColors::rangeKamikaze(){}
q(const).float CCommandColors::rangeSelfDestruct(){}
q(const).float CCommandColors::rangeInterceptorOn(){}
q(const).float CCommandColors::rangeInterceptorOff(){}
std::map<(std::string,int)> CCommandColors::colorNames(){}
float CCommandColors::colors(){}
bool CCommandColors::alwaysDrawQueue(){}
float CCommandColors::queueIconAlpha(){}
float CCommandColors::queueIconScale(){}
bool CCommandColors::useQueueIcons(){}
bool CCommandColors::useColorRestarts(){}
bool CCommandColors::useRestartColor(){}
float CCommandColors::restartAlpha(){}
float CCommandColors::queuedLineWidth(){}
unsigned int CCommandColors::queuedBlendSrc(){}
unsigned int CCommandColors::queuedBlendDst(){}
unsigned int CCommandColors::stipplePattern(){}
unsigned int CCommandColors::stippleFactor(){}
float CCommandColors::stippleSpeed(){}
float CCommandColors::selectedLineWidth(){}
unsigned int CCommandColors::selectedBlendSrc(){}
unsigned int CCommandColors::selectedBlendDst(){}
bool CCommandColors::buildBoxesOnShift(){}
float CCommandColors::mouseBoxLineWidth(){}
unsigned int CCommandColors::mouseBoxBlendSrc(){}
unsigned int CCommandColors::mouseBoxBlendDst(){}
float CCommandColors::unitBoxLineWidth(){}
std::map<(int,CCommandColors::DrawData)> CCommandColors::customCmds_type(){}
CCommandColors::customCmds_type CCommandColors::customCmds(){}
CCommandColors CCommandColors::cmdColors(){}
