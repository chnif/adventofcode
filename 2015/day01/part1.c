// advent of code 2015
// day 01 : not quite lisp
// part 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.h"

int part1(char **line)
{
	int count = 0;

	for(int i = 0; i < strlen(line[0]); i++)
	{
		if(line[0][i] == '(')
		{
			count++;
		}
		else if (line[0][i] == ')')
		{
			count--;
		}
	}
	return count;
}

int main()
{

	char **lines = NULL;
	int lines_count = 1;
	int *count = NULL;
	read_file_to_array("input.txt", &lines, &count, &lines_count);

	printf("year 2015 day01 part 1 : %d", part1(lines));

	free(lines);
	free(count);
	return 0;
}
