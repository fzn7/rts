// TODO: Substitue CIGameCommands with your actual class name
std::map<(std::string,p.actionExecutor_t)> CIGameCommands::actionExecutorsMap_t(){}
void CIGameCommands::AddDefaultActionExecutors(){}
void CIGameCommands::AddActionExecutor(actionExecutor_t * executor){}
void CIGameCommands::RemoveActionExecutor(const std::string & command){}
void CIGameCommands::RemoveAllActionExecutors(){}
q(const).actionExecutor_t CIGameCommands::GetActionExecutor(const std::string & command){}
actionExecutorsMap_t CIGameCommands::actionExecutors(){}
