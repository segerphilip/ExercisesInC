/* Chapter 1 cards.c

Philip Seger, 1/28/17, SoftSys

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Read the input from a user, as well as the file, then
   write content to the file.
*/
int main(int argc, char const *argv[]) {
    // configure the filemode
    char *file_mode = "w";

    // A and I flags
    int ch;
    while ((ch = getopt(argc, argv, "a")) != -1) {
        switch (ch) {
            case 'a':
                file_mode = "a";
                break;
            case 'i':
                printf("-i is not implemented\n");
                break;
            default:
                fprintf(stderr, "Unknown option '%s'", optarg);
                return 1;
        }
    }

    // continue past flags
    argc -= optind;
    argv += optind;

    // read input

    // open files, either in append or overwrite mode
    FILE *file;
    int i;
    for (i=0; i<argc; i++) {
        file = fopen(argv[i], file_mode);
    }

    return 0;
}
