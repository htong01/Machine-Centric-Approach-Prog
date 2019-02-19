#include "linkedlist.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  // test for copy constructor

  int val[] = {1,2,3};
  LinkedList<int> l(3, val);
  for(int i=0;i<l.size();i++) cout<<l.getItem(i)<<endl;

  LinkedList<int> list;
  // Push three elements onto the front
  list.insert(1, 0);
  list.insert(2, 0);
  list.insert(3, 0);
  list.insert(555, 1);
  list.insert(222, 4);   // insert at the end of linked list

  list.remove(0);                // remove first
  list.remove(list.size());      // remove last
  list.remove(1);               // general case

  // Make a copy
  LinkedList<int> another = list;

  // Push some more elements onto the front of the original
  list.insert(4, 0);
  list.insert(5, 0);

  for(int i = 0; i < list.size(); i++){
    printf(" list[%d] = %d\n", i, list.getItem(i));
  }

  for(int i = 0; i < another.size(); i++){
    printf("another[%d] = %d\n", i, another.getItem(i));
  }

  return(0);
}

