#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s (as a pointer), return the number of 
    characters in the string.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s) 
{
    int i = 0;
    while (*s) {
        s = s + 1;
        i++;
    }
    return i;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char *rv, char *s) 
{
    // find length of string
    int len = string_length(s);
    // initialize pointer at end of string but before the null terminator
    char *p = s + (len - 1);
    // iterate through rv
    for (int i = 0; i < len; i++) {
        // sets value at rv[i] to current value of *p
        *(rv + i) = *p;
        // decrement position of p in string s
        p--;
    }
    // terminate reverse string!
    *(rv + len) = 0;
    return rv;
}

#ifndef TESTING
int main(void) 
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
    
