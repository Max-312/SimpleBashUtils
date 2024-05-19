# Simple Bash Utils

Development of Bash utilities for working with text: cat, grep.

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [Introduction](#introduction)
2. [Chapter II](#chapter-ii) \
    2.1. [Information](#information)
3. [Chapter III](#chapter-iii) \
    3.1. [Part 1](#part-1-working-with-the-cat utility)  
    3.2. [Part 2](#part-2-working-with-the-grep utility)  

## Chapter I

## Introduction

In this project, you will get acquainted with the basic Bash utilities for working with texts in the C programming language and learn how to develop them. These utilities (cat and grep) are quite often used when working in a Linux terminal. As part of this project, you will also learn how Bash utilities are organized and learn the structural approach.  


## Chapter II

## Information

### Cat history

> cat was part of early versions of Unix, such as Version 1, and replaced pr, the PDP-7 utility, and Multics for copying a single file to the screen.

### Using cat

cat is one of the most commonly used commands in Unix-like operating systems. The command has three interrelated functions in relation to text files: displaying, merging copies of them, and creating new ones.

`cat [OPTION] [FILE]...`

### Cat options

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | - b (GNU: --number-nonblank) | numbers only non-empty strings |
| 2 | -e assumes and -v (GNU only: -E is the same, but without using -v) | also displays end-of-line characters as $ |
| 3 | -n (GNU: --number) | numbers all output lines |
| 4 | -s (GNU: --squeeze-blank) | compresses several adjacent empty lines |
| 5 | -t assumes and -v (GNU: -T is the same, but without using -v) | also displays tabs as ^I |

### Grep history 

 Thompson wrote the first version in PDP-11 assembly language to help Lee E. McMahon analyze the text of the Federalist Notes and determine the authorship of individual articles. The ed text editor (also created by Thompson) had regular expression support, but it couldn't be used for such a large amount of text, so Thompson extracted this code into a separate tool. He chose this name because in ed, the g/re/p command printed all the lines corresponding to a given pattern. 
grep was first included in Version 4 of Unix. Stating that it is "commonly referred to as a prototype software tool," McIlroy credited grep with "irrevocably introducing" Thompson's philosophy of tools into Unix.

### Using grep 

`grep [options] template [file_name]`

### Grep options 

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | - e | Template. |
| 2 | - i | Ignores case differences.  |
| 3 | - v | Inverts the meaning of the search for matches. |
| 4 | - c | Outputs only the number of matching lines. |
| 5 | - l | Outputs only matching files. |
| 6 | -n | Precedes each line of output with the line number from the input file. |
| 7 | - h | Outputs matching strings without prefixing them with file names. |
| 8 | - s| Suppresses error messages about non-existent or unreadable files. |
| 9 | - f file | Gets regular expressions from a file. |
| 10 | - o | Prints only matching (non-empty) parts of the matched string. |

## Chapter III


## Part 1. Working with the cat utility

The cat utility has been developed:
- It must support all flags (including GNU versions) specified [above](#cat options)
- The source, header and assembly files must be located in the src/cat directory/
- The final executable file should be located in the src/cat/ directory and named s21_cat

## Part 2. Working with the grep utility

The grep utility has been developed:
- Support for the following flags: `-e`, `-i`, `-v`, `-c`, `-l`, `-n`
- Only pcre or regex libraries can be used for regular expressions  
- The source, header and make files must be located in the src/grep directory/
- The final executable file should be located in the src/grep/ directory and named s21_grep
- Support for all flags, including: `-h`, `-s`, `-f`, `-o`
- Only pcre or regex libraries can be used for regular expressions  
- The source, header and make files must be located in the src/grep directory/
- The final executable file should be located in the src/grep/ directory and named s21_grep
- Support for all flags, including their paired combinations (for example, `-iv`, `-in`)
- Only pcre or regex libraries can be used for regular expressions
- The source, header and make files must be located in the src/grep directory/
- The final executable file should be located in the src/grep/ directory and named s21_grep