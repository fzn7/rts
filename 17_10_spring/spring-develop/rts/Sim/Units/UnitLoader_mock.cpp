// TODO: Substitue CUnitLoader with your actual class name
q(const).UnitDef CUnitLoader::unitDef(){}
q(const).CUnit CUnitLoader::builder(){}
float3 CUnitLoader::pos(){}
float3 CUnitLoader::speed(){}
int CUnitLoader::unitID(){}
int CUnitLoader::teamID(){}
int CUnitLoader::facing(){}
bool CUnitLoader::beingBuilt(){}
bool CUnitLoader::flattenGround(){}
CUnitLoader CUnitLoader::GetInstance(){}
CCommandAI CUnitLoader::NewCommandAI(CUnit * u, const UnitDef * ud){}
CUnit CUnitLoader::LoadUnit(const std::string & name, const UnitLoadParams & params){}
CUnit CUnitLoader::LoadUnit(const UnitLoadParams & params){}
CWeapon CUnitLoader::LoadWeapon(CUnit * owner, const UnitDefWeapon * udw){}
void CUnitLoader::ParseAndExecuteGiveUnitsCommand(const std::vector<(std::string)> & args, int team){}
void CUnitLoader::GiveUnits(const std::string & objectName, float3 pos, int amount, int team, int allyTeamFeatures){}
void CUnitLoader::FlattenGround(const CUnit * unit){}
void CUnitLoader::RestoreGround(const CUnit * unit){}
