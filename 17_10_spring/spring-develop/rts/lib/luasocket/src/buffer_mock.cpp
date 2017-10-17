// TODO: Substitue Cbuffer with your actual class name
double Cbuffer::birthday(){}
size_t Cbuffer::sent(){}
size_t Cbuffer::received(){}
p_io Cbuffer::io(){}
p_timeout Cbuffer::tm(){}
size_t Cbuffer::first(){}
size_t Cbuffer::last(){}
char Cbuffer::data(){}
t_buffer_ Cbuffer::t_buffer(){}
t_buffer Cbuffer::p_buffer(){}
int Cbuffer::buffer_open(lua_State * L){}
void Cbuffer::buffer_init(p_buffer buf, p_io io, p_timeout tm){}
int Cbuffer::buffer_meth_send(lua_State * L, p_buffer buf){}
int Cbuffer::buffer_meth_receive(lua_State * L, p_buffer buf){}
int Cbuffer::buffer_meth_getstats(lua_State * L, p_buffer buf){}
int Cbuffer::buffer_meth_setstats(lua_State * L, p_buffer buf){}
int Cbuffer::buffer_isempty(p_buffer buf){}
