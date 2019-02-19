
#include "problem3.h"
#include <stdio.h>
#include <math.h>

Triangle* getLarger(const Triangle* first, const Triangle* second)
{
  Triangle* t;
  if(first == NULL){
    return(second);
  }
  else if (second == NULL){
    return(first);
  }

  double s1 = fabs( 0.5 * (( (*first).b.x - (*first).a.x) * ((*first).c.y - (*first).a.y) 
  	- ((*first).c.x - (*first).a.x) * ((*first).b.y - (*first).a.y)) );
  double s2 = fabs( 0.5 * (( (*second).b.x - (*second).a.x) * ((*second).c.y - (*second).a.y) 
  	- ((*second).c.x - (*second).a.x) * ((*second).b.y - (*second).a.y)) );
  if (s1 > s2){
  	// *t = *first;
  	printf("The first triangle is larger, and the size is %f \n", s1);
    return first;
  }
  else if(s1 < s2){
  	// *t = *second;
  	printf("The second triangle is larger, and the size is %f \n", s2);
    return second;
  }
  else{
    // *t = *first;
  	printf("They are the same size, and the size is %f \n", s1);
    return first;
  }

  // return(t); 
}

