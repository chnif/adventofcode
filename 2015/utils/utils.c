#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define INITIAL_SIZE 256

int read_file_to_array(const char *filename, char ***lines, int **count, int *lines_count)
{
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Error opening the file %s", filename);
		return -1;
	}

	*lines = malloc(INITIAL_SIZE * sizeof(char *));
	*count = malloc(INITIAL_SIZE * sizeof(int));

	if(*lines == NULL || *count == NULL)
	{
		printf("Memory allocation failed");
		fclose(file);
		return -1;
	}

	char *line = NULL;
	size_t len = 0;
	int index = 0;
	int capacity = 2;

	while (getline(&line, &len, file) != -1)
	{

		// skip empty lines
		if (strlen(line) == 0) {
            continue;
        }

		if (index >= INITIAL_SIZE)
		{
			capacity = index + 10;
			char **new_lines = realloc(*lines, capacity * sizeof(char *));
			int *new_count = realloc(*count, capacity * sizeof(int));

			if (*lines == NULL || *count == NULL)
			{
				printf("Memory allocation failed");
				free(line);
				fclose(file);
				return -1;
			}

			*lines = new_lines;
			*count = new_count;
		}

		(*lines)[index] = strdup(line);
		(*count)[index] = strlen(line);
		index++;
	}

	*lines_count = index + 1;
	fclose(file);

	return 0;
}