#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BROADCAST_IP "255.255.255.255"
#define PORT         12345
#define PROTOCOL     0
#define SIZE         1024
#define MESSAGE      "hello"

static void cleanup(int fd) {
    if (fd >= 0) {
      close(fd);
    }
}

int main() {
  struct sockaddr_in server;
  int fd;
  int broadcast_enable = 1;

  fd = socket(AF_INET, SOCK_DGRAM, PROTOCOL);
  if (fd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  if (setsockopt(fd, SOL_SOCKET, SO_BROADCAST, 
                 &broadcast_enable, sizeof(broadcast_enable)) < 0) {
    perror("setsockopt (SO_BROADCAST)");
    cleanup(fd);
    return EXIT_FAILURE;
  }

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);

  if (inet_pton(AF_INET, BROADCAST_IP, &server.sin_addr) <= 0) {
    perror("inet_pton");
    cleanup(fd);
    return EXIT_FAILURE;
  }

    printf("Sending broadcast message '%s' to %s:%d\n", 
           MESSAGE, BROADCAST_IP, PORT);

  if (sendto(fd, MESSAGE, strlen(MESSAGE) + 1, 0,
             (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("sendto");
    cleanup(fd);
    return EXIT_FAILURE;
  }

  printf("Message sent successfully\n");
  cleanup(fd);
  return EXIT_SUCCESS;
}