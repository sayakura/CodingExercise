#include <stdio.h>
int main(void)
{
    static char buffer[4];

    /**
     *  FILE *
     *  freopen(const char *path, const char *mode, FILE *stream);
     * The freopen() function opens the file whose name is the string pointed to by path and associates the
     * stream pointed to by stream with it.  The original stream (if it exists) is closed.  The mode argument
     * is used just as in the fopen() function.
     */
    freopen("/dev/null", "a", stdout);
    // equivelent to setbuf(stdout, buffer)
    // _IOFBF: fully buffered
    // BUFSIZE should be larger than the size of buffer, so that 
    // the content of buffer won't be cleared out when the content 
    // in buffer exceeded BUFSIZ
    setvbuf(stdout, buffer, _IOFBF, BUFSIZ);
    printf("abc\n");
    freopen ("/dev/tty", "a", stdout);
    printf("%s", buffer);
    printf("hello motherfucker\n");
    return (0);
}
