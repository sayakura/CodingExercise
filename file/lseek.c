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

    lseek only records the current file offset within the kernel(current file offset from file table entry)
    it does not cause any I/O to take place.
    This offset is then used by the next read or write operation.

    The file’s offset can be greater than the file’s current size, in which case the next write to the file will extend the file. 
    This is referred to as creating a hole in a file and is allowed. 
    Any bytes in a file that have not been written are read back as 0.

    A hole in a file isn’t required to have storage backing it on disk.
    Depending on the file system implementation, when you write after seeking past the end of a file,
    new disk blocks might be allocated to store the data, but there is no need to allocate disk blocks
    for the data between the old end of file and the location where you start writing.
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int     main(void)
{
    int         fd;
    char        buf[11];
    const char  *content = "0123456789";
    off_t       cur;

    fd = creat("lseek.txt", 0666);
    write(fd, content, 10);
    close(fd);
    bzero(buf, sizeof(buf));
    fd = open("lseek.txt", O_RDWR);

    read(fd, buf, 10);
    printf("buf: %s\n", buf); 

    // SEEK_SET: the file’s offset is set to offset bytes from the beginning of the file.
    bzero(buf, sizeof(buf));
    lseek(fd, 5, SEEK_SET); // set the offset to 5, so it will read from 5
    // offset now is 5
    read(fd, buf, 10); 
    printf("lseek(fd, 5, SEEK_SET) : %s\n", buf);

    // SEEK_CUR: the file’s offset is set to its current value plus the offset. The offset can be positive or negative.
    bzero(buf, sizeof(buf));
    lseek(fd, 0, SEEK_SET); // set the offset to 0
    lseek(fd, 5, SEEK_CUR); // set the offset to current offset (0) plus 5 
    // offset now is 5
    read(fd, buf, 10); 
    printf("lseek(fd, 0, SEEK_CUR) : %s\n", buf);

    // SEEK_END: the file’s offset is set to the size of the file plus the offset. The offset can be positive or negative.
    bzero(buf, sizeof(buf));
    lseek(fd, 10, SEEK_SET); // set the offset to 10
    lseek(fd, -5, SEEK_END); // set the offset to current offset(10) minus 5
    // offset now is 5
    read(fd, buf, 10); 
    printf("lseek(fd, -5, SEEK_END): %s\n", buf);
    
    // offset now is 10 (end of the file)
    assert(lseek(fd, 0, SEEK_END) == 10);  // just confirm that it's at the end.
    cur = lseek(fd, 10, SEEK_CUR); // set offset to 20 (creating a hole of size 10)
    assert(cur == 20);  
    if (write(fd, content, 10) < 0)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }
    close(fd); 
    printf("Current file: \n");
    if (fork() == 0)
        execl("/bin/ls", "ls", "-l", "lseek.txt", NULL);
    if (fork() == 0)
        execl("/usr/bin/od", "od", "-c", "lseek.txt", NULL);
    return (0);
}
/*
buf: 0123456789
lseek(fd, 5, SEEK_SET) : 56789
lseek(fd, 0, SEEK_CUR) : 56789
lseek(fd, -5, SEEK_END): 56789
Current file:
0000000    0   1   2   3   4   5   6   7   8   9  \0  \0  \0  \0  \0  \0
0000020   \0  \0  \0  \0   0   1   2   3   4   5   6   7   8   9
0000036
-rw-r--r--  1 qpeng  2018_july  30 Apr 11 11:52 lseek.txt
*/