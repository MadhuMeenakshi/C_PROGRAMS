#ifndef STRINGS_H
#define STRINGS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void swapStrings(char str1[], char str2[]);

void sortStrings(char str[][20], int n);

void palindrome(char str[]);

void highestFreq(char str[]);

void removeDuplicate(char str[]);

void duplicateChars(char str[]);

void removeChars(char str1[], char str2[]);

void rotation(char str1[], char str2[]);

void reverseRecursion(char str[], int index);

void permutation(char str[], int l, int r);

void divideString(char str[], int n);

void firstNonRepeat(char str[]);

void containingWord(char arr[][20], int n, char word[]);

void reverseWords(char str[]);

void compress(char str[]);

void naiveSearch(char text[], char pattern[]);

void rabinKarp(char text[], char pattern[]);

void longestUnique(char str[]);

void interleavings(char str1[], char str2[],
                   char result[], int i, int j, int m, int n);

void anagram(char str1[], char str2[]);

void countWords(char str[]);

void stringToInt(char str[]);

void removeBandAC(char str[]);

void streamNonRepeat(char str[]);

void removeAdjacent(char str[]);

void secondHighestFreq(char str[]);

#endif