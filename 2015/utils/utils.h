#ifndef UTILS_H
#define UTILS_H

int read_file_to_array(const char *filename, char ***lines, int **count, int *line_count);
char* read_file_to_string(const char* filename);

#endif