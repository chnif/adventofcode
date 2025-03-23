// advent of code 2015
// day 06 : probably a fire hazard
// part 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.h"

void update_grid(int grid[1000][1000], int interrupt, int coords[4])
{
    for(int x = coords[0]; x <= coords[2]; x++)
    {
        for(int y = coords[1]; y <= coords[3]; y++)
        {
            switch (interrupt)
            {
            case 0:
                grid[x][y] = grid[x][y] == 0 ? 0 : grid[x][y] - 1;
                break;
            case 1:
                grid[x][y] += 1;
                break;
            case 2:
                grid[x][y] += 2;
                break;
            default:
                break;
            }
        }
    }
}
void parse(char* line, int* interrupt, int coords[4])
{
    char s[10];
    sscanf(line, "%10[^0-9] %d,%d through %d,%d", s, &coords[0], &coords[1], &coords[2], &coords[3]);

    if (strcmp(s, "turn off ") == 0) 
    {
        *interrupt = 0;   
    }
    else if (strcmp(s, "turn on ") == 0)
    {
        *interrupt = 1;
    }
    else if (strcmp(s, "toggle ") == 0)
    {
        *interrupt = 2;
    }
    else 
    {
        printf("Error capturing @interrup flag \n");
    }
}

int part2(char** lines, int lines_count)
{
    int count = 0;
    int coords[4] = {0};
    int interrupt;
    int grid[1000][1000] = {0};

    for (int i = 0; i < lines_count - 1; i++)
    {
        parse(lines[i], &interrupt, coords);
        update_grid(grid, interrupt, coords);
    }

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            count += grid[i][j];
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

	printf("year 2015 day06 part 2 : %d \n", part2(lines, lines_count));

	return 0;
}