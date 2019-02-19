
#include "problem1.h"
#include <stdio.h>

void linspace(double* array, double min, double max, int n)
{
  if(n <= 0 || array == NULL){
    printf("invalid input");
  }
  else if (n == 1){
  	printf("%f\n", min);                // if n = 1, return it's min number.
  }
  else{
    double diff = (max - min)/(n - 1);  // if n != 1, find the difference between each element first
    for(int i=0;i<n;i++){
    	printf("%f ",min + i*diff);
    	array[i] = min + i*diff;          // each element is the mininum plus it's "distance" to minimum
    }
    printf("\n");
  }

}

