# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <cs50.h>

/*********************************************
 * Takes an input, a number, non-negative and lower than 24 (<-23) and prints two pyramids with a gap size 2 separating them.
 * Left align the bottom corner of the left pyramid. (done automatically at the moment)
 * Author: Jasper Lelijveld & google/stackoverflow
 *********************************************/
 
 int main (void)
 {
     int rows;
     bool answer = false;
     
     while (answer == false)                                        // repeat question until answered properly // can be done with a do while statement
     {
        printf("Height (between 0 and 23): ");
        rows = GetInt();
        if (rows < 0 || rows > 23)                                      // checks whether input > 0 && < 24
        {
            printf("Number is to large or to small. Try again\n");           // no, try again
        }
        else
            break;                                                      // yes, exit input loop
     } 
     for (int i = 0; i < rows; i++)                                 // height of pyramids = rows
     {
         for (int j = 0; j < rows; j++)                                 // for each row spaces are printed until l < rows (This prints the left pyramid)
         {
             if (j < rows - 1 - i)                                              // thus, spaces are printed. Based on the fact that in the first row their should be i - 1 spaces
             {
                printf(" ");
             }
             else                                                               // thus, # are printed. Based on the fact that their should be 1 # in the first row, 2 # in the second row, etc.
             {
                printf("#");
             }
         }
         printf("  ");                                                  // two spaces are printed after the left pyramids row is printed
         for (int k = -1; k < i; k++)                                   // right pyarmid is printed
         {
             printf("#");
         }
         printf("\n");                                              // ends the row and repeats until rows = input are printed
     }
 }