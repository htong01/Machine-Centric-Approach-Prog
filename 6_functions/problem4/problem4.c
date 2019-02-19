
#include "problem4.h"
#include <stdio.h>
#include <string.h>

const char* find_shortest(const char * const * strings, int len)
{
// If no input

	if(len == 0){
		printf("invalid input \n");
		return(NULL);
	}
	
	const int n = len; 
	int c = 0;
	for(int i=0;i<n;i++){
		if(strings[i] == NULL){
			// printf("invalid input \n");
			// return(NULL);
			c++;
		}
    }
    if(c == n){
    	return(NULL);
    }
// For ordinary case

	const char * const *pointer;

	int min = 100;
	int a = 0;
	// const int n = len;                   // initializations
	int count[n];                        // new array to count for the length of each strings
	for(int i=0;i<n;i++){
		if(strings[i] == NULL){
			continue;
		}
		count[i] = strlen(strings[i]);
		// printf("length of the %d string is %d\n",(i+1),count[i]);
		if(count[i]<min){               // find the shortest string
			pointer = &strings[i];
			min = count[i];
			a = i;                      // save it's index
		}
	}
    
    printf("the shortest string is %s\n",strings[a]);

	return(*pointer);

}

