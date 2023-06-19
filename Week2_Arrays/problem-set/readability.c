// Checks the reading grade from a phrase.
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Indicates the functions below main.
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    // Calls the functions for the number of sentences, words anda letters.
    float S = (float) count_sentences(text) / count_words(text) * 100;
    float L = (float) count_letters(text) / count_words(text) * 100;

    // Coleman-Liau index.
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // Prints the results.
    if (grade > 15)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Gets the letters count.
int count_letters(string text)
{
    int lettersNumber = 0;
    int textSize = strlen(text);

    for (int i = 0; i < textSize; i++)
    {
        if (isalpha(text[i]))
        {
            lettersNumber++;
        }
    }

    return lettersNumber;
}

// Gets the words count.
int count_words(string text)
{
    int textSize = strlen(text);
    int spaces = 0;

    for (int i = 0; i < textSize; i++)
    {
        if (isspace(text[i]))
        {
            spaces++;
        }
    }

    return spaces + 1;
}

// Gets the sentences count.
int count_sentences(string text)
{
    int textSize = strlen(text);
    int sentences = 0;

    for (int i = 0; i < textSize; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}