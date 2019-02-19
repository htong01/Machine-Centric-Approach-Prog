#include "array.h"
#include <cstdio>
#include <iostream>

using namespace std;

// void test_initialize(int size, int value);

int main(int argc, char* argv[])
{
  // Here's some quick test code to get you started.  You'll need much more
  // thorough testing, of course.


  Array a;
  a.initialize(10, 5);

  Array rtoo;
  rtoo.initialize(0, 0);
  rtoo = a;
  
  for(int i = 0; i < a.size(); i++){
    a[i] = i * 2;
  }

  cout << a;
  cout << rtoo;

  a.append(100);
  cout << a;
  a.append(rtoo);
  cout << a;
  a.cleanup();
  cout << a.size() << endl;

  return 0;
}

// void test_initialize(int size, int value)
// {

// }
