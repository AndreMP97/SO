#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  pid_t pid;
  int cid, ppid, dif;
  pid = fork();
  if (pid < 0) {
    printf("Erro! Fork failed!\n");
    exit(1);
  }
  else if (pid == 0) {
      cid = getpid();
      ppid = getppid();
      dif = cid - ppid;
      printf("Processo filho | pid: %d | ppid: %d\n",cid,ppid);
      exit(dif);
  }
  else {
    int status;
    wait(&status);
    printf("Dif = %d\n",WEXITSTATUS(status));
  }
  return 0;
}
