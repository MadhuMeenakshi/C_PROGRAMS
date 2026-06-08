#ifndef POINTERS_H
#define POINTERS_H


#include <stdio.h>

/*
===========================================================
Question 1: Pointer Increment
Access and print the third element using
pointer arithmetic.
===========================================================
*/
void thirdElement(int arr[]);


/*
===========================================================
Question 2: Pointer Addition
Print the last element by adding an integer
to the pointer.
===========================================================
*/
void lastElement(int arr[]);


/*
===========================================================
Question 3: Pointer Subtraction
Find distance between two pointers.
===========================================================
*/
void pointerDistance(int arr[]);


/*
===========================================================
Question 4: Pointer Comparison
Compare two pointers and determine which
points to the earlier array element.
===========================================================
*/
void pointerCompare(int arr[]);


/*
===========================================================
Question 5: Traverse Array using Pointer Arithmetic
Print all elements without array indexing.
===========================================================
*/
void traverseArray(int arr[], int size);


/*
===========================================================
Question 6: Invalid Pointer Arithmetic
Demonstrate why adding two pointers is invalid.
===========================================================
*/
void invalidPointerArithmetic(void);


/*
===========================================================
Question 7: Pointer Arithmetic with Double
Print second element of double array.
===========================================================
*/
void doublePointerArithmetic(double arr[]);


/*
===========================================================
Question 8: Pointer Arithmetic and Array Bounds
Demonstrate out-of-bounds pointer access.
===========================================================
*/
void arrayBounds(void);


/*
===========================================================
Question 9: Reverse Array using Pointer Arithmetic
Reverse array in-place without indexing.
===========================================================
*/
void reverseArray(int arr[], int size);




#endif