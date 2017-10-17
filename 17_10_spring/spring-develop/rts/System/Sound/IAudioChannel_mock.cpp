// TODO: Substitue CIAudioChannel with your actual class name
void CIAudioChannel::Enable(bool newState){}
void CIAudioChannel::SetVolume(float newVolume){}
void CIAudioChannel::PlaySample(size_t id, float volume){}
void CIAudioChannel::PlaySample(size_t id){}
void CIAudioChannel::PlaySample(size_t id, const float3 & p, float volume){}
void CIAudioChannel::PlaySample(size_t id, const float3 & p){}
void CIAudioChannel::PlaySample(size_t id, const float3 & p, const float3 & velocity, float volume){}
void CIAudioChannel::PlaySample(size_t id, const float3 & p, const float3 & velocity){}
void CIAudioChannel::PlaySample(size_t id, const CWorldObject * p, float volume){}
void CIAudioChannel::PlaySample(size_t id, const CWorldObject * p){}
void CIAudioChannel::PlayRandomSample(const GuiSoundSet & soundSet, const CWorldObject * obj){}
void CIAudioChannel::PlayRandomSample(const GuiSoundSet & soundSet, const float3 & pos){}
void CIAudioChannel::StreamPlay(const std::string & path, float volume, bool enqueue){}
void CIAudioChannel::StreamPlay(const std::string & path, float volume){}
void CIAudioChannel::StreamPlay(const std::string & path){}
void CIAudioChannel::StreamStop(){}
void CIAudioChannel::StreamPause(){}
float CIAudioChannel::StreamGetTime(){}
float CIAudioChannel::StreamGetPlayTime(){}
void CIAudioChannel::FindSourceAndPlay(size_t id, const float3 & p, const float3 & velocity, float volume, bool relative){}
void CIAudioChannel::SoundSourceFinished(CSoundSource * sndSource){}
float CIAudioChannel::volume(){}
bool CIAudioChannel::enabled(){}
unsigned int CIAudioChannel::emitsPerFrame(){}
unsigned int CIAudioChannel::emitsThisFrame(){}
unsigned int CIAudioChannel::maxConcurrentSources(){}
