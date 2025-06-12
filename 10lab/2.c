#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int pid1, pid2;
  int status;

  pid1 = fork();

  if (pid1 < 0) {
    exit(1);
  } else if (pid1 == 0) {
    int pid3, pid4;

    printf("1) pid - %d | ppid - %d\n", getpid(), getppid());

    pid3 = fork();

    if (pid3 < 0) {
      exit(1);
    } else if (pid3 == 0) {
      printf("3) pid - %d | ppid - %d\n", getpid(), getppid());
      exit(0);
    }

    pid4 = fork();

    if (pid4 < 0) {
      exit(1);
    } else if (pid4 == 0) {
      printf("4) pid - %d | ppid - %d\n", getpid(), getppid());
      exit(0);
    }

    wait(&status);
    wait(&status);
    exit(0);
  }

  pid2 = fork();

  if (pid2 < 0) {
    exit(1);
  } else if (pid2 == 0) {
    int pid5;

    printf("2) pid - %d | ppid - %d\n", getpid(), getppid());

    pid5 = fork();

    if (pid5 < 0) {
      exit(1);
    } else if (pid5 == 0) {
      printf("5) pid - %d | ppid - %d\n", getpid(), getppid());
      exit(0);
    }

    wait(&status);
    exit(0);
  }

  wait(&status);
  wait(&status);

  return 0;
}