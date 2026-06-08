#ifndef fptrs_H
#define fptrs_H

#include <stdio.h>

/* Basic arithmetic functions */

int add(int x, int y);
int sub(int x, int y);
int div(int x, int y);
int multiply(int x, int y);

/* Recursive factorial using function pointer */

int fact(int n);

/* Chained function pointer example */

int doubleValue(int x);
int increment(int x);
int square(int x);

void chainedFunctions(void);

/* Function returning function pointer */

int subtract(int a, int b);

int (*getOperation(char *name))(int, int);

/* String operation functions */

void reverseString(char *str);
void toUpperCase(char *str);
void countVowels(char *str);

extern void (*stringOps[3])(char *);

/* Logging functions */

void consoleLog(char *msg);
void fileLog(char *msg);
void networkLog(char *msg);

/* Event handlers */

void buttonPressEvent(void);
void sensorTriggerEvent(void);

/* Interrupt handlers */

void timerInterrupt(void);
void keyboardInterrupt(void);
void errorInterrupt(void);

#endif