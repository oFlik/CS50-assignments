// Mario more for CS50x
#include <cs50.h>
#include <stdio.h>

int main(void)
{

// Gets the input from the user
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    int i = 0;

// Prints the bricks based on the input.
    do
    {
        for (int j = 0; j < height - 1; j++)
        {
            printf(" ");
        }

        height--;
        i++;

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf("\n");
    }
    while (height > 0);
// bye
}