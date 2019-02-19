
#include "problem1.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
  int n = 7;
  double min = -5;
  double max = 5;
  double a[n];
  linspace(a, min, max, n);

  n = 4;
  min = 2;
  max = 6;
  linspace(a, min, max, n);

  n = 1;
  min = 4.2;
  max = 5.8;
  linspace(a, min, max, n);


  return(0);
}

