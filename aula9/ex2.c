#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  DIR *dp;
  struct dirent *dirp;
  struct stat my_stat;
  if (argc != 2) {
    printf("***ERROR***! Too many arguments!\n");
    exit(-1);
  }
  if ((dp = opendir(argv[1])) == NULL) {
    printf("***ERROR***! Couldn't open directory!\n");
    exit(-1);
  }
  while ((dirp = readdir(dp)) != NULL) {
      printf("------------------------------\n");
      printf("Entrada: %s\n", dirp -> d_name);
      if (lstat(argv[1], &my_stat) < 0) {
        perror("lstat");
        exit(-1);
      }
      printf("File type:                ");
      if(S_ISREG(my_stat.st_mode))       printf("regular file\n");
      else if(S_ISDIR(my_stat.st_mode))  printf("directory\n");
      else if(S_ISCHR(my_stat.st_mode))  printf("character special files\n");
      else if(S_ISBLK(my_stat.st_mode))  printf("block special files\n");
      else if(S_ISFIFO(my_stat.st_mode)) printf("FIFO/pipe\n");
      else if(S_ISLNK(my_stat.st_mode))  printf("symbolic links\n");
      else if(S_ISSOCK(my_stat.st_mode)) printf("socket\n");
      else printf("unknown?\n");
      printf("I-node number:            %ld\n", (long) my_stat.st_ino);
      printf("Blocks allocated:         %lld\n",(long long) my_stat.st_blocks);
  }
  if (closedir(dp) < 0) {
    printf("***ERROR***! Couldn't close directory!\n");
    exit(-1);
  }
  return 0;
}
