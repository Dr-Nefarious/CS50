#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;


void print_bulb(char letter);
int char_to_binary(char letter);

int main(void)
{
    string message = get_string("Message: ");

    int byte = 0;
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        print_bulb(message[i]);
        //byte = char_to_binary(message[i]);
        //printf("Byte: %08d\n", byte);
    }

}


void print_bulb(char letter)
{
    // Convert character to ASCII value

    int ascii_val = letter;

    static int remainder_arr[BITS_IN_BYTE], binary_arr[BITS_IN_BYTE];
    int quotient = ascii_val * 2;

    // Convert ASCII value to binary

    // Divide the ASCII value by 2 repeatedly 8 times to create a byte
    // Add the remainder of each successive division to an array
    for (int i = 0, n = BITS_IN_BYTE; i < n ; i++)
    {
        quotient = quotient / 2;
        remainder_arr[i] = quotient % 2;
    }

    // Flip the contents of the array (create a mirror image)
    // This is will convert it to binary
    for (int i = BITS_IN_BYTE - 1, j = 0; i >= 0; i--, j++)
    {
        binary_arr[j] = remainder_arr[i];
    }

    // Iterate over the array
    // Print an "on" bulb when there is a 1 and "off" when there is a 0
    for (int k = 0, arrLen = BITS_IN_BYTE; k < arrLen; k++)
    {
        if (binary_arr[k] == 0)
        {
            // Dark emoji
            printf("\U000026AB");
        }
        else if (binary_arr[k] == 1)
        {
            // Light emoji
            printf("\U0001F7E1");
        }

    }
    printf("\n");
}

int char_to_binary(char letter)

{
    // Convert character to ASCII value

    int ascii_val = letter;

    static int remainder_arr[BITS_IN_BYTE], binary_arr[BITS_IN_BYTE];
    int quotient = ascii_val * 2;

    // Convert ASCII value to binary

    // Divide the ASCII value by 2 repeatedly 8 times to create a byte
    // Add the remainder of each successive division to an array
    for (int i = 0, n = BITS_IN_BYTE; i < n ; i++)
    {
        quotient = quotient / 2;
        remainder_arr[i] = quotient % 2;
    }

    // Flip the contents of the array (create a mirror image)
    // This is will convert it to binary
    for (int i = BITS_IN_BYTE - 1, j = 0; i >= 0; i--, j++)
    {
        binary_arr[j] = remainder_arr[i];
    }

    // Cannot return an array so convert array to a string so the leading 0s are kept
    int binary_num = 0;

    for (int k = 0; k < BITS_IN_BYTE; k++)
    {
        binary_num = 10 * binary_num + binary_arr[k];
    }
    return binary_num;
}