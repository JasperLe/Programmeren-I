#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>
#include <cs50.h>

#define _XOPEN_SOURCE

// GAAT TOT ÉTUDES met buf[1023]

int main (void)
{
    string password;
    password = GetString();
    
    FILE *fp = fopen("/usr/share/dict/words","r");
    char buf[2047];
    while(fscanf(fp, "%s", buf) != EOF)
    {
        printf("%s\n", buf);
        if (strcmp(buf, password) == 0)
        {
            printf("Bingo %s\n", buf);
            return 0;
        }
        printf("%s\n", buf);
        if (strlen(buf) == 2047)
        {
            printf("That was allot");
            return 1;
        }
    }
}