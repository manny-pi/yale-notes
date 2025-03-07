#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "decimal.h"

#define MAX_DIGIT (DECIMAL_BASE - 1)

// Return 1 if number includes a digit
// outside range 0..9. Return 0 otherwise.
static int
hasBadDigit(size_t precision, const char number[])
{
    for(size_t i = 0; i < precision; i++) {
        if(number[i] < 0 || number[i] > MAX_DIGIT) {
            return 1;
        }
    }
    // else
    return 0;
}

int 
decimalAdd(size_t precision, char augend[], const char addend[])
{
    // check for bad digits
    if(hasBadDigit(precision, augend) || hasBadDigit(precision, addend)) {
        return DECIMAL_BAD_DIGIT;
    }

    // do trial addition to check for overflow
    int carry = 0;
    for(size_t i = 0; i < precision; i++) {
        carry = (addend[i] + augend[i] + carry) / DECIMAL_BASE;
    }
    
    if(carry != 0) {
        return DECIMAL_OVERFLOW;
    }

    // no overflow, do the real addition
    carry = 0;
    int digitSum;

    for(size_t i = 0; i < precision; i++) {
        digitSum = augend[i] + addend[i] + carry;
        augend[i] = digitSum % DECIMAL_BASE;
        carry = digitSum / DECIMAL_BASE;
    }

    return DECIMAL_OK;
}

int
decimalSubtract(size_t precision, char minuend[], const char subtrahend[])
{
    // check for bad digits
    if(hasBadDigit(precision, minuend) || hasBadDigit(precision, subtrahend)) {
        return DECIMAL_BAD_DIGIT;
    }

    // do trial subtraction to check for underflow
    // carry is 0 if no carry, 1 if we carried a -1
    int carry = 0;
    for(size_t i = 0; i < precision; i++) {
        carry = (minuend[i] - subtrahend[i] - carry) < 0;
    }

    if(carry) {
        return DECIMAL_OVERFLOW;
    }

    // do real subtraction
    carry = 0;
    int digitDifference;

    for(size_t i = 0; i < precision; i++) {
        digitDifference = minuend[i] - subtrahend[i] - carry;
        
        // The extra parens tell gcc that we really
        // do want an assignment here.
        if((carry = (digitDifference < 0))) {
            digitDifference += DECIMAL_BASE;
        } 
        minuend[i] = digitDifference;
    }
    
    return DECIMAL_OK;
}

void
decimalPrint(size_t precision, const char number[])
{
    if(precision == 0) {
        // annoying corner case, we'll just handle it here
        printf("0");
    } else if(hasBadDigit(precision, number)) {
        printf(DECIMAL_BAD_OUTPUT);
    } else {

        size_t i;   // used in both loops, so declared outside

        // skip leading zeros
        for(i = precision - 1; number[i] == 0 && i > 0; i--);

        // because i is unsigned, we can't test i <= 0;
        // instead, we detect when it wraps around
        for(; i < precision; i--) {
            putchar('0' + number[i]);
        }
    }
}
