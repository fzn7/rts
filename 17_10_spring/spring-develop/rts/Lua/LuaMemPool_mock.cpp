// TODO: Substitue CLuaMemPool with your actual class name
LuaMemPool CLuaMemPool::operator =(const LuaMemPool & p){}
LuaMemPool CLuaMemPool::operator =(LuaMemPool p){}
size_t CLuaMemPool::GetPoolCount(){}
LuaMemPool CLuaMemPool::GetSharedPtr(){}
LuaMemPool CLuaMemPool::AcquirePtr(bool shared, bool owned){}
void CLuaMemPool::ReleasePtr(LuaMemPool * p, const CLuaHandle * o){}
void CLuaMemPool::FreeShared(){}
void CLuaMemPool::InitStatic(bool enable){}
void CLuaMemPool::KillStatic(){}
void CLuaMemPool::DeleteBlocks(){}
void CLuaMemPool::Alloc(size_t size){}
void CLuaMemPool::Realloc(void * ptr, size_t nsize, size_t osize){}
void CLuaMemPool::Free(void * ptr, size_t size){}
void CLuaMemPool::LogStats(const char * handle, const char * lctype){}
size_t CLuaMemPool::MIN_ALLOC_SIZE(){}
size_t CLuaMemPool::MAX_ALLOC_SIZE(){}
bool CLuaMemPool::enabled(){}
spring::unsynced_map<(size_t,p.void)> CLuaMemPool::freeChunksTable(){}
spring::unsynced_map<(size_t,size_t)> CLuaMemPool::chunkCountTable(){}
std::vector<(p.void)> CLuaMemPool::allocBlocks(){}
size_t CLuaMemPool::allocStats(){}
size_t CLuaMemPool::globalIndex(){}
size_t CLuaMemPool::sharedCount(){}
