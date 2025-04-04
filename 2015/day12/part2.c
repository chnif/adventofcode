// advent of code 2015
// day 12 : jsabacusframework.io
// part 2

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.h"

int solution(const char* filename)
{
    char* json = read_file_to_string(filename);
    int sum = 0;
    int stack[100] = {1};
    int top = 0;
    int in_string = 0;
    int found_red = 0;
    char buffer[20];
    int buf_index = 0;

    for (int i = 0; json[i] != '\0'; i++)
    {
        char c = json[i];
        if (c == '"' && (i == 0 || json[i - 1] != '\\'))
        {
            in_string = !in_string;
            found_red = 0;
            continue;
        }

        if (in_string)
        {
            if (!found_red && strncmp(&json[i], "red", 3) == 0 && json[i + 3] == '"')
            {
                stack[top] = 0;
                found_red = 1;
            }

            continue;
        }

        if (c == '{')
        {
            stack[++top] = 1;
            continue;
        }

        if (c == '}')
        {
            top--;
            continue;
        }

        if (isdigit(c) || (c == '-' && isdigit(json[i + 1])))
        {
            buf_index = 0;
            buffer[buf_index++] = c;

            while (isdigit(json[i + 1]))
            {
                buffer[buf_index++] = json[++i];
            }
            buffer[buf_index] = '\0';

            if (stack[top])
            {
                sum += atoi(buffer);
            }
        }
    }

        return sum;
}

int main()
{
    printf("year 2015 day11 part 2 : %d \n", solution("input.txt"));
    return EXIT_SUCCESS;
}
