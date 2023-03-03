// How are things like images created using 0s and 1s

//  A bit map is a map of bits. Lets say that 0 is black and 0 is white
// You can represent art with it and make a smiley face for example

// RGB allows you to create a rainbow of colors by just combinations of red, blue and green
// If you have no R B or G, you get black
// If you have a lot of RGB, (255) you get white

/* Hexadecimal */

// When you want more than 0-9, you start using the letters of alphabet
// Instead of using base-2 for binary or base-10 for decimal, base-16 is for hexadecimal

// In the world of hexadecimal, you just use powers of 16
// 16^0, 16^1, 16 ^2...
// 0-9, 10 is 0A, 0F is 15
// 10 is 16, 11 is 17 in decimal
// 16 X 15 + 1*16 = FF =255. You generally only use pairs (up to 16^1) in hexadecimal

// How many bits are needed to make 15 in binary. 4 bits suffice (1111). This would let you represent F
// Hexadecimal can be represented in just 4 bits. Allows you to represent things a little more succinctly

/* Addresses */

// It's easier to use hexadecimal to describe the locations of the addresses of things in memory
// To prevent any ambiguity, you use 0x prefix to make it more clear that something is in hex
// So 10 is not "10" but 16. So would be written as 0x10

#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%p\n", &n); // %p allows you to print to address of a variable
}

// & allows you to get the address of a variable in memory
// * (called the dereference operator) does the opposite. It tells you to go to a specific address in memory

/* Pointers */

// C is as close to the computer's language as you can get
// C allows you to poke around in the computer's memory and do things with it

// Pointer is an address of something in the computers memory

int main(void)
{
    int n = 50;
    int *p = &n; // if you want to store the address of n in a variable
    // p is an address so *p. * means that p is going to a pointer
    printf("%p\n", p);
}

/* Strings */

int main(void)
{
    string s = "HI!";
    // in memory it will look like HI!\0
    // in C when you use double quotes to make a string, it is an indicator to put the nul character
    // s itself is a variable, and thus must take up space itself

}

// Lets imagine that the s[0] is at 0x123, s[1] is at 0x124, s[2] is at 0x125 and s[3] is at 0x126
// But what is s really? COmputer then figures out what the address is of the very first character of the string
// It stores only that address as the address for s. So s is at 0x123
// WHy is is enough to just store the first byte address? Because we always nul terminate them
// So until you have to nul character, you know that all of them are part of the same string

int main(void)
{
    string s = "HI!";// this actually char *s = "HI!";
    printf("%p\n", s);
    // String are not a keyword in C, that is a cs50 thing.
    // Really its a pointer to a char.
}

typedef char *string; // This is the code that was used in the cs50 library so that string can be used

int main(void)
{
    int n = 50;
    int *p = &n; // son't really need this line
    printf("%i\n", *p); // deference p. Prints out 50
}

int main(void)
{
    char *s = "HI!";
    printf("%s\n", s);
    printf("%p\n", &s[0]) // print out the address of the first character
}

/* Pointer Arithmetic */

int main(void)
{
    char *s = "HI!";
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);

    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));

    printf("%s\n", s);
    printf("%s\n", s+1); // will print out character and everything after it until the nul character
    printf("%s\n", s+2);

    // Note that if you're doing this on an integer, you can still do s+1, s+2, etc
    // It doesn't matter the datatype. Don't nned to do s+4 or s+8
}

// Strcmp is needed because == would just compare the memory addresses instead of the actual character

int main(void)
{
    //int i = get_int("i: ");
    // int j = get_int("j: ");

    string s = get_string("s: ");
    string t = get_string("t: ");

    if (s == t)
    {
        printf("Same\n")
    }
    else
    {
        printf("Different\n");
    }


}

/* Copying */

int main(void)
{
    string s = get_string("s: ");

    string t = s; // more clear when you write it as char *t = s

    if (strlen(t) > 0) // bottom line assumes that the user has entered at least one character into s. If they just blindly hit enter, then that would cause a seg fault
        {    // strlen t gets rid othat possiblity to reduce the chances of crashing the program
            t[0] = toupper(t[0]); // copy s into t and then capitalize the first letter in t
        }
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // OUtput is s: Hi! and so is t.
    // This is because t and s have the same memory address in C. Copies the same address for s into t, so when you change it, so does the value in s
}

// malloc -> memory allocation: allows you to ask the OS system for some number of bytes
// returns to you the address of the first byte of memory that it found free for you
// It is not nul terminated. You have to remember how many bytes you asked it for. String do that for you, but malloc does not

// free -> opposite. When you are done with the memory, then you free it by passing in the same address and allows you to hand it back to the OS system
// If you never free the memory, then you will run out of RAM and cause the computer to freeze

#include <stdlib.h> // contains the functions for malloc and free

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc((strlen(s) + 1)); // set t to be the address for a free chunk of memory
    // +1 is for the nul character
    // t is just a pointer to a random value of free space

    /*for (int i = 0, n = strlen(s) + 1; i < n; i++) // bett than doing for (int i = 0; i < strlen(s) + 1; i++) because you always check strlen for value
    {
        t[i] = s[i]; // each char in s into t
    }*/

    strcpy(t, s); // don't need the loop

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

}

// There are other issues that can arise in the above code. Malloc and get_string can return a special character called "NULL"
// Nul is '\0' character. But NULL is a pointer to address zero. This is in the top LH corner of the memory that nothing is supposed to go in by convention
// What if in get_string you type in an antire essay and there isn't enough memory in the computer? How does get_string signal to programmer that's too much?
// get_string will return NULL if something goes wrong

int main(void)
{
    char *s = get_string("s: ");

    if(s == NULL)
    {
        return 1;
    }

    char *t = malloc((strlen(s) + 1)); // could also fail if you ask for too much memory

    if (t == NULL)
    {
        return 1;
    }

    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);  // Good to free the memory that you asked for when you are done
    // Not necessarily needed here because when the program is done, the memory is freed up automatically
    // But for programs that run all of the time, like Chrome or Word. Over time if the program is not called free, bad things happen

    return 0; // explicitly says that program ends succesfully

}

/* Valgrind */
// Tool that helps you find mistakes

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int)); //manual way of asking for enough memory for an array
    // int x[3]; gives you an array called x of size 3
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
}
// How to find these bugs with software
// May compile, but that doesnt mean that there aren't memory errors
// Valgrind can help you to find these errors

$ valgrind ./memory # run on things that have already been compiled

// not zero indexing so you are invalidly writing 4 bytes of memory to somewhere that you shouldn't be
// second solution is to free(x); at the end of the program. That way nothing is lost

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    if (x == NULL)
    {
        return 1;
    }

    x[0] = 72;
    x[1] = 73;
    x[2] = 33;

    free(x);
    return 0;
}


int main(void)
{
    int scores[1024]; // if you do not initialize an array with values, there will be "garbage" values there
    // These are remnants of the memory that has been used before

    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}

//garbage values-> if you don't give variables a value when initializing them, this can lead to garbage values

/* Pointer fun with Binky*/

int main(void)
{
    int *x;
    int *y;

    x = malloc(sizeof(int));

    *x = 42;
    //*y = 13; // what's bad about this line? We didn't ask for any space, so y was not initilizaed to anything
    // Inside of y is a garbage value

    y = x; // do this line instead

    *y = 13;
}

// if you want to swap the value of two variables, you have to make a temporary/dummy variable

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x , y);

    // but you get x is 1 and y is 2 for both
    // Since you are swapping them by value instead of reference/address, C has no capability of going to those locations and swapping the,
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
// really this is a problem of "scope"
// a and b only exist within the curly braces and not in main

// What happens when functions are called in C?
// Different things get put in different part of the CPU's memory
// When you open or run a program, you are loading the machine code of the program into the computer's memory from the computer's hardrive
// It is put in the machine code arear
// Below that is in the globals (outisde of main)
// heap -> heap of memory that can be used. This is where malloc grabs memory. Initially there is nothing in here. There is just a bunch of free space
// Malloc carves out from this area and keeps track of which bytes have already been allocated
// This grows downwards the more amount of memory you use
// There is another chunck of memory called stack, and this grows upwards
// stack is where functions have variables and arguments stored temporarily.
// This is why you can have a segment error if you recurse too many times in a function and the heap and stack collide

// When you call the main function of any program, it is allocated to a slice of memory (called a frame) to the bottom of the stack
// first main will be placed in the memory
// The main calls swap which has all of those variable. When it is done exectued, the memory is automatically freed up
// Technically it's there and is where you can get garbage values from when you use the same memory
// main has two variables, x and y
// Swap gets a new slice of memory, and x gets copied into a and y gets copied into b, b gets a copy into tmp.
// but x and y are still untouched which is why nothing happens when you try to swap them




void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// a is the address of an integer. Tmp is the same as before, but if you want to get the value at a, you do *a. This goes to the address and grabs the value 1
// in main, you would also have to add the & so that you can get the address of x and y
 swap(&x, &y);


/* Overflow */

// heap overflow and stack overflow -> when yout overflow out of memory here and start touching things not supposed to
// buffer overflow ->

// get_string, get_char, get_int, etc. -> hard to get user input without buffer overflow

// how can we do this without the cs50 library

int main(void)
{
    int x;
    printf("x: ");
    scanf("%i", &x); // need to tell scanf where to put user's integer from the keyboard.
    // &x now has a treasure map to the location of x and can now change it
    printf("x: %i\n", x);
}
// get_int is easy to implement (also has a feature where reprompted if user does not entre an int), but not as easy for strings
// because how do you know what the user will enter? And how long it will be?

int main(void)
{
    char *s = NULL;
    printf("s: ");
    scanf("%s", &s); // dont technically need an & for here like everything else. Because strings are an address
    printf("s: %s\n", s);
} // when you type in any string like "cat" or "dog", it prints out the 0
// This could be because it is just reading the NULL itself. is in initilialized to null
// You didn't request actual memory to store the cat or dog. It is reading it into a garbage location
// you didn't request 4 or 10 bytes etc. -> this is what makes scanf difficult to use

int main(void)
{
    char s[4]; // now can write "cat"
    printf("s: ");
    scanf("%s", &s);
    printf("s: %s\n", s);
}

// Saves names and numbers to a CSV file

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a"); //variable called file that will point to a file on the hardrive and opens in append mode


    string name = get_string("Name: ");
    string number = get_string("Number: ");

    fprintf(file, "%s, %s\n", name, number); // lets you print things to a file

    fclose(file);
}

//BMP are maps of bits 