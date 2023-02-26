/* Compiling */

// the source cord needs to be converted into machine code inoder for it to run

#include <stdio.h>

int main(void)
{
    printf("Hello, world\n");
}

// Make is not a compiler, it just automates it
// The compiler that make uses is a compiler called clang

$ clang hello.c
$ ls -> a.out
// a file is created with a very undescripitve name

// clang supports CL arguments which are key phrases after the command in the terminal window that modifies the behavior of the command

$ clang -o hello hello.c -> this will change the name to helloinstead of a.out
// a.out is the default name for the output (assembler.out)

// If you try to put cs50 library in and use get_string, you will get a linker error because it doesn't know where the header file is located on the hard drive of the computer

$ clang -o hello hello.c -lcs50
$ ./hello

// You have to do -l for all of the libraries that are not built-in to C
// Make does all of this easier

// When you compile code, there are a lot of different things that happen
// It allows things to be able to run on mac or PCs for example

//First step is pre-processing: the # is a preprocessive directive
// they are analysized initally before everything else for the header files
// Copies and pastes the contents of the header file into the top of the file
// It adds the declaratiion of get_string and printf to the top

// There is a folder inside of the computer/server called /usr/include that contains the header files

// Step 2 is compiling -> converts the source code to the assembly code

// Step 3: Assemling -> Converts the assembly code to machine code (0s and 1s)

// Step 4: Linking -> in the assembly code, you only have the code that your wrote
// So the code that is written by CS50 and stdio and other libraries used are also linked in

// You can also decompile -> reverse the process and convert from machine code to C
// This can be used to hack code, they can also see the original code you wrote

/* Debugging */
// Skipping debugging part

/* Arrays */

//Computers only has a fixed amount of RAM
// Each datatype has a specific number of bits associated with them
// boolean -> 1 byte (1 bit)
// int -> 4 bytes (32 bits). 4 billion values (-2 billion and + billion)
// long -> 64 bits (8 bytes)
// float -> 4 bytes. Only gives you a certain amount of precision
// double -> 8 bytes
// char -> 1 byte
// string -> variable number amount

// If there are a finit

#include <stdio.h>

int main(void)
{
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    //printf("Average: %i\n", (score1 + score2 + score3) / 3); // can use %d
    // if you want to have a decimal instead and have it be more precise
    printf("Average: %i\n", (score1 + score2 + score3) / 3.0); // at least one of the numbers on the right has to be a float

    // Can also typecast and convert the 3 to a float: (float) 3
}

// The above is still bad design
// An array is the way of storign your data back to back in the computer's memory, so that you can access each individual member easily

int scores[3];
// This is a way of telling the computer to give you 12 bytes in total (4 x 3) so they are all stored back to back in the RAM

int main(void)
{
    int scores[3];

    scores[0] = 72;
    scores[1] = 73;
    scores[2] = 33;

    printf("Average: %i\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}

// An even better way of doing this:

int main(void)
{
    int scores[3];

    for (int i = 0; i < 3; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %i\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}
// The memory is wrapped around contiguously


------------------------------------------------------
#include <cs50.h>
#include <stdio.h>

const int N = 3; // global variable that lets you know that the N is 3 so that you don't have to worry about changing it multiple places
// Don't use the constant in function. It should be independent of the special variable

float average(int array[]);
//array can be called anything

int main(void)
{
    int scores[N];

    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %i\n", average(N, scores)); // pass in the length of the array to the average function
}

float average(int length, int array[])
{
    // You want to create a function that can take the average of a variable number of things
    int sum = 0;
   /// for (int i = 0; i < N; i++)
    for (int i = 0; i < length; i++)
    {
       sum += array[i]; // same as sum = sum + array[i];
    }
    //return sum / (float) N;
    return sum / (float) length;
}

/* Characters and strings */
// A string is an array of characters
// if s = Hi!, then s[0] = H, s[1] = 'i', s[2] = '!'
// But how do you know how long a string is? Hi! is 3 bytes, and David is 5 bytes
// There is a delimiter called the nul character -> \0 So Hi! is actually 4 bytes
// Nul says that the string ends here

#include <stdio.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%c%c%c\n", c1,c2,c3);
    printf("%i %i %i\n", c1,c2,c3); //-> you can see the numbers for each char 72,73,33
}

// Need the cs50 library to use string
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%c%c%c\n", s[0], s[1], s[2], s[3]); // can print out the characters making up the string
}

int main(void)
{
    string words[2];

    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]); //words is an array of string, but a string is just an array of characters
    printf("%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3]);

}

// Length.c

// Can't dynamically figure out the length of an array (in C), but you can do that for a string because of the nul character

int main(void)
{
    string name = get_string("What's your name? ");

    int n = 0;
    // cant use a for loop because you don't know in advance how long the string is
    while (name[n] != '\0') // name is an array, the loop finishes when you reach the nul
    {
        n++;
    }
    printf("%i\n", n);
}

// string.h is a library of string related functions

int main(void)
{
    string name = get_string("What's your name? ");

    int n = strlen(name);
    printf("%i\n", n);
}

// ctype relates to c datatypes
// checking if something is uppercase and converting it

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0; i <strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32); // the upper to lower case are always 32 from each other
        }
        else
        {
            printf("%c", s[i]); // leave the letter alone if it already is uppercase
        }
    }
    printf("\n");
}

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// can use the ctype library to do abpve instead

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    // for (int i = 0; i < strlen(s); i++)
    // not the best to put the strlen string within the for loop because the value never changes
    // We care constantly asking for the length of s but it doesn't ever change

    for (int i = 0; n = strlen(s); i < n; i++) // i changes but n does not, so compare i against n
    {
        printf("%c", toupper(s[i])); // to upper already leaves the letter alone if it is already uppercase
    }
    printf("\n");
}

/* Command Line Arguments */

#include <cs50.h>
#include <stdio.h>

int main (int argc, string argv[]) // void means program takes no command line arguments
// argv is all of the word that you type at the prompt/ command line
// argc  is the count of words
{
    printf("hello, %s\n", argv[1]);
}

int main (int argc, string argv[])
{
    // If the user entered two things (the name of the program and their name)
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else // print out default
    {
        printf("hello, world");
    }
}

/* Exit Status */
// Tells you the error status
// The int in main is the integer returned. It automatically returns 0.

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1; // the returns are not needed because it automatically returns 0 when successful
    }
    else
    {
        printf("hello, %s", argv[1])
        return 0;
    }
}

$ echo $? -> allows you to see the error number that was returned.

// 0 by default means success

/* Cryptography */

// This is the science of encrypting information into cipher text
// Goes from plaintext (input) -> cipher -> ciphertext (output)
// key (input) needed for rotational algorithm (caesar cipher)
// opposite is called decryption