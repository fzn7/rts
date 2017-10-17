// TODO: Substitue Cio with your actual class name
q(const).char Cio::p_error(void * ctx, int err){}
int Cio::p_send(void * ctx, const char * data, size_t count, size_t * sent, p_timeout tm){}
int Cio::p_recv(void * ctx, char * data, size_t count, size_t * got, p_timeout tm){}
void Cio::ctx(){}
p_send Cio::send(){}
p_recv Cio::recv(){}
p_error Cio::error(){}
t_io_ Cio::t_io(){}
t_io Cio::p_io(){}
void Cio::io_init(p_io io, p_send send, p_recv recv, p_error error, void * ctx){}
q(const).char Cio::io_strerror(int err){}
