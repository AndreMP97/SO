#include <stdio.h>

int main() {
  //char
  char c, *cptr;
  c = 'a';
  cptr = &c;
  printf("tamanho de um char: %lu\n",sizeof(c));
  printf("tamanho do endereco de um char: %lu\n",sizeof(&c));
  printf("tamanho de um apontador para um char: %lu\n",sizeof(cptr));
  printf("tamanho do conteudo apontado por um apontador para um char: %lu\n",sizeof(*cptr));
  printf("Os valores apontados pelos endereços '%p' e '%p' sao '%c' e '%c'\n",&c,cptr,c,*cptr);
  //short
  short s, *sptr;
  s = 1000;
  sptr = &s;
  printf("tamanho de um short: %lu\n",sizeof(s));
  printf("tamanho do endereco de um short: %lu\n",sizeof(&s));
  printf("tamanho de um apontador para um short: %lu\n",sizeof(sptr));
  printf("tamanho do conteudo apontado por um apontador para um short: %lu\n",sizeof(*sptr));
  printf("Os valores apontados pelos endereços '%p' e '%p' sao '%d' e '%d'\n",&s,sptr,s,*sptr);
  //int
  int i, *iptr;
  i = 1000;
  iptr = &i;
  printf("tamanho de um int: %lu\n",sizeof(i));
  printf("tamanho do endereco de um int: %lu\n",sizeof(&i));
  printf("tamanho de um apontador para um int: %lu\n",sizeof(iptr));
  printf("tamanho do conteudo apontado por um apontador para um int: %lu\n",sizeof(*iptr));
  printf("Os valores apontados pelos endereços '%p' e '%p' sao '%d' e '%d'\n",&i,iptr,i,*iptr);
  //long
  long l, *lptr;
  l = 1000000;
  lptr = &l;
  printf("tamanho de um long: %lu\n",sizeof(l));
  printf("tamanho do endereco de um long: %lu\n",sizeof(&l));
  printf("tamanho de um apontador para um long: %lu\n",sizeof(lptr));
  printf("tamanho do conteudo apontado por um apontador para um long: %lu\n",sizeof(*lptr));
  printf("Os valores apontados pelos endereços '%p' e '%p' sao '%ld' e '%ld'\n",&l,lptr,l,*lptr);
  //float
  float f, *fptr;
  f = 1.0;
  fptr = &f;
  printf("tamanho de um float: %lu\n",sizeof(f));
  printf("tamanho do endereco de um float: %lu\n",sizeof(&f));
  printf("tamanho de um apontador para um float: %lu\n",sizeof(fptr));
  printf("tamanho do conteudo apontado por um apontador para um float: %lu\n",sizeof(*fptr));
  printf("Os valores apontados pelos endereços '%p' e '%p' sao '%.2f' e '%.2f'\n",&f,fptr,f,*fptr);
  //double
  double d, *dptr;
  d = 1.0;
  dptr = &d;
  printf("tamanho de um double: %lu\n",sizeof(d));
  printf("tamanho do endereco de um double: %lu\n",sizeof(&d));
  printf("tamanho de um apontador para um double: %lu\n",sizeof(dptr));
  printf("tamanho do conteudo apontado por um apontador para um double: %lu\n",sizeof(*dptr));
  printf("Os valores apontados pelos endereços '%p' e '%p' sao '%lf' e '%lf'\n",&d,dptr,d,*dptr);
  return 0;
}
