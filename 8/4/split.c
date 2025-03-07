#include <stdio.h>
#include "split.h"

char *join(char **a, int c)
{
    return NULL;
}

char **split(const char *s, int c)
{
    printf("Input: %s\n", s);
    printf("Delim: %d\n", c);
    char k;
    for (int i = 0; (k = s[i]) != '\0'; ++i)
    {
        printf("...");
        printf("%c..", k);
    }
    return NULL;
}

void freeSplit(char **a)
{
}