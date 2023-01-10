#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Implement a program that encrypts messages using Caesar’s cipher */

bool only_digits(string s);
void caesar_cipher(char input, int key);

int main(int argc, string argv[])
{
    // Make sure that user enters key when running program
    if (argc == 2)
    {
        if (only_digits(argv[1]))
        {
            // Get message to encrypt
            string input = get_string("plaintext: ");
            int key = atoi(argv[1]); // convert key from string to integer
            printf("ciphertext: ");

            for (int i = 0; i < strlen(input); i++)
            {
                caesar_cipher(input[i], key); // Run cipher function on each character in message
            }
            printf("\n");

        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}

bool only_digits(string s)
{
    // Check that entered key is an integer
    int num_count= 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
             num_count++;
        }
    }

    if (num_count == strlen(s))
    {
        return true;
    }
    else
    {
        return false;
    }


}


void caesar_cipher(char letter, int key)
{
    // If the character is alphabetical, rotate the letter
    if (isalpha(letter))
    {
         if (isupper(letter))
         {
            printf ("%c", ((letter - 65 + key) % 26) + 65);
         }

         else
         {
            printf ("%c", ((letter - 97 + key) % 26) + 97);
         }

    }

    // If the character is numerical or punctuation, don't change it
    else
    {
        printf("%c", letter);
    }


}