// TODO: Substitue CCrashHandler with your actual class name
void CCrashHandler::CrashHandler::Install(){}
void CCrashHandler::CrashHandler::Remove(){}
void CCrashHandler::CrashHandler::Stacktrace(Threading::NativeThreadHandle thread, const std::string & threadName, const int logLevel){}
void CCrashHandler::CrashHandler::Stacktrace(Threading::NativeThreadHandle thread, const std::string & threadName){}
void CCrashHandler::CrashHandler::PrepareStacktrace(const int logLevel){}
void CCrashHandler::CrashHandler::PrepareStacktrace(){}
void CCrashHandler::CrashHandler::CleanupStacktrace(const int logLevel){}
void CCrashHandler::CrashHandler::CleanupStacktrace(){}
void CCrashHandler::CrashHandler::SuspendedStacktrace(Threading::ThreadControls * ctls, const std::string & threadName){}
void CCrashHandler::CrashHandler::OutputStacktrace(){}
