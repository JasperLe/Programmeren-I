#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

/**************
 * File name: initials
 * Vak: Programmeer theorie 1
 * Auteur: Jasper Lelijveld
 * Studentnummer: 11401753
 * 
 * Vraagt invoer van naam en verandert alle eerste letters in hoofdletters.
 * 
 * Geen bugs
 * 
 * BLOK HOORT HELEMAAL BOVENAAN
 * *************/
 
int main(void)
{
    string name;
    name = GetString();
    int length = strlen(name);
    
    if (isalpha(name[0]))
    {
        if (isupper(name[0]))
        {
            printf("%c", name[0]);
        }
        else
        {
            name[0] = toupper(name[0]);
            printf("%c", name[0]);
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (isalpha(name[i]) && isspace(name[i - 1]))
        {
            if (isupper(name[i]))
            {
                printf("%c", name[i]);
            }
            else
            {
                name[i] = toupper(name[i]);
                printf("%c", name[i]);
            }
        }
    }
    printf("\n");
}