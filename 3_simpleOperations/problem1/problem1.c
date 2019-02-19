
#include "problem1.h"
#include <stdio.h>

 int print_factors(int n)
// int main()
{
  int i;
  // printf("The input number is %d \n",n);
  printf("Prime factor is: ");
  if(n<=1){
  	printf("Invalid input");
  	return(NULL);
  }
  while (n > 1){
  	 for(i = 1; i <= n; i++){
	  	 if(n % i == 0 && i != 1){
	  	 	printf("%d ", i);
	  	 	n = n/i;
	  	 	break;
	  	} 
      }
	
    }
  printf("\n");
  return(0);
}

