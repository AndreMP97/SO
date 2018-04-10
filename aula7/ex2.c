#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int signal_ok = 0;

void my_handler(int sig) {
  if (sig == SIGUSR1) {
    signal_ok = 1;
  }
}

int main() {
  pid_t pid;
  signal(SIGUSR1, my_handler);
  pid = fork();
  if (pid == 0) {
    while(signal_ok == 0);
    printf("Filho\n");
  }
  else {
    printf("Pai\n");
    kill(pid, SIGUSR1);
    wait(NULL);
  }
  return 0;
}
