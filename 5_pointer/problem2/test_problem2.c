
#include "problem2.h"


int main(int argc, char* argv[])
{
  int a[5] = {11,2,3,5,7};
  find_min(a, 5);
  
  int b[0] = {};
  find_min(b, 0);

  int c[5] = {3,3,3,3,3};
  find_min(c, 5);

  return(0);
}

