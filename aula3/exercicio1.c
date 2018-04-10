#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//usar fork(), getpid(), getppid() e getuid()

int main() {
  pid_t pid;
  if ((pid = fork()) < 0) {
    printf("Erro! Fork failed!\n");
    exit(0);
  }
  else {
    printf("Processo | pid: %d | ppid: %d | uid: %d \n",getpid(),getppid(),getuid());
  }
  return 0;
}
