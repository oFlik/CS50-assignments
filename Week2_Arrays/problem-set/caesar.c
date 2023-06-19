#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Functions declaration
bool only_digits(string key);
char rotate(char letter, int key);

// "A" and "a" number on ASCII
const int initiallower = 97;
const int initialupper = 65;

int main(int argc, string argv[])
{
    // checks if the command line has only 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // calls the function to check if the command line second argument is a digit
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // converts the given argument to an int and prompt the user for an text to be converted
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    // prints the chars rotated by calling a function
    for (int i = 0; i < strlen(plaintext); i++)
    {
        plaintext[i] = rotate(plaintext[i], key);
        printf("%c", plaintext[i]);
    }
    printf("\n");

}

// checks if the command line argument has only digits
bool only_digits(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (isdigit(key[i]) == false)
        {
            return false;
        }
    }
    return true;
}

// rotates the letters by the key number of times.
char rotate(char letter, int key)
{
    // gets the ascii number of the char
    int lettNumb = letter;

    // does the rotation if its a lower char
    if (islower(letter) != 0)
    {
        lettNumb -= initiallower;

        lettNumb += key;

        if (lettNumb > 25)
        {
            int x = lettNumb / 25;
            lettNumb = (lettNumb % 25) - x;
        }
        else
        {
            lettNumb = lettNumb % 25;
        }

        lettNumb += initiallower;
    }
    // does the rotation if its a upper char
    else if (isupper(letter) != 0)
    {
        lettNumb -= initialupper;

        lettNumb += key;

        if (lettNumb > 25)
        {
            int x = lettNumb / 25;
            lettNumb = (lettNumb % 25) - x;
        }
        else
        {
            lettNumb = lettNumb % 25;
        }

        lettNumb += initialupper;
    }

    letter = lettNumb;

    return letter;
}