// advent of code 2015
// day 08 : matchstricks
// part 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.h"

int get_len_mem(const char* string) {
	return (int)strlen(string);
}

int get_len_code(const char* string) 
{
    int count = 2;

    while (*string) 
	{
        if (*string == '\\') 
		{  
            count++;
            string++;

            if (*string == '\\')
			{
				count++;
				string++;		
			}
            else if (*string == 'x') 
			{
                count += 3;
                string += 2;
            }

			else if (*string == '"') 
			{
				count+=2;
				string++; 
			}
		}
		else
		{
			count++;
			string++;
		}
	}
    return count;
}

int solution(char** lines, int lines_count)
{
	int count_char_code = 0;
	int count_char_mem = 0;
	
	for (int i = 0; i < lines_count; i++)
	{
		count_char_code += get_len_code(lines[i]);
		count_char_mem += get_len_mem(lines[i]);
	}
    return  count_char_code - count_char_mem;
}

int main()
{
	//char **lines = NULL;
	//int lines_count = 1;
	//int *count = NULL;
	//read_file_to_array("input.txt", &lines, &count, &lines_count);

	//printf("year 2015 day08 part 1 : %d \n", solution(lines, lines_count));

	char* lines[] = {"", "abc", "aaa\"aaa", "\x27"};
	int lines_count = 4;

	for (int i = 0; i < 4; i++)
	{
		printf("[DEBUG] @string %15s : @char_code %d  @char_mem %d \n", lines[i], get_len_code(lines[i]), get_len_mem(lines[i]));
	}

	printf("year 2015 day08 part 1 : %d \n", solution(lines, lines_count));
	/*
	while(**lines)
	{
		int char_code = CODE_LEN(*lines);
		int mem_code = MEM_LEN(*lines);
		*lines[strcspn(*lines, "\n")] = '\0';
		printf("[DEBUG] @string  %50s : @char_code %d  @char_mem %d \n", *lines, char_code, mem_code);
		*lines++;
	}
	*/
	return 0;
}
