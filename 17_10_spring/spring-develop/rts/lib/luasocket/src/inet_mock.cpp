// TODO: Substitue Cinet with your actual class name
int Cinet::inet_open(lua_State * L){}
q(const).char Cinet::inet_trycreate(p_socket ps, int type){}
q(const).char Cinet::inet_tryconnect(p_socket ps, const char * address, unsigned short port, p_timeout tm){}
q(const).char Cinet::inet_trybind(p_socket ps, const char * address, unsigned short port){}
int Cinet::inet_meth_getpeername(lua_State * L, p_socket ps){}
int Cinet::inet_meth_getsockname(lua_State * L, p_socket ps){}
