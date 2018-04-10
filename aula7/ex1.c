#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void my_handler(int sig) {
  switch(sig) {
    case SIGTSTP: {
      printf("Ctrl-z\n");
      printf("PID : %d\n", getpid());
      break;
    }
    case SIGINT: {
      printf("Ctrl-c\n");
      printf("PID : %d\n", getpid());
      break;
    }
    default: {
      printf("Debug!\n");
      break;
    }
  }
}

int main() {
  signal(SIGTSTP, my_handler);
  signal(SIGINT, my_handler);
  signal(SIGTERM, my_handler);
  signal(SIGKILL, my_handler);
  while(1) {
    pause();
  }
  return 0;
}
