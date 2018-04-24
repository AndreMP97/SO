#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <linux/limits.h>
#include <sys/types.h>
#include <sys/stat.h>

void my_du(char *subdir);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("***ERROR***! Too many arguments!\n");
    exit(-1);
  }
  my_du(argv[1]);
  return 0;
}

void my_du(char *subdir) {
  DIR *my_dir;
  struct dirent *my_dirent;
  struct stat my_stat;
  long long total = 0, curr;
  if ((my_dir = opendir(subdir)) == NULL) {
    printf("***ERROR***! Couldn't open directory!\n");
    exit(-1);
  }
  while ((my_dirent = readdir(my_dir)) != NULL) {
    if (lstat(subdir, &my_stat) < 0) {
      printf("***ERROR***! lstat!\n");
      exit(-1);
    }
    if (S_ISREG(my_stat.st_mode)) {
      printf("Blocks allocated:         %lld\n",(long long) my_stat.st_blocks);
      curr = (my_stat.st_blocks*512) - my_stat.st_blocks;
      total += curr;
    }
  }
  printf("Space wasted:         %lld\n",total);
  if (closedir(my_dir) < 0) {
    printf("***ERROR***! Couldn't close directory!\n");
    exit(-1);
  }
}

//multiplar por 512 e subtrair pelo tamanho real
