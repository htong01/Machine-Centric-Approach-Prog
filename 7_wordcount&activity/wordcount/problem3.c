/* problem3.c - Word counting */
#include <stdio.h>
#include <string.h>

struct RESULT{                                // build a structure to store all the three result values
  int count_w;
  int count_l;
  int count_c;
};


struct RESULT count(FILE *fp) 
{
  struct RESULT R1;
  R1.count_w = R1.count_c = 0;               // initializations
  R1.count_l = 0;                            // if there have input, must already have a line. Other code only count for new lines
  int state = 0;                             // state marks the beginning of a new word. If state=0, then the next character is start of a new word
  int c;
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
return(R1);
}



int main(int argc, char* argv[])
{
  if(strcmp(argv[1], "-l") == 0 ||strcmp(argv[1], "-w") == 0 || strcmp(argv[1], "-c") == 0){

    char* filename = argv[argc-1];
    FILE *fp = fopen (filename, "r");          // open the file
  if(fp == NULL){                            // if filename is not specified, read from stdin
    fp = fopen ("new_file.tsv", "w+");       // write the input to a new file
    fprintf(fp,"%s",argv[argc-1]);
    fclose(fp);  
    fp = fopen ("new_file.tsv", "r");
  }
  struct RESULT R1 = count(fp);
  fclose(fp);

   if(argc == 2){                       // if action not specified, print all counting result and return
    printf("%d %d %d %s\n", R1.count_l, R1.count_w, R1.count_c,filename);
    // fclose(fp);
    return(0);
  }


  if( strcmp(argv[1], "-l") == 0 ){          // if action specified:
    printf("%d ", R1.count_l);     
  }
  else if( strcmp(argv[1], "-w") == 0 ){
    printf("%d ", R1.count_w);
  }
  else if( strcmp(argv[1], "-c") == 0 ){
    printf("%d ", R1.count_c);     
  }
  if(argv[2]!=NULL){

  if( strcmp(argv[2], "-l") == 0 ){          // if action specified:
   printf("%d ", R1.count_l);     
  }
  else if( strcmp(argv[2], "-w") == 0 ){
   printf("%d ", R1.count_w);
  }
  else if( strcmp(argv[2], "-c") == 0 ){
   printf("%d ", R1.count_c);     
  }
}

  printf("%s",filename);
  }


else{
  char* filename = argv[1];                  // input a filename
  FILE *fp = fopen (filename, "r");          // open the file
  if(fp == NULL){                            // if filename is not specified, read from stdin
  	fp = fopen ("new_file.tsv", "w+");       // write the input to a new file
  	fprintf(fp,"%s ",argv[1]);
  	fclose(fp);  
  	fp = fopen ("new_file.tsv", "r");
  }
  struct RESULT R1 = count(fp);
  fclose(fp);

  if(argv[2] == NULL){                       // if action not specified, print all counting result and return
  	printf("%d %d %d %s\n", R1.count_l, R1.count_w, R1.count_c,filename);
  	// fclose(fp);
  	return(0);
  }

  if( strcmp(argv[2], "-l") == 0 ){          // if action specified:
  	printf("%d ", R1.count_l);     
  }
  else if( strcmp(argv[2], "-w") == 0 ){
  	printf("%d ", R1.count_w);
  }
  else if( strcmp(argv[2], "-c") == 0 ){
  	printf("%d ", R1.count_c);     
  }

  if(argv[3] != NULL){
      if( strcmp(argv[3], "-l") == 0 ){
    printf("%d ", R1.count_l);     
  }
  else if( strcmp(argv[3], "-w") == 0 ){
    printf("%d ", R1.count_w);
  }
  else if( strcmp(argv[3], "-c") == 0 ){
    printf("%d ", R1.count_c);     
  }

  }
  printf("%s",filename);
}


  return(0);
}

