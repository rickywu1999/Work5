#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>


//Note to Nancy: will probably not start this until 8 or 9. If you have time, bugfix this (could not compile at library) and work on printing out size of the files
void print_dir(struct dirent ent, int level){
  while (ent){
    int c;
    DIR *d;
    struct dirent newent;
    char n[] = ent->name;
    printf("%s",n);
    
    if (ent->d_type == DT_REG){
      //this part is literally for spacing and formatiting purposes
      c =level;
      while (c > 0){
        printf("\n");
        c++;
      }
      printf("file\n");
    }
    
    if (ent->d_type == DT_DIR){
      printf("directory\n");
      //recursion is over here! basically if there is a directory, then use print_dir on the directory's ent
      d = opendir(n);
      newent = readdir(d);
      print_dir(newent,level++);
      closedir(d);
    }
    ent = readdir(d);
  }
}

int main(){
  DIR *d = opendir("stuff");
  if (!d){
    printf("Directory not found!\n");
    return 0;
  }
  struct dirent *ent = readdir (d);
  print_dir(ent,0);
  close_dir(d);
  return 0;
}
