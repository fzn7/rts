// TODO: Substitue CSelectedUnitsHandler with your actual class name
void CSelectedUnitsHandler::Init(unsigned int numPlayers){}
void CSelectedUnitsHandler::SelectGroup(int num){}
void CSelectedUnitsHandler::AiOrder(int unitid, const Command & c, int playerID){}
int CSelectedUnitsHandler::GetDefaultCmd(const CUnit * unit, const CFeature * feature){}
bool CSelectedUnitsHandler::CommandsChanged(){}
void CSelectedUnitsHandler::NetOrder(Command & c, int playerId){}
void CSelectedUnitsHandler::NetSelect(std::vector<(int)> & s, int playerId){}
void CSelectedUnitsHandler::ClearNetSelect(int playerId){}
void CSelectedUnitsHandler::DependentDied(CObject * o){}
void CSelectedUnitsHandler::Draw(){}
CSelectedUnitsHandler::AvailableCommandsStruct CSelectedUnitsHandler::GetAvailableCommands(){}
void CSelectedUnitsHandler::GiveCommand(Command c, bool fromUser){}
void CSelectedUnitsHandler::GiveCommand(Command c){}
void CSelectedUnitsHandler::AddUnit(CUnit * unit){}
void CSelectedUnitsHandler::RemoveUnit(CUnit * unit){}
void CSelectedUnitsHandler::ClearSelected(){}
void CSelectedUnitsHandler::HandleUnitBoxSelection(const float4 & planeRight, const float4 & planeLeft, const float4 & planeTop, const float4 & planeBottom){}
void CSelectedUnitsHandler::HandleSingleUnitClickSelection(CUnit * unit, bool doInViewTest, bool selectType){}
void CSelectedUnitsHandler::ToggleBuildIconsFirst(){}
void CSelectedUnitsHandler::PossibleCommandChange(CUnit * sender){}
void CSelectedUnitsHandler::DrawCommands(){}
std::string CSelectedUnitsHandler::GetTooltip(){}
void CSelectedUnitsHandler::SetCommandPage(int page){}
void CSelectedUnitsHandler::SendCommand(const Command & c){}
void CSelectedUnitsHandler::SendCommandsToUnits(const std::vector<(int)> & unitIDs, const std::vector<(Command)> & commands, bool pairwise){}
void CSelectedUnitsHandler::SendCommandsToUnits(const std::vector<(int)> & unitIDs, const std::vector<(Command)> & commands){}
bool CSelectedUnitsHandler::IsUnitSelected(const CUnit * unit){}
bool CSelectedUnitsHandler::IsUnitSelected(const int unitID){}
void CSelectedUnitsHandler::SelectUnits(const std::string & line){}
void CSelectedUnitsHandler::SelectCycle(const std::string & command){}
bool CSelectedUnitsHandler::selectionChanged(){}
bool CSelectedUnitsHandler::possibleCommandsChanged(){}
spring::unordered_set<(int)> CSelectedUnitsHandler::selectedUnits(){}
std::vector<(std::vector<(int)>)> CSelectedUnitsHandler::netSelected(){}
int CSelectedUnitsHandler::selectedGroup(){}
int CSelectedUnitsHandler::soundMultiselID(){}
bool CSelectedUnitsHandler::autoAddBuiltUnitsToFactoryGroup(){}
bool CSelectedUnitsHandler::autoAddBuiltUnitsToSelectedGroup(){}
bool CSelectedUnitsHandler::buildIconsFirst(){}
CSelectedUnitsHandler CSelectedUnitsHandler::selectedUnitsHandler(){}
