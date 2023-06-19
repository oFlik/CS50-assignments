// Teste final da semana 1 do CS50x.
#include <cs50.c>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card = get_long("Number: ");

    // Pega a quantidade de números inseridos pelo usuário.
    long x = card;
    int size = 0;

    do
    {
        size++;
        x = x / 10;
    }
    while (x != 0);

    // Declaração de variáveis para Luhn’s Algorithm.
    int par = 0;
    int impar = 0;
    int iniciais = 0;

    for (int i = 2; i < size + 2; i++)
    {
        int last = card % 10;
        card = card / 10;

        if (i == size - 1)
        {
            iniciais = card;
        }

        //Faz a validação em si.
        if (i % 2 == 0)
        {
            if (last > 4)
            {
                par += last % 10;
                par += last / 10;
            }
            else
            {
                par += last;
            }
        }
        else
        {
            if (last > 4)
            {
                impar += (last * 2) % 10;
                impar += (last * 2) / 10;
            }
            else
            {
                impar += last * 2;
            }
        }
    }

    int validate = par + impar % 10;

    // Dependendo do resultado da validação, imprime o nome do cartão ou se é inválido.
    if (validate % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (iniciais >= 40 && iniciais < 50)
        {
            if (size == 13 || size == 16)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            switch (iniciais)
            {
                case 34:
                case 37:
                    printf("AMEX\n");
                    break;
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                    printf("MASTERCARD\n");
                    break;
                default:
                    printf("INVALID\n");
                    break;
            }
        }
    }

    system("PAUSE");
}
// Fim do exame 10/10!