// TODO: Substitue CISound with your actual class name
ISound CISound::singleton(){}
void CISound::Initialize(bool forceNullSound){}
void CISound::Initialize(){}
void CISound::Shutdown(){}
bool CISound::HasSoundItem(const std::string & name){}
size_t CISound::GetSoundId(const std::string & name){}
SoundItem CISound::GetSoundItem(size_t id){}
CSoundSource CISound::GetNextBestSource(bool lock){}
CSoundSource CISound::GetNextBestSource(){}
void CISound::UpdateListener(const float3 & camPos, const float3 & camDir, const float3 & camUp){}
void CISound::NewFrame(){}
void CISound::ConfigNotify(const std::string & key, const std::string & value){}
void CISound::PitchAdjust(const float newPitch){}
bool CISound::Mute(){}
bool CISound::IsMuted(){}
bool CISound::ChangeOutput(bool forceNullSound){}
bool CISound::ChangeOutput(){}
void CISound::Iconified(bool state){}
void CISound::PrintDebugInfo(){}
bool CISound::SoundThreadQuit(){}
bool CISound::CanLoadSoundDefs(){}
bool CISound::LoadSoundDefs(const std::string & fileName, const std::string & modes){}
q(const).float3 CISound::GetListenerPos(){}
unsigned int CISound::numEmptyPlayRequests(){}
unsigned int CISound::numAbortedPlays(){}
bool CISound::LoadSoundDefsImpl(const std::string & fileName, const std::string & modes){}
bool CISound::IsNullAudio(){}
