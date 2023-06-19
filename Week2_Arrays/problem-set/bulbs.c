//bulbs for CS50's problem set 2
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    //pega o texto do usuário
    string text = get_string("Message: ");

    //cria o loop para iterar por todas as letras do texto
    for (int i = 0; i < strlen(text); i++)
    {
        //criação de variáveis, lista pra armazenar os valores binários e outra pra guardar o inteiro da letra usada.
        int byte[BITS_IN_BYTE];
        int next = (int) text[i];

        //itera sobre a letra em questão armazenando os binários na array criada.
        for (int j = BITS_IN_BYTE; j > 0; j--)
        {
            byte[j - 1] = next % 2;
            next /= 2;
        }

        //chama a função para imprimir a lista em formato de emoji.
        for (int j = 0; j < 8; j++)
        {
            print_bulb(byte[j]);
        }
        printf("\n");

    }
}

//converte um int para um emoji.
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
