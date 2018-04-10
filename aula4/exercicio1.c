#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
    char buf[100];
    int n;
    while ((n = read(fd[READ], buf, 99)) > 0) {
      buf[n] = '\0';
      printf("Filho: %s",buf);
      write(STDOUT_FILENO,buf,n);
    }
    close(fd[READ]);
    buf[n] = 0;
  }
  else {
    close(fd[READ]);
    char* msg1 = "Hello world!\n";
    char* msg2 = "Goodbye!\n";
    write(fd[WRITE], msg1, strlen(msg1));
    sleep(1);
    write(fd[WRITE], msg2, strlen(msg2));
    close(fd[WRITE]);
  }
  return 0;
}
