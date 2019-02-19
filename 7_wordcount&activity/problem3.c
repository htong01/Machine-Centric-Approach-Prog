/* problem3.c - Word counting */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct RESULT{                                // build a structure to store all the three result values
  int count_w;
  int count_l;
  int count_c;
};

void process_file(char file[], int argc, char* argv[])
{

  struct RESULT R1;
  R1.count_w = R1.count_c = R1.count_l = 0;
  int state = 0;                             // state marks the beginning of a new word. If state=0, then the next character is start of a new word
  int c;


  FILE *fp = fopen(file, "r");
    while((c = getc (fp)) != EOF){             // read in files by characters
    R1.count_c++;                            // count for bytes
   if(c==' '){
     state = 0;
   }
   else if( c=='\n' || c=='\t'){
      state = 0;
      R1.count_l++;                        // only when meet \n or \t, count for a new line
   }
   else if(state == 0){
     state = 1;
     R1.count_w++;                         // only record words when state=0
   }
  }

  if(argc == 2) 
    printf("%d %d %d %s\n", R1.count_l, R1.count_w, R1.count_c,argv[1]);
  else
  {

    int options[3] = {0,0,0};
    for(int i = 1; i < argc; i++)
    {
      if(strcmp(argv[i],"-l")==0)
        options[0] = R1.count_l;
      else if(strcmp(argv[i],"-w")==0)
        options[1] = R1.count_w;
      else if(strcmp(argv[i],"-c")==0)
        options[2] = R1.count_c;
    }
    for(int i = 0; i < 3; i++)
    {
      if(options[i] != 0)
        printf("%d ", options[i]);
    }
    printf("%s\n", file);
  }
  fclose(fp);
}

//Case2: Count based on stdin
void process_stdin(int argc, char* argv[])
{
  struct RESULT R1;
  R1.count_w = R1.count_c = R1.count_l = 0;
  int state = 0;                             // state marks the beginning of a new word. If state=0, then the next character is start of a new word
  int c;
  char ch;


  while((ch = getchar())!=EOF)
  {
    R1.count_c++;                            // count for bytes
   if(c==' '){
     state = 0;
   }
   else if( c=='\n' || c=='\t'){
      state = 0;
      R1.count_l++;                        // only when meet \n or \t, count for a new line
   }
   else if(state == 0){
     state = 1;
     R1.count_w++;                         // only record words when state=0
   }
  }
  if(argc == 1)
    printf("%d %d %d\n", R1.count_l, R1.count_w, R1.count_c);
  else
  {

    int options[3] = {0,0,0};
    for(int i = 1; i < argc; i++)
    {
      if(strcmp(argv[i],"-l")==0)
        options[0] = R1.count_l;
      else if(strcmp(argv[i],"-w")==0)
        options[1] = R1.count_w;
      else if(strcmp(argv[i],"-c")==0)
        options[2] = R1.count_c;
    }
    for(int i = 0; i < 3; i++)
    {
      if(options[i] != 0)
        printf("%d ", options[i]);
    }
  }
}

int main(int argc, char* argv[])
{
  if(argc == 1)
    process_stdin(argc, argv); 
  else if(argc >= 2)
  { 
    int flag = 0;
    for(int i = 1; i < argc; i++)
    {
      if(argv[i][0] == '-')
        continue;
      else
      {
        flag = 1;
        process_file(argv[i],argc,argv); //read from file
        break;
      }
    }
    if(flag == 0)
      process_stdin(argc, argv); //read from stdin
  }
  return 0;
}

