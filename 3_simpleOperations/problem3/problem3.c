
#include "problem3.h"
#include <stdio.h>
#include <tgmath.h>

double calculate(double x, char operation, double y)
{
  double result;
  if (operation == '+'){
  	result = x + y;
  	printf("%f\n",result);
      return(result); 
  }
  else if (operation == '-'){
  	result = x - y;
  	printf("%f\n",result);
          return(result); 
  }
  else if (operation == '*'){
  	result = x * y;
  	printf("%f\n",result);
          return(result); 
  }
  else if (operation == '/'){
    if(y == 0){
      printf("invalid input");
      return(0);
    }
  	result = x / y;
  	printf("%f\n",result);
          return(result); 
  }
   else if (operation == '^'){
  	result =  pow(x,y);
  	printf("%f\n",result);
          return(result); 
  }

return(0);
}

