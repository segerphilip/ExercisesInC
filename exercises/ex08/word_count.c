/* Simple example using Glib to read a text file.

Assignment found here: https://github.com/AllenDowney/ExercisesInC/blob/master/exercises/ex08/ex08.md

Edits by Philip Seger. 4/10/17.

Comments: I should have used more than just a main method, however I did not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

// incrementer that just prints out the key and value pairs from the hashtable
void print(gpointer key, gpointer value, gpointer user_data) {
    printf("%s: %d\n", key, *(int*)value);
}

int main(int argc, char** argv) {
    // Always have to have Sci-Fi
    char* book = "MrSpaceship.txt";
    gchar* content;
    GError *error = NULL;
    int i = 0;

    // attempt to read txt file
    g_file_get_contents(book, &content, NULL, &error);

    // if reading the txt file fails, fail gracefully and cleanup
    if (error != NULL) {
        fprintf("Something has broken with file read, %s\n", error->message);
        g_error_free(error);
        return 1;
    }

    // clear out common characters and spaces
    g_strdelimit(content, "\n\t/*$.,!?\":()-", ' ');

    // split words on whitespace
    gchar** words = g_strsplit(content, " ", -1);

    // hashtable created for eventually storing a word and how often it appears
    // weird how we take these for granted in python
    GHashTable* word_count = g_hash_table_new(g_str_hash, g_str_equal);

    // iterate through words, check if they exist:
    // if so, increment the counter
    // if not, store a word counter combo
    while (words[i] != NULL) {
        int* lookup = (int*)g_hash_table_lookup(word_count, words[i]);
        int* count = malloc(sizeof(int));

        if (lookup) {
            *count = *lookup + 1;
            g_hash_table_replace(word_count, words[i], count);
        } else {
            *count = 1;
            g_hash_table_insert(word_count, words[i], count);
        }
        i++;
    }

    // print things nicely for every instance in the hash table
    // if I had extra time, this is where you would reorganize to print in
    // ascending or descending order
    g_hash_table_foreach(word_count, print, NULL);

    // delete old data and free it
    g_hash_table_destroy(word_count);
    g_free(content);

    return 0;
}
