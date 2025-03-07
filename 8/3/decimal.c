/*

Source: https://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#hw1-2022

Yale Notes, Assignment 8.3

Status:
    I'm struggling just a little bit 
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include "decimal.h"

/*
Checks if a number contains a non-decimal digit; outside of range 0-9.
*/
static bool hasBadDigit(const char number[]);

int decimalAdd(size_t precision, char augend[], const char addend[])
{
}

int decimalSubtract(size_t precision, char minuend[], const char subtrahend[])
{
}

void decimalPrint(size_t precision, const char number[])
{
    for (int i = 0;;++i) {
        putchar('0' + number[i]);
    }
}

static bool hasBadDigit(const char number[])
{
    int i = 0;
    while (number[i] != '\0') 
    {
        if (!isnumber( (int) number[i])) {
            return true;
        }
    }
    return false;
}
