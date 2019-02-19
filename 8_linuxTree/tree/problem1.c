/* problem1.c - implementation of Linux `tree` */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>  // opendir()/ readdir()/ closedir()
#include <dirent.h>
#include <sys/stat.h>   // stat()
#include <unistd.h>    // getcwd


int trave_dir(char* path,int depth)
{
    DIR *d;                // declarations⬇
    struct dirent *file; 
    struct stat sb;    
    char c[5] = "    ";

    d = opendir(path);
    if(d == NULL){
        printf("error opendir %s \n",path);           // invalid input
        return (-1);
    }

    while((file = readdir(d)) != NULL)
    {
        if(strncmp(file->d_name, ".", 1) == 0){       // Remove hidden files(start from '.')
            continue;
        }
        for(int j=1;j<depth;j++){
            printf("%s",c);
        }
        printf("%s\n", file->d_name);

        char file_path[200];
		bzero(file_path,200);                        // initialize the file_path in each recursion
		strcat(file_path,path);
		strcat(file_path,"/");
		strcat(file_path,file->d_name);              // generate new path

        stat(file_path, &sb);
        if( S_ISDIR(sb.st_mode) )                    // check whether the file is a directory
        {
            // for(int j=0;j<depth;j++){
            //     printf("%s",c);
            // }
            trave_dir(file_path,depth + 1);                    // continue searching

        }
    }
    // printf("    ");
    closedir(d);
    return (0);
}

int main(int argc, char* argv[])
{
    char *file = argv[1];
    int depth = 1;
    if (argv[1] == NULL){
        char buffer[100];  
        getcwd(buffer,100);      // if no specific input, set path to the current directory
        file = buffer;
    }

    trave_dir(file,depth);

    printf("\n");
    return (0);
}

