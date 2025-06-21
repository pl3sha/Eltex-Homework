#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define PROTOCOL 0
#define INDEX 0
#define SIZE 1024
#define MULTI_IP "224.0.0.1"

int main(void) {
    struct sockaddr_in server;
    struct ip_mreqn group_sock;
    int fd;
    char buffer[SIZE];
    socklen_t len;

    if ((fd = socket(AF_INET, SOCK_DGRAM, PROTOCOL)) < 0) {
        perror("Socket creation error");
        return EXIT_FAILURE;
    }

    int reuse = 1;
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("SO_REUSEADDR setup error");
        close(fd);
        return EXIT_FAILURE;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;

    memset(&group_sock, 0, sizeof(group_sock));
    group_sock.imr_address.s_addr = INADDR_ANY;
    group_sock.imr_ifindex = INDEX;

    if (inet_pton(AF_INET, MULTI_IP, &group_sock.imr_multiaddr.s_addr) <= 0) {
        perror("IP conversion error");
        close(fd);
        return EXIT_FAILURE;
    }

    if (setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &group_sock, sizeof(group_sock)) < 0) {
        perror("Socket setup error");
        close(fd);
        return EXIT_FAILURE;
    }

    if (bind(fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Socket binding error");
        close(fd);
        return EXIT_FAILURE;
    }

    len = sizeof(server);
    memset(buffer, 0, SIZE);

    printf("Waiting for message...\n");
    if (recvfrom(fd, buffer, SIZE, 0, (struct sockaddr *)&server, &len) < 0) {
        perror("Data receiving error");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Received message: '%s'\n", buffer);

    close(fd);
    return EXIT_SUCCESS;
}