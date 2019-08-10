

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int         main(int ac, char **av)
{
    static char buf[200];

    int     fd = open("./testdir", O_RDONLY);
    int     fd2 = openat(fd, "test2/test2.test", O_RDONLY);

    printf("fd: %d fd2: %d\n", fd, fd2);
    if (fd < 0 || fd2 < 0)
        return (1);
    int bread = read(fd2, buf, 100);
    if (bread < 0)
        return (1);
    printf("%s", buf);
    return (0);
}