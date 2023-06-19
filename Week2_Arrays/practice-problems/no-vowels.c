// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string palavra);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("ERROR\n");
        return 1;
    }

    printf("%s\n", replace(argv[1]));
}

string replace(string palavra)
{

    int tamanho = strlen(palavra);

    for (int i = 0; i < tamanho; i++)
    {
        switch (palavra[i])
        {
            case 'a':
                palavra[i] = '6';
                break;
            case 'e':
                palavra[i] = '3';
                break;
            case 'i':
                palavra[i] = '1';
                break;
            case 'o':
                palavra[i] = '0';
                break;
        }
    }

    return palavra;
}