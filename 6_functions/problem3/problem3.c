
#include "problem3.h"
#include <stdio.h>

void find_frequency(const char* str, int len, unsigned int histogram[26])
{
  if(str == NULL){
    printf("invalid input");
    return;
  }
  // else{
    int count[26] = {0};
    int i = 0;
    for(int n=0; n<len; n++){
  		if ((str[n] >= 'a' && str[n] <= 'z')) {            // for lower case letters
              i = str[n] - 'a';                              // index for counting array is the current letter minus ascii value for 'a', since a should be the index 0
              count[i]++;                                // count plus 1
  	    }
  	    else if( (str[n] >= 'A' && str[n] <= 'Z') ){      // for upper case letters
  	    	i = str[n] - 'A';
  	    	count[i]++;
  	    }
    }
    
    for(int m = 0;m<26;m++){                               // print the result
      histogram[m] = count[m];
    	printf("%d",histogram[m]);
    }
  printf("\n");
  // }
}
