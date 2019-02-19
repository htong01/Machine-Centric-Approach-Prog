
#include "problem3.h"


int main(int argc, char* argv[])
{

	int arr[] = { 7, 2, 10, 13, 15, 8, 3, 20 } ; // general case
	find_sequence(arr, 8);

	int arrrr[] = { 7, 7, 7, 7, 7} ;  // same element in array
	find_sequence(arrrr,5);

	int arrrrr[] = {7} ;              // only one element
	find_sequence(arrrrr,1);

	int arrr[] = {10, 8, 6, 5, 3, 1} ;       // no increasing subsequence
	find_sequence(arrr,6);

	// int ar[] = NULL;
	// find_sequence(ar,0);

  return(0);
}

