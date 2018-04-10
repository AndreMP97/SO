#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  pid_t pid;
  for (int i=0; i < n; i++) {
    pid = fork();
    if (pid < 0) {
      printf("Erro! Fork failed!\n");
      exit(1);
    }
    else if (pid == 0) {
      printf("Processo %d | pid: %d | ppid: %d\n",i,getpid(),getppid());
    }
    else {
      wait(NULL);
      exit(0);
    }
  }
  return 0;
}
