/*
    The fcntl function is used for five different purposes.

    1. Duplicate an existing descriptor (cmd = F_DUPFD or F_DUPFD_CLOEXEC)
    2. Get/set file descriptor flags (cmd = F_GETFD or F_SETFD)
    3. Get/set file status flags (cmd = F_GETFL or F_SETFL)
    4. Get/set asynchronous I/O ownership (cmd = F_GETOWN or F_SETOWN)
    5. Get/set record locks (cmd = F_GETLK, F_SETLK, or F_SETLKW
*/
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int     main(void)
{
    int     fd;
    int     val;

    fd =  open("fcntl.txt", O_CREAT | O_RDONLY);
    val = fcntl(fd, F_GETFL, 0);
    val &= O_ACCMODE; // use the O_ACCMODE mask to obtain the access-mode bits 
    switch (val)
    {
        case O_RDONLY:
            printf("read only!\n"); // this should be triggered.
            break;
        case O_WRONLY:
            printf("write only!\n");
            break;
        case O_RDWR:
            printf("write and write!\n");
            break;
        default:
            break;
    }
    close(fd);
    return (0);
}