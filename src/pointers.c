    #include "pointers.h"


void thirdElement(int arr[])
{
    int *ptr = arr;

    ptr = ptr + 2;

    printf("Third element is %d\n", *ptr);
}


void lastElement(int arr[])
{
    int *ptr = arr;

    ptr = ptr + 4;

    printf("Last element is %d\n", *ptr);
}


void pointerDistance(int arr[])
{
    int *p1 = &arr[4];
    int *p2 = &arr[1];

    printf("Distance between pointers is %ld\n",
           p1 - p2);
}


void pointerCompare(int arr[])
{
    int *ptr1 = &arr[2];
    int *ptr2 = &arr[4];

    if(ptr1 < ptr2)
    {
        printf("Pointer ptr1 points to an earlier element than ptr2\n");
    }
    else
    {
        printf("Pointer ptr2 points to an earlier element than ptr1\n");
    }
}


void traverseArray(int arr[], int size)
{
    int *ptr = arr;

    while(ptr < arr + size)
    {
        printf("%d ", *ptr);

        ptr++;
    }

    printf("\n");
}


void invalidPointerArithmetic(void)
{
    printf("Error: Cannot add two pointers in C.\n");

    printf("Pointer addition is not defined.\n");

    /*
    int arr[5];

    int *p1 = &arr[1];

    int *p2 = &arr[3];

    int *p3 = p1 + p2; // INVALID
    */
}


void doublePointerArithmetic(double arr[])
{
    double *ptr = arr;

    ptr++;

    printf("Second element is %.1lf\n", *ptr);

    printf("Pointer increments by sizeof(double)\n");
}


void arrayBounds(void)
{
    int arr[] = {10,20,30};

    int *ptr = arr + 5;

    printf("Pointer created outside array bounds\n");

    printf("Dereferencing it causes undefined behavior\n");

    /*
    printf("%d", *ptr);
    */
}


void reverseArray(int arr[], int size)
{
    int *start = arr;

    int *end = arr + size - 1;

    while(start < end)
    {
        int temp = *start;

        *start = *end;

        *end = temp;

        start++;

        end--;
    }

    printf("Reversed array: ");

    int *ptr = arr;

    while(ptr < arr + size)
    {
        printf("%d ", *ptr);

        ptr++;
    }

    printf("\n");
}