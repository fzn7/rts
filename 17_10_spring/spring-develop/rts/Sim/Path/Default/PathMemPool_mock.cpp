// TODO: Substitue CPathMemPool with your actual class name
DynMemPool<(sizeof(CPathCache))> CPathMemPool::PCMemPool(){}
DynMemPool<(sizeof(CPathEstimator))> CPathMemPool::PEMemPool(){}
DynMemPool<(sizeof(CPathFinder))> CPathMemPool::PFMemPool(){}
PCMemPool CPathMemPool::pcMemPool(){}
PEMemPool CPathMemPool::peMemPool(){}
PFMemPool CPathMemPool::pfMemPool(){}
