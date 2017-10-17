// TODO: Substitue CTargetAnimation with your actual class name
void CTargetAnimation::operator ++(){}
bool CTargetAnimation::reachedEnd(){}
aiVector3D CTargetAnimation::curPosition(){}
aiVector3D CTargetAnimation::curTargetPosition(){}
float CTargetAnimation::curTime(){}
q(const).std::vector<(aiVectorKey)> CTargetAnimation::objPos(){}
q(const).std::vector<(aiVectorKey)> CTargetAnimation::targetObjPos(){}
unsigned int CTargetAnimation::nextObjPos(){}
unsigned int CTargetAnimation::nextTargetObjPos(){}
std::vector<(aiVectorKey)> CTargetAnimation::defaultObjPos(){}
std::vector<(aiVectorKey)> CTargetAnimation::defaultTargetObjPos(){}
void CTargetAnimation::SetTargetAnimationChannel(const std::vector<(aiVectorKey)> * targetPositions){}
void CTargetAnimation::SetMainAnimationChannel(const std::vector<(aiVectorKey)> * objectPositions){}
void CTargetAnimation::SetFixedMainAnimationChannel(const aiVector3D & fixed){}
void CTargetAnimation::Process(std::vector<(aiVectorKey)> * distanceTrack){}
q(const).std::vector<(aiVectorKey)> CTargetAnimation::targetPositions(){}
q(const).std::vector<(aiVectorKey)> CTargetAnimation::objectPositions(){}
aiVector3D CTargetAnimation::fixedMain(){}
