/* excitedly.c
 * Code to make writing "more exciting"
 * EE 200 Exam 1
 * 9 October 2018
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>




int main(int argc, char* argv[])
{
  FILE* input = fopen("boring.txt","r");
  FILE* output = fopen("exciting.txt","w+");
  
  char buf[255];
  // char a[] = "the";
  // char b[] = "the one and only";

  while(fgets(buf,255,(FILE*)input)){
  	for(int i=0;i<strlen(buf);i++){
    	if( !strncmp(&buf[i],"!",1)){
          fprintf(output,"%c%c%c",buf[i],buf[i],buf[i]);
          continue;
          
        }
      else if( (!strncmp(&buf[i],".",1) ) && ( (!strncmp(&buf[i-1],"t",1)) || (!strncmp(&buf[i-1],"s",1)) ) ) {
          fprintf(output,"!");
      }
      else if( ( (!strncmp(&buf[i-1],"'",1)) || (!strncmp(&buf[i]," ",1))) && (!strncmp(&buf[i-1],"e",1)) && (!strncmp(&buf[i-2],"h",1) && (!strncmp(&buf[i-3],"t",1)) ) ) {
          fprintf(output," one and only");
      }
      else{
    	  fprintf(output,"%c",buf[i]);
        }
    }

  }


  fclose(input);
  fclose(output);

  return(0);
}

