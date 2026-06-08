#ifndef BITWISE_H
#define BITWISE_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/*
===========================================================
Write a program to perform the following operations
on LSB/MSB and specific bits:

1. Set the LSB
2. Clear the LSB
3. Toggle the LSB

4. Set the MSB
5. Clear the MSB
6. Toggle the MSB

7. Set nth bit
8. Clear nth bit
9. Toggle nth bit
===========================================================
*/

void bitOps(uint16_t a , int n);



/*
===========================================================
Write a program to modify specific portions
of a given integer:

1. Set all bits in LSB byte

2. Set all bits in MSB byte

3. Set all bits in Least Significant Nibble

4. Set all bits in Most Significant Nibble

5. Set n bits to 1

6. Clear n bits

7. Toggle n bits
===========================================================
*/

void byteOps(uint16_t REG , int n);



/*
===========================================================
Write a program to check bit status:

1. Check whether LSB is set

2. Check whether MSB is set

3. Check whether nth bit is set
===========================================================
*/

void bitCheck(uint8_t x , int n);



/*
===========================================================
Write macros to:

1. Set nth bit

2. Clear nth bit

3. Toggle nth bit
===========================================================
*/

#define SETBIT(x,n)    (x |= (1<<n))

#define CLEARBIT(x,n)  (x &= ~(1<<n))

#define TOGGLEBIT(x,n) (x ^= (1<<n))



/*
===========================================================
Write a C program to count the number
of set bits in an unsigned integer.
===========================================================
*/

void setBits(uint16_t n);



/*
===========================================================
How can you count the number of set bits
in a floating point number?
===========================================================
*/

void floatBits(float f);



/*
===========================================================
Write a C program to:

1. Count number of bits set to 1

2. Compare different methods

3. Check whether 20th bit of a
   32-bit integer is set
===========================================================
*/

void method1(unsigned int n);

void method2(unsigned int n);

void check20(unsigned int n);



/*
===========================================================
Write a C program to check whether
a number is a power of 2.
===========================================================
*/

void powOf2(uint16_t m);



/*
===========================================================
Write a C program to determine whether
a number is odd or even using
bitwise operators.
===========================================================
*/

void oddEven(int n);



/*
===========================================================
Implement:

setbits(x,p,n,y)

Set n bits in x starting at position p
with rightmost n bits of y.
===========================================================
*/

unsigned setbits(unsigned x,
                 int p,
                 int n,
                 unsigned y);



/*
===========================================================
Given two integers A and B,
count the number of bits to be flipped
to convert A into B.
===========================================================
*/

void flipBits(int a, int b);



/*
===========================================================
Write a program to reverse all bits
in an integer.
===========================================================
*/

unsigned int reverseBits(unsigned int n);



/*
===========================================================
Write a program to reverse:

1. Bits at odd positions

2. Bits at even positions
===========================================================
*/

unsigned int swapOddEven(unsigned int n);



/*
===========================================================
Write a program to multiply
a number by 9 using bitwise shifts.
===========================================================
*/

int multiply9(int n);



/*
===========================================================
Write a program to determine
the size of an integer in bits
using bit shifts.
===========================================================
*/

void intSize();



/*
===========================================================
Write a program to convert
Little Endian to Big Endian.
===========================================================
*/

unsigned int endian(unsigned int n);


/*
===========================================================
1. Check Least Significant Bit (LSB)

Write a C program to check whether
the Least Significant Bit is set or not.

Example:
Input : 5  -> 0101
Output: LSB is set
===========================================================
*/

void checkLSB(uint8_t n);



/*
===========================================================
2. Check Most Significant Bit (MSB)

Write a C program to check whether
the Most Significant Bit is set or not.

Example:
Input : 128 -> 10000000
Output: MSB is set
===========================================================
*/

void checkMSB(uint8_t n);



/*
===========================================================
3. Get nth Bit

Write a C program to get the value
of the nth bit of a number.

Example:
Input : 10 -> 1010
Bit position : 2

Output: Bit 2 is 1
===========================================================
*/

void getNthBit(uint16_t n , int pos);



/*
===========================================================
4. Set nth Bit

Write a C program to set
(make 1) the nth bit.

Example:
Input : 8 -> 1000
Position : 0

Output: 9 -> 1001
===========================================================
*/

void setNthBit(uint16_t n , int pos);



/*
===========================================================
5. Clear nth Bit

Write a C program to clear
(make 0) the nth bit.

Example:
Input : 10 -> 1010
Position : 3

Output: 2 -> 0010
===========================================================
*/

void clearNthBit(uint16_t n , int pos);



/*
===========================================================
6. Toggle nth Bit

Write a C program to toggle
(flip) the nth bit.

Example:
Input : 10 -> 1010
Position : 1

Output: 8 -> 1000
===========================================================
*/

void toggleNthBit(uint16_t n , int pos);



/*
===========================================================
7. Get Highest Set Bit

Write a C program to find
the highest set bit position.

Example:
Input : 18 -> 10010

Output: Position 4
===========================================================
*/

void highestSetBit(uint16_t n);



/*
===========================================================
8. Get Lowest Set Bit

Write a C program to find
the lowest set bit position.

Example:
Input : 18 -> 10010

Output: Position 1
===========================================================
*/

void lowestSetBit(uint16_t n);



/*
===========================================================
9. Count Trailing Zeros

Write a C program to count
trailing zeros in binary.

Example:
Input : 40 -> 101000

Output: 3
===========================================================
*/

void trailingZeros(uint16_t n);



/*
===========================================================
10. Count Leading Zeros

Write a C program to count
leading zeros in 32-bit integer.

Example:
Input : 16

Output: 27
===========================================================
*/

void leadingZeros(uint32_t n);



/*
===========================================================
11. Flip All Bits

Write a C program to flip
all bits using bitwise operators.

Example:
Input : 5 -> 00000101

Output: 250 -> 11111010
===========================================================
*/

void flipAllBits(uint8_t n);



/*
===========================================================
12. Count Total Zeros and Ones

Write a C program to count
number of zeros and ones.

Example:
Input : 15 -> 00001111

Output:
Ones  = 4
Zeros = 4
===========================================================
*/

void countZerosOnes(uint8_t n);



/*
===========================================================
13. Rotate Bits

Write a C program to rotate bits
left or right.

Example:
Input : 16
Rotate left by 2

Output: 64
===========================================================
*/

void leftRotate(uint8_t n , int rot);

void rightRotate(uint8_t n , int rot);



/*
===========================================================
14. Decimal to Binary

Write a C program to convert
decimal to binary using bitwise ops.

Example:
Input : 13

Output: 1101
===========================================================
*/

void decToBinary(uint16_t n);



/*
===========================================================
15. Swap Two Numbers Using XOR

Write a C program to swap
two numbers using XOR.

Example:
a = 5
b = 9

Output:
a = 9
b = 5
===========================================================
*/

void swapXOR(int a , int b);



/*
===========================================================
16. Check Odd or Even

Write a C program to determine
whether a number is odd or even
using bitwise AND.

Example:
Input : 7

Output: Odd
===========================================================
*/

void oddEven(uint16_t n);


#endif
