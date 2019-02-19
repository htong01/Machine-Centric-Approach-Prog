
#include "problem2.h"
#include <stdio.h>

int* find_min(int* array, int n)
{
  if(array == NULL){
    printf("invalid input");
    return(0);
  }
  
  int a = array[0];
  int* pointer;
  if(n<=0){
  	return(NULL);                // if array has no element or wrong input, return NULL
  }
  for(int i = 0; i < n; i++){
  	if(array[i]<a){             
  		a = array[i];              // if the current element is smaller than the previous one, exchange
      pointer = &array[i];       // take address of the smallest element
  	}
  }
  printf("smallest element is %d\n",a);
return(pointer);
}

