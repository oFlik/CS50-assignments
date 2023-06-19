// Gets an input and return the total of coins to return
#include <cs50.c>
#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
    system("PAUSE");
}

int get_cents(void)
{
    // TODO
    int cents;

    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    return cents;
}

int calculate_quarters(int cents)
{
    // TODO
    int quarters = 0;
    int restQuarters = 0;

    if (cents < 25)
    {
        restQuarters = cents;
    }
    else
    {
        quarters = cents / 25;
        restQuarters = cents % 25;
    }

    return quarters;
    return restQuarters;
}

int calculate_dimes(int restQuarters)
{
    // TODO
    int dimes = 0;
    int restDimes = 0;

    if (restQuarters < 10)
    {
        restDimes = restQuarters;
    }
    else
    {
        dimes = restQuarters / 10;
        restDimes = restQuarters % 10;
    }

    return dimes;
    return restDimes;
}

int calculate_nickels(int restDimes)
{
    // TODO
    int nickels = 0;
    int restNickels = 0;

    if (restDimes < 5)
    {
        restNickels = restDimes;
    }
    else
    {
        nickels = restDimes / 5;
        restNickels = restDimes % 5;
    }

    return nickels;
    return restNickels;
}

int calculate_pennies(int restNickels)
{
    // TODO
    int pennies;

    pennies = restNickels / 1;

    return pennies;
}
