/* Example code for Exercises in C.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

Edits by Philip Seger 4/24/17.

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void free_anything(int *p) {
    free(p);
}


int read_element(int *array, int index) {
    int x = array[index];
    return x;
}


int main ()
{
    // int never_allocated;
    int *free_twice = malloc (sizeof (int));
    int *use_after_free = malloc (sizeof (int));
    int *never_free = malloc (sizeof (int));
    int array1[100];
    int *array2 = malloc (100 * sizeof (int));

    // valgrind does not bounds-check static arrays
    // P: follow bounds of array.
    read_element(array1, 0);
    read_element(array1, 99);

    // but it does bounds-check dynamic arrays
    // P: leave as is
    read_element(array2, 0);
    read_element(array2, 99);

    // P: free array2 as we don't use again
    free(array2);

    // and it catches use after free
    // P: how about switching the order so it makes sense
    // free(use_after_free);
    // *use_after_free = 17;
    *use_after_free = 17;
    free(use_after_free);

    // never_free is definitely lost
    *never_free = 17;
    // P: free it!
    free(never_free);

    // the following line would generate a warning
    // free(&never_allocated);

    // but this one doesn't
    // P: cool, but let's throw that out
    // free_anything(&never_allocated);

    free(free_twice);
    // P: but why?!?
    // free(free_twice);

    // P: should be perf now
    return 0;
}
