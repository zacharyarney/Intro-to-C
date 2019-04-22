#include <stdio.h>
#include <string.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    // reusing string_length from stings.c
    int len = strlen(y);
    for (int i = 0; i < len; i++) {
        // can also be x[i] = y[i]
        // maybe future Zach will be more comfortable with alternative syntax
        *(x + i) = *(y + i);
    }
    // could also be x[len + 1] = 0
    // below syntax doesn't need to add 1 becuase
    // you're adding on top of the first index
    *(x + len) = 0;
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    while (*str != '\0') {
        if (*str == c) {
            return str;
        }
        str++;
    }
    return NULL;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
// iterate through haystack to find char that matches needle
// when matching char is found iterate through following chars
// while less than length of needle to check for rest of needle
// if all chars match within range, return pointer
// if non-matching character found in range, break inner loop and move on
// only major difference here is the inner loop
char *find_string(char *haystack, char *needle)
{
    while (*haystack != '\0') {
        if (*haystack == *needle) {
            for (int i = 1; needle[i] != '\0'; i++) {
                if (haystack[i] != needle[i]) {
                    break;
                }
            }
            return haystack;
        }
        haystack++;
    }
    return NULL;
}

#ifndef TESTING
int main(void)
{
    char *hello = "hello";
    char *world= "world";
    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
