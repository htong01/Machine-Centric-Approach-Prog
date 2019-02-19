#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <exception>
using namespace std;



class OutOfBoundsException:public exception    // inherit from exception
{
  public:
  	const char* what() const throw()
	{
		return "out of bounds" ;
	}
};



template<class T>
class Array{

  private:
  	T *data;           // pointer for array
  	int len;             // length of your array

  public:

	Array();                              // default constructer

	Array(int length, T value);
	Array(int length, T* values);
	Array(const Array<T>& ar);               // copy constructer
	int size();
	Array& append(T x);
	Array& append(Array y){
         int s = y.size() + size();
         T* tmp = new T[s];
         for (int i = 0; i<s; i++){
             if (i<size()) tmp[i] = data[i];
             else tmp[i] = y[i-size()];
         }
         data = tmp;
         len = s;
         return *this;
      };
	T& operator[](const int index);
	Array<T>& operator = (const Array<T> &arr);
	Array<T>& operator + (const Array<T> &arr);

	template <class U>                     
	friend ostream& operator<<(ostream& os, const Array<U> &arr);

	~Array();                            // default deconstructer


};



template<class T>
Array<T>::Array(int length, T value){
	len = length;
	// data = (T *) malloc(sizeof(T) * length);   // initialize a space to store data
	data = new T[length];

	for(int i=0;i<length;i++){
		data[i] = value;                             // copy value to each element in data
    }
}

template<class T>
Array<T>::Array(int length, T* values){
	len = length;
	// data = (T *) malloc(sizeof(T) * length);
	data = new T[length];

	for(int i=0;i<length;i++){
		data[i] = *(values+i);                             // copy value to each element in data
    }
}

template<class T>
Array<T>::Array(){
	data = NULL;
	len = 0;
}

template<class T>
Array<T>::~Array(){
	// free(data);
	delete []data;
	len = 0;
}

template<class T>
int Array<T>::size(){
	return len;
}

template<class T>
Array<T>::Array(const Array<T>& arr){                     // copy constructer
	// T* temp = (T *) malloc(sizeof(T) * arr.len);
	T *temp = new T[arr.len];
	for(int i=0;i<arr.len;i++){
		temp[i] = arr.data[i];
	}
	data = temp;
	len = arr.len;
}

// template<class T>
// void Array<T>::append(Array<T> y)
// {
// 	// int* temp = (int *) malloc(sizeof(int) * (len+y.len));
// 	int * temp = new T[len + y.len];
// 	for (int i=0;i<len;i++){
// 		temp[i] = data[i];
// 	}
// 	// free(data);
// 	delete []data;
// 	data = temp;
// 	for(int i=0;i<y.len;i++){
// 		data[len+i] = y.data[i];                       // add the new array ata the end of the original one
// 	}
// 	len = len + y.len;
// }

template<class T>
Array<T>& Array<T>::append(T x)
{
	// T* temp = (T *) malloc(sizeof(T) * (len+1)); // initialize a new space to save data
	T* temp = new T[len + 1];
	for(int i=0;i<len;i++){
		temp[i] = data[i];
	}
	// free(data);
	delete []data;
	data = temp;
	data[len] = x;                                      // add the new element
	len++;
	return *this;
}

template<class T>
Array<T>& Array<T>::operator + (const Array<T> &arr)
{
	static Array<T> result;

	int new_len = len + arr.len;                   // new length of the array after operator +

	// T* temp = (T *) malloc(sizeof(T) * new_len);
	T* temp = new T[new_len];
	for(int i=0;i<len;i++){
		temp[i] = data[i];
	}
	for(int j=len;j<(len + arr.len);j++){
		temp[j] = arr.data[j-len];
	}
	// free(result.data);
	delete []result.data;
	result.data = temp;
	result.len = new_len;
	return result;

}

template<class T>
T& Array<T>::operator[](const int index)
{
	if(index<0 || index>=len)                // error case
	{
		throw OutOfBoundsException();
	}

	return data[index];
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T> &arr)
{
	if(this == &arr){                                    // check if it equals to the array itself
		return *this;
	}
	// T* temp = (T *) malloc(sizeof(T) * arr.len);
	T* temp = new T[arr.len];
	for(int i=0;i<arr.len;i++){
		temp[i] = arr.data[i];
	}
	// free(data);
	delete []data;
	data = temp;
	len = arr.len;
	return *this;
}

template<class T>
ostream& operator<<(ostream& os, const Array<T> &arr)
{
	if(arr.len == 0){
		cout << "Error, empty array" << endl;
		exit(0);
	}

	os << '[';
	for(int i=0;i<arr.len;i++){
		os << arr.data[i];
		if(i<arr.len-1){                              // print ',' after each element except for the last one
			cout << ',';
		}
	}
	os << ']' << endl;
	return os;
}


#endif // class array