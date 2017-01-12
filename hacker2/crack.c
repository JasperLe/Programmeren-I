#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>
#include <cs50.h>


#define _XOPEN_SOURCE
#define ASCII_num_low 48
#define ASCII_num_up 58


/************************************
 * CHECK DE DICTIONARY SHIT
 * 
 * Kan de volgende codes kraken:
 * HALRCq0IBXEPM : Berkeley
 * 50zPJlUFIYY0o : 13
 * 50MxVjGD7EfY6 : //
 * 50z2Htq2DN2qs : //
 * 50CMVwEqJXRUY : //
 * 50TGdEyijNDNY : //
 * 50QykIulIPuKI : //
 * 50q.zrL5e0Sak : password
 * 50Bpa7n/23iug : 12345
 * HAYRs6vZAb4wo : password
 ***********************************/
 


int main(int argc, string argv[])
{
    // If less than, or more than 1 argument is entered show an error message
    if (argc != 2)
    {
        printf("Try again\n");
        return 1;
    }
    else
    {
        char *res, *encrypted_password;
        char salt[1], random[8];
        encrypted_password = argv[1];
        for (int i = 0; i < 2; i++)
        {
            salt[i] = encrypted_password[i];
        }

        // DICTIONARY WORK!!!!!!!!!
        FILE *fp = fopen("/usr/share/dict/words","r");
        char buf[2047];
        while(fscanf(fp, "%s", buf) != EOF)
        {
            if (strlen(buf) == 2047)
            {
                printf("That was allot");
                return 1;
            }
            res = crypt(buf, salt);
            if (strcmp(res, argv[1]) == 0)
            {
                printf("Bingo! %s\n", buf);
                return 0;
            }
        }
        fclose(fp);
        printf("Het is geen woord uit het amerikaanse woordenboek.\n");
        
            // Random characters


        for (int a = ASCII_num_low; a < ASCII_num_up; a++)
        {
            for (int b = ASCII_num_low; b < ASCII_num_up; b++)
            {
                for (int c = ASCII_num_low; c < ASCII_num_up; c++)
                {
                    for (int d = ASCII_num_low; d < ASCII_num_up; d++)
                    {
                        for (int e = ASCII_num_low; e < ASCII_num_up; e++)
                        {
                            for (int f = ASCII_num_low; f < ASCII_num_up; f++)
                            {
                                for (int g = ASCII_num_low; g < ASCII_num_up; g++)
                                {
                                    for (int h = ASCII_num_low; h < ASCII_num_up; h++)
                                    {
                                        res = crypt(random, salt);
                                        if (strcmp(res, argv[1]) == 0)
                                        {
                                            printf("Bingo! %s\n", random);
                                            return 0;
                                        }
                                        random[0] = h;
                                    }
                                    random[1] = g;
                                }
                                random[2] = f;
                           }
                           random[3] = e;
                       }
                       random[4] = d;
                   }
                   random[5] = c;
                }
                random[6] = b;
            }
            random[7] = a;
            
            printf("Still looking...%i\n", a - 48);
        }
        printf("Het is geen getal tussen 00000000 en 99999999\n");
        return 0;
    }
}