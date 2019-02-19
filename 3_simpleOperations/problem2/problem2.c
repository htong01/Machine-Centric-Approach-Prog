
#include "problem2.h"
#include <stdio.h>
#include<math.h>

int find_power(int n)
{
  printf("input number is: %d \n",n);
  if (n == 1){
    return(1);
  }
  int i;
  for(i = n; i > 1; i--){
  	float num = log2(i);
    if (num - (int)num == 0){
    	printf("the largest power of 2 is %d \n",i);
        return(i); 
    	break;
    }
  }
return(0);

}

