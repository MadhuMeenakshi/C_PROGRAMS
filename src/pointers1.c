#include <stdio.h>


// ===========================================================
// 8. NULL Pointer Safety
// ===========================================================

void nullPointerSafety(void)
{
    int *p = NULL;

    if(p != NULL)
    {
        printf("%d\n", *p);
    }
    else
    {
        printf("Pointer is NULL\n");
    }

    int a = 100;

    p = &a;

    if(p != NULL)
    {
        printf("Value = %d\n", *p);
    }
}


// ===========================================================
// 9. Passing Array to Function
// ===========================================================

void display(int *arr, int n)
{
    int *ptr = arr;

    while(ptr < arr + n)
    {
        printf("%d ", *ptr);

        ptr++;
    }

    printf("\n");
}


// ===========================================================
// 10. Visualizing Memory Addresses
// ===========================================================

void memoryAddresses(void)
{
    int a = 10;
    int b = 20;
    int c = 30;

    printf("&a = %p\n", (void*)&a);

    printf("&b = %p\n", (void*)&b);

    printf("&c = %p\n", (void*)&c);
}


// ===========================================================
// 11. Pointer to Pointer
// ===========================================================

void pointerToPointer(void)
{
    int a = 5;

    int *p = &a;

    int **pp = &p;

    printf("a    = %d\n", a);

    printf("*p   = %d\n", *p);

    printf("**pp = %d\n", **pp);
}


// ===========================================================
// 12. Garbage Pointer
// ===========================================================

void garbagePointerDemo(void)
{
    int *p;

    printf("Uninitialized Pointer Address = %p\n",
           (void*)p);

    printf("Do not dereference this pointer\n");

    int a = 50;

    p = &a;

    printf("Value = %d\n", *p);
}


// ===========================================================
// 13. Pointer Type Compatibility
// ===========================================================

void pointerTypeCompatibility(void)
{
    int x = 10;

    int *ip = &x;

    float *fp;

    // Compiler warning without cast
    fp = (float*)ip;

    printf("Address through int pointer   = %p\n",
           (void*)ip);

    printf("Address through float pointer = %p\n",
           (void*)fp);

    printf("Type casting performed\n");
}




    
