
#include "problem2.h"
#include <stdio.h>
#include <string.h>

void lower(char* str)
{
 if(str != NULL){
  int n = strlen(str);        // find out how many input characters   

  if(n == 0 ){
  	printf("");
  }
  // if(!str){
  //   return;
  // }
  
  for(int i=0; i<n; i++){
  	if (str[i] >= 'A' && str[i] <= 'Z'){    // whether the input is uppercase
  		// printf("%c",str[i]+32);             // convert to lower case in ascii value  
      str[i] = str[i] + 32;
  	}
  	// else{
  	// 	printf("%c",str[i]);
  	// }
  }  
// printf("\n");
}
}