// advent of code 2015
// day 01 : not quite lisp
// part 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.h"

int part2(char **line)
{
	int count = 0;
	int i = 0;

	while (count != -1)
	{
		if(line[0][i] == '(')
		{
			count++;
		}
		else if (line[0][i] == ')')
		{
			count--;
		}
		i++;
	}

	return i;
}

int main()
{

	char **lines = NULL;
	int lines_count = 1;
	int *count = NULL;
	read_file_to_array("input.txt", &lines, &count, &lines_count);

	printf("year 2015 day01 part 2 : %d", part2(lines));

	free(lines);
	free(count);
	return 0;
}
