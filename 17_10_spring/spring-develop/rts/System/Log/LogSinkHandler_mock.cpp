// TODO: Substitue CLogSinkHandler with your actual class name
void CLogSinkHandler::RecordLogMessage(int level, const std::string & section, const std::string & text){}
void CLogSinkHandler::AddSink(ILogSink * logSink){}
void CLogSinkHandler::RemoveSink(ILogSink * logSink){}
void CLogSinkHandler::RecordLogMessage(int level, const std::string & section, const std::string & text){}
std::set<(p.ILogSink)> CLogSinkHandler::sinks(){}
std::string CLogSinkHandler::prvSection(){}
std::string CLogSinkHandler::prvMessage(){}
bool CLogSinkHandler::sinking(){}
