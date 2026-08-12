# 💻 CS50x - Week 02: Arrays
## 🌟 Overview
This folder contains my solutions for Week 2 of Harvard's CS50x course, focusing on arrays in C programming. Week 2 dives into manipulating arrays, strings (as arrays of characters), command-line arguments, and basic algorithms. These exercises build foundational skills in data processing and problem-solving, preparing me for more complex C programming challenges. 🎉
## 🧩 Problem Sets
Below are the problem sets and labs included in this folder, with brief descriptions:
- **Scrabble**: A program that determines the winner of a Scrabble game by calculating word scores. It uses arrays to process characters and assign points based on letter values. 🔡
- **Readability**: A program that computes the reading level of text using the Coleman-Liau index, processing text as an array of characters to count letters, words, and sentences. 📖
- **Caesar**: A cipher program that encrypts text by shifting letters, using a command-line argument for the shift key. 🔏
- **Substitution**: A program that encrypts text using a substitution cipher, mapping letters to a provided key. 🗝️

## 📚 Learning Objectives
Through these assignments, I aimed to master the following concepts:
- **Arrays**: Declaring, initializing, and iterating over arrays to store and manipulate data.
- **Strings**: Treating strings as arrays of characters for tasks like text processing.
- **Command-Line Arguments**: Using `argc` and `argv` to handle program inputs.
- **Algorithms**: Implementing logic for scoring, counting, or encrypting data.
- **Memory Management**: Avoiding errors like buffer overflows by respecting array bounds.

## ⚙️ How to Run the Code
To compile and run the programs:
1. Ensure a C compiler (e.g., `clang`) is installed.
2. Clone the repository: `git clone https://github.com/nvgraha/coding-practice.git`
3. Navigate to the folder: `cd coding-practice/Week-02-Arrays`
4. Compile a program: `clang program_name.c -o program_name -lcs50`
5. Run it: `./program_name`
6. For programs requiring arguments (e.g., Caesar): `./caesar 14`

Use CS50 tools like `make` for compilation, `style50` for formatting, and `check50` for testing. 🛠️

## 💭 Reflections
Working on Week 2 was both challenging and rewarding! 🌟 Understanding strings as arrays of characters was a key insight, especially for problems like Readability and Scrabble. Handling command-line arguments in Caesar taught me how to make programs more dynamic. I faced challenges with edge cases (e.g., invalid inputs), but debugging with `debug50` helped me improve. These exercises boosted my confidence in C programming and problem-solving.
***
## 📂 Directory Structure
Here’s how the repository is organized:
```
Week-02-Arrays/
├── Problem-Set-02/
│   ├── scrabble.c
│   ├── readability.c
│   ├── caesar.c
│   ├── substitution.c
│   └── README.md
└── README.md
```

Thanks for checking out my CS50x project! Looking forward to diving into Algorithms and low-level programming in Week 3! 💻🚀
