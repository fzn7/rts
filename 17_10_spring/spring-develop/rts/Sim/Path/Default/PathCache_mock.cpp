// TODO: Substitue CPathCache with your actual class name
void CPathCache::Update(){}
bool CPathCache::AddPath(const IPath::Path * path, const IPath::SearchResult result, const int2 strtBlock, const int2 goalBlock, float goalRadius, int pathType){}
q(const).CPathCache::CacheItem CPathCache::GetCachedPath(const int2 strtBlock, const int2 goalBlock, float goalRadius, int pathType){}
void CPathCache::RemoveFrontQueItem(){}
std::uint64_t CPathCache::GetHash(const int2 strtBlk, const int2 goalBlk, std::uint32_t goalRadius, std::int32_t pathType){}
bool CPathCache::HashCollision(const CPathCache::CacheItem & ci, const int2 strtBlk, const int2 goalBlk, float goalRadius, int pathType){}
CPathCache::CacheItem CPathCache::dummyCacheItem(){}
std::deque<(CacheQueItem)> CPathCache::cacheQue(){}
spring::unordered_map<(std::uint64_t,CPathCache::CacheItem)> CPathCache::cachedPaths(){}
std::uint32_t CPathCache::numBlocksX(){}
std::uint32_t CPathCache::numBlocksZ(){}
std::uint64_t CPathCache::numBlocks(){}
std::uint64_t CPathCache::maxCacheSize(){}
std::uint32_t CPathCache::numCacheHits(){}
std::uint32_t CPathCache::numCacheMisses(){}
std::uint32_t CPathCache::numHashCollisions(){}
