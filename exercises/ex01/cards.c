/* Chapter 1 progress

Philip Seger, 1/28/17, SoftSys

*/
#include <stdio.h>
#include <stdlib.h>

/*
*/
void get_input(char *card_name) {
    puts("Enter the card name: ");
    scanf("%2s", card_name);
}

/*
*/
int get_value(char *card_name) {
    int val = 0;
    switch (card_name[0]) {
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        default:
            val = atoi(card_name);
            if ((val < 1) || (val > 10)) {
                puts("I don't understand that value!");
                break;
            }
    }
    return val;
}

/* Increments the card count value.
val - Value of the inputted card
*count - Pointer to the count
*/
void increment_count(int val, int *count) {
    if ((val > 2) && (val < 7)) {
        *count = *count + 1;
    } else if (val == 10) {
        *count = *count - 1;
    }
    printf("Current count: %i\n", *count);
}

/* Main function which does card count of input.
*/
int main() {
    char card_name[3];
    int count = 0;
    int val;
    while (card_name[0] != 'X') {
        get_input(card_name);
        val = get_value(card_name);
        increment_count(val, &count);
    }
    return 0;
}
