// TODO: Substitue CSpatialSort with your actual class name
void CSpatialSort::Fill(const aiVector3D * pPositions, unsigned int pNumPositions, unsigned int pElementOffset, bool pFinalize){}
void CSpatialSort::Fill(const aiVector3D * pPositions, unsigned int pNumPositions, unsigned int pElementOffset){}
void CSpatialSort::Append(const aiVector3D * pPositions, unsigned int pNumPositions, unsigned int pElementOffset, bool pFinalize){}
void CSpatialSort::Append(const aiVector3D * pPositions, unsigned int pNumPositions, unsigned int pElementOffset){}
void CSpatialSort::Finalize(){}
void CSpatialSort::FindPositions(const aiVector3D & pPosition, ai_real pRadius, std::vector<(unsigned int)> & poResults){}
void CSpatialSort::FindIdenticalPositions(const aiVector3D & pPosition, std::vector<(unsigned int)> & poResults){}
unsigned int CSpatialSort::GenerateMappingTable(std::vector<(unsigned int)> & fill, ai_real pRadius){}
aiVector3D CSpatialSort::mPlaneNormal(){}
std::vector<(Assimp::SpatialSort::Entry)> CSpatialSort::mPositions(){}
