#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#define PATH        "/tmp/server.socket"
#define PROTOCOL    0
#define SIZE        1024

static void cleanup(int fd, const char *path) {
    if (fd >= 0) {
        close(fd);
    }
    if (path) {
        unlink(path);
    }
}

int main() {
    struct sockaddr_un server, client;
    char buffer[SIZE];
    int fd;
    socklen_t len = sizeof(client);

    fd = socket(AF_LOCAL, SOCK_DGRAM, PROTOCOL);
    if (fd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    unlink(PATH);
    
    memset(&server, 0, sizeof(server));
    server.sun_family = AF_LOCAL;
    if (strlen(PATH) >= sizeof(server.sun_path)) {
        fprintf(stderr, "Path too long\n");
        cleanup(fd, NULL);
        return EXIT_FAILURE;
    }
    strcpy(server.sun_path, PATH);

    if (bind(fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        cleanup(fd, PATH);
        return EXIT_FAILURE;
    }

    printf("Server started at %s\n", PATH);

    while (1) {
        int received = recvfrom(fd, buffer, SIZE - 1, 0, 
                              (struct sockaddr *)&client, &len);
        if (received < 0) {
            perror("recvfrom");
            continue;
        }

        buffer[received] = '\0';
        printf("Received: %s\n", buffer);

        int num = atoi(buffer);
        sprintf(buffer, "%d", num + 1);
        
        if (sendto(fd, buffer, strlen(buffer) + 1, 0,
                  (struct sockaddr *)&client, len) < 0) {
            perror("sendto");
        }
    }

    cleanup(fd, PATH);
    return EXIT_SUCCESS;
}