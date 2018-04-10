#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  pid_t pid;
  pid = fork();
  if (pid < 0) {
    printf("Erro! Fork failed!\n");
    exit(1);
  }
  else if (pid == 0) {
    if (execlp("ls", "ls", "-l", NULL) < 0) {
      printf("shouldn't be here\n");
      exit(1);
    }
  }
  else {
    wait(NULL);
  }
  return 0;
}
