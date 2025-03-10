#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "dictionary.h"

#define WORD_LENGTH 45

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./speller textfile\n");
        return 1;
    }

    char *dictionary = "dictionaries/large";
    if (!load(dictionary))
    {
        printf("Could not load %s.\n", dictionary);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        unload();
        return 1;
    }

    char word[WORD_LENGTH + 1];
    int index = 0;
    int misspell_count = 0;

    char c;
    while ((c = fgetc(file)) != EOF)
    {
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            word[index] = c;
            index++;
            if (index >= WORD_LENGTH)
            {
                word[WORD_LENGTH] = '\0';
                index = WORD_LENGTH;
            }
        }
        else if (index > 0)
        {
            word[index] = '\0';
            index = 0;

            if (!check(word))
            {
                printf("Misspelled: %s\n", word);
                misspell_count++;
            }
        }
    }

    fclose(file);
    printf("Misspelled words: %d\n", misspell_count);
    unload();
    return 0;
}
