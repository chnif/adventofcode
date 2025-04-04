// advent of code 2015
// day 12 : jsabacusframework.io
// part 1

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"

int solution(const char* filename)
{
    char* json = read_file_to_string(filename);
    int sum = 0;
    while (*json)
    {
        if (*json == '-' || isdigit(*json))
        {
            int number = strtol(json, (char**)&json, 10);
            sum += number;
        }
        else
        {
            json++;
        }
    }

    return sum;
}

int main()
{
    printf("year 2015 day11 part 1 : %d \n", solution("input.txt"));
    return EXIT_SUCCESS;
}
