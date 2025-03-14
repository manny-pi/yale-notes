/*

Source: https://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#hw1-2022

Yale Notes, Assignment 8.2

Status #1: Almost complete. When the input contains a ' ', it swaps it with an ASCII character.
I suspect that I need to check my condition for swapping string.s

Status #2: Code finally works. Turns out I was ignoring a very elusive detail in the swap 
condition. Since this implementation considers the character *before* the incomming 
character for swapping, I also needed to check if it was a valid candidate.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    int c, mod = 7;
    bool swappable = false; // use to track when two characters can be swapped
    int pos;                // use to track current position in index
    char swapped_string[50];

    while (true)
    {
        pos = 0; // use to track current position in index

        printf("input> ");
        while ((c = fgetc(stdin)) != '\n' && pos < 49)
        {
            swapped_string[pos] = c;

            if ( pos > 0)
            {
                // some locale's consider spaces and tabs to be alphabetic characters
                if (isalpha(c) && islower(c) && !isblank(c))
                {
                    if (swappable == true) // kind of a weird place to put the other half of the condition...
                    {
                        if ((swapped_string[pos - 1] % mod) == (c % mod) && isalpha(swapped_string[pos - 1]))
                        {
                            swapped_string[pos] = swapped_string[pos - 1];
                            swapped_string[pos - 1] = c;
                            swappable = false;
                        }
                    } else {
                        swappable = true; // reset swappable so characters can be swapped again
                    }
                }
            }
            ++pos;
        }

        swapped_string[pos] = '\0';
        printf("ouptut: %s\n\n", swapped_string);

        while (pos >= 0) // zero-fill the array.
        {
            swapped_string[pos] = '\0';
            --pos;
        }
    }

    return 0;
}