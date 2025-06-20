#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT        12345
#define PROTOCOL    0
#define SIZE        1024

static void cleanup(int fd) {
    if (fd >= 0) {
        close(fd);
    }
}

int main() {
  struct sockaddr_in server, client;
  char buffer[SIZE];
  int fd;
  socklen_t len = sizeof(client);

  fd = socket(AF_INET, SOCK_DGRAM, PROTOCOL);
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

    printf("UDP Server started on port %d\n", PORT);

    while (1) {
        int recv_len = recvfrom(fd, buffer, SIZE - 1, 0, 
                               (struct sockaddr *)&client, &len);

      if (recv_len < 0) {
        perror("recvfrom");
        continue;
      }

      buffer[recv_len] = '\0';
      printf("Received: %s\n", buffer);

      int num = atoi(buffer);
      sprintf(buffer, "%d", num + 1);

      if (sendto(fd, buffer, strlen(buffer) + 1, 0,
                  (struct sockaddr *)&client, len) < 0) {
          perror("sendto");
      }
  }

  cleanup(fd);
  return EXIT_SUCCESS;
}