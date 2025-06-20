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
  socklen_t len = sizeof(server);
    
  srand(time(NULL));

  fd = socket(AF_INET, SOCK_DGRAM, PROTOCOL);
  if (fd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(HOST);
  server.sin_port = htons(PORT);

  int random_num = rand() % MAX_NUM;
  sprintf(buffer, "%d", random_num);
  printf("Sending: %s\n", buffer);

  if (sendto(fd, buffer, strlen(buffer) + 1, 0,
               (struct sockaddr *)&server, len) < 0) {
      perror("sendto");
      cleanup(fd);
      return EXIT_FAILURE;
    }

    int recv_len = recvfrom(fd, buffer, SIZE - 1, 0,
                           (struct sockaddr *)&server, &len);
    if (recv_len < 0) {
    perror("recvfrom");
      cleanup(fd);
      return EXIT_FAILURE;
  }

    buffer[recv_len] = '\0';
    printf("Received: %s\n", buffer);

    cleanup(fd);
    return EXIT_SUCCESS;
}