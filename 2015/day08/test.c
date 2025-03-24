#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* s = "\\x27"; // 10
    int count = 2;

    while(*s)
    {
        
        printf("%c \n", *s);
        s++;
    }

    printf("number of character : %d \n", count);

    return 0;
}