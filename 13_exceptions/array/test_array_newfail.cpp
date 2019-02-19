// Implement a version of `new` that fails on command
// Based on https://stackoverflow.com/questions/1923664/simulating-low-memory-using-c
#include <memory>
#include <iostream>
#include <cstdio>
#include "array.h"
// Global flag that sets whether or not `new` will fail
bool memoryAllocFail = false; // Succeed by default

// Custom implementation of new
void* operator new(std::size_t size)
{
    std::cout << "New allocation of size " << size << std::endl;
    if (memoryAllocFail)
    {
       throw std::bad_alloc();
    }

    return malloc(size);
}

void operator delete(void* block)
{
    std::cout << "Freed allocation" << std::endl;
    free(block);
}

int main(int argc, char* argv[])
{

    Array<int> a(10, 5);
    Array<int> c(2,2);
    Array<int> b(3,7);
    Array<int> z(25,0);

    int val[] = {1,2,3};
    int * ptr = val;
    Array<int> arr(3,0);



    try {
      std::cout << "The fourth number is: " << c[3] << std::endl;
    }
    catch (const std::exception& e){
      std::cout << "There was an error: " << e.what() << std::endl;
    }


    memoryAllocFail = true;
    try
    { 
        z = a + b + c;
    } 
    catch (std::bad_alloc & ba) 
    { 
        std::cerr << "bad_alloc caught: " << ba.what() << endl; 
    } 
    cout<<"actual size"<<z.size()<<endl;


    memoryAllocFail = false;
    try
    { 
        Array<int> arr(3,ptr);
    } 
    catch (std::bad_alloc & ba) 
    { 
        std::cerr << "bad_alloc caught: " << ba.what() << endl; 
    } 
    cout<<"array is "<<arr<<endl;
    cout<<"actual size "<<arr.size()<<endl;

    return(0);
}

