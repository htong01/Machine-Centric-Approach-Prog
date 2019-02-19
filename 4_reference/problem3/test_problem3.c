
#include "problem3.h"


int main(int argc, char* argv[])
{


  Triangle t1; 
  t1.a.x = 0;
  t1.b.x = 2;
  t1.c.x = 4;
  t1.a.y = 0;
  t1.b.y = 2;
  t1.c.y = 0;

  Triangle t2;  
  t2.a.x = 0;
  t2.b.x = 4;
  t2.c.x = 8;
  t2.a.y = 0;
  t2.b.y = 2;
  t2.c.y = 0;
  getLarger(&t1, &t2);

  return(0);
}

