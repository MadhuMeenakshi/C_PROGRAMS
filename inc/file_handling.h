#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

void createFile(void);
void displayFile(void);
void writeMultipleLines(void);
void readLinesToArray(void);
void appendLines(void);
void copyFile(void);
void deleteFileDemo(void);
void readWriteVariable(void);
void countLines(void);
void countWordsCharacters(void);
void displayAndCountLines(void);
void removeLine(void);
void modifyLine(void);
void replaceWord(void);
void toUpperFile(void);
void toLowerFile(void);
void capitalizeWords(void);
void reverseLines(void);
void encryptFile(void);
void decryptFile(void);
void joinFiles(void);
void mergeAlternateLines(void);
void appendFileToAnother(void);
int compareFiles(const char *file1,
                 const char *file2);
void listDirectoryFiles(const char *path);
long fileSize(const char *filename);
void lastModifiedTime(const char *filename);
void commonDirectoryPath(void);
void employeeDatabase(void);
void groceryInventory(void);
void commandLineSumToFile(int argc,
                          char *argv[]);
void countSemicolonLines(void);
void countBlankLines(void);

#endif