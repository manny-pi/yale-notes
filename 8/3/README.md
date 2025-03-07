# 8.3 Assignment 3

## Overview

The `decimal.h` header file below defines an interface for three functions `decimalAdd`, `decimalSubtract`, and `decimalPrint` for working with binary-coded decimal values stored in arrays of chars, where each char contains the numeric value of one of the digits, stored in least-significant-digit-first (“little endian”) order.

Your task is to provide a file `decimal.c` that implements these functions so that their behavior matches their description in the comments in `decimal.h`. The arithmetic part of this implementation is likely to be straightforward, but you will need to pay attention to proper handling of errors.

*NOTE: See `testDecimal.c` for the souition*

```C
// Functions for doing arithmetic on
// arbitrary-precision decimal numbers.
//
// Each number is represented as an array
// of chars, one per digit,
// with the least significant digit first.
//
// For example, 123 would be stored in a[]
// with a[0] == 3, a[1] == 2, and a[2] == 1.

// Error codes
#define DECIMAL_OK (0)           // returned if operation succeeds
#define DECIMAL_OVERFLOW (1)     // returned if operation would overflow
#define DECIMAL_BAD_DIGIT (2)    // returned for digits outside 0..9

// Used to represent numbers with bad digits in the output.
#define DECIMAL_BAD_OUTPUT ("BAD")

// Base for arithmetic.
// This will not change, but is provided for convenience.
#define DECIMAL_BASE (10)

// Adds addend to augend,
// leaving result in augend.
// Argument precision gives size
// of both augend and addend.
//
// Returns DECIMAL_OK with no errors,
// DECIMAL_OVERFLOW if sum would overflow,
// DECIMAL_BAD_DIGIT if either argument
// includes a digit outside the range 0..9.
//
// If an error occurs, augend should not be changed.
int decimalAdd(size_t precision, char augend[], const char addend[]);

// Subtracts subtrahend from minuend,
// leaving result in minuend.
// Argument precision gives size of both
// minuend and subtrahend.
//
// Returns DECIMAL_OK with no errors,
// DECIMAL_OVERFLOW if result would be negative,
// DECIMAL_BAD_DIGIT if either argument
// includes a digit outside the range 0..9.
//
// If an error occurs, minuend should not be changed.
int decimalSubtract(size_t precision, char minuend[], const char subtrahend[]);

// Print number with given precision to stdout, omitting leading zeros.
// If number contains bad digits, print the string DECIMAL_BAD_OUTPUT.
void decimalPrint(size_t precision, const char number[]);
```

## Testing the assignment

We have provided a test harness `testDecimal.c` that can be compiled together with `decimal.c` to produce a runnable test program. When running this program, the first two arguments specify the precision and the test to run.

Some tests take additional arguments that provide inputs to particular functions. The print test takes one argument and calls testPrint on it. The add and sub tests take two arguments and will print the return value of `decimalAdd` or `decimalSubtract`, as well as calling decimalPrint on the two arrays after executing `decimalAdd` or `decimalSubtract`. The addHuge and subHuge tests take no arguments, but instead generate pseudorandom inputs using the precision as a seed. Otherwise their output is similar to the add and sub tests.

Here is an example of running testDecimal on some simple test cases:

```bash
$ ./testDecimal 12 empty
$ ./testDecimal 12 print 12345
12345
$ ./testDecimal 12 print Melville
BAD
$ ./testDecimal 12 add 12345 98765
0
111110
98765
$ ./testDecimal 5 add 12345 98765
1
12345
98765
./testDecimal: test add failed
$ ./testDecimal 12 add 12345 Melville
2
12345
BAD
./testDecimal: test add failed
$ ./testDecimal 12 sub 12345 98765
1
12345
98765
./testDecimal: test sub failed
$ ./testDecimal 12 sub 98765 12345
0
86420
12345
$ ./testDecimal 50 addHuge
0
40245711501906646519292776163101632940323710970989
22647134177517598577324389047941968387115159664553
$ ./testDecimal 50 subHuge
1
17598577324389047941968387115159664553208551306436
22647134177517598577324389047941968387115159664553
./testDecimal: test subHuge failed
```

You can also run the public test script in /c/cs223/Hwk3/test.public, which will grab decimal.c from your current working directory, or run /c/cs223/bin/testit 3 public to run the same test script on your submitted solution.
