/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

int grows ()
{
  int local = 6;
  printf ("heeeyyyooo here %p\n", &local);

  return 0;
}

int chunks ()
{
  void *i = malloc(7);
  void *j = malloc(7);

  printf ("i %p\n", i);
  printf ("j %p\n", j);

  return 0;
}

int main ()
{
    int local = 5;
    void *p = malloc(128);
    void *h = malloc(128);

    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of local is %p\n", &local);
    printf ("Address of p is %p\n", p);
    printf ("Address of p is now %p\n", h);

    grows();
    chunks();

    return 0;
}
