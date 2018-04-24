#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX 20

sem_t thr1_turn, thr2_turn;
//compile with -lpthread

void *thr1_fun(void *arg);
void *thr2_fun(void *arg);

int main() {
  pthread_t thr1, thr2;
  sem_init(&thr1_turn, 0, 0);
  sem_init(&thr2_turn, 0, 0);
  if (pthread_create(&thr1, NULL, thr1_fun, NULL) != 0) {
    printf("***ERROR!*** Thread 1 creation failed!\n");
    exit(-1);
  }
  if (pthread_create(&thr2, NULL, thr2_fun, NULL) != 0) {
    printf("***ERROR!*** Thread 2 creation failed!\n");
    exit(-1);
  }
  if (pthread_join(thr1, NULL) != 0) {
    printf("***ERROR!*** Thread 1 joining failed!\n");
    exit(-1);
  }
  if (pthread_join(thr2, NULL) != 0) {
    printf("***ERROR!*** Thread 2 joining failed!\n");
    exit(-1);
  }
  pthread_exit(NULL);
  sem_destroy(&thr1_turn);
  sem_destroy(&thr2_turn);
  return 0;
}

void *thr1_fun(void *arg) {
  int n = 1;
  while (n <= MAX) {
    sem_wait(&thr1_turn);
    printf("Thr1: %d\n", n);
    n += 2;
    sem_post(&thr2_turn);
  }
  return NULL;
}

void *thr2_fun(void *arg) {
  int n = 2;
  sem_post(&thr1_turn);
  while (n <= MAX) {
    sem_wait(&thr2_turn);
    printf("Thr2: %d\n",n);
    n += 2;
    sem_post(&thr1_turn);
  }
  return NULL;
}

//https://www.youtube.com/watch?v=TYnNKdf7cZM
