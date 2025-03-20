#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define INITIAL_SIZE 10

int read_file_to_array(const char *filename, char ***lines, int **count, int *line_count)
{
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Error opening the file %s", filename);
		return -1;
	}

	*lines = malloc(INITIAL_SIZE * sizeof(char *));
	*count = malloc(INITIAL_SIZE * sizeof(int));
	int count_lines = 0;

	if(*lines == NULL || *count == NULL)
	{
		printf("Memory allocation failed");
		fclose(file);
		return -1;
	}

	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, file)) != -1)
	{

		// skip empty lines
		if (strlen(line) == 0) {
            continue;
        }

		if (count_lines >= INITIAL_SIZE)
		{
			int new_size = count_lines + 10;
			char **new_lines = realloc(*lines, new_size * sizeof(char *));
			int *new_count = realloc(*count, new_size * sizeof(int));

			if (new_lines == NULL || new_count == NULL)
			{
				printf("Memory allocation failed");
				free(*lines);
				free(*count);
				return -1;
			}
			*lines = new_lines;
			*count = new_count;
		}

		(*lines)[count_lines] = line;
		(*count)[count_lines] = strlen(line);

		line = NULL;
		len = 0;
	}

	return 0;
}