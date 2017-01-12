#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>
#include <cs50.h>


#define _XOPEN_SOURCE

int main (void)
{
    // Random characters
    char random[8];

    for (int a = 32; a < 127; a++)
    {
        random[0] = a;
        for (int b = 32; b < 127; b++)
        {
            random[1] = b;
            for (int c = 32; c < 127; c++)
            {
                random[2] = c;
                for (int d = 32; d < 127; d++)
                {
                    random[3] = d;
                    for (int e = 32; e < 127; e++)
                    {
                        random[4] = e;
                        for (int f = 32; f < 127; f++)
                        {
                            random[5] = f;
                            for (int g = 32; g < 127; g++)
                            {
                                random[6] = g;
                                for (int h = 32; h < 127; h++)
                                {
                                    random[7] = h;
                                    printf("%s\n", random);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}