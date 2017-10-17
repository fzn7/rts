// TODO: Substitue CIconHandler with your actual class name
void CIconHandler::Ref(){}
void CIconHandler::UnRef(){}
void CIconHandler::CopyData(const icon::CIconData * iconData){}
void CIconHandler::BindTexture(){}
void CIconHandler::DrawArray(CVertexArray * va, float x0, float y0, float x1, float y1, const unsigned char * c){}
void CIconHandler::Draw(float x0, float y0, float x1, float y1){}
void CIconHandler::Draw(const float3 & botLeft, const float3 & botRight, const float3 & topLeft, const float3 & topRight){}
bool CIconHandler::ownTexture(){}
int CIconHandler::refCount(){}
std::string CIconHandler::name(){}
unsigned int CIconHandler::texID(){}
int CIconHandler::xsize(){}
int CIconHandler::ysize(){}
float CIconHandler::size(){}
float CIconHandler::distance(){}
float CIconHandler::distSqr(){}
bool CIconHandler::radiusAdjust(){}
bool CIconHandler::AddIcon(const std::string & iconName, const std::string & textureName, float size, float distance, bool radiusAdjust){}
bool CIconHandler::FreeIcon(const std::string & iconName){}
CIcon CIconHandler::GetIcon(const std::string & iconName){}
bool CIconHandler::LoadIcons(const std::string & filename){}
unsigned int CIconHandler::GetDefaultTexture(){}
unsigned int CIconHandler::defTexID(){}
icon::CIconData CIconHandler::defIconData(){}
spring::unordered_map<(std::string,CIcon)> CIconHandler::IconMap(){}
icon::CIconHandler::IconMap CIconHandler::iconMap(){}
icon::CIconData CIconHandler::safetyData(){}
icon::CIconHandler CIconHandler::icon::iconHandler(){}
