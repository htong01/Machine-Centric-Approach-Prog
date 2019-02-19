#include "priorityqueue.h"
#include <cstdio>
#include <thread>
#include <iostream>

using namespace std;

void thread_push(PriorityQueue<int> &p) {
    for(int i=0;i<100;i++) {
      p.push(i);
    }
}

void thread_push2(PriorityQueue<int> &p) {
    for(int i=100;i<200;i++) {
      p.push(i);
    }
}

void thread_pop(PriorityQueue<int> &p) {
    for(int i=0;i<50;i++) {
      p.pop();
    }
}

void thread_pop2(PriorityQueue<int> &p) {
    for(int i=10;i<15;i++) {
      p.pop();
    }
}


int main(int argc, char* argv[])
{
  PriorityQueue<int> q;

  q.pop();          // check pop when the heap is empty
  q.top();          // if empty heap

  // Push three elements onto the front
  q.push(1);
  q.push(2);
  q.push(3);

  // Make a copy
  PriorityQueue<int> another = q;

  // Push some more elements onto the front of the original
  q.push(4);
  q.push(5);
  q.push(5);        // if insert an already exist element

  while(q.size() > 0){
    printf("%d ", q.top());
    q.pop();
  }
  printf("\n");

  while(another.size() > 0){
    printf("%d ", another.top());
    another.pop();
  }
  printf("\n");


PriorityQueue<int> test;
    cout << "---------------test thread push-----------------"<<endl;

    thread t1(thread_push,ref(test));
    thread t2(thread_push2,ref(test));

    t1.join();
    t2.join();

    cout << "top element is "<< test.top() << endl;

    cout << "---------------test thread pop-----------------"<<endl;

    thread t3(thread_pop,ref(test));
    thread t4(thread_pop2,ref(test));

    t3.join();
    t4.join();

    cout<< "size is " << test.size() << " after pop" << endl;
    cout << "top element is "<< test.top() << endl;


  return(0);
}

