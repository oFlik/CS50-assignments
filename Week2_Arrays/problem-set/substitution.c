#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function declaration
int validate(int number, string argument);
char encipher(char letter, string key);

// alphabet for comparison
const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[])
{
    // calls the function to validade the command line arguments
    if (validate(argc, argv[1]) == 1)
    {
        return 1;
    }

    // gets the user's input
    string plaintext = get_string("plaintext:  ");

    // prepares for printing the ciphertext
    printf("ciphertext: ");

    // calls the function to enciphe one char at a time
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", encipher(plaintext[i], argv[1]));
    }

    printf("\n");
}

// validate the command line arguments
int validate(int number, string argument)
{
    // checks if there's only one additional argument
    if (number != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // checks if there's the correct number of chars
    else if (strlen(argument) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // creates the loop to iterate in every char
    for (int i = 0; i < strlen(argument); i++)
    {
        // checks if its a valid alphabetic letter
        if (isdigit(argument[i]) != 0 || isalpha(argument[i]) == 0)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

        // checks if there's no repeated chars
        int count = 0;

        for (int j = 0; j < strlen(argument); j++)
        {
            if (argument[j] == argument[i])
            {
                count++;
            }
        }

        if (count > 1)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }

    // if the char passed every validation, returns 0
    return 0;
}

// encipher one char at a time using the key
char encipher(char letter, string key)
{
    if (islower(letter) != 0)
    {
        letter = toupper(letter);

        for (int i = 0; i < strlen(alphabet); i++)
        {
            if (letter == alphabet[i])
            {
                letter = tolower(key[i]);

                return letter;
            }
        }
    }
    else if (isupper(letter) != 0)
    {
        for (int i = 0; i < strlen(alphabet); i++)
        {
            if (letter == alphabet[i])
            {
                letter = toupper(key[i]);

                return letter;
            }
        }
    }

    return letter;
}