/* problem1.c - implementation of Linux `tree` */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>  // opendir()/ readdir()/ closedir()
#include <dirent.h>
#include <sys/stat.h>   // stat()
#include <unistd.h>    // getcwd


int travel_dir(char* path)
{
    DIR *d;                // declarations⬇
    struct dirent *file; 
    struct stat sb;    

    int count = 0;


    d = opendir(path);
    char new_path[10][100];

    while((file = readdir(d)) != NULL)
    {
        if(strncmp(file->d_name, ".", 1) == 0){       // Remove hidden files(start from '.')
            continue;
        }
        printf("%s ", file->d_name);

        char file_path[200];
		bzero(file_path,200);                        // initialize the file_path in each recursion
		strcat(file_path,path);
		strcat(file_path,"/");
		strcat(file_path,file->d_name);              // generate new path

        stat(file_path, &sb);
        if( S_ISDIR(sb.st_mode) )                    // check whether the file is a directory
        {
            strcpy(new_path[count], file_path);      // save all the nodes
            count++;
        }
    }
        printf("    ");

    for(int i = 0;i<count;i++){
        travel_dir(new_path[i]);                    // continue searching, using BFS
    }
    closedir(d);
    return (0);
}

int main(int argc, char* argv[])
{
    char *file = argv[1];

    if (argv[1] == NULL){
        char buffer[100];  
        getcwd(buffer,100);      // if no specific input, set path to the current directory
        file = buffer;
    }

    travel_dir(file);

    printf("\n");
    return (0);
}

