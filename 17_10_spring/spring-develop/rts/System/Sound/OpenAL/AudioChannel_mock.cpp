// TODO: Substitue CAudioChannel with your actual class name
std::pair<(std::string,float)> CAudioChannel::StreamQueueItem(){}
void CAudioChannel::Enable(bool newState){}
void CAudioChannel::SetVolume(float newVolume){}
void CAudioChannel::PlaySample(size_t id, float volume){}
void CAudioChannel::PlaySample(size_t id){}
void CAudioChannel::PlaySample(size_t id, const float3 & pos, float volume){}
void CAudioChannel::PlaySample(size_t id, const float3 & pos){}
void CAudioChannel::PlaySample(size_t id, const float3 & pos, const float3 & velocity, float volume){}
void CAudioChannel::PlaySample(size_t id, const float3 & pos, const float3 & velocity){}
void CAudioChannel::PlaySample(size_t id, const CWorldObject * obj, float volume){}
void CAudioChannel::PlaySample(size_t id, const CWorldObject * obj){}
void CAudioChannel::PlayRandomSample(const GuiSoundSet & soundSet, const CWorldObject * obj){}
void CAudioChannel::PlayRandomSample(const GuiSoundSet & soundSet, const float3 & pos){}
void CAudioChannel::StreamPlay(const std::string & path, float volume, bool enqueue){}
void CAudioChannel::StreamPlay(const std::string & path, float volume){}
void CAudioChannel::StreamPlay(const std::string & path){}
void CAudioChannel::StreamStop(){}
void CAudioChannel::StreamPause(){}
float CAudioChannel::StreamGetTime(){}
float CAudioChannel::StreamGetPlayTime(){}
void CAudioChannel::FindSourceAndPlay(size_t id, const float3 & pos, const float3 & velocity, float volume, bool relative){}
void CAudioChannel::SoundSourceFinished(CSoundSource * sndSource){}
spring::unsynced_set<(p.CSoundSource)> CAudioChannel::curSources(){}
std::vector<(AudioChannel::StreamQueueItem)> CAudioChannel::streamQueue(){}
CSoundSource CAudioChannel::curStreamSrc(){}
size_t CAudioChannel::MAX_STREAM_QUEUESIZE(){}
