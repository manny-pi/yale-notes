/*

Source: https://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#hw1-2022

Yale Notes, Assignment 8.2

Status: Almost complete. When the input contains a ' ', it swaps it with an ASCII character.
I suspect that I need to check my condition for swapping string.s
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    int c, mod = 7;
    char _;
    bool swappable = false; // use to track when two characters can be swapped
    int pos;            // use to track current position in index
    char swapped_string[50];

    while (true)
    {
        pos = 0;            // use to track current position in index

        printf("input> ");
        while ((c = fgetc(stdin)) != '\n' && pos < 49)
        {
            _ = (char)c;
            swapped_string[pos] = _;
    
            if (isalnum(c))
            {
                if (swappable == true)
                {
                    if ((swapped_string[pos - 1] % mod) == (c % mod))
                    {
                        swapped_string[pos] = swapped_string[pos - 1];
                        swapped_string[pos - 1] = _;
                        swappable = false;
                    }
                }
            }
            else
            {
                swappable = true;
            }
    
            pos += 1;
        }
        swapped_string[pos] = '\0';
        printf("ouptut: %s\n\n", swapped_string);

        while (pos >= 0)
        {
            swapped_string[pos] = '\0';
            --pos;
        }
    }

    return 0;
}