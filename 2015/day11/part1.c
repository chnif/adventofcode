// advent of code 2015
// day 11 : corporate policy
// part 1

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_increasing_rule(char password[8])
{
    size_t n = strlen(password);
    for(size_t i = 0; i < n - 2; i++)
    {
        if (password[i] + 1 == password[i+1] && password[i+1] + 1 == password[i+2])
        {
            return 1;
        }
    }
    return 0;
}

int is_character_rule(char password[8])
{
    size_t n = strlen(password);
    for(size_t i = 0; i < n; i++)
    {
        if(password[i] == 'i' || password[i] == 'l' || password[i] == 'o')
        {
            return 0;
        }
    }
    return 1;
}

int is_pair_rule(char password[8])
{
    size_t n = strlen(password);
    for(size_t i = 0; i < n - 4; i++)
    {
        if(password[i] == password[i + 1])
        {
            for(size_t j = i + 2; j < n - 1; j++)
            {
                if(password[j] == password[j + 1] && password[i] != password[j])
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int is_password_ok(char password[8])
{
    if(is_increasing_rule(password) && is_character_rule(password) && is_pair_rule(password))
    {
        return 1;
    }
    return 0;
}

int increment(char password[8])
{
    size_t n = strlen(password);
    size_t i = 1;
    int carry = 0;

    if (password[n - 1] + 1 > 'z')
    {
        carry = 1;
    }
    password[n - 1] = (password[n - 1] - 'a' + 1) % 26 + 'a';

    while (i < strlen(password))
    {
        if (carry)
        {
            if (password[n - 1 - i] + 1 > 'z')
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            password[n - 1 - i] = (password[n - 1 - i] - 'a' + 1) % 26 + 'a';
        }
        i++;
    }
    return EXIT_SUCCESS;
}

int solution(char input[8])
{
    while (is_password_ok(input) != 1)
    {
        increment(input);
    }
    return EXIT_SUCCESS;
}


int main()
{
    char input[8] = "hepxcrrq";
    solution(input);
    printf("year 2015 day11 part 1 : %s \n", input);
    return EXIT_SUCCESS;
}
