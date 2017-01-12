/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int dimensions;

// x & y coordinates blank
int blank_x, blank_y;

// prototypes
void swap(int *a, int *b);
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);


int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    dimensions = atoi(argv[1]);
    if (dimensions < DIM_MIN || dimensions > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
    
    // give blank its coordinates
    blank_x = dimensions - 1, blank_y = dimensions - 1;
    
    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < dimensions; i++)
        {
            for (int j = 0; j < dimensions; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < dimensions - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("\033[0m");
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int number = (dimensions * dimensions);
    for (int i = 0; i < dimensions; i++)
    {
        for (int j = 0; j < dimensions; j++)
        {
            number -= 1;
            board[i][j] = number;
        }
    }
    if ((dimensions & 1) == 0)
    {
        swap(&board[dimensions - 1][dimensions - 3], &board[dimensions - 1][dimensions - 2]);
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < dimensions; i++)
    {
        for (int j = 0; j < dimensions; j++)
        {
            if (board[i][j] != 0)
            {
                printf("\033[1;31m%3i", board[i][j]);
            }
            else
            {
                printf(" ");
                printf("\033[47m  ");
                printf("\033[0m");
            }
        }
        printf("\n");
    }
}

/**
 * Returns true if tile is allowed to move and moves it
 * else false
 */
bool move(int tile)
{
    // determine whether move is allowed and assigns new values blank_x & blank_y
    for (int i = 0; i < dimensions; i++)
    {
        for (int j = 0; j < dimensions; j++)
        {
            if (board[i][j] == tile)
            {
          //      (abs(blank_x - i) + abs(blank_y - j) == 1)   is beter
                if (((i + 1 == blank_y && blank_x == j) || (i - 1 == blank_y && blank_x == j)) || ((j + 1 == blank_x && blank_y == i) || (j - 1 == blank_x && blank_y == i)))
                {
                    swap(&board[i][j], &board[blank_y][blank_x]);
                    blank_x = j;
                    blank_y = i;
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int k = 1;

    for (int i = 0; i < dimensions; i++)
    {
        for (int j = 0; j < dimensions; j++)
        {
            if (board[i][j] != k)
            {
                return false;
            }
            k++;
            if (k == (dimensions * dimensions))
            {
                break;
            }
        }
    }
    return true;
}

/**
 * Swaps two inputs
 * Made it work thanks to http://stackoverflow.com/questions/1501217/c-function-to-swap-values-in-2d-array
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}