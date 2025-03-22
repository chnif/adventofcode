// advent of code 2015
// day 03 : perfectly spherical houses in a vacuum
// part 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.h"

typedef struct
{
    int x;
    int y;
} Coords;

int update_coords(Coords *coord, char dir)
{
    switch (dir) 
    {
        case '^':
            coord->y += 1;
            break;
        case '<':
            coord->x -= 1;
            break;
        case '>':
            coord->x += 1;
            break;
        case 'v':
            coord->y -= 1;
            break;
        default:
            printf("Error: invalide direction '%c' \n", dir);
            return -1;
    }

    return 0;
}

int is_coord_visited(Coords* coords, int size, Coords coord)
{
    for (int i = 0; i < size; i++)
    {
        if (coords[i].x == coord.x && coords[i].y == coord.y)
        {
            return 1;
        }
    }

    return 0;
}

int part1(char *line)
{
    Coords coord_santa = {0, 0};
    Coords coord_houses[strlen(line)];
    coord_houses[0].x = 0;
    coord_houses[0].y = 0;
    int count_visited = 1;

    for (int i = 0; i < strlen(line); i++)
    {
        update_coords(&coord_santa, line[i]);

        if (is_coord_visited(coord_houses, count_visited, coord_santa) == 0)
        {
            coord_houses[count_visited] = coord_santa;
            count_visited++;

        } 
    }
    return count_visited;
}

int main()
{	
    char *line = read_file_to_string("input.txt");
    printf("year 2015 day03 part 1 : %d \n", part1(line));
	return 0;
}