#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define READ 0
#define WRITE 1

int main() {
  int fd[2], i;
  pid_t pid;
  printf("Numero de argumentos: ");
  scanf("%d",&i);
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
    char buf[100];
    int n;
    while ((n = read(fd[READ], buf, 99)) > 0) {
      buf[n] = '\0';
      printf("Filho: %s",buf);
    }
    close(fd[READ]);
    buf[n] = 0;
  }
  else {
    close(fd[READ]);
    for (int j = 0; j < i; j++) {
      char *msg;
      scanf("%as",&msg);
      write(fd[WRITE], msg, strlen(msg));
    }
    close(fd[WRITE]);
  }
  return 0;
}
