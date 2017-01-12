#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define ASCII_lower 122
#define ASCII_upper 90

/*************************************************
 * File name: Caesar
 * Vak: Programmeer theorie 1
 * Auteur: Jasper Lelijveld
 * Studentnummer: 11401753
 * 
 * Via commandline uitvoeren. Voer een getal in bij het aanroepen via de commandline. Vervolgens kan je tekst invoeren.
 * Deze string wordt aangepast op basis van het ingevoerde getal. Vervolgens wordt de aangepaste string afgedrukt.
 * 
 * Geen bugs.
 ************************************************/

int main(int argc, string argv[])
{
    // If less than, or more than 1 argument is entered show an error message
    if (argc != 2)
    {
        printf("Try again\n");
        return 1;
    }
    // else continue
    else if (argc == 2)
    {
        // assign second argument(the first entered) to an key number
        int key = atoi(argv[1]);
        // get an input in string
        string input = GetString();
        // get the inputs length
        int input_length = strlen(input);
        // for every character in the input, determine if upper or lower and shift the input cha by the key
        for (int i = 0; i < input_length; i++)
        {
            // check for upper and adjust for the ASCII and add key
            if (isupper(input[i]))
            {
                input[i] += key;
                if (input[i] > ASCII_upper)
                {
                    input[i] %= 90;
                    input[i] -= 26;
                }
            }
            // check for lower and adjust for the ASCII and add key
            else if (islower(input[i]))
            {
                input[i] += key;
                if (input[i] > ASCII_lower)
                {
                    input[i] %= 122;
                    input[i] -= 26;
                }
            }
        }
        // print the adjusted string and return 0;
        printf("%s\n", input);
        return 0;
    }
}