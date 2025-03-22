// advent of code 2015
// day 05 : doesn't he ahve intern-elves for this ?
// part 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.h"

int is_string_nice(char *line)
{
    char vowels[5] = {'a','e','i','o','u'};
    char tokens[4][2] = {{'a', 'b'}, {'c', 'd'}, {'p', 'q'}, {'x', 'y'}};
    int count_vowels = 0;
    int count_doubles = 0;
    int count_tokens = 0;

    for (int i = 0; i < strlen(line) - 1; i++)
    {
        for (int v = 0; v < 5; v++)
        {
            if (line[i] == vowels[v]){
                count_vowels++;
            }
        }

        if (i != strlen(line) - 2 && line[i] == line[i+1])
        {
            count_doubles++;
        }

        for (int t = 0; t < 4; t++)
        {
            if (i != strlen(line) - 2 
                && line[i] == tokens[t][0]
                && line[i+1] == tokens[t][1])
            {
                count_tokens++;
            }
        }
    }

    if (count_vowels >= 3 && count_doubles >= 1 && count_tokens == 0)
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

	printf("year 2015 day05 part 1 : %d \n", part1(lines, lines_count));

	return 0;
}
