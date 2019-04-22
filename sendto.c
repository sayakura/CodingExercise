#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>

ssize_t
sendto(int socket, const void *buffer, size_t length, int flags,
    const struct sockaddr *dest_addr, socklen_t dest_len);

int         main(void)
{
    struct sockaddr_in to;
    int                 bsent;
    int                 sockfd;

    memset(&to, 0, sizeof(to));
    to.sin_family = AF_INET; // ipv4
    to.sin_addr.s_addr = inet_addr("127.0.0.1"); // ip
    to.sin_port = htons(4242); // port 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    bsent = sendto(sockfd, "hello\0", 5, 0, (struct sockaddr *)&to, sizeof(to));
    printf("send: %d\n", bsent);
    return (0);
}