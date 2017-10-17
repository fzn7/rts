// TODO: Substitue CWatchdog with your actual class name
void CWatchdog::Watchdog::Install(){}
void CWatchdog::Watchdog::Uninstall(){}
void CWatchdog::Watchdog::ClearTimer(bool disable, Threading::NativeThreadId * _threadId){}
void CWatchdog::Watchdog::ClearTimer(bool disable){}
void CWatchdog::Watchdog::ClearTimer(){}
void CWatchdog::Watchdog::ClearTimer(const WatchdogThreadnum num, bool disable){}
void CWatchdog::Watchdog::ClearTimer(const WatchdogThreadnum num){}
void CWatchdog::Watchdog::ClearTimer(const std::string & name, bool disable){}
void CWatchdog::Watchdog::ClearTimer(const std::string & name){}
void CWatchdog::Watchdog::ClearPrimaryTimers(bool disable){}
void CWatchdog::Watchdog::ClearPrimaryTimers(){}
void CWatchdog::Watchdog::RegisterThread(WatchdogThreadnum num, bool primary){}
void CWatchdog::Watchdog::RegisterThread(WatchdogThreadnum num){}
void CWatchdog::Watchdog::DeregisterThread(WatchdogThreadnum num){}
