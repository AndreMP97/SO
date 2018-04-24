#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
  DIR *dp;
  struct dirent *dirp;
  if (argc != 2) {
    printf("***ERROR***! Too many arguments!\n");
    exit(-1);
  }
  if ((dp = opendir(argv[1])) == NULL) {
    printf("***ERROR***! Couldn't open directory!\n");
    exit(-1);
  }
  while ((dirp = readdir(dp)) != NULL) {
      printf("Entrada: %s\n", dirp -> d_name);
  }
  if (closedir(dp) < 0) {
    printf("***ERROR***! Couldn't close directory!\n");
    exit(-1);
  }
  return 0;
}
