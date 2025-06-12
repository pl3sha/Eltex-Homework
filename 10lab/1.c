#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int pid = fork();
  int status = 0;

  if (pid < 0) {
    exit(status);
  } else if (pid != 0) {
    printf("parent:\npid - %d\n", getpid());
    printf("ppid - %d\n", getppid());
    wait(&status);
    printf("code return - %d\n", WEXITSTATUS(status));
  } else {
    printf("child:\npid - %d\n", getpid());
    printf("ppid - %d\n", getppid());
    exit(status);
  }

  return 0;
}