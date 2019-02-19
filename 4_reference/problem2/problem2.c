
#include "problem2.h"
#include <time.h>
#include <stdio.h>
#include <string.h>

#define BUF_LEN 256
void print_time(time_t time)
{
	char buf[BUF_LEN] = {0};
    struct tm *ptm = localtime(&time);
    // printf("%s",asctime(ptm));
    strftime(buf, BUF_LEN, "%A, %B %d, %G %H:%M:%S", ptm);
    puts(buf);
  // Weekday, Month Day, Year hours:minutes:seconds


}

