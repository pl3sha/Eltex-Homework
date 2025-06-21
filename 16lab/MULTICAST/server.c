#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define IP "224.0.0.1"
#define PORT 12345
#define PROTOCOL 0
#define MESSAGE "Hello"

int main(void) {
    struct sockaddr_in server;
    int fd;
    
    if ((fd = socket(AF_INET, SOCK_DGRAM, PROTOCOL)) < 0) {
        perror("Socket creation error");
        return EXIT_FAILURE;
    }

    unsigned char ttl = 1;
    if (setsockopt(fd, IPPROTO_IP, IP_MULTICAST_TTL, &ttl, sizeof(ttl)) < 0) {
        perror("TTL setup error");
        close(fd);
        return EXIT_FAILURE;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (inet_pton(AF_INET, IP, &server.sin_addr) <= 0) {
        perror("IP conversion error");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Sending message: %s\n", MESSAGE);
    if (sendto(fd, MESSAGE, strlen(MESSAGE), 0, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Message sending error");
        close(fd);
        return EXIT_FAILURE;
    }
    printf("Message sent successfully\n");

    close(fd);
    return EXIT_SUCCESS;
}