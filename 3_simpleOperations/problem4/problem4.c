
#include "problem4.h"
#include <stdio.h>
#include <math.h>

Triangle getLarger(Triangle first, Triangle second)
{
  Triangle t;
  double s1 = fabs( 0.5 * ((first.b.x - first.a.x) * (first.c.y - first.a.y) - (first.c.x - first.a.x) * (first.b.y - first.a.y)) );
  double s2 = fabs( 0.5 * ((second.b.x - second.a.x) * (second.c.y - second.a.y) - (second.c.x - second.a.x) * (second.b.y - second.a.y)) );
  if (s1 > s2){
  	t = first;
  //	printf("The first triangle is larger, and the size is %f \n", s1);
  }
  else if(s1 < s2){
  	t = second;
  	// printf("The second triangle is larger, and the size is %f \n", s2);
  }
  else{
    t = first;
  	 printf("They are the same size \n");
  }
  
  // Fill in this function

  // You'll want to replace this with something that returns a meaningful
  // result.
  return(t); 
}

