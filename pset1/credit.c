#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

/**************************************************
 * This program takes a number checks whether it is valid, and outputs the creditcard company
 * No operations are performed on the original credit_card_number, a substitute (calc) is used
 * Author: Jasper Lelijveld & google/stackoverflow
 * v1a
 *********************************************** */
 

int main (void)
{
    int length = 0, length_check = 0;
    long long credit_card_number, division, calc, sum = 0, print, sub_sum;
    
    // ask for the creditcard number
    printf("Number: ");
    credit_card_number = GetLongLong();
    calc = credit_card_number;              // not changing credit_card_number
    division = credit_card_number;
    
    // checks for first number and the amount of numbers
    for (int i = 0; division > 10; i++)
    {
        division /= 10;
        length = i;
        length_check = i + 2;
    }
    for (int i = 0; calc; i++)              // while calc is != 0
    {
        print = calc % 10;
        if ((i & 1) != 0)                       // checks what number is being analyzed and determines based on i whether it should be multiplied or summed
        {
            if (print > 4)                          // if number > 4, the number should be split in two numbers (no while loop because only one execution is needed)
            {
                print = print * 2;
                sub_sum = print % 10;
                sub_sum += 1;
                sum += sub_sum;                     // two numbers are added to sum
            }
            else
            sum += (print * 2);                     // if number > 4 simply multiply number
        }
        else                                    // odd, simply add number to sum
        {
            sum += print;
        }
        calc /= 10;                             // divide by 10 and repeat
        length--;
        // printf("%lld\n", sum);               // remove (//) to check the sum after each digit is
    }
    sum += calc;
    if (((sum != 0) || (division != 3 || division != 4 || division != 5)) && (length_check < 13 || length_check > 16))       // if any of these conditions, length, last number and sum aren't met, print invalid
    {
        printf("INVALID\n");
    }
    else                                           // depending on last (or first depending on your perspective) number, assign the correct company
    {
        switch (division)
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
    // printf("%lld\n", sum);                  // to check whether the number is actually an invalid number (remove // to implement)
}