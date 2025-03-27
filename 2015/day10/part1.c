// advent of code 2015
// day 10 : elves look, elves say
// part 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.h"

void update_string(char** line)
{
    char* string = (char*)malloc(strlen(*line) * 2 + 1);
    int i = 0;
    int j = 0;
    int count = 1;

    while ((*line)[i])
    {
        if ((*line)[i] == (*line)[i + 1])
        {
            count++;
        }
        else
        {
            j += sprintf(string + j, "%d%c", count, (*line)[i]);
            count = 1;
        }
        i++;
    }

    string[j] = '\0';
    free(*line);
    *line = string;
}

int solution(char* line)
{
    int n = 40;
    for (int i = 0; i < n; i++) {
        update_string(&line);
    }
    return strlen(line);
}

int main()
{

    char* line = (char*)malloc(1000);
    strcpy(line, "1113222113");

    printf("year 2015 day10 part 1 : %d \n", solution(line));

	return 0;
}
