#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <linux/limits.h>
#include <sys/types.h>
#include <sys/stat.h>

void my_find(char *pathname, char *filename);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("***ERROR***! Too many arguments!\n");
    exit(-1);
  }
  my_find(".",argv[1]);
  return 0;
}

void my_find(char *pathname, char *filename) {
  DIR *my_dir;
  struct dirent *my_dirent;
  struct stat my_stat;
  char str[NAME_MAX];
  if ((my_dir = opendir(pathname)) == NULL) {
    printf("***ERROR***! Couldn't open directory!\n");
    exit(-1);
  }
  while ((my_dirent = readdir(my_dir)) != NULL) {
    if(strcmp(".", my_dirent -> d_name) != 0 && strcmp("..", my_dirent -> d_name) != 0) {
      sprintf(str,"%s/%s",pathname,my_dirent->d_name);
      if (strcmp(filename, my_dirent->d_name) == 0) {
        printf("Found %s\n",str);
      }
      if (lstat(str, &my_stat) < 0) {
        printf("***ERROR***! lstat!\n");
        exit(-1);
      }
      if (S_ISDIR(my_stat.st_mode)) {
        my_find(str,filename);
      }
    }
  }
  if (closedir(my_dir) < 0) {
    printf("***ERROR***! Couldn't close directory!\n");
    exit(-1);
  }
}
