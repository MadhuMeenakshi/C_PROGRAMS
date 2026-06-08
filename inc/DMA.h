#ifndef DMA_H
#define DMA_H

/* Exercise 1 */
void allocateInteger(void);

/* Exercise 2 */
void integerArrayMalloc(void);

/* Exercise 3 */
void integerArrayCalloc(void);

/* Exercise 4 */
void compareMallocCalloc(void);

/* Exercise 5 */
void reallocArray(void);

/* Exercise 6 */
void dynamic2DArray(void);

/* Exercise 7 */
void dynamicStringInput(void);

/* Exercise 8 */
char *myStrdup(const char *str);

/* Exercise 9 */
void linkedListThreeNodes(void);

/* Exercise 10 */
void reverseDynamicArray(void);

/* Exercise 11 */
void acceptUntilEnter(void);

/* Exercise 12 */
void frequencyCounter(void);

/* Exercise 13 */
void memoryLeakDemo(void);

/* Exercise 14 */
void tokenizeString(void);

/* Exercise 15 */
void dynamicMenuArray(void);

/* Exercise 16 */
void safeMemoryAllocation(void);

/* Exercise 17 */

typedef struct
{
    char name[50];
    int age;
} Person;

void dynamicStructArray(void);

/* Exercise 18 */
void insertAtPosition(void);

/* Exercise 19 */
void arrayOfIntegerPointers(void);

/* Exercise 20 */
void fragmentationDemo(void);


/* Linked List Structure (Exercise 9) */

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

#endif