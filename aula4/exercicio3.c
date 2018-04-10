#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

#define READ 0
#define WRITE 1

int main(int argc, char *argv[]) {
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
    int file = open(argv[2], O_CREAT | O_TRUNC | O_RDWR, S_IRWXU);
    dup2(fd[READ],STDIN_FILENO);
    dup2(file, STDOUT_FILENO);
    close(fd[WRITE]);
    close(fd[READ]);
    execlp("grep", "grep", argv[3], NULL);
  }
  else {
    int file = open(argv[1],O_RDONLY);
    if (file < 0) {
      printf("Erro! O ficheiro não existe!\n");
      exit(-1);
    }
    dup2(file, STDIN_FILENO);
    dup2(fd[WRITE], STDOUT_FILENO);
    close(fd[READ]);
    close(fd[WRITE]);
    execlp("cat", "cat", NULL);
  }
  return 0;
}
