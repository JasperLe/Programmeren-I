#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET 26
#define ASCII_LOWER 96
#define ASCII_UPPER 64
#define ASCII_CODE_LOWER 97
#define ASCII_CODE_UPPER 65

/*************************************************
 * File name: Vigenere
 * Vak: Programmeer theorie 1
 * Auteur: Jasper Lelijveld
 * Studentnummer: 11401753
 * 
 * Via commandline uitvoeren. Dit programma vereist een input in de vorm van een string.
 * Dit is de encryptie code. Vervolgens wordt deze string aangepast zodat a=0 tot z=25.
 * Met deze code wordt de vervolgens ingevoerde string aangepast. De code herhaalt zich steeds, dus, aba *3 is abaabaaba. 
 * Leestekens, cijfers en spaties worden overgeslagen en de code gaat dan niet 1 i verder.
 * 
 * Return 1 zodra de encryptie_code != alpha, of != 1 is (dus als er meerdere argumenten zijn ingevoerd in de commandline).
 * 
 * KAN MAKKELIJKER (waarschijnlijk)
 * 
 * BLOK HOORT HELEMAAL BOVENAAN
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
        int key_length = strlen(argv[1]);
        string key = argv[1];
        for (int i = 0; i < key_length; i++)
        {
            if (isdigit(key[i]))
            {
                printf("Try again\n");
                return 1;
            }
        }
        // check code for non alpha input
        string input = GetString();
        // get the inputs length
        int input_length = strlen(input);

        for (int i = 0; i < key_length; i++)
        {
            // check for alpha
            if (isalpha(key[i]))
            {
            // check key for upper and adjust for the ASCII
                if (isupper(key[i]))
                {
                    key[i] -= ASCII_CODE_UPPER;
                }
                // check for lower and adjust for the ASCII and add key
                else if (islower(key[i]))
                {
                    key[i] -= ASCII_CODE_LOWER;
                }
            }
        }
        int j = 0;
        
// HAD OOK MAKKELIJKER GEKUNT, NAMELIJK: gebruik een voorwaarde en pas op basis daarvan de ACII_etc aan, dus niet check upper/lower dan een van de twee blokken. Maar check upper/lower en pas op basis daarvan de blokwaarden aan
        for (int i = 0; i < input_length; i++)
        {
            // check for upper and adjust for the ASCII and add key, move key[] by 1
            if (isupper(input[i]))
            {
                input[i] -= ASCII_UPPER;
                input[i] += key[j];
                if (input[i] > ALPHABET)
                {
                    input[i] %= ALPHABET;
                }
                input[i] += ASCII_UPPER;
                j++;
            }
            // check for lower and adjust for the ASCII and add key, move key[] by 1
            else if (islower(input[i]))
            {
                input[i] -= ASCII_LOWER;
                input[i] += key[j];
                if (input[i] > ALPHABET)
                {
                    input[i] %= ALPHABET;
                }
                input[i] += ASCII_LOWER;
                j++;
            }
            // when j == key_length, it should start again from [0]
            if (j == key_length)
            {
                j = 0;
            }
        }
        printf("%s\n", input);
    }
}