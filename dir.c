#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>

int main(){
  DIR *d = opendir("stuff");
  if (!d){
    printf("Directory not found!\n");
    return 0;
  }
  struct dirent *ent = readdir (d);
  while (ent){
    printf("%s: ",ent->d_name);
    if (ent->d_type == DT_REG)   
      printf("file\n");
    else
      printf("directory\n");
    ent = readdir(d);
  }
  return 0;
}
