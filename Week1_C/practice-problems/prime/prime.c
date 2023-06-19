#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    //Pega os valores mínimo e máximo do usuário.
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    //Se o número for primo, esceve ele no terminal.
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    //Checa se o número é maior que 2.
    if (number < 2)
    {
        return false;
    }

    //Calcula se a divisão do número por todos entre 2 e ele resultam em algum resto.
    for (int a = 2; a < number - 1; a++)
    {
        int resto = number % a;

        if (resto == 0)
        {
            return false;
        }
    }

    return true;
}
