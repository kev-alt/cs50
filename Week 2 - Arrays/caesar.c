#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_valid_key(string key);
char caesar_encrypt(char c, int key);

int main(int argc, string argv[])
{
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", caesar_encrypt(plaintext[i], key));
    }

    printf("\n");
    return 0;
}

bool is_valid_key(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}

char caesar_encrypt(char c, int key)
{
    if (isalpha(c))
    {
        char base = isupper(c) ? 'A' : 'a';
        return (c - base + key) % 26 + base;
    }
    return c;
}
