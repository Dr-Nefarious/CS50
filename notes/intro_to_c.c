// source code is the code that is written by the person
// Machine code is the binary code that computers can understand
// The program that converts source code to machine code is called an compiler/interpreter

#include <stdio.h>

int main (void)
{
    string answer = get_string("What's your name? ");
    // If you want to plug a variable in, you need to use placeholder for a string
    // Format code -> %s
    printf("hello, %s\n", answer);
}

#include <stdio.h>

int main (void)
{
    string first = get_string("What's your first name? ");
    string last = get_string("What's your last name? ");

    printf("hello, %s %s\n", first, last);
}

/*  Data types */

    // bool, char, double, float, int, long, string

    // Conditionals

    // if, else

    if (x < y)
    {
        printf("x is less than y");
    }
    else
    {
        printf("x is greater than y");
    }

    //

    if (x < y)
    {
        printf("x is less than y");
    }
    else if (x > y)
    {
        printf("x is greater than y");
    }
    else if (x == y)


/* Compare  */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if ( x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}

/* Characters */
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    get_char("Do you agree? ");

    // When dealing with single characters, you must use single quotes
    // Use double quotes for strings
    if (c == 'y' || c == 'Y')
    {
        printf("Agreed.\n");
    }

    else if (c == 'n' || c == 'N')
    {
        printf("Not agreed.\n");
    }
}

/* Loops */

#include <stdio.h>

int main(void)
{
    printf("meow\n");
    printf("meow\n");
    printf("meow\n");
}

// You generally want to be able to change the code in one place
// Also don't want to copy and paste the same thing

int counter = 0;

// If you want to increment an existing variable
counter = counter + 1; // Dont need to declare datatype if variable is already initialized

// There are different syntactic ways to do something (syntactic sugar)
counter +=1 ;
// If you are just adding one
counter++;
counter--; // for decrementing

int main(void)
{
    int i = 3;
    while (i > 0) // boolean expression is contained within the parentheses
    {
        // while counter is above 0, then it will update each loop until condition is met

        printf("meow\n");
        i--;
    }
}

// Same way to do this but increasing number
int main(void)
{
    int i = 0;
    while (i < 3) // boolean expression is contained within the parentheses
    {
        // while counter is above 0, then it will update each loop until condition is met

        printf("meow\n");
        i++;
    }
}

// another way to do this is by using a for loop
#include <stdbool.h> // this makes t/f recognizable as keywords

for (int i = 0; i < 3; i++) // is initialized to 0
{
    printf("meow\n");
}

// If you want to print something forever
while (true)
// Can also do while (1) because o is intepreted as false; non-zero numbers are ture
{
    printf("meow\n");
}

/* Mario and Functions */

#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 4; i++)
    {
        printf("?");
    }
    printf("\n"); // put the return line after the ??? are printed out
}

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("#\n"); // make a brick vertical
    }
}

// how to make a brick that has both height and rows
int main(void)
{
    // if you want to harden you code and not be able to change a variable value
    const int N = 3;
    for (int i = 0; i < N; i++)
    {
        // A grid is 3 rows
        for (int j = 0; j < N; j++)
        {
            printf("#");
        }
        // put a new row after the first loop
        printf("\n");

    }
}


int main(void)
{
    // Get size of grid
    // If the user does NOT enter a positve number
    int n;
    do
    {
        n = get_int("Size: ");
    }
    // Everything in the do part will be re-looped until the user does not enter n < 1
    while (n < 1);

    // Print the grid
    for (int i = 0; i < n; i++)
    {
        // A grid is 3 rows
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        // put a new row after the first loop
        printf("\n");

    }
}


// Can also generate the psuedocode
#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int size);


int main(void)
{
    // Get size of grid
    int n = get_size();

    // Print grid of bricks
    print_grid(n);
}

// function returns an int (output), but does not take any input
int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);
    return n;
}

// has no return value (just has a side effect: print to screen)
void print_grid(int size)
{
   // Print the grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}


/*Floating-Point Imprecision */

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%i", x + y);
}
// inside of your computer has memory which contain the bytes that contain the bytes
// There is a limit because there is a finite number of 0s and 1s

// computers typically use 32 bits to represent an int
// Half of them are used for negative rest are for positive numbers
// if you set x and y equal 2 billion, it will run out of memory and give wrong number
// integer-overflow

// c gives other datatypes more memory allocations
// longs have 64 bits

int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");

    printf("%li", x + y);
}


// Truncation -> when you are working with decimals, you may truncate the value

int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");

    printf("%li", x / y);
}

// if you do 1/3, you get the answer as 0
// typecast -> convert one datatype to another by explicitly telling the compiler to do so
//

int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");

    float z = (float) x / (float) y;
    printf("%.20f", x / y); // This will give you a weird approximation
    //floating-point imprecision. Computer will give the closest approximation due to finite RAM
}

int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");

    double z = (double) x / (double) y;
    printf("%.20f", z); // This will give you a weird approximation

}

// Allocate 64 bits to doubles instead of 32 in floats