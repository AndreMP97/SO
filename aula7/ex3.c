#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

//compile with -lpthread

int main() {
  pid_t pid;
  char *name = "/sem";
  sem_t *s_turn = sem_open(name, O_CREAT | O_EXCL, S_IRUSR, S_IWUSR, 0);
  sem_unlink(name);
  pid = fork();
  if (pid == 0) {
    sem_wait(s_turn);
    printf("FILHO\n");
  }
  else {
    sem_post(s_turn);
    printf("PAI\n");
    wait(NULL);
  }
  sem_close(s_turn);
  return 0;
}
