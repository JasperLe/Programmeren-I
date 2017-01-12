#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>

/**************************************************
 * This program takes a number checks whether it is valid, and outputs the creditcard company
 * No operations are performed on the original credit_card_number, a substitute (calc) is used which is placed in an array.
 * Author: Jasper Lelijveld & google/stackoverflow
 * v1b
 *********************************************** */

int main (void)
{
    int length = 1, position = 0, sum = 0, company;
    long long credit_card_number, calc, division;
    
    // ask for the creditcard number
    printf("Number: ");
    credit_card_number = GetLongLong();
    calc = credit_card_number;              // using substitute so not to changing credit_card_number
    division = credit_card_number;          // for determining length
    
    for (int i = 0; division > 9; i++)      // determining length by dividing by 10
    {
        division /= 10;
        company = division;
        length++;
    }
    if (length != 0)                        // if length is not 0 initialize an array with length [length]
    {
        int numberArray[length];            
        division = calc;
        while (division != 0)               // assigning numbers to positions
        {
            numberArray[position] = division % 10;
            division /= 10;
            position++;
        }
        for (int i = 0; i < length; i++)        // multiply every second number
        {
            i++;
            numberArray[i] = numberArray[i] * 2;
            if (numberArray[i] > 9)             // if multiplied number is larger than 9, take the products of the multiplication and assign to the same position
            {
                int temp = 0;
                temp = numberArray[i];
                temp %= 10;
                temp += 1;
                numberArray[i] = temp;          
            }
            sum += numberArray[i];              // sum the total array
        }
        sum %= sum;                             // use % to check for 0
        if (((sum != 0) || (company != 3 || company != 4 || company != 5)) && (length < 13 || length > 16))     // if any of these conditions, length, last number and sum aren't met, print invalid
        {
            printf("INVALID");
        }
        else                                    // else take company and print the correct name
        {
            switch (company)
            {
                case 3:
                printf("AMEX\n");
                break;
                case 4:
                printf("VISA\n");
                break;
                case 5:
                printf("MASTERCARD\n");
                break;
            }
        }
    }
}