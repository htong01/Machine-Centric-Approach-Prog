#include <iostream>
#ifndef ARRAY_H
#define ARRAY_H
using namespace std;

class Array{

public:
	Array();
	~Array();
	Array& initialize(int size, int val);
	void cleanup();
	int size();
	void append(int x);
	void append(Array y);
	Array& operator = (const Array &a);
	int& operator [] (const int index);
	friend ostream& operator << (ostream& out, const Array& a);
private:
	int* arr;
	int length;
};


#endif
