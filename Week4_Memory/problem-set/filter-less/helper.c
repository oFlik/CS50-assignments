#include "helpers.h"
#include <math.h>
#include <stdbool.h>

RGBTRIPLE corners(RGBTRIPLE current, RGBTRIPLE first, RGBTRIPLE second, RGBTRIPLE third);
RGBTRIPLE sides(RGBTRIPLE first, RGBTRIPLE current, RGBTRIPLE second, RGBTRIPLE third, RGBTRIPLE forth, RGBTRIPLE fifth);
RGBTRIPLE standard(RGBTRIPLE first, RGBTRIPLE second, RGBTRIPLE third, RGBTRIPLE forth, RGBTRIPLE current, RGBTRIPLE sixth,
                   RGBTRIPLE seventh, RGBTRIPLE eigth, RGBTRIPLE nineth);
int checkTemp(int temp);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Pega a média dos valores RGB e converte pra cinza.
            int avg = round(((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = avg;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // FEITO DE PRIMEIRA TAMBÉM O HOMEM É UM DEUS <edit> não sabia como arredondar então demorou bem mais.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Aplica a forma para converter pra sépia.
            int tempR = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            tempR = checkTemp(tempR);

            int tempG = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            tempG = checkTemp(tempG);

            int tempB = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            tempB = checkTemp(tempB);

            image[i][j].rgbtRed = tempR;
            image[i][j].rgbtGreen = tempG;
            image[i][j].rgbtBlue = tempB;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // De segunda, pois esqueci de colocar o if
    for (int i = 0; i < height; i++)
    {
        int last = width - 1;
        bool pair = false;

        // define se o tamanho da linha é par, para saber onde parar.
        if (last % 2 == 0)
        {
            pair = true;
        }

        for (int j = 0; j < width; j++)
        {
            // Vai trocando os valores inciais pelos finais, até todos estarem trocados.
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][last];
            image[i][last] = temp;

            last--;

            if (pair == true)
            {
                if (last == width / 2)
                {
                    break;
                }
            }
            else
            {
                if (last < width / 2)
                {
                    break;
                }
            }
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Esse foi o mais difícil, muitos valores pra arredondar.
    // Cria uma cópia, pois se usarmos o original, vamos fazer blur por cima de blur
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Define variável pra armazenar o valor da última linha e coluna
    int lastH = height - 1;
    int lastW = width - 1;

    // Faz o blur nos cantos.
    image[0][0] = corners(copy[0][0], copy[0][1], copy[1][0], copy[1][1]);
    image[0][lastW] = corners(copy[0][lastW], copy[0][lastW - 1], copy[1][lastW - 1], copy[1][lastW]);
    image[lastH][0] = corners(copy[lastH][0], copy[lastH - 1][0], copy[lastH - 1][1], copy[lastH][1]);
    image[lastH][lastW] = corners(copy[lastH][lastW], copy[lastH - 1][lastW - 1], copy[lastH - 1][lastW], copy[lastH][lastW - 1]);

    // Faz o blur nas bordas.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j != 0 && j != lastW)
            {
                image[i][j] = sides(copy[i][j - 1], copy[i][j], copy[i][j + 1], copy[i + 1][j - 1], copy[i + 1][j], copy[i + 1][j + 1]);
            }
            else if (i == lastH && j != 0 && j != lastW)
            {
                image[i][j] = sides(copy[i][j - 1], copy[i][j], copy[i][j + 1], copy[i - 1][j - 1], copy[i - 1][j], copy[i - 1][j + 1]);
            }
            else if (j == 0 && i != 0 && i != lastH)
            {
                image[i][j] = sides(copy[i - 1][j], copy[i][j], copy[i + 1][j], copy[i - 1][j + 1], copy[i][j + 1], copy[i + 1][j + 1]);
            }
            else if (j == lastW && i != 0 && i != lastH)
            {
                image[i][j] = sides(copy[i - 1][j], copy[i][j], copy[i + 1][j], copy[i - 1][j - 1], copy[i][j - 1], copy[i + 1][j - 1]);
            }
            // Faz o blur no resto da imagem.
            else if (i != 0 && i != lastH && j != 0 && j != lastW)
            {
                image[i][j] = standard(copy[i - 1][j - 1], copy[i - 1][j], copy[i - 1][j + 1], copy[i][j - 1], copy[i][j], copy[i][j + 1],
                                       copy[i + 1][j - 1], copy[i + 1][j], copy[i + 1][j + 1]);
            }
        }
    }

    return;
}

// Blur nos cantos
RGBTRIPLE corners(RGBTRIPLE current, RGBTRIPLE first, RGBTRIPLE second, RGBTRIPLE third)
{
    RGBTRIPLE new;

    new.rgbtBlue = round((current.rgbtBlue + first.rgbtBlue + second.rgbtBlue + third.rgbtBlue) / 4.0);
    new.rgbtGreen = round((current.rgbtGreen + first.rgbtGreen + second.rgbtGreen + third.rgbtGreen) / 4.0);
    new.rgbtRed = round((current.rgbtRed + first.rgbtRed + second.rgbtRed + third.rgbtRed) / 4.0);

    return new;
}

// Blur nas bordas
RGBTRIPLE sides(RGBTRIPLE first, RGBTRIPLE current, RGBTRIPLE second, RGBTRIPLE third, RGBTRIPLE forth, RGBTRIPLE fifth)
{
    RGBTRIPLE new;

    new.rgbtBlue = round((current.rgbtBlue + first.rgbtBlue + second.rgbtBlue + third.rgbtBlue + forth.rgbtBlue + fifth.rgbtBlue) /
                         6.0);
    new.rgbtGreen = round((current.rgbtGreen + first.rgbtGreen + second.rgbtGreen + third.rgbtGreen + forth.rgbtGreen +
                           fifth.rgbtGreen) / 6.0);
    new.rgbtRed = round((current.rgbtRed + first.rgbtRed + second.rgbtRed + third.rgbtRed + forth.rgbtRed + fifth.rgbtRed) / 6.0);

    return new;
}

// Blur no resto da imagem
RGBTRIPLE standard(RGBTRIPLE first, RGBTRIPLE second, RGBTRIPLE third, RGBTRIPLE forth, RGBTRIPLE current, RGBTRIPLE sixth,
                   RGBTRIPLE seventh, RGBTRIPLE eigth, RGBTRIPLE nineth)
{
    RGBTRIPLE new;

    new.rgbtBlue = round((current.rgbtBlue + first.rgbtBlue + second.rgbtBlue + third.rgbtBlue + forth.rgbtBlue + sixth.rgbtBlue +
                          seventh.rgbtBlue + eigth.rgbtBlue + nineth.rgbtBlue) / 9.0);
    new.rgbtGreen = round((current.rgbtGreen + first.rgbtGreen + second.rgbtGreen + third.rgbtGreen + forth.rgbtGreen + sixth.rgbtGreen
                           + seventh.rgbtGreen + eigth.rgbtGreen + nineth.rgbtGreen) / 9.0);
    new.rgbtRed = round((current.rgbtRed + first.rgbtRed + second.rgbtRed + third.rgbtRed + forth.rgbtRed + sixth.rgbtRed +
                         seventh.rgbtRed + eigth.rgbtRed + nineth.rgbtRed) / 9.0);

    return new;
}

// Usado no filtro sépia
int checkTemp(int temp)
{
    if (temp < 0)
    {
        temp = 0;
    }
    else if (temp > 255)
    {
        temp = 255;
    }

    return temp;
}