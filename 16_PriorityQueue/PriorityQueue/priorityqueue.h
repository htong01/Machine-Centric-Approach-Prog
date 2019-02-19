#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream> 
#include <vector> 
#include <thread>
#include <mutex>

using namespace std;

mutex mylock;

template <class T>
class PriorityQueue{
  public:
  	PriorityQueue():mSize(0){};                     // default constructor


  	PriorityQueue(const PriorityQueue &other){     // copy constructor, deep copy
  		if(this == &other) return;

  		this->mSize = other.mSize;
  		this->heap = other.heap;
  	};


  	~PriorityQueue(){heap.clear();};               // default destructor


  	PriorityQueue& operator=(const PriorityQueue &other){
  		if(this == &other) return *this;

  		this->mSize = other.mSize;
  		this->heap = other.heap;
  		return *this;
  	};



  	int size(){return mSize;};


  	T top(){
  		if(mSize==0){
  			cout << "error: empty heap" << endl;
  			return 0;
  		}
  		return heap[0];
  	};


  	void push(T x){

  		mylock.lock();
  		mSize++;
  		int i = mSize - 1;
  		heap.push_back(x);

  		int parent = i;
  		while(parent>0){
	  		parent = (i - 1)/2;     // if current pushed element is larger than its parent, then swap
	  		if(heap[i] > heap[parent]) swap(heap[i],heap[parent]);
	  		i = parent;
	  	}
	  	mylock.unlock();
  	};


  	void pop(){
  		if(mSize == 0) return;
  		
  		mylock.lock();
  	
  		heap[0] = heap.back();            // copy the last element to top
  		heap.pop_back();                  // pop last element
  		mSize--;


  		int i = 0;

  		while((2*i+2)<mSize){
	  		int right = 2*i + 2;
	  		int left = 2*i + 1;
	  		int largest = i;
	  		if(left<mSize && heap[left]>heap[i]) 
	  			largest = left;
	  		if(right<mSize && heap[right]>heap[largest])
	  			largest = right;
	  		if(largest!=i){
	  			swap(heap[i],heap[largest]);
	  		}
	  		i++;
  		}
  		mylock.unlock();
  	};


  private:
  	vector<T> heap;
  	int mSize;
  	mutable mutex m;
};

#endif
