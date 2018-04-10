#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//usar fork(), getpid(), getppid() e getuid()

int main() {
  pid_t pidA, pidB;
  pidA = fork();
  if(pidA < 0) {
    printf("Erro! Fork failed!\n");
    exit(1);
  }
  else if (pidA == 0) {
    printf("Processo filho A| pid: %d | ppid: %d\n",getpid(),getppid());
  }
  else {
    pidB = fork();
    if (pidB < 0) {
      printf("Erro! Fork failed!\n");
      exit(1);
    }
    else if (pidB > 0) {
      printf("Processo pai | pid: %d | ppid: %d\n",getpid(),getppid());
    }
    else {
      printf("Processo filho B | pid: %d | ppid: %d\n",getpid(),getppid());
    }
  }
  return 0;
}
