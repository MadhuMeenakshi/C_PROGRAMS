#ifndef STRINGS_H
#define STRINGS_H

#include <stdio.h>
#include <string.h>

void reverseWords(char str[]);

void removeRepeated(char str[]);

void highestFreq(char str[]);

void lowestFreq(char str[]);

void reverseString(char str[]);

void removeSpaces(char str[]);

void replaceChar(char str[], char old, char newc);

void charFrequency(char str[]);

void firstWord(char str[], char word[]);

void removeWord(char str[], char word[]);

void countWords(char str[]);

void toggleCase(char str[]);

void removeLast(char str[], char ch);

void replaceFirst(char str[], char old, char newc);

void countWord(char str[], char word[]);

void palindrome(char str[]);

void lastOccurrence(char str[], char ch);

void trim(char str[]);

void firstOccurrence(char str[], char ch);

void allOccurrences(char str[], char word[]);

#endif