#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct
{
    char c;
    int i;
    float f;
} StructDemo;

typedef union
{
    char c;
    int i;
    float f;
} UnionDemo;

typedef struct
{
    unsigned error : 1;
    unsigned ready : 1;
    unsigned mode  : 2;
    unsigned spare : 4;
} StatusRegister;

typedef struct
{
    char a;
    int b;
    short c;
} PaddingDemo;

typedef void (*DriverFunc)(void);

typedef struct
{
    DriverFunc init;
    DriverFunc start;
} Driver;

typedef struct
{
    int id;
    char name[20];
} Student;

typedef struct
{
    int pin;
    char city[20];
} Address;

typedef struct
{
    int empId;
    Address addr;
    int samples[5];
} Employee;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void structureVsUnion(void);

void bitFieldDemo(void);

void structurePaddingDemo(void);

void initDriver(void);
void startDriver(void);
void functionPointerStructureDemo(void);

void dynamicMemoryStructureDemo(void);

void structurePointerDemo(void);

void nestedStructureDemo(void);

void passByValue(Student s);
void passByReference(Student *s);
Student createStudent(void);
void structuresAndFunctionsDemo(void);

void introductionToStructuresDemo(void);

void structureInitializationDemo(void);

void memoryLayoutDemo(void);

#endif