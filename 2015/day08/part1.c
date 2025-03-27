// advent of code 2015
// day 08 : matchstricks
// part 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.h"

#define INITIAL_SIZE 256

int* read_file_with_specialchar(const char* filename)


	int count[2] = {0};
	*lines = malloc(INITIAL_SIZE * sizeof(char *));
	char *line = NULL;
	size_t len = 0;
	int index = 0;
	int capacity = 2;


	FILE *file = fopen(filename, "r");
	if (file == NULL) 
	{
		perror("Error opening file");
		return 1;
	}

	while ((read = getline(&line, &len, file)) != -1) {
        // Process escape sequences in the string
        process_escape_sequences(line);

        // Print the processed line (after handling escapes)
        printf("Processed line: %s", line);
    }

    // Clean up
    free(line);
    fclose(file);

    return 0;

    char* read_ptr = line;
    char* write_ptr = s;

    while (*read_ptr != '\0') {
        if (*read_ptr == '\\') {
            // Handle the escape sequence
            switch (*(read_ptr + 1)) {
                case '\\':
                    *write_ptr++ = '\\';  // Handle \\ as a single backslash
                    read_ptr += 2;        // Skip the next character
                    break;
                case '\"':
                    *write_ptr++ = '\"';  // Handle \" as a quote
                    read_ptr += 2;        // Skip the next character
                    break;
                case 'n':
                    *write_ptr++ = '\n';  // Handle \n as newline
                    read_ptr += 2;        // Skip the next character
                    break;
                case 't':
                    *write_ptr++ = '\t';  // Handle \t as tab
                    read_ptr += 2;        // Skip the next character
                    break;
                default:
                    // If it's not a recognized escape sequence, just copy it as is
                    *write_ptr++ = *read_ptr++;
                    break;
            }
        } else {
            *write_ptr++ = *read_ptr++;  // Regular character, copy it
        }
    }

    *write_ptr = '\0';  // Null-terminate the string

	return code_count;
}

int get_len_mem(const char* string) {
	return (int)strlen(string);
}

int get_len_code(const char* string) 
{
    int count = 2;

    while (*string) 
	{
		printf("Current char: '%c' (ASCII: %d)\n", *string, *string);
        if (*string == '\\') 
		{
			count += 3;
			string += 2;
		}
		else if (*string == '"') 
		{
			count += 3;
			string += 2;
		}
		else if (*string == '\\' && *(string + 1) == 'x') 
		{
			printf("[DEBUG] \\x detected");
			count += 4;
			string += 4;
		}
		else
		{
			count += 1;
			string += 1;
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

	//printf("year 2015 day08 part 1 : %d \n", solution(lines, lines_count));
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
