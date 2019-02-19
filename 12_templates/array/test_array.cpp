#include "array.h"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
  Array<int> a(10, 5);
  Array<int> c(2,2);
  // Array<int> b(3,7);
  // Array<int> z(25,0);
  // z = a + b + c;
  cout << c;
  a.append(a);
  //cout << a;
  // double x = 3;
  // a.append(x);
  // cout << a;
  // cout << z;

  // int val[] = {1,2,3};
  // int * ptr = val;
  // Array arr(3,ptr);
  // cout << arr;

  return(0);
}

