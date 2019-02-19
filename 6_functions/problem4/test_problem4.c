
#include "problem4.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	int len = 4;
	const char *str[]={"Annn","aaa","hello","world."};
	find_shortest(str, len);

	const char *strr[]={NULL,"aaa","hel","wor"};
	find_shortest(strr, len);

	int n = 0;
	const char * strrr[]={"\0"};    // NULL input
	find_shortest(strrr, n);

  return(0);
}

