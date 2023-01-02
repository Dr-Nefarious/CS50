#include <cs50.h>
#include <stdio.h>

// Create a file th

int main (void){
    // Prompt user for their name and tell them hello
    string name = get_string("What's your name?: ");
    printf("Hello %s", name);
}