// TODO: Substitue CPathFinderDef with your actual class name
bool CPathFinderDef::WithinConstraints(unsigned int xSquare, unsigned int zSquare){}
bool CPathFinderDef::IsGoal(unsigned int xSquare, unsigned int zSquare){}
float CPathFinderDef::Heuristic(unsigned int xSquare, unsigned int zSquare, unsigned int blockSize){}
bool CPathFinderDef::IsGoalBlocked(const MoveDef & moveDef, const CMoveMath::BlockType & blockMask, const CSolidObject * owner){}
int2 CPathFinderDef::GoalSquareOffset(unsigned int blockSize){}
float3 CPathFinderDef::goal(){}
float CPathFinderDef::sqGoalRadius(){}
bool CPathFinderDef::startInGoalRadius(){}
bool CPathFinderDef::constraintDisabled(){}
bool CPathFinderDef::testMobile(){}
bool CPathFinderDef::needPath(){}
bool CPathFinderDef::exactPath(){}
bool CPathFinderDef::dirIndependent(){}
bool CPathFinderDef::synced(){}
unsigned int CPathFinderDef::goalSquareX(){}
unsigned int CPathFinderDef::goalSquareZ(){}
unsigned int CPathFinderDef::halfWayX(){}
unsigned int CPathFinderDef::halfWayZ(){}
unsigned int CPathFinderDef::searchRadiusSq(){}
SRectangle CPathFinderDef::startBlockRect(){}
SRectangle CPathFinderDef::goalBlockRect(){}
