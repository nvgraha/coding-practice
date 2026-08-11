#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string key);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Check if program run with necessary (command-line) values
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Using only_digits function
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (only_digits(argv[1]) == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    // Print ciphertext
    printf("ciphertext: ");

    // Ciphering using rotate function
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char cipher = rotate(plaintext[i], key);
        printf("%c", cipher);
    }
    printf("\n");
    return 0;
}

// Check if every char in a 'string' is a digit
bool only_digits(string key)
{
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}

// Caesar’s cipher (rotate function) for each character in the plaintext:
char rotate(char c, int n)
{
    // Rotate the character if it's an uppercase
    if (isupper(c))
    {
        c = (c - 65) + n;
        c = (c % 26) + 65;
        return c;
    }
    // Rotate the character if it's a lowercase
    else if (islower(c))
    {
        c = (c - 97) + n;
        c = (c % 26) + 97;
        return c;
    }
    // Non-alphabetical characters remain unchanged
    else
    {
        return c;
    }
}
