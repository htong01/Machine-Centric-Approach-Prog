/* problem2.c - Activity summary */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
	if(argc < 2) //Expected 2 parameters
	{
		printf("%s\n", "usage: programname duration");
		return 0;
	}
	FILE *f = fopen("activity.tsv", "r");
	if(f == NULL)
	{
		printf("%s\n", "error opening the file");
		return 0;
	}

	int seconds;
	int length = strlen(argv[1]);
	char c[15];
	strncat(c, argv[1], length - 1);
	int num = atoi(c);
	char dur = argv[1][length-1];
	switch(dur) //Deferent option
	{
		case 'd':
			seconds = num*24*3600;
			break;
		case 'w':
			seconds = num*7*24*3600;
			break;
		case 'y':
			seconds = num*365*24*3600;
			break;
	}
	char buff[256];
	time_t rawtime;
	time(&rawtime);
	long int bound = rawtime - seconds;
	int total = 0;
	while(fgets(buff, 255, (FILE*)f) != NULL)
	{
		char* c1 = strtok(buff, "\t");
		char* c2 = strtok(NULL, "\t");
		char* c3 = strtok(NULL, "\t");
		long int t = atoi(c1);
		if(t >= bound)
		{
			int mins = atoi(c3);
			total += mins;
		}
	}
	printf("Total exercise: %d minutes\n", total);
	return 0;
}

