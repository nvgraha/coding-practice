#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(char t);
int count_words(char t);
int count_sentences(char t);
int grade(float l, float w, float s);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Initialize variables
    int letters = 0;
    int words = 1;
    int sentences = 0;

    // Count the number of letters, words, and sentences in the text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        letters += count_letters(text[i]);
        words += count_words(text[i]);
        sentences += count_sentences(text[i]);
    }

    // Compute the Coleman-Liau index
    int level = grade(letters, words, sentences);

    // Print the grade level
    if (level < 1)
        printf("Before Grade 1\n");
    else if (level >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %i\n", level);
}

int count_letters(char t)
{
    if (isalnum(t) != 0)
        return 1;
    else
        return 0;
}

int count_words(char t)
{
    if (isspace(t) != 0)
        return 1;
    else
        return 0;
}

int count_sentences(char t)
{
    if (t == '.' || t == '!' || t == '?')
        return 1;
    else
        return 0;
}

// Coleman-Liau index
int grade(float l, float w, float s)
{
    double index = 0.0588 * ((l * 100) / w) - 0.296 * ((s * 100) / w) - 15.8;
    return round(index);
}
