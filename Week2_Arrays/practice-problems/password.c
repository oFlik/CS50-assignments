// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool lower, upper, number, symbol = false;
    int heigth = strlen(password);

    for (int i = 0; i < heigth; i++)
    {
        if (islower(password[i]) != 0)
        {
            lower = true;
        }
        else if (isupper(password[i]) != 0)
        {
            upper = true;
        }
        else if (isalnum(password[i]) != 0)
        {
            number = true;
        }
        else if (ispunct(password[i]) != 0)
        {
            symbol = true;
        }
    }

    if (lower == true && upper == true && number == true && symbol == true)
    {
        return true;
    }

    return false;
}
