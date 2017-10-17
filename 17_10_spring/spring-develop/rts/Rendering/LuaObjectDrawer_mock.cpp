// TODO: Substitue CLuaObjectDrawer with your actual class name
void CLuaObjectDrawer::DrawDeferredPass(LuaObjType objType){}
bool CLuaObjectDrawer::DrawSingleObjectCommon(const CSolidObject * obj, LuaObjType objType, bool applyTrans){}
bool CLuaObjectDrawer::DrawSingleObject(const CSolidObject * obj, LuaObjType objType){}
bool CLuaObjectDrawer::DrawSingleObjectNoTrans(const CSolidObject * obj, LuaObjType objType){}
void CLuaObjectDrawer::Update(bool init){}
void CLuaObjectDrawer::Init(){}
void CLuaObjectDrawer::Kill(){}
void CLuaObjectDrawer::SetObjectLOD(CSolidObject * obj, LuaObjType objType, unsigned int lodCount){}
bool CLuaObjectDrawer::AddObjectForLOD(CSolidObject * obj, LuaObjType objType, bool useAlphaMat, bool useShadowMat){}
bool CLuaObjectDrawer::AddOpaqueMaterialObject(CSolidObject * obj, LuaObjType objType){}
bool CLuaObjectDrawer::AddAlphaMaterialObject(CSolidObject * obj, LuaObjType objType){}
bool CLuaObjectDrawer::AddShadowMaterialObject(CSolidObject * obj, LuaObjType objType){}
void CLuaObjectDrawer::DrawOpaqueMaterialObjects(LuaObjType objType, bool deferredPass){}
void CLuaObjectDrawer::DrawAlphaMaterialObjects(LuaObjType objType, bool deferredPass){}
void CLuaObjectDrawer::DrawShadowMaterialObjects(LuaObjType objType, bool deferredPass){}
void CLuaObjectDrawer::ReadLODScales(LuaObjType objType){}
void CLuaObjectDrawer::SetDrawPassGlobalLODFactor(LuaObjType objType){}
LuaMatType CLuaObjectDrawer::GetDrawPassOpaqueMat(){}
LuaMatType CLuaObjectDrawer::GetDrawPassAlphaMat(){}
void CLuaObjectDrawer::DrawMaterialBins(LuaObjType objType, LuaMatType matType, bool deferredPass){}
void CLuaObjectDrawer::DrawMaterialBin(const LuaMatBin * currBin, const LuaMaterial * prevMat, LuaObjType objType, LuaMatType matType, bool deferredPass, bool alphaMatBin){}
void CLuaObjectDrawer::DrawBinObject(const CSolidObject * obj, LuaObjType objType, const LuaObjectLODMaterial * lodMat, const LuaMaterial * luaMat, bool deferredPass, bool alphaMatBin, bool applyTrans, bool noLuaCall){}
GL::GeometryBuffer CLuaObjectDrawer::geomBuffer(){}
bool CLuaObjectDrawer::inDrawPass(){}
bool CLuaObjectDrawer::inAlphaBin(){}
bool CLuaObjectDrawer::drawDeferredEnabled(){}
bool CLuaObjectDrawer::drawDeferredAllowed(){}
bool CLuaObjectDrawer::bufferClearAllowed(){}
int CLuaObjectDrawer::binObjTeam(){}
float CLuaObjectDrawer::LODScale(){}
float CLuaObjectDrawer::LODScaleShadow(){}
float CLuaObjectDrawer::LODScaleReflection(){}
float CLuaObjectDrawer::LODScaleRefraction(){}
