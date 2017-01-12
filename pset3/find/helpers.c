/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 * Binary search functoin.
 */
bool search(int value, int values[], int n)
{
    int halfway, lower_bound = 0, upper_bound = (n - 1); // initialisaties niet soms wel, soms niet declareren op één regel
    while (lower_bound <= upper_bound)
    {
        halfway = (lower_bound + upper_bound) / 2;
        if (values[halfway] < value)
        {
            lower_bound = halfway + 1;
        }
        else if (values[halfway] > value)
        {
            upper_bound = halfway - 1;
        }
        else
        {
            return 1; // true is netter
        }
    }
    return 0;   // false is netter
}
    

/**
 * Sorts array of n values.
 * Based on the pseudocode from the video on insertion sort & wikipedia
 * source : https://www.youtube.com/watch?v=DFG-XuyPYUQ / https://en.wikipedia.org/wiki/Insertion_sort
 */
void sort(int values[], int n)
{
    int sorted = 0, element = 0;
    for (int i = 1; i < n - 1; i++) // moet gewoon n zijn
    {
        element = values[i];
        sorted = i;
        while (sorted > 0 && values[sorted - 1] > element)
        {
            values[sorted] = values[sorted - 1];
            sorted = sorted - 1;
        }
        values[sorted] = element;
    }
}