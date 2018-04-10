#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>

int signal_ok = 0;

void my_handler(int sig) {
  if (sig == SIGUSR1) {
    signal_ok = 1;
  }
}

void wait_for_signal() {
  while(signal_ok == 0) sched_yield();
  signal_ok = 0;
}

int main() {
  int n, max = 10000;
  pid_t pid;
  signal(SIGUSR1, my_handler);
  pid = fork();
  if (pid == 0) { //filho
    pid = getppid();
    n = 1;
    while(n <= max) {
      printf("FILHO %d\n",n);
      n += 2;
      kill(pid, SIGUSR1);
    }
    wait_for_signal();
  }
  else {
    n = 2;
    while (n <= max) {
      wait_for_signal();
      printf("PAI %d\n",n);
      n += 1;
      kill(pid, SIGUSR1);
    }
    wait(NULL);
  }
  return 0;
}
