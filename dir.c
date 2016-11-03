#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <string.h>

void print_dir(char * path, int level){
    int c;
    DIR *d;
    char s[100] = "";
    struct dirent *ent;
    
    struct stat sb;
    int total = 0;
    
    if (!(d = opendir(path))){
        printf("Directory not found!");
        return;
    }
    while ((ent = readdir(d))){
        
        //solely for idetation and  formatting purposes
        c =level;
        while (c > 0){
            printf("\t");
            c--;
        }
        //---------------------------------------------
        strcat(s,path);
        strcat(s,"/");
        strcat(s,ent->d_name);
        
        
        printf("|%s ",ent->d_name);
        
        if (ent->d_type == DT_REG){
            printf("(file)\n");
            stat(s,&sb);
            total += sb.st_size;
        }
        
        if (strcmp(ent->d_name,".") == 0 || strcmp(ent->d_name,"..") == 0 )
            printf("\n");
        
        else if (ent->d_type == DT_DIR){
            printf("(directory)\n");
            print_dir(s,level+1);
        }
        memset(s, 0, strlen(s));
    }
    closedir(d);
    c =level;
    while (c > 0){
        printf("\t");
        c--;
    }
    printf("||SIZE OF DIRECTORY: %d\n",total);
}

int main(){
    print_dir("stuff",0);
    return 0;
}
