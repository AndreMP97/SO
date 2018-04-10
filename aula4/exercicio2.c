#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define READ 0
#define WRITE 1

int main() {
  int fd[2];
  pid_t pid;
  if (pipe(fd) < 0) {
    printf("Erro! Pipe failed!\n");
    exit(-1);
  }
  if ((pid = fork()) < 0) {
    printf("Erro! Fork failed!\n");
    exit(-1);
  }
  if (pid == 0) {
    close(fd[WRITE]);
    dup2(fd[READ], STDIN_FILENO);
    close(fd[READ]);
    if (execlp("more", "more", NULL) < 0) {
      printf("Erro a executar!\n");
      exit(-1);
    }
  }
  else {
    char buf[100];
    int n;
    close(fd[READ]);
    for (int i = 0; i < 100; i++) {
      sprintf(buf,"Linha %d\n",(i+1));
      write(fd[WRITE], buf, strlen(buf));
    }
    close(fd[WRITE]);
    wait(NULL);
  }
  return 0;
}
