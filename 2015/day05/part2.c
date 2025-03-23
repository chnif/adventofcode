// advent of code 2015
// day 05 : doesn't he ahve intern-elves for this ?
// part 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.h"

int is_string_nice(char *line)
{
    int len = strlen(line);
    int count_pair = 0;
    int count_repeat = 0;

    for (int i = 1; i < len - 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (line[j] == line[i] && line[j+1] == line[i+1] && j + 1 != i)
            {
                count_pair++;
            }
        }

        if (line[i-1] == line[i+1])
        {
            count_repeat++;
        }
    }

    if (count_pair >= 1 && count_repeat >= 1)
    {
        return 1;
    }
    return 0;
}

int part1(char **lines, int lines_count)
{
	int count = 0;

    for (int i = 0; i < lines_count - 1; i++)
    {
        if (is_string_nice(lines[i]))
        {
            count++;
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

	printf("year 2015 day05 part 2 : %d \n", part1(lines, lines_count));

	return 0;
}
