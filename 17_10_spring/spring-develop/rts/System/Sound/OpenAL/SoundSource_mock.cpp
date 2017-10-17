// TODO: Substitue CSoundSource with your actual class name
CSoundSource CSoundSource::operator =(const CSoundSource & src){}
void CSoundSource::Update(){}
void CSoundSource::UpdateVolume(){}
int CSoundSource::GetCurrentPriority(){}
bool CSoundSource::IsPlaying(const bool checkOpenAl){}
bool CSoundSource::IsPlaying(){}
void CSoundSource::Stop(){}
void CSoundSource::Play(IAudioChannel * channel, SoundItem * buffer, float3 pos, float3 velocity, float volume, bool relative){}
void CSoundSource::Play(IAudioChannel * channel, SoundItem * buffer, float3 pos, float3 velocity, float volume){}
void CSoundSource::PlayAsync(IAudioChannel * channel, SoundItem * buffer, float3 pos, float3 velocity, float volume, bool relative){}
void CSoundSource::PlayAsync(IAudioChannel * channel, SoundItem * buffer, float3 pos, float3 velocity, float volume){}
void CSoundSource::PlayStream(IAudioChannel * channel, const std::string & stream, float volume){}
void CSoundSource::StreamStop(){}
void CSoundSource::StreamPause(){}
float CSoundSource::GetStreamTime(){}
float CSoundSource::GetStreamPlayTime(){}
float CSoundSource::referenceDistance(){}
float CSoundSource::globalPitch(){}
float CSoundSource::heightRolloffModifier(){}
ALuint CSoundSource::id(){}
SoundItem CSoundSource::curPlaying(){}
IAudioChannel CSoundSource::curChannel(){}
COggStream CSoundSource::curStream(){}
float CSoundSource::curVolume(){}
spring_time CSoundSource::loopStop(){}
bool CSoundSource::in3D(){}
bool CSoundSource::efxEnabled(){}
int CSoundSource::efxUpdates(){}
ALfloat CSoundSource::curHeightRolloffModifier(){}
AsyncSoundItemData CSoundSource::asyncPlay(){}
