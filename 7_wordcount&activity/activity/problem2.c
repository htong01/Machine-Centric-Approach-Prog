/* problem2.c - Activity summary */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>  // isdigit()

int main(int argc, char* argv[])
{
  if(argv[1] == NULL || strlen(argv[1])==1 ){  // summary duration not specified
        printf("usage\n");                // print the message on how to use it.
        return(0);
  }

  for(int i=0; i<strlen(argv[1])-1; i++){ // when input is not the format we want
    if(! isdigit(argv[1][i]) ){
      printf("usage \n");
      return(0);
    }
  }



// If all standard input, duration time specified and also other description does not include numbers
  long int dur_time;
  int num;
  int len = strlen(argv[1]);
  long int day = 24*60*60;

  for (int i=0;i<len-1;i++){
  	num = strtol(&argv[1][i], NULL, 0);          // convert input to int
  }
  // printf("%d\n",num);
  if(argv[1][len-1] == 'd'){
  	dur_time = num * day;
  }
  else if(argv[1][len-1] == 'w'){
  	dur_time = num * day *7;             // 7 days one week
  }
  else if(argv[1][len-1] == 'y'){
  	dur_time = num * day * 365;           // 365 days one year
  }



  FILE *fp ;
  fp = fopen("activity.tsv","r");       // open file

  if(fp == NULL){
  	printf("error\n"); 
  	return(0);
  }


  char buff[256];
  time_t rawtime = time(&rawtime);
  long int bound = rawtime - dur_time;
  int total = 0;
  while(fgets(buff, 255, (FILE*)fp) != NULL)
  {
    char* c1 = strtok(buff, "\t");
    char* c2 = strtok(NULL, "\t");
    char* c3 = strtok(NULL, "\t");
    long int t = atoi(c1);
    if(t >= bound)
    {
      int mins = atoi(c3);
      total += mins;
    }
  }
  printf("Total exercise: %d minutes\n", total);

  return(total);
}


