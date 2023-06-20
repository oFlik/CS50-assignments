#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    // Iterates over the i column
    for (int i = 0; i < height; i++)
    {
        // Iterates over the j line
        for (int j = 0; j < width; j++)
        {
            // Set value for black in hexadec
            int black = 0x00;

            // Set pixel to check
            RGBTRIPLE *pixel = &image[i][j];

            // Check if the pixel is black, if yes, change the color
            if (pixel->rgbtBlue == black || pixel->rgbtGreen == black || pixel->rgbtRed == black)
            {
                pixel->rgbtBlue = 0xf0;
                pixel->rgbtGreen = 0x3c;
                pixel->rgbtRed = 0x13;
            }
        }
    }
}
