#include <stdio.h>
#define SIZE 10

void show_vector(char *a, int n);

int main() {
  char v[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  show_vector(v, SIZE);
  printf("string: %s\n",v);
  return 0;
}

void show_vector(char *a, int n) {
  int i;
  for (i = 0; i < n; i++) {
    // imprima aqui os valores e os endereços de cada elemento do vector
    printf("endereco v[%d]: %p\nvalor v[%d]: %c\n",i,&a[i],i,a[i]);
  }
}
