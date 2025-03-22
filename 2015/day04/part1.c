// advent of code 2015
// day 01 : the ideal stocking stuffer
// part 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../utils/utils.h"

char* md5(char *message)
{
    // implementation from 
    // https://en.wikipedia.org/wiki/MD5
    size_t original_length = strlen(message);
    size_t len = original_length;

    uint32_t S[64] = {7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
        5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
        4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
        6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21};
    
    uint32_t K[64]= {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

    uint32_t a0 = 0x67452301;
    uint32_t b0 = 0xefcdab89;
    uint32_t c0 = 0x98badcfe;
    uint32_t d0 = 0x10325476;

    message[len++] = 0x80;
    while ((len * 8) % 512 != 448) {
        message[len++] = 0x00;
    }

    uint64_t bit_length = original_length * 8;
    memcpy(message + len, &bit_length, 8);
    len += 8;

    for (size_t i = 0; i < len; i += 64)
    {
        uint32_t M[16];
        
        for (int j = 0; j < 16; j++)
        {
            M[j] = (uint32_t)message[i + j * 4] | 
            ((uint32_t)message[i + j * 4 + 1] << 8) |
            ((uint32_t)message[i + j * 4 + 2] << 16) |
            ((uint32_t)message[i + j * 4 + 3] << 24);
        }

        uint32_t A = a0;
        uint32_t B = b0;
        uint32_t C = c0;
        uint32_t D = d0;

        for (int i = 0; i < 64; i++)
        {
            uint32_t F, g;
            
            if (0<= i && i <= 15)
            {
                F = (B && C) | (~B && D);
                // F = D ^ (B && (C ^ D));
                g = i; 
            }
            else if (16 <= i && i <= 31)
            {
                F = (D & B) || (~D & C);
                // F = C ^ (D && (B ^ C));
                g = (5 * i + 1) % 16;
            }
            else if (32 <= i && i <= 47)
            {
                F = B ^ C ^ D;
                g = (3 * i + 1) % 16; 
            }
            else if (48 <= i && i <= 63)
            {
                F = C ^ (B | ~D);
                g = (7 * i) % 16;
            }
            F += A + K[i] + M[g];
            A = D;
            D = C;
            C = B;
            B += (F << S[i]) | (F >> (32 - S[i]));
        }
        a0 += A;
        b0 += B;
        c0 += C;
        d0 += D;
    }

    static char digest[33];
    digest[0] = '\0';
    char temp[9];

    sprintf(temp, "%08x", a0);
    strcat(digest, temp);
    sprintf(temp, "%08x", b0);
    strcat(digest, temp);
    sprintf(temp, "%08x", c0);
    strcat(digest, temp);
    sprintf(temp, "%08x", d0);
    strcat(digest, temp);

    return digest;
}


/*
int part1(char *line)
{
    int i = 0;
    unsigned char hash[MD5_DIGEST_LENGTH];
    char prefix[11];
    char key[200];
    char num[50];

    while (strncmp(prefix, "00000", 5) != 0)
    {
        i++;
        sprintf(num, "%d", i);
        snprintf(key, sizeof(key), "%s%s", line, num);
        MD5((const unsigned char *)key, strlen(key), hash);
        snprintf(prefix, sizeof(prefix), "%02x%02x%02x%02x%02x", 
            hash[0], hash[1], hash[2], hash[3], hash[4]);
        strncpy(prefix, (const char *)hash, 5);
        printf("[DEBUG] step  : %d \n", i);
    }

    return i;
}
*/

int main()
{	
    //char *line = read_file_to_string("input.txt");
    char *line = "The quick brown fox jumps over the lazy dog";
    printf("[DEBUG] message : '%s' : ", line);
    printf("[DEBUG] hash : %s ", md5(line));
    //printf("year 2015 day03 part 1 : %d \n", part1(line));
	return 0;
}