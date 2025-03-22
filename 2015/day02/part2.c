// advent of code 2015
// day 02 : i was told there would be no math
// part 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.h"

int part1(char **lines, int lines_count)
{
    int l, w, h;
	int total_square_feet = 0;

    for (int i = 0; i < lines_count - 1; i++)
	{
		int p1, p2, p3, min;
		
		sscanf(lines[i], "%dx%dx%d", &l, &w, &h);
		
		p1 = 2 * (l + w);
		p2 = 2 * (w + h);
		p3 = 2 * (h + l);
		min = p1;
		if (p2 < min) min = p2;
		if (p3 < min) min = p3;

		total_square_feet += min + l * w * h;
		
	}

	return total_square_feet;
}

int main()
{

	char **lines = NULL;
	int lines_count = 0;
	int *count = NULL;
	read_file_to_array("input.txt", &lines, &count, &lines_count);
	printf("year 2015 day02 part 2 : %d \n", part1(lines, lines_count));
	return 0;
}
