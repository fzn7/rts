// TODO: Substitue CSM3Map with your actual class name
void CSM3Map::ConfigNotify(const std::string & key, const std::string & value){}
void CSM3Map::InitGroundDrawer(){}
void CSM3Map::KillGroundDrawer(){}
CBaseGroundDrawer CSM3Map::GetGroundDrawer(){}
void CSM3Map::UpdateHeightMapUnsynced(const SRectangle & hmu){}
void CSM3Map::DrawMinimap(){}
int CSM3Map::GetNumFeatures(){}
int CSM3Map::GetNumFeatureTypes(){}
void CSM3Map::GetFeatureInfo(MapFeatureInfo * f){}
q(const).char CSM3Map::GetFeatureTypeName(int typeID){}
unsigned char CSM3Map::GetInfoMap(const std::string & name, MapBitmapInfo * bm){}
void CSM3Map::FreeInfoMap(const std::string & name, unsigned char * data){}
void CSM3Map::GridVisibility(CCamera * cam, IQuadDrawer * cb, float maxDist, int quadSize, int extraSize){}
void CSM3Map::GridVisibility(CCamera * cam, IQuadDrawer * cb, float maxDist, int quadSize){}
CSM3GroundDrawer CSM3Map::groundDrawer(){}
terrain::Terrain CSM3Map::renderer(){}
unsigned int CSM3Map::minimapTexture(){}
std::map<(std::string,CSM3ReadMap::InfoMap)> CSM3Map::infoMaps(){}
std::vector<(p.std::string)> CSM3Map::featureTypes(){}
MapFeatureInfo CSM3Map::featureInfo(){}
unsigned int CSM3Map::numFeatures(){}
void CSM3Map::LoadFeatureData(){}
Frustum CSM3Map::tmpFrustum(){}
