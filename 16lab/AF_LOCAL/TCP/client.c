#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <time.h>
#include <unistd.h>

#define PATH_SERVER  "/tmp/server.socket"
#define PATH_CLIENT  "/tmp/client.socket"
#define PROTOCOL    0
#define SIZE        1024
#define MAX_NUM     100

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
    
    srand(time(NULL));

    fd = socket(AF_LOCAL, SOCK_STREAM, PROTOCOL);
    if (fd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    unlink(PATH_CLIENT);
    
    memset(&client, 0, sizeof(client));
    client.sun_family = AF_LOCAL;
    if (strlen(PATH_CLIENT) >= sizeof(client.sun_path)) {
        fprintf(stderr, "Client path too long\n");
        cleanup(fd, NULL);
        return EXIT_FAILURE;
    }
    strcpy(client.sun_path, PATH_CLIENT);

    if (bind(fd, (struct sockaddr *)&client, sizeof(client)) < 0) {
        perror("bind");
        cleanup(fd, PATH_CLIENT);
        return EXIT_FAILURE;
    }

    memset(&server, 0, sizeof(server));
    server.sun_family = AF_LOCAL;
    if (strlen(PATH_SERVER) >= sizeof(server.sun_path)) {
        fprintf(stderr, "Server path too long\n");
        cleanup(fd, PATH_CLIENT);
        return EXIT_FAILURE;
    }
    strcpy(server.sun_path, PATH_SERVER);

    if (connect(fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        cleanup(fd, PATH_CLIENT);
        return EXIT_FAILURE;
    }

    int random_num = rand() % MAX_NUM;
    sprintf(buffer, "%d", random_num);
    printf("Sending: %s\n", buffer);

    if (send(fd, buffer, strlen(buffer) + 1, 0) < 0) {
        perror("send");
        cleanup(fd, PATH_CLIENT);
        return EXIT_FAILURE;
    }

    int recviced = recv(fd, buffer, SIZE - 1, 0);
    if (recviced < 0) {
        perror("recv");
        cleanup(fd, PATH_CLIENT);
        return EXIT_FAILURE;
    }

    buffer[recviced] = '\0';
    printf("Received: %s\n", buffer);

    cleanup(fd, PATH_CLIENT);
    return EXIT_SUCCESS;
}