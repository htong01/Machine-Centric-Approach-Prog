#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

using namespace std;

template<class T>
class Node{
public:
	T data;
	Node<T> *next;
};


template<class T>
class LinkedList{
  private:
  	Node<T> *head;
  	int len;
  public:
  	LinkedList():head(NULL),len(0){};   // default constructor


  	LinkedList(int length, T* values){    // initialize
	  	head = NULL;
	  	len = 0;
		for(int i = 0; i < length; i++)
		{	
			insert(values[i],i);   
		}
  	};


  	// copy constructor
  	LinkedList(const LinkedList<T>& other){
  		head = NULL;
		len = 0;
		Node<T>* temp = other.head;
		Node<T>* newNode = new Node<T>;
		newNode->data = temp->data;
		newNode->next = NULL;
		head = newNode;
		len++;
		temp = temp->next;
		while(temp != NULL && len < other.len)
		{
			newNode->next = new Node<T>;
			newNode = newNode->next;
			newNode->data = temp->data;
			newNode->next = NULL;
			temp = temp->next;
			len++;
		}
  	};


  	// take operator = as deep copy of a linkedlist
  	LinkedList& operator= (const LinkedList& other){
  		if(this == &other) return *this;

  		Node<T> *itr = other.head;
  		while(itr != NULL){
  			// itr->data = other->data;
  			itr = itr -> next;
  			len++;
  		}
  		return *this;
  	};


  	// default destructor
  	~LinkedList(){
  		Node<T> *temp = head;
  		for(int i=0;i<len;i++){
  			Node<T> *newNode = temp->next;
  			delete temp;
  			temp = newNode;
  		}
  		len = 0;
    };     


  	int size(){return len;};          // get size


  	int getItem(int n){
  		if(n<0||n>len){
            return 0;
        }
        else{
            Node<T> *temp = head;
            for(int i=0;i<n;i++) temp=temp->next;
            return temp->data;
        }
  	};


  	void insert(T x, int pos){
  		if(pos<0||pos>len){
            return;
        }
  		if(pos == 0){
  			Node<T> *NewNode = new Node<T>;   // insert at the begining
		    NewNode->data = x;
   		    NewNode->next = head;
   		    len++;
   		    head = NewNode;
  		}
  		else if(pos == len){
  			Node<T> *NewNode = head;
  			for(int i=0;i<len-1;i++){       // to the end of an linked list
  				NewNode = NewNode->next;
  			}                              // NewNode now points at endNNN
  			Node<T> *N = new Node<T>;
  			N->data = x;
  			N->next = NULL;
  			NewNode->next = N;   
  			len++;
  		}
  		else{
  			Node<T> *NewNode = head;
  			for(int i=0;i<pos;i++){
  				NewNode = NewNode->next;
  			}
  			Node<T> *N = new Node<T>;  // to store the information in current position need to be inserted
  			N->data = NewNode->data;
  			N->next = NewNode->next;
  			NewNode->data = x;         // put the origin node back
  			NewNode->next = N;
  			len++;
  		}

  	};
  	void remove(int pos){
  		if(pos<0||pos>len){
            return;
        }
  		if(pos == 0){
  			Node<T> *temp = head;
  			Node<T> *tempNext = temp->next;
  			head = tempNext;
  			delete temp;
  			len--;
  		}
  		else if(pos == len){
  			Node<T> *temp = head;
  			for(int i=0;i<len-1;i++){       // to the end of an linked list
  				temp = temp->next;
  			}  
  			delete temp;
  			len--;
  		}
  		else{
  			Node<T> *temp = head;
  			for(int i=0;i<pos-1;i++){       
  				temp = temp->next;
  			}  
  			Node<T> *tempNext = temp->next;
  			Node<T> *tempNNext = tempNext->next;
  			temp->next = tempNNext;
  			delete tempNext;
  			len--;
  		}
  	};

};


#endif
