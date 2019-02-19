#include "array.h"
#include <string>

using namespace std;
// default constructor
Array::Array()
{
	initialize(1, 0);
}

// default destructor
Array::~Array()
{

}

Array& Array::initialize(int size, int val)
{
	arr = new int(size);
	length = size;
	for(int i = 0; i < size; i ++)
		arr[i] = val;
	return *this;
}

void Array::cleanup()
{
	delete []arr;
	length = 0;
}

int Array::size()
{
	return length;
}

void Array::append(int x)
{

	int* newArr = new int[length+1];
	for(int i = 0; i < length; i++)
		newArr[i] = arr[i];
	delete []arr;
	arr = newArr;
	arr[length] = x;
	length += 1;
}

void Array::append(Array y)
{
	int* newArr = new int[length + y.length];
	for(int i = 0; i < length; i++)
		newArr[i] = arr[i];
	delete []arr;
	arr = newArr;
	for(int i = 0; i < y.length; i++)
		arr[length+i] = y.arr[i];
	length += y.length;
}

Array& Array::operator = (const Array &a)
{
	int* newArr = new int[a.length];
	for(int i = 0; i < a.length; i++)
		newArr[i] = a.arr[i];
	delete []arr;
	arr = newArr;
	length = a.length;
	return *this;
}

int& Array::operator [](const int index)
{
	if(index < 0 || index > length)
	{
		cout << "error";
		exit(0);
	}
	else
		return arr[index];
}

ostream& operator << (ostream& out, const Array& a)
{
	if(a.length == 0)
	{
		cout << "error print" << endl;
		exit(0);
	}
	else
	{
		out << '[';
		for(int i = 0; i < a.length; i++)
		{
			out << a.arr[i];
			if(i != a.length-1)
				out << ", ";
		}
		out << ']' << endl;
		return out;
	}
}

