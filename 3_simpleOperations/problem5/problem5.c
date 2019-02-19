
#include "problem5.h"
#include <stdlib.h>
#include <stdio.h>
void print_random(int n, int max)
{
  // printf("%d random integers in range %d: \n",n,max);
  if(n<=0){
		printf("invalid input\n");
	}
  if(max == 0){
		printf("%d ",max);
	}
  if(max != 0){
  for(int i = 1; i <= n; i++){
    int r = rand() % (max);
    printf("%d ",r);
  }
}
  printf("\n");
}

