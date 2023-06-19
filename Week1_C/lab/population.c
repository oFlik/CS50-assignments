#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Declaração de variáveis
    int inicial;
    int final;
    int anos = 0;

    //Conseguir os valores inicial e final do usuário
    do
    {
        inicial = get_int("Quatidade inicial: ");
    }
    while (inicial < 9);

    do
    {
        final = get_int("Quantidade final: ");
    }
    while (final < inicial);

    //Cálculo da quantidade de anos necessária
    for (int a = inicial; a < final;)
    {
        inicial = inicial + (inicial / 3) - (inicial / 4);
        a = inicial;
        anos++;
    }

    //Retorna para o usuário a quantidade final
    printf("Years: %i", anos);
}
