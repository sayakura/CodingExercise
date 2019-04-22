#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>

int     main(void)
{
    char    buffer[100];
    int     sockfd;
    int     b_recv;
    unsigned int    addrlen;
    struct  sockaddr from;
    struct  sockaddr_in addr;
    struct  sockaddr_in *temp;
    char    ip[33];

    memset(ip, 0, sizeof(ip));
    bzero(&from, sizeof(from));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost only
    addr.sin_port = htons(4242);
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        perror("socket");
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        perror("bind");
    addrlen = sizeof(from);
    printf("running...\n");
    b_recv = recvfrom(sockfd, buffer, 5, 0, &from, &addrlen);
    buffer[b_recv] = '\0';
    printf("received! %s (%d bytes)\n", buffer, b_recv);
    temp = (struct sockaddr_in *)&from;
    inet_ntop(AF_INET, &temp->sin_addr.s_addr, ip, sizeof(ip));
    printf("from: %s\n", ip);
    return (0);
}