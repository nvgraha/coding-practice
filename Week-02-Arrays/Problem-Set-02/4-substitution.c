#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool validate_key(string key);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Using validate_key function
    if (!validate_key(argv[1]))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Prompt user for plaintext
    string p = get_string("plaintext:  ");
    string key = argv[1];

    // Convert key to uppercase
    for (int i = 'A'; i <= 'Z'; i++)
    {
        key[i - 'A'] = toupper(key[i - 'A']) - i;
    }

    // Print ciphertext
    printf("ciphertext: ");

    // Encrypt plaintext to ciphertext using the corresponding index of the encryption key
    for (int i = 0, len = strlen(p); i < len; i++)
    {
        if (isalpha(p[i]))
        {
            p[i] = p[i] + key[p[i] - (isupper(p[i]) ? 'A' : 'a')];
            printf("%c", p[i]);
        }
        else
        {
            p[i] = p[i];
            printf("%c", p[i]);
        }
    }
    printf("\n");
    return 0;
}

// Function to make sure input in argv[1] is a 26 unique non-repeated alphabetic character
bool validate_key(string key)
{
    int len = strlen(key);
    if (len != 26)
        return false;

    int freq[26] = {0};
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
            return false;
        int index = toupper(key[i]) - 'A';
        if (freq[index] > 0)
        {
            printf("Key must not contain repeated character\n");
            return false;
        }
        freq[index]++;
    }
    return true;
}
