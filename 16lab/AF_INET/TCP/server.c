#include <ctype.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT        12345
#define PROTOCOL    0
#define SIZE        1024
#define MAX_CLIENT  3

static void cleanup(int fd) {
  if (fd >= 0) {
    close(fd);
  }
}

int main() {
  struct sockaddr_in server, client;
  int fd = socket(AF_INET, SOCK_STREAM, PROTOCOL);
  char buffer[SIZE];
  socklen_t len = sizeof(client);

  if (fd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(PORT);

  if (bind(fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("bind");
        cleanup(fd);
        return EXIT_FAILURE;
  }

  if (listen(fd, MAX_CLIENT) < 0) {
    perror("listen");
    cleanup(fd);
    return EXIT_FAILURE;
  }

  printf("Server started on port %d\n", PORT);

  while (1) {
      int fdclient = accept(fd, (struct sockaddr *)&client, &len);

      if (fdclient < 0) {
        perror("accept");
              continue;
      }

      int recviced = recv(fdclient, buffer, SIZE - 1, 0);

      if (recviced < 0) {
        perror("recv");
              close(fdclient);
              continue;
      }

      buffer[recviced] = '\0';
      printf("Received: %s\n", buffer);

      int num = atoi(buffer);
      sprintf(buffer, "%d", num + 1);

      if (send(fdclient, buffer, strlen(buffer) + 1, 0) < 0) {
              perror("send");
      }

      close(fdclient);
  }

  cleanup(fd);
  return EXIT_SUCCESS;
}