#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

/* Implement a program that calculates the approximate grade level needed to comprehend some text */


int count_letters(string input);
int word_count(string input);
int sentence_count(string input);

int main (void)
{
    string text = get_string("Text: ");
    printf("%s\n", text);

    int letters = count_letters(text);
    printf("%i letters\n", letters);

    int words = word_count(text);
    printf("%i words\n", words);

    int sentences = sentence_count(text);
    printf("%i sentences\n", sentences);

    // Calculating the Coleman-Liau index
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences/ (float) words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }

}

int count_letters(string input)
{
    int letters = 0;

    // For each characters throughout the length of the text
    for (int i = 0; i < strlen(input); i++)
    {
        // If the character is not nul and is alphabetic
        if (input[i]!= '\0' && isalpha(input[i]))
        {
            // Increment letters
            letters++;
        }
    }
    return letters;
}

int word_count(string input)
{
    int words = 1;

    for (int j = 0; j < strlen(input); j++)
    {
        // Assume each word is separated by a space
        if (input[j] == ' ')
        {
            words++;
        }
    }
    return words;
}

int sentence_count(string input)
{
    int sentences = 0;

    for (int k = 0; k < strlen(input); k++)
    {
        // Check if character is a punctuation marker
        if (input[k] == '.' || input[k] == '?' || input[k] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}