
#include "problem3.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
  const char* str = "AaaaaBCD";
  int len = 8;
  unsigned int histogram[26] = {0};
  find_frequency(str, len, histogram);

  const char* strr = "AaaaaBCD%$#";
  int len2 = 8;
  unsigned int histogram2[26] = {0};
  find_frequency(strr, len2, histogram2);

  const char* strrr;                      // Null input, thus output all 0
  int len3 = 0;
  unsigned int histogram3[26] = {0};
  // printf("%s",strrr);
  find_frequency(strrr, len3, histogram3);
  
  return(0);
}

