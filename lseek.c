/*
    Every open file has an associated “current file offset,”
    normally a non-negative integer that measures the number
    of bytes from the beginning of the file. 
    Read and write operations normally start at the current
    file offset and cause the offset to be incremented by the
    number of bytes read or written. By default, this offset is
    initialized to 0 when a file is opened, unless the O_APPEND option is specified.

    #include <unistd.h>

    off_t lseek(int fd, off_t offset, int whence);

    • If whence is SEEK_SET, the file’s offset is set to offset bytes from the beginning of the file.
    • If whence is SEEK_CUR, the file’s offset is set to its current value plus the offset. The offset can be positive or negative.
    • If whence is SEEK_END, the file’s offset is set to the size of the file plus the offset. The offset can be positive or negative.

    Because a successful call to lseek returns the new file offset, we can seek zero bytes from the current position to determine the current offset:

    Normally, a file’s current offset must be a non-negative integer. 
    It is possible, however, that certain devices could allow negative offsets.
    But for regular files, the offset must be non-negative.
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
 #include <string.h>

int     main(void)
{
    int     fd;
    char    buf[11];

    bzero(buf, sizeof(buf));
    fd = open("test.txt", O_RDONLY);

    read(fd, buf, 10);
    printf("buf: %s\n", buf); 


    bzero(buf, sizeof(buf));
    lseek(fd, 5, SEEK_SET); // set the offset to 5, so it will read from 5
    read(fd, buf, 10); // offset now is 5
    printf("lseek(fd, 5, SEEK_SET) : %s\n", buf);


    bzero(buf, sizeof(buf));
    lseek(fd, 0, SEEK_SET); // set the offset to 0
    lseek(fd, 5, SEEK_CUR); // set the offset to current offset (0) plus 5 
    read(fd, buf, 10); // offset now is 5
    printf("lseek(fd, 0, SEEK_CUR) : %s\n", buf);


    bzero(buf, sizeof(buf));
    lseek(fd, 10, SEEK_SET); // set the offset to 10
    lseek(fd, -5, SEEK_END); // set the offset to current offset(10) minus 5
    read(fd, buf, 10); // offset now is 5
    printf("lseek(fd, -5, SEEK_END): %s\n", buf);

    close(fd);
    return (0);
}
/*
output: 
buf: 1234567890
lseek(fd, 5, SEEK_SET) : 67890
lseek(fd, 0, SEEK_CUR) : 67890
lseek(fd, -5, SEEK_END): 67890
*/