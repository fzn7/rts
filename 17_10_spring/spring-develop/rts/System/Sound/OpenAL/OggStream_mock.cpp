// TODO: Substitue COggStream with your actual class name
void COggStream::Play(const std::string & path, float volume){}
void COggStream::Stop(){}
void COggStream::Update(){}
float COggStream::GetTotalTime(){}
bool COggStream::TogglePause(){}
void COggStream::DisplayInfo(){}
bool COggStream::IsPlaying(){}
bool COggStream::StartPlaying(){}
bool COggStream::DecodeStream(ALuint buffer){}
void COggStream::EmptyBuffers(){}
void COggStream::ReleaseBuffers(){}
bool COggStream::UpdateBuffers(){}
OggVorbis_File COggStream::ovFile(){}
vorbis_info COggStream::vorbisInfo(){}
unsigned int COggStream::BUFFER_SIZE(){}
unsigned int COggStream::NUM_BUFFERS(){}
char COggStream::pcmDecodeBuffer(){}
ALuint COggStream::buffers(){}
ALuint COggStream::source(){}
ALenum COggStream::format(){}
bool COggStream::stopped(){}
bool COggStream::paused(){}
spring_time COggStream::msecsPlayed(){}
spring_time COggStream::lastTick(){}
std::vector<(std::string)> COggStream::vorbisTags(){}
std::string COggStream::vendor(){}
