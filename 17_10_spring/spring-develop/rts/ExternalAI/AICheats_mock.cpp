// TODO: Substitue CAICheats with your actual class name
CSkirmishAIWrapper CAICheats::ai(){}
CUnit CAICheats::GetUnit(int unitId){}
void CAICheats::SetMyIncomeMultiplier(float incomeMultiplier){}
void CAICheats::GiveMeMetal(float amount){}
void CAICheats::GiveMeEnergy(float amount){}
int CAICheats::CreateUnit(const char * name, const float3 & pos){}
int CAICheats::GetEnemyUnits(int * unitIds, int unitIds_max){}
int CAICheats::GetEnemyUnits(int * unitIds){}
int CAICheats::GetEnemyUnits(int * unitIds, const float3 & pos, float radius, int unitIds_max){}
int CAICheats::GetEnemyUnits(int * unitIds, const float3 & pos, float radius){}
int CAICheats::GetNeutralUnits(int * unitIds, int unitIds_max){}
int CAICheats::GetNeutralUnits(int * unitIds){}
int CAICheats::GetNeutralUnits(int * unitIds, const float3 & pos, float radius, int unitIds_max){}
int CAICheats::GetNeutralUnits(int * unitIds, const float3 & pos, float radius){}
int CAICheats::GetFeatures(int * features, int max){}
int CAICheats::GetFeatures(int * features, int max, const float3 & pos, float radius){}
q(const).UnitDef CAICheats::GetUnitDef(int unitId){}
float3 CAICheats::GetUnitPos(int unitId){}
float3 CAICheats::GetUnitVelocity(int unitId){}
int CAICheats::GetUnitTeam(int unitId){}
int CAICheats::GetUnitAllyTeam(int unitId){}
float CAICheats::GetUnitHealth(int unitId){}
float CAICheats::GetUnitMaxHealth(int unitId){}
float CAICheats::GetUnitPower(int unitId){}
float CAICheats::GetUnitExperience(int unitId){}
bool CAICheats::IsUnitActivated(int unitId){}
bool CAICheats::UnitBeingBuilt(int unitId){}
bool CAICheats::IsUnitNeutral(int unitId){}
bool CAICheats::GetUnitResourceInfo(int unitId, UnitResourceInfo * resourceInfo){}
q(const).CCommandQueue CAICheats::GetCurrentUnitCommands(int unitId){}
int CAICheats::GetBuildingFacing(int unitId){}
bool CAICheats::IsUnitCloaked(int unitId){}
bool CAICheats::IsUnitParalyzed(int unitId){}
bool CAICheats::OnlyPassiveCheats(){}
void CAICheats::EnableCheatEvents(bool enable){}
bool CAICheats::GetProperty(int unit, int property, void * dst){}
bool CAICheats::GetValue(int id, void * dst){}
int CAICheats::HandleCommand(int commandId, void * data){}
