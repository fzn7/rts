// TODO: Substitue CSoundBuffer with your actual class name
bool CSoundBuffer::LoadWAV(const std::string & file, std::vector<(std::uint8_t)> buffer){}
bool CSoundBuffer::LoadVorbis(const std::string & file, std::vector<(std::uint8_t)> buffer){}
int CSoundBuffer::BufferSize(){}
void CSoundBuffer::Initialise(){}
void CSoundBuffer::Deinitialise(){}
size_t CSoundBuffer::GetId(const std::string & name){}
std::shared_ptr<(SoundBuffer)> CSoundBuffer::GetById(const size_t id){}
size_t CSoundBuffer::Count(){}
size_t CSoundBuffer::AllocedSize(){}
size_t CSoundBuffer::Insert(std::shared_ptr<(SoundBuffer)> buffer){}
bool CSoundBuffer::AlGenBuffer(const std::string & file, ALenum format, const std::uint8_t * data, size_t datalength, int rate){}
std::string CSoundBuffer::filename(){}
ALuint CSoundBuffer::id(){}
ALuint CSoundBuffer::channels(){}
ALfloat CSoundBuffer::length(){}
spring::unsynced_map<(std::string,size_t)> CSoundBuffer::bufferMapT(){}
std::vector<(std::shared_ptr<(SoundBuffer)>)> CSoundBuffer::bufferVecT(){}
SoundBuffer::bufferMapT CSoundBuffer::bufferMap(){}
SoundBuffer::bufferVecT CSoundBuffer::buffers(){}
