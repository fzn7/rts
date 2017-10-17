// TODO: Substitue CBackend with your actual class name
void CBackend::log_sink_ptr(int level, const char * section, const char * record){}
void CBackend::log_backend_registerSink(log_sink_ptr sink){}
void CBackend::log_backend_unregisterSink(log_sink_ptr sink){}
void CBackend::log_cleanup_ptr(){}
void CBackend::log_backend_registerCleanup(log_cleanup_ptr cleanupFunc){}
void CBackend::log_backend_unregisterCleanup(log_cleanup_ptr cleanupFunc){}
