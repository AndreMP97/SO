#include <stdio.h>

int main() {
  int i = 5;
  int *p = &i; //pointer, p=5;
  printf("Valor: %d\n",*p);
  printf("Endereco: %p\n",p);
  p++; //jump to next available memory address
  printf("Valor: %d\n",*p); //print value of memory address
  printf("Endereco: %p\n",p);
  *p++ = 0; //set memory address to 0xf000...
  printf("Endereco: %p\n",p);
  //printf("%d\n",*p); //core dumped, value not assigned
  return 0;
}
