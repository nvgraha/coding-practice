from cs50 import get_string

# Prompt the user for some text
text = get_string("Text: ")

# Initialize variables
letters = 0
words = 1
sentences = 0

# Count the number of letters, words, and sentences in the text
for i in text:
    if i.isalpha():
        letters += 1
    elif i == " ":
        words += 1
    elif i == "." or i == "!" or i == "?":
        sentences += 1

# Coleman-Liau index
index = 0.0588 * (letters*100/words) - 0.296 * (sentences*100/words) - 15.8

# Print the grade level
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade ", round(index))
