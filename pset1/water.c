#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

/* ******************************************************************************* 
 * This program asks for a input, and outputs the amount of water used in liters
 * Authors: Jasper Lelijveld & google for the 'check whether input=int' statement
 * v1
********************************************************************************/

int main (void)
{
    {
    int shower_time, bottles = 0, water_per_minute = 12;

    printf("Hey! Wanna know how many bottles of water you use while showering?\n");
    // asks for an int input and repeats while anser = false
    do
    {
        printf("minutes: ");
        // checks whether the input is an int, if so, break and end program
        shower_time = GetInt();
    } while (shower_time < 0 || shower_time == 0);
    // only print the output when the input conditions are fulfilled

        bottles = shower_time * water_per_minute;
        // should I include this? : <printf("minutes: %d\n", shower_time);>
        printf("bottles: %d", bottles);
    }
    return 0;
}