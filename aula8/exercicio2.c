#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long *create_vector1(int);
long long *create_vector2(int);
void do_work(void);
void *new_worker(void *arg);
void produto_interno(int, int);

int threads, vector_size;
long long prod_int, *vector_a, *vector_b;
pthread_mutex_t mutex;

int main(int argc, char *argv[]) {
  vector_size = atoi(argv[1]);
  threads = atoi(argv[2]);
  vector_a = create_vector1(vector_size);
  vector_b = create_vector2(vector_size);
  do_work();
  return EXIT_SUCCESS;
}

long long *create_vector1(int size) {
  int i;
  long long *vector;
  vector = (long long *) malloc(size * sizeof(long long));
  for (i = 0; i < size; i++)
    vector[i] = i;
  return vector;
}

long long *create_vector2(int size) {
  int i;
  long long *vector;
  vector = (long long *) malloc(size * sizeof(long long));
  for (i = 0; i < size; i++)
    vector[i] = size-i-1;
  return vector;
}

void do_work(void) {
  prod_int = 0;
  pthread_t workers[threads];
  long wid;
  pthread_mutex_init(&mutex, NULL);
  for (wid = 0; wid < threads; wid++) {
    if (pthread_create(&workers[wid], NULL, new_worker, (void *) wid) != 0) {
      printf("***ERROR!*** Thread %ld creation failed!\n",wid);
      exit(-1);
    }
  }
  for (wid = 0; wid < threads; wid++) {
    if (pthread_join(workers[wid], NULL) != 0) {
      printf("***ERROR!*** Thread %ld joining failed!\n",wid);
      exit(-1);
    }
  }
  //produto_interno(0, vector_size);
  //printf("Produto Interno = %lld\n", prod_int);
  return;
}

void *new_worker(void *arg) {
  int block, start, end;
  long wid;
  wid = (long) arg;
  block = vector_size/threads;
  if ((block * threads) != vector_size) {
    block++;
  }
  start = block*wid;
  end = start + block;
  if (start > vector_size) {
    end = vector_size;
  }
  produto_interno(start,end);
  printf("Produto Interno = %lld\n", prod_int);
  return NULL;
}

void produto_interno(int start, int end) {
  for (int i = start; i < end; i++) {
    pthread_mutex_lock(&mutex);
    prod_int += vector_a[i] + vector_b[i];
    pthread_mutex_unlock(&mutex);
  }
}

/*void produto_interno(int start, int end) {
  long long sum = 0;
  for (int i = start; i < end; i++) {
    sum += vector_a[i] + vector_b[i];
  }
  pthread_mutex_lock(&mutex);
  prod_int += sum;
  pthread_mutex_unlock(&mutex);
}*/

/*void produto_interno(int start, int end) {
  int i;
  for (i = start; i < end; i++)
  prod_int += vector_a[i] * vector_b[i];
  return;
}*/
