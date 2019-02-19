
#include "problem3.h"
#include <stdio.h>

int* find_sequence(int* seq, int n)
{
  int* pointer;
  
  if(seq==NULL || n==0){
    printf("invalid input");    // if NULL array
    return(NULL);
  }



  const int m = n;
  int a[m];
  a[0] = 0;
  int j = 0;
  int len = 0;
  int ind = 0;

  for(int i=0;i<n;i++){
  	if(seq[i-1]>seq[i]){         // stands for the start of a new subsequence
  		// printf("%d, ",i);
  		j = i;                     // record such starting point
  	}
    if(len < (i-j+1)){  // if  length less than new subsequence
      len = (i-j+1);    // record the current length
      ind = j;           // index = new start point
    }
  }

if(len <= 1){
  return(NULL);            // no increasing subsequence
}
else{
  pointer = &seq[ind];
  return(pointer);
  }
}

