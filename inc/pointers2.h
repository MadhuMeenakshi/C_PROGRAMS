#ifndef POINTERS2_H
#define POINTERS2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pointerDeclarationDemo(void);

void arrayTraversal(int *arr,int n);
void reverseArray(int *arr,int n);

void doublePointerDemo(void);
void allocateMemory(int **ptr);

void swap(int *a,int *b);
void modifyArray(int *arr,int n);

void dynamicMemoryDemo(void);

void stringCopy(char *dest,const char *src);
void stringReverse(char *str);

void safeBufferDemo(void);

void matrixDisplay(int (*arr)[3],int rows);
void transposeMatrix(int (*arr)[3],int rows);

struct Student
{
    int id;
    char name[20];
};

void structureDemo(void);

void fileIODemo(const char *filename);

struct Node
{
    int data;
    struct Node *next;
};

void insertBegin(int data);
void insertEnd(int data);
void displayList(void);
void deleteNode(int key);

void reverseStringRec(char *start,char *end);
int recursiveSum(int *arr,int n);

#endif