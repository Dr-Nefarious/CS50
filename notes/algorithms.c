// An array is made up of contiguous memory

// What if you have an array of numbers and want to know what position contains the integer 50?
// Computers can't just look at the array and have a "bird's eye view" of it like we can
// Computer has to individually check each position of the array and determine which one contains 50

// What if we want a bool that tells us (y/n) -> a number is present
// We need an algorithm to do this



//Linear search:
for each door from left to right
    if 50 is behind each door
        Return true
Return false

If you added if/else return false -> It would have returned false before finding the 50

for i from 0 to n-1
    if 50 is behind doors[i]
        Return true
Return false

// Binary search -> sort the array first
// Divide and conquer: dividing the problem in half

If no doors left
    Return false
If 50 behind middle door
    Return true
Else if 50 < middle door
    Search left half
Else if 50 > middle door
    Search right half

// Here's a better way of doing it
if no doors left
    Return false
If 50 is behind doors[middle]
    return true
else if 50 < doors[middle]
    search doors[0] through doors[middle - 1]
else if 50 > doors[middle]
    search doors[middle + 1] through doors[n - 1] // The last element of any array is always n-1 because we start counting at zero

/*Running time*/
(add graph)

// log2(n) refers to tearing the book in half over and over again

// big O notation -> You don't really care about the order of the smaller ones. O(n/2) becomes O(n) because if you have billions of pages, going two at a time
// won't make much of a difference than going one page at a time
// Tearing the book over and over again: O(log n)

// Common formulas for analyzing algorithms from slowest to fastest
O(n^2)
O(n log n)
O(n)   -> linear search: may take you as many as all the steps to find it
O(log n)  -> binary search
O(1) // Take a fixed number of steps or one step that never change no matter how big n is

//Omega is the symbol for describing the best case of the algorithms (lower bound)
// ** how few steps an algorithm takes
// If the 50 was in the first door opened, it would have been omega(1)
// Because only one step was needed

// If an algorithm has the identical upper and lower bound, you can use a theta
// An example is counting everyone in a room. You can't do much better/faster unless you skip people: theta(n)

/* search.c */
#include <cs50.h>
#include <stdio.h>

// This is a code implementation of linear search

int main(void)
{
    int  numbers[] = {20, 500, 10, 5, 100, 1, 50}; // This is a static array that doesn't change

    int n = get_int("Number: "); // Prompt user for a number
    for (int i = 0; i < 7; i++) // The array is 7 int long
    {
        if (numbers[i] == n) // n is the number the human typed in
        {
            printf("Found\n");
            return 0; // Zero means success
        }
    }
    printf("Not found\n");
    return 1; // any other number means failed
}

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        // In C, you cannot compare two strings using ==
        // String compare take two strings as input, and returns 0 if they are equal
        //

        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0; // This part is needed because if the element is in the array, you will print found and not found
            // Because the loop is still going.
            // Could use break instead, but return 0 is the easiest way to say that the program is done and to exit
        }
    }
    printf("Not found\n");
    return 1;
}

//Segmentation fault (core dumped) is there because the i < 7, but there are only 6 elements in the array
// The loop is iterating over something that isn't there
// Touched memory you shouldn't have by looping too far or used a negative number to get into your array or something

// In terminal -> $ echo $? Tells you what was returned

code phonebook.c

int main(void)
{
    string main[] = {"Carter", "David"};
    string numbers[] = {"+1-617-495-1000", "+1-949-468-2750"}; // To tie the numbers to the name

    string name = get_string("Name: "); // ASk the user for a name (Carter or David)
    for (int i = 0; i < 2; i++) // Dont actually hard code these numbers in
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", numbers[i]); // look up in one array the name, and then print from the other one the number
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
// In the ABOVE program, you are assuming that the arrays are going from left to right
// You need to keep the related information together more easily


/* Structs */
// arrays are lightweight data structure that allow you to clump the same datatypes together

// in C you can create your own data structures with their own names

// Can add the name and number to a new data structure called "person"
typedef struct
{
    // What you want inside of it
    string name;
    string number;
}
person; // Name of the structure

int main(void)
{
    person people[2]; // We want two people to exist inside of this array

    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].name = "+1-949-468-2750";

    string name = get_string("Name: ");
    for (int i = 0; i < 2; i++)  // Don't hardcode but the two is for the two people
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

/* Sorting */

// What if we want to sort this list of numbers?
    7 2 5 4 1 6 0 3
The input is the unsorted list and the output is the sorted (0 1 2 3 4 5 6 7)

// Selection sort- > you have to check each of them individually to see if they are the smallest
// You go through the numbers and get the smallest one (0)
// Then you go switch the numbers based on that until the numbers are all sorted

for i from 0 to n-1
    Find smallest number between numbers[i] and numbers[n-1]
    Swap smallest number with numbers[i]

// Bubble sort -> you swap the numbers (next to them) based on which is bigger
// Swap the pairs of number


// Bubble sort -> The largest numbers "bubble" to the top of the array
// Compares pairs of numbers to see which of the two are larger/smaller
// Swaps them if one is in the wrong position

Selection Sort
// If you have n numbers, you have to make n-1 comparisons
// To find 1, you have to make n-2 comparisons
(n-1) + (n-2) + (n-3)+...+ 1 -> n(n-1)/2 = n^2/2 -n/2
// As n gets larger, the n^2 will be the one that gets bigger faster
// So it's on the order of n^2 steps O(n^2)



// Even if the sort is already sorted (best case) -> It will still need to compare against each number (omega(n^2))
// Because you don't know if 0 is the smallest until you compare against all the other 7 numbers

Bubble sort
Repeat n-1 times
    for i from 0 to n-2
        if numbers[i] and numbers[i+1] out of order
            swap them
    If no swaps
        Quit

//why are we doing it from n-2 instead of n-1? Because you're looking at the ith person and the i-1th person.
//  You don't want to point your left finger at the last person. You want to point to the second to last person and compare them to the last person

 (n-1) x (n-1) -> n^2 -2n + 1 ->  on the order of n^2

 // What would the lower bound of bubble sort be? omega(n).
// If the numbers are already sorted, then you only have to pass through them once

// Bubble sort is still very slow O(n^2)

// Recursion -> refers to a function that can call itself on a smaller problem

If no doors left
    Return false
If number behind middle door
    Return true
Else if number < middle door
    Search left half
Else if number > middle door
    Search right half

// Search right/left half are the recursive parts of the function that are called over and over
//But it's on a small problem as you cut in half over and over and again


code iteration.C

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        // When i is 0, you print one brick, when i is 1, your print out two bricks
        {
            printf("#");
        }
        printf("\n");
    }
}

recursion.C

// How would we do the exact same thing recursively

void draw(int n);

int main(void)
{
    //draw(1);

}

void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
    draw(n + 1); // This will lay the bricks down from top to bottom (incorrect)
    // Makes an infinitely tall pyramid because there is nothing to stop the height
}

// Let's recursively create bricks

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);

}

void draw(int n)
{
    // Base case: Needed so that draw doesn't call itself infinitely times
    if (n <= 0)
    {
        return; // Ensures that the codes doesn't run forever
    }
    // A pyramid of height 4 is just a pyramid of height 3 plus another row
    draw(n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
    draw(n + 1);
}

/* Merge Sort */
// Cut the numbers in half, then sort them, and merge until the entire array is sorteed
// No going back and forth like the other algorithms

If only one number
    Quit // Base case
Else

Sort left half of numbers
Sort right half numbers
Merge sorted halves

// This is O(n log n)