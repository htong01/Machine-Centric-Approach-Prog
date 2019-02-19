
#include "problem2.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
  char* str;  
  str = "ABC";
  lower(str);

  char* strr;
  strr = "1fFLIi7@";  // only modify upper case letters
  lower(strr);

  char* strrr;      //null input
  lower(strrr);

  return(0);
}

