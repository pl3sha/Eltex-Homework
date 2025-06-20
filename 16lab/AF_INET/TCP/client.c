#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

#define HOST        "127.0.0.1"
#define PROTOCOL    0
#define PORT        12345
#define SIZE        1024
#define MAX_NUM     100

static void cleanup(int fd) {
  if (fd >= 0) {
    close(fd);
  }
}

int main() {
  struct sockaddr_in server;
  char buffer[SIZE];
  int fd;
    
  srand(time(NULL));

  fd = socket(AF_INET, SOCK_STREAM, PROTOCOL);
  if (fd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(HOST);
  server.sin_port = htons(PORT);

  if (connect(fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("connect");
    cleanup(fd);
    return EXIT_FAILURE;
  }

    int random_num = rand() % MAX_NUM;
    sprintf(buffer, "%d", random_num);
    printf("Sending: %s\n", buffer);

    if (send(fd, buffer, strlen(buffer) + 1, 0) < 0) {
        perror("send");
        cleanup(fd);
        return EXIT_FAILURE;
    }

  int recvied = recv(fd, buffer, SIZE - 1, 0);
  if (recvied < 0) {
    perror("recv");
    cleanup(fd);
    return EXIT_FAILURE;
  }

  buffer[recvied] = '\0';
  printf("Received: %s\n", buffer);

  cleanup(fd);
  return EXIT_SUCCESS;
}