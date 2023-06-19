// Mario less for CS50x.
#include <cs50.h>
#include <stdio.h>

// How many comments do you want me to put harvard? Turns out is 4.

int main(void)
{
    
// Gets the input, and repeat until the rules aplied.
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

// Prints the chars based on the input.

    int i = 0;
    int j = 0;

    do
    {
        for (int k = 0; k < height - 1; k++)
        {
            printf(" ");
        }

        height--;
        j++;

        for (int l = 0; l < j; l++)
        {
            printf("#");
        }

        printf("\n");
    }
    while (i < height);
}