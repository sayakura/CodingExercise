#include <sys/socket.h>

int shutdown(int sockfd, int how);

If how is SHUT_RD, then reading from the socket is disabled. If how is SHUT_WR, then we can’t use the socket for transmitting data. We can use SHUT_RDWR to disable both data transmission and reception.

Given that we can close a socket, why is shutdown needed? There are several reasons. First, close will deallocate the network endpoint only when the last active reference is closed. **If we duplicate the socket (with dup, for example), the socket won’t be deallocated until we close the last file descriptor referring to it. The shutdown function allows us to deactivate a socket independently of the number of active file descriptors referencing it.** Second, it is sometimes convenient to shut a socket down in one direction only. For example, we can shut a socket down for writing if we want the process we are communicating with to be able to tell when we are done transmitting data, while still allowing us to use the socket to receive data sent to us by the process.

