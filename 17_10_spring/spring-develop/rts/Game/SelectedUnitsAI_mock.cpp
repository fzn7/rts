// TODO: Substitue CSelectedUnitsAI with your actual class name
void CSelectedUnitsAI::GiveCommandNet(Command & c, int player){}
float3 CSelectedUnitsAI::centerPos(){}
float3 CSelectedUnitsAI::rightPos(){}
int CSelectedUnitsAI::sumLength(){}
float CSelectedUnitsAI::avgLength(){}
float CSelectedUnitsAI::frontLength(){}
float CSelectedUnitsAI::addSpace(){}
void CSelectedUnitsAI::CalculateGroupData(int player, bool queueing){}
void CSelectedUnitsAI::MakeFrontMove(Command * c, int player){}
void CSelectedUnitsAI::CreateUnitOrder(std::multimap<(float,int)> & out, int player){}
float3 CSelectedUnitsAI::MoveToPos(int unit, float3 nextCornerPos, float3 dir, Command * command, std::vector<(std::pair<(int,Command)>)> * frontcmds, bool * newline){}
void CSelectedUnitsAI::AddUnitSetMaxSpeedCommand(CUnit * unit, unsigned char options){}
void CSelectedUnitsAI::AddGroupSetMaxSpeedCommand(CUnit * unit, unsigned char options){}
void CSelectedUnitsAI::SelectAttack(const Command & cmd, int player){}
void CSelectedUnitsAI::SelectCircleUnits(const float3 & pos, float radius, int player, std::vector<(int)> & units){}
void CSelectedUnitsAI::SelectRectangleUnits(const float3 & pos0, const float3 & pos1, int player, std::vector<(int)> & units){}
float3 CSelectedUnitsAI::LastQueuePosition(const CUnit * unit){}
float3 CSelectedUnitsAI::minCoor(){}
float3 CSelectedUnitsAI::maxCoor(){}
float3 CSelectedUnitsAI::centerCoor(){}
float CSelectedUnitsAI::minMaxSpeed(){}
float3 CSelectedUnitsAI::frontDir(){}
float3 CSelectedUnitsAI::sideDir(){}
float CSelectedUnitsAI::columnDist(){}
int CSelectedUnitsAI::numColumns(){}
CSelectedUnitsHandlerAI CSelectedUnitsAI::selectedUnitsAI(){}
