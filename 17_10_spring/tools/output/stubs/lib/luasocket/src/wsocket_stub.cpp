#include <iostream>
/*=========================================================================*\
* Socket compatibilization module for Win32
* LuaSocket toolkit
*
* The penalty of calling select to avoid busy-wait is only paid when
* the I/O call fail in the first place.
*
* RCS ID: $Id: wsocket.c,v 1.36 2007/06/11 23:44:54 diego Exp $
\*=========================================================================*/
#include <string.h>

#include "socket.h"

/* WinSock doesn't have a strerror... */
static const char*
wstrerror(int err);

/*-------------------------------------------------------------------------*\
* Initializes module
\*-------------------------------------------------------------------------*/
int
socket_open(void)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Close module
\*-------------------------------------------------------------------------*/
int
socket_close(void)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Wait for readable/writable/connected socket with timeout
\*-------------------------------------------------------------------------*/
#define WAITFD_R 1
#define WAITFD_W 2
#define WAITFD_E 4
#define WAITFD_C (WAITFD_E | WAITFD_W)

int
socket_waitfd(p_socket ps, int sw, p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Select with int timeout in ms
\*-------------------------------------------------------------------------*/
int
socket_select(t_socket n,
              fd_set* rfds,
              fd_set* wfds,
              fd_set* efds,
              p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Close and inutilize socket
\*-------------------------------------------------------------------------*/
void
socket_destroy(p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
*
\*-------------------------------------------------------------------------*/
void
socket_shutdown(p_socket ps, int how)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Creates and sets up a socket
\*-------------------------------------------------------------------------*/
int
socket_create(p_socket ps, int domain, int type, int protocol)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Connects or returns error message
\*-------------------------------------------------------------------------*/
int
socket_connect(p_socket ps, SA* addr, socklen_t len, p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Binds or returns error message
\*-------------------------------------------------------------------------*/
int
socket_bind(p_socket ps, SA* addr, socklen_t len)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
*
\*-------------------------------------------------------------------------*/
int
socket_listen(p_socket ps, int backlog)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Accept with timeout
\*-------------------------------------------------------------------------*/
int
socket_accept(p_socket ps, p_socket pa, SA* addr, socklen_t* len, p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Send with timeout
* On windows, if you try to send 10MB, the OS will buffer EVERYTHING
* this can take an awful lot of time and we will end up blocked.
* Therefore, whoever calls this function should not pass a huge buffer.
\*-------------------------------------------------------------------------*/
int
socket_send(p_socket ps,
            const char* data,
            size_t count,
            size_t* sent,
            p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Sendto with timeout
\*-------------------------------------------------------------------------*/
int
socket_sendto(p_socket ps,
              const char* data,
              size_t count,
              size_t* sent,
              SA* addr,
              socklen_t len,
              p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Receive with timeout
\*-------------------------------------------------------------------------*/
int
socket_recv(p_socket ps, char* data, size_t count, size_t* got, p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Recvfrom with timeout
\*-------------------------------------------------------------------------*/
int
socket_recvfrom(p_socket ps,
                char* data,
                size_t count,
                size_t* got,
                SA* addr,
                socklen_t* len,
                p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Put socket into blocking mode
\*-------------------------------------------------------------------------*/
void
socket_setblocking(p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Put socket into non-blocking mode
\*-------------------------------------------------------------------------*/
void
socket_setnonblocking(p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* DNS helpers
\*-------------------------------------------------------------------------*/
int
socket_gethostbyaddr(const char* addr, socklen_t len, struct hostent** hp)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
socket_gethostbyname(const char* addr, struct hostent** hp)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Error translation functions
\*-------------------------------------------------------------------------*/
const char*
socket_hoststrerror(int err)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const char*
socket_strerror(int err)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const char*
socket_ioerror(p_socket ps, int err)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const char*
wstrerror(int err)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
