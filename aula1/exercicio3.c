#include <stdio.h>

int main() {
  int x[3] = {23, 41, 17};
  printf("x[0]=%d\nx[1]=%d\nx[2]=%d\n",x[0],x[1],x[2]);
  printf("x=%p\n*x=%d\n",x,*x);
  printf("x+1=%p\n",x+1);
  printf("*x+1=%d\n",*(x+1));
  printf("x+2=%p\n*x+2=%d\n",x+2,*(x+2)); //*(x+2)=x[2]
  printf("&(x[0])=%p\n*&(x[0])=%d\n",&(x[0]),*&(x[0])); //&(x[0])=x
  printf("&*(x[0])=%d\n",&*(x[0])); //invalid
  return 0;
}
