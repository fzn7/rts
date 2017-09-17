#include <iostream>
/*=========================================================================*\
* Socket compatibilization module for Unix
* LuaSocket toolkit
*
* The code is now interrupt-safe.
* The penalty of calling select to avoid busy-wait is only paid when
* the I/O call fail in the first place.
*
* RCS ID: $Id: usocket.c,v 1.38 2007/10/13 23:55:20 diego Exp $
\*=========================================================================*/
#include <signal.h>
#include <string.h>

#include "socket.h"

/*-------------------------------------------------------------------------*\
* Wait for readable/writable/connected socket with timeout
\*-------------------------------------------------------------------------*/
#ifdef SOCKET_POLL
#include <sys/poll.h>

#define WAITFD_R POLLIN
#define WAITFD_W POLLOUT
#define WAITFD_C (POLLIN | POLLOUT)
int
socket_waitfd(p_socket ps, int sw, p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#else

#define WAITFD_R 1
#define WAITFD_W 2
#define WAITFD_C (WAITFD_R | WAITFD_W)

int
socket_waitfd(p_socket ps, int sw, p_timeout tm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

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
* Close and inutilize socket
\*-------------------------------------------------------------------------*/
void
socket_destroy(p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*-------------------------------------------------------------------------*\
* Select with timeout control
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
* Creates and sets up a socket
\*-------------------------------------------------------------------------*/
int
socket_create(p_socket ps, int domain, int type, int protocol)
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
*
\*-------------------------------------------------------------------------*/
void
socket_shutdown(p_socket ps, int how)
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
* Make sure important error messages are standard
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
