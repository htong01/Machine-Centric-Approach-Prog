/* problem1.c - Activity log */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
  if(argv[1] == NULL || argv[2] == NULL){ // when activity or duration empty
      	printf("usage\n");                // print the message on how to use it.
      	return(0);
  }

  for(int i=0; i<strlen(argv[2]); i++){ // when input is not the format we want
    if(! isdigit(argv[2][i]) ){
      printf("usage\n");
      return(0);
    }
  }

  FILE *fp = NULL;
  fp = fopen("activity.tsv","a+"); // open a file, if not exit, create one. Previous content will be kept by "a+"

  time_t t = time(&t);             // current time
  fprintf(fp,"%ld",t);
  for (int i = 1; i < argc; i++)
    {
      fprintf(fp,"\t");
      fprintf(fp,"%s",argv[i]);   // write the command line content to the file
    }
  fprintf(fp,"\n");
  fclose(fp);                      // close file 

  return(0);
}

