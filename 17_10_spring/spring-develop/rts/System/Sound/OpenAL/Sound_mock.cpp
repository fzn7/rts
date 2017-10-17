// TODO: Substitue CSound with your actual class name
ALCdevice_struct CSound::ALCdevice(){}
bool CSound::HasSoundItem(const std::string & name){}
size_t CSound::GetSoundId(const std::string & name){}
SoundItem CSound::GetSoundItem(size_t id){}
CSoundSource CSound::GetNextBestSource(bool lock){}
CSoundSource CSound::GetNextBestSource(){}
void CSound::UpdateListener(const float3 & campos, const float3 & camdir, const float3 & camup){}
void CSound::NewFrame(){}
void CSound::ConfigNotify(const std::string & key, const std::string & value){}
void CSound::PitchAdjust(const float newPitch){}
bool CSound::Mute(){}
bool CSound::IsMuted(){}
void CSound::Iconified(bool state){}
void CSound::PrintDebugInfo(){}
bool CSound::LoadSoundDefsImpl(const std::string & fileName, const std::string & modes){}
spring::unordered_map<(std::string,std::string)> CSound::SoundItemNameMap(){}
spring::unordered_map<(std::string,CSound::SoundItemNameMap)> CSound::SoundItemDefsMap(){}
void CSound::InitThread(int maxSounds){}
void CSound::UpdateThread(int maxSounds){}
void CSound::Update(){}
int CSound::GetMaxMonoSources(ALCdevice * device, int maxSounds){}
void CSound::UpdateListenerReal(){}
size_t CSound::MakeItemFromDef(const CSound::SoundItemNameMap & itemDef){}
size_t CSound::LoadSoundBuffer(const std::string & filename){}
float CSound::masterVolume(){}
bool CSound::mute(){}
bool CSound::appIsIconified(){}
bool CSound::pitchAdjust(){}
spring::unordered_map<(std::string,size_t)> CSound::soundMap(){}
std::vector<(p.SoundItem)> CSound::soundItems(){}
std::vector<(CSoundSource)> CSound::soundSources(){}
float3 CSound::myPos(){}
float3 CSound::camDir(){}
float3 CSound::camUp(){}
float3 CSound::prevVelocity(){}
bool CSound::listenerNeedsUpdate(){}
CSound::SoundItemNameMap CSound::defaultItemNameMap(){}
CSound::SoundItemDefsMap CSound::soundItemDefsMap(){}
spring::thread CSound::soundThread(){}
q(volatile).bool CSound::soundThreadQuit(){}
q(volatile).bool CSound::canLoadDefs(){}
