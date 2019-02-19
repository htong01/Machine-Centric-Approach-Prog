#include <stdio.h>
#include <tgmath.h>

double cal(double x,char c,double y ){
  double result;

  if (c == '+'){
  	result = x + y;
  	printf("%lf\n",result);
    return(result);
  }
  else if (c == '-'){
  	result = x - y;
  	printf("%.13lf\n",result);
    return(result);
  }
  else if (c == '*'){
  	result = x * y;
  	printf("%lf\n",result);
    return(result);
  }
  else if (c == '/'){
  	result = x / y;
  	printf("%lf\n",result);
    return(result);
  }
   else if (c == '^'){
  	result =  pow(x,y);
  	printf("%lf\n",result);
    return(result);
  }
  return(0);
}


int main(int argc, char* argv[])
{
  double x, y;
  char c;
  scanf("%lf %c %lf", &x, &c, &y);
  cal(x,c,y);

  return(0);
}


