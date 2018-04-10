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
  int n, max = 20;
  pid_t pid;
  char *sempai = "/sempai", *semfilho = "/semfilho";
  sem_t *s_filho = sem_open(semfilho, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0);
  sem_t *s_pai = sem_open(sempai, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0);
  sem_unlink(semfilho);
  sem_unlink(sempai);
  pid = fork();
  if (pid == 0) {
    n = 1;
    while (n <= max) {
      sem_wait(s_filho);
      printf("FILHO: %d\n", n);
      n += 2;
      sem_post(s_pai);
    }
  }
  else {
    n = 2;
    sem_post(s_filho);
    while (n <= max) {
      sem_wait(s_pai);
      printf("PAI: %d\n",n);
      sem_post(s_filho);
      n += 2;
    }
    //wait(NULL);
  }
  sem_close(s_filho);
  sem_close(s_pai);
  return 0;
}
