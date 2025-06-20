#include <arpa/inet.h>
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
  char client_ip[INET_ADDRSTRLEN];

  fd = socket(AF_INET, SOCK_DGRAM, PROTOCOL);
  if (fd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = INADDR_ANY;

  if (bind(fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("bind");
    cleanup(fd);
    return EXIT_FAILURE;
  }

    printf("Listening for broadcast messages on port %d...\n", PORT);

    int received = recvfrom(fd, buffer, SIZE - 1, 0,
                          (struct sockaddr *)&client, &len);
    if (received < 0) {
      perror("recvfrom");
      cleanup(fd);
      return EXIT_FAILURE;
  }

    inet_ntop(AF_INET, &(client.sin_addr),
              client_ip, INET_ADDRSTRLEN);

    buffer[received] = '\0';
    printf("Received message '%s' from %s:%d\n",
           buffer, client_ip, ntohs(client.sin_port));

    cleanup(fd);
    return EXIT_SUCCESS;
}