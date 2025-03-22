// advent of code 2015
// day 05 : doesn't he ahve intern-elves for this ?
// part 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.h"

int is_string_nice(char *line)
{
    int count_pair = 0;
    int count_repeat = 0;
    int counts[26] = {0};

    for (int i = 0; i < strlen(line); i++)
    {
        printf("[DEBUG] step : [%c, %c, %c] \n", line[i], line[i+1], line[i+2]);
        
        if (i != strlen(line) - 2 && line[i] == line[i+2] && line[i+1] == line[i+3])
        {
            count_pair++;
        }
        

        if (i != strlen(line) - 1 && line[i] == line[i+2])
        {
            printf("[DEBUG] -> letters %c is in between [%c, %c] \n", line[i+1], line[i], line[i+1]);
            count_repeat++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (counts[i] >= 2)
        {
            count_pair++;
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
        if (is_string_nice(lines[i]) == 1)
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

	//printf("year 2015 day05 part 2 : %d \n", part1(lines, lines_count));
    char* string = "xxyxx";
    printf("[DEBUG] string %s is %d \n", string, is_string_nice(string));
	return 0;
}
