#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    int n = strlen(input);

    //converts the char to int
    int integer = input[n - 1] - 48;
    // shorten the string size by 1
    input[n - 1] = input[n];

    // base case
    if (n == 0)
    {
        return 0;
    }

    return integer + 10 * convert(input);
}