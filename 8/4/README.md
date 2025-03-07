# 8.4 Assignment 4 

The split.h header file below defines an interface for three functions `join`, `split`, and `freeSplit`.

The `split` function takes as arguments a null-terminated string and a separator character (represented as an int), returning an array of strings consisting of the substrings obtained by splitting the input string using the given separator character, followed by a null pointer to mark the end of the array. This can be used, for example, to split up a path name into its components: calling `split("/c/cs223/bin/submit", '/')` should return a six-element array of pointers to the strings `""`, `"c"`, `"cs223"`, `"bin"`, `"submit"`, followed by a null pointer (0). Note that consecutive occurrences of the separator may produce empty strings in the array: `split("////", '/')` should also return a six-element array, in which the last element is 0 and the rest of the elements are empty strings "".

The `join` function is the inverse of split: given an array returned by split, or an array with similar structure (like `argv`), it concatenates all the strings in the array together into a new string using the given separator in between each consecutive pair. In the special case where the separator is the null character `'\0'`, the strings are concatenated together with no character between them.

Each of these functions will need to use `malloc` to obtain space to store their return values. The `freeSplit` function should free any data allocated by `split`. A simple call to `free` should free any data allocated by `join`.

Your task is to provide a file `split.c` that implements all three functions in `split.h`.

```C
// Split and join operations for strings

// Given an array of pointers to strings,
// terminated by a null pointer, 
// concatenate them separated by character c,
// or no character if c is '\0'.
// Return the result as a malloc'd string.
//
// Examples:
//
// char *a[] = { "ab", "cd", "efg", 0 };
// join(a, ':') returns "ab:cd:efg"
// join(a, '\0') returns "abcdefg"
//
char *join(char **a, int c);

// Reverse of join: given a string s containing
// separators c, construct an array of pointers
// to copies of substrings of s separated by c.
// A null pointer is used to mark the end of this array.
//
// If c is null, a copy of the entire string will be
// returned as the only substring.
//
// Return value may include malloc'd data that can
// be freed with freeSplit if not modified.
//
// Examples:
//
// split("a:b:c", ':') returns {"a", "b", "c", 0}
// split("a::bc", ':') returns {"a", "", "bc", 0}
// split("a::bc", '\0') returns {"a::bc", 0}
//
// (The initializer syntax in the return values
// is for illustration only.)
char **split(const char *s, int c);

// Free all space used by a, assuming a
// was returned by split() and not subsequently
// modified.
void freeSplit(char **a);
```
