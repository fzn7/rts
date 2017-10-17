// TODO: Substitue CLuaUnitScript with your actual class name
CUnit CLuaUnitScript::activeUnit(){}
CUnitScript CLuaUnitScript::activeScript(){}
CLuaHandle CLuaUnitScript::handle(){}
lua_State CLuaUnitScript::L(){}
std::vector<(int)> CLuaUnitScript::scriptIndex(){}
spring::unordered_map<(std::string,int)> CLuaUnitScript::scriptNames(){}
bool CLuaUnitScript::inKilled(){}
void CLuaUnitScript::ShowScriptError(const std::string & msg){}
int CLuaUnitScript::UpdateCallIn(){}
void CLuaUnitScript::UpdateCallIn(const std::string & fname, int ref){}
void CLuaUnitScript::RemoveCallIn(const std::string & fname){}
float CLuaUnitScript::PopNumber(int fn, float def){}
bool CLuaUnitScript::PopBoolean(int fn, bool def){}
int CLuaUnitScript::RunQueryCallIn(int fn){}
int CLuaUnitScript::RunQueryCallIn(int fn, float arg1){}
void CLuaUnitScript::Call(int fn, float arg1){}
void CLuaUnitScript::Call(int fn, float arg1, float arg2){}
void CLuaUnitScript::Call(int fn, float arg1, float arg2, float arg3){}
void CLuaUnitScript::RawPushFunction(int functionId){}
void CLuaUnitScript::PushFunction(int id){}
void CLuaUnitScript::PushUnit(const CUnit * targetUnit){}
bool CLuaUnitScript::RunCallIn(int id, int inArgs, int outArgs){}
bool CLuaUnitScript::RawRunCallIn(int functionId, int inArgs, int outArgs){}
std::string CLuaUnitScript::GetScriptName(int functionId){}
bool CLuaUnitScript::HasBlockShot(int weaponNum){}
bool CLuaUnitScript::HasTargetWeight(int weaponNum){}
void CLuaUnitScript::RawCall(int functionId){}
void CLuaUnitScript::Create(){}
void CLuaUnitScript::Killed(){}
void CLuaUnitScript::WindChanged(float heading, float speed){}
void CLuaUnitScript::ExtractionRateChanged(float speed){}
void CLuaUnitScript::RockUnit(const float3 & rockDir){}
void CLuaUnitScript::HitByWeapon(const float3 & hitDir, int weaponDefId, float & inoutDamage){}
void CLuaUnitScript::SetSFXOccupy(int curTerrainType){}
void CLuaUnitScript::QueryLandingPads(std::vector<(int)> & out_pieces){}
void CLuaUnitScript::BeginTransport(const CUnit * unit){}
int CLuaUnitScript::QueryTransport(const CUnit * unit){}
void CLuaUnitScript::TransportPickup(const CUnit * unit){}
void CLuaUnitScript::TransportDrop(const CUnit * unit, const float3 & pos){}
void CLuaUnitScript::StartBuilding(float heading, float pitch){}
int CLuaUnitScript::QueryNanoPiece(){}
int CLuaUnitScript::QueryBuildInfo(){}
void CLuaUnitScript::Destroy(){}
void CLuaUnitScript::StartMoving(bool reversing){}
void CLuaUnitScript::StopMoving(){}
void CLuaUnitScript::StartSkidding(const float3 & vel){}
void CLuaUnitScript::StopSkidding(){}
void CLuaUnitScript::ChangeHeading(short deltaHeading){}
void CLuaUnitScript::StartUnload(){}
void CLuaUnitScript::EndTransport(){}
void CLuaUnitScript::StartBuilding(){}
void CLuaUnitScript::StopBuilding(){}
void CLuaUnitScript::Falling(){}
void CLuaUnitScript::Landed(){}
void CLuaUnitScript::Activate(){}
void CLuaUnitScript::Deactivate(){}
void CLuaUnitScript::MoveRate(int curRate){}
void CLuaUnitScript::FireWeapon(int weaponNum){}
void CLuaUnitScript::EndBurst(int weaponNum){}
int CLuaUnitScript::QueryWeapon(int weaponNum){}
void CLuaUnitScript::AimWeapon(int weaponNum, float heading, float pitch){}
void CLuaUnitScript::AimShieldWeapon(CPlasmaRepulser * weapon){}
int CLuaUnitScript::AimFromWeapon(int weaponNum){}
void CLuaUnitScript::Shot(int weaponNum){}
bool CLuaUnitScript::BlockShot(int weaponNum, const CUnit * targetUnit, bool userTarget){}
float CLuaUnitScript::TargetWeight(int weaponNum, const CUnit * targetUnit){}
void CLuaUnitScript::AnimFinished(AnimType type, int piece, int axis){}
void CLuaUnitScript::HandleFreed(CLuaHandle * handle){}
bool CLuaUnitScript::PushEntries(lua_State * L){}
int CLuaUnitScript::CreateScript(lua_State * L){}
int CLuaUnitScript::UpdateCallIn(lua_State * L){}
int CLuaUnitScript::CallAsUnit(lua_State * L){}
int CLuaUnitScript::GetUnitValue(lua_State * L, CUnitScript * script, int arg){}
int CLuaUnitScript::GetUnitValue(lua_State * L){}
int CLuaUnitScript::GetUnitCOBValue(lua_State * L){}
int CLuaUnitScript::SetUnitValue(lua_State * L, CUnitScript * script, int arg){}
int CLuaUnitScript::SetUnitValue(lua_State * L){}
int CLuaUnitScript::SetUnitCOBValue(lua_State * L){}
int CLuaUnitScript::SetPieceVisibility(lua_State * L){}
int CLuaUnitScript::EmitSfx(lua_State * L){}
int CLuaUnitScript::AttachUnit(lua_State * L){}
int CLuaUnitScript::DropUnit(lua_State * L){}
int CLuaUnitScript::Explode(lua_State * L){}
int CLuaUnitScript::ShowFlare(lua_State * L){}
int CLuaUnitScript::Spin(lua_State * L){}
int CLuaUnitScript::StopSpin(lua_State * L){}
int CLuaUnitScript::Turn(lua_State * L){}
int CLuaUnitScript::Move(lua_State * L){}
int CLuaUnitScript::IsInAnimation(lua_State * L, const char * caller, AnimType type){}
int CLuaUnitScript::IsInTurn(lua_State * L){}
int CLuaUnitScript::IsInMove(lua_State * L){}
int CLuaUnitScript::IsInSpin(lua_State * L){}
int CLuaUnitScript::WaitForAnimation(lua_State * L, const char * caller, AnimType type){}
int CLuaUnitScript::WaitForTurn(lua_State * L){}
int CLuaUnitScript::WaitForMove(lua_State * L){}
int CLuaUnitScript::SetDeathScriptFinished(lua_State * L){}
int CLuaUnitScript::GetPieceTranslation(lua_State * L){}
int CLuaUnitScript::GetPieceRotation(lua_State * L){}
int CLuaUnitScript::GetPiecePosDir(lua_State * L){}
int CLuaUnitScript::GetActiveUnitID(lua_State * L){}
