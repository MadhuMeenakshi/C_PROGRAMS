#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DMA.h"

void allocateInteger(void)
{
    int *ptr;

    ptr = malloc(sizeof(int));

    if(ptr == NULL)
    {
        printf("malloc failed\n");
        return;
    }

    *ptr = 10;

    printf("Value = %d\n", *ptr);

    free(ptr);
}

void integerArrayMalloc(void)
{
    int n;

    printf("Enter size : ");
    scanf("%d",&n);

    int *arr;

    arr = malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("malloc failed\n");
        return;
    }

    printf("Enter elements\n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Array Elements : ");

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");

    free(arr);
}

void integerArrayCalloc(void)
{
    int n;

    printf("Enter size : ");
    scanf("%d",&n);

    int *arr;

    arr = calloc(n,sizeof(int));

    if(arr == NULL)
    {
        printf("calloc failed\n");
        return;
    }

    printf("Default Values : ");

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");

    printf("Enter values\n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Array : ");

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");

    free(arr);
}

void compareMallocCalloc(void)
{
    int *mPtr;
    int *cPtr;

    int n = 5;

    mPtr = malloc(n * sizeof(int));
    cPtr = calloc(n,sizeof(int));

    if(mPtr == NULL || cPtr == NULL)
    {
        printf("Allocation failed\n");

        free(mPtr);
        free(cPtr);

        return;
    }

    printf("malloc values : ");

    for(int i=0;i<n;i++)
    {
        printf("%d ",mPtr[i]);
    }

    printf("\n");

    printf("calloc values : ");

    for(int i=0;i<n;i++)
    {
        printf("%d ",cPtr[i]);
    }

    printf("\n");

    free(mPtr);
    free(cPtr);
}

void reallocArray(void)
{
    int *arr;

    arr = malloc(2 * sizeof(int));

    if(arr == NULL)
    {
        printf("malloc failed\n");
        return;
    }

    printf("Enter first 2 elements\n");

    for(int i=0;i<2;i++)
    {
        scanf("%d",&arr[i]);
    }

    int *temp;

    temp = realloc(arr,5 * sizeof(int));

    if(temp == NULL)
    {
        printf("realloc failed\n");
        free(arr);
        return;
    }

    arr = temp;

    printf("Enter remaining 3 elements\n");

    for(int i=2;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Array : ");

    for(int i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");

    free(arr);
}



void dynamic2DArray(void)
{
    int rows, cols;

    printf("Enter rows and columns : ");
    scanf("%d %d",&rows,&cols);

    int **arr;

    arr = malloc(rows * sizeof(int *));

    if(arr == NULL)
    {
        printf("malloc failed\n");
        return;
    }

    for(int i=0;i<rows;i++)
    {
        arr[i] = malloc(cols * sizeof(int));

        if(arr[i] == NULL)
        {
            printf("malloc failed\n");
            return;
        }
    }

    printf("Enter matrix elements\n");

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("Matrix :\n");

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ",arr[i][j]);
        }

        printf("\n");
    }

    for(int i=0;i<rows;i++)
    {
        free(arr[i]);
    }

    free(arr);
}

void dynamicStringInput(void)
{
    char str[100];

    printf("Enter string : ");

    getchar();

    fgets(str,sizeof(str),stdin);

    str[strcspn(str,"\n")] = '\0';

    int len = strlen(str);

    char *copy;

    copy = malloc((len + 1) * sizeof(char));

    if(copy == NULL)
    {
        printf("malloc failed\n");
        return;
    }

    strcpy(copy,str);

    printf("Copied String : %s\n",copy);

    free(copy);
}

char *myStrdup(const char *str)
{
    int len = strlen(str);

    char *copy;

    copy = malloc((len + 1) * sizeof(char));

    if(copy == NULL)
    {
        return NULL;
    }

    int i = 0;

    while(str[i] != '\0')
    {
        copy[i] = str[i];
        i++;
    }

    copy[i] = '\0';

    return copy;
}

void linkedListThreeNodes(void)
{
    Node *n1;
    Node *n2;
    Node *n3;

    n1 = malloc(sizeof(Node));
    n2 = malloc(sizeof(Node));
    n3 = malloc(sizeof(Node));

    if(n1 == NULL || n2 == NULL || n3 == NULL)
    {
        printf("malloc failed\n");
        return;
    }

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    Node *temp = n1;

    printf("Linked List : ");

    while(temp != NULL)
    {
        printf("%d ",temp->data);

        temp = temp->next;
    }

    printf("\n");

    free(n1);
    free(n2);
    free(n3);
}

void reverseDynamicArray(void)
{
    int n;

    printf("Enter size : ");
    scanf("%d",&n);

    int *arr;

    arr = malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("malloc failed\n");
        return;
    }

    printf("Enter elements\n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int *left = arr;
    int *right = arr + n - 1;

    while(left < right)
    {
        int temp;

        temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }

    printf("Reversed Array : ");

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");

    free(arr);
}



void acceptUntilEnter(void)
{
    char *str = NULL;
    int size = 0;
    char ch;

    printf("Enter Text : ");

    while((ch = getchar()) != '\n')
    {
        size++;

        str = realloc(str,size + 1);

        if(str == NULL)
        {
            printf("realloc failed\n");
            return;
        }

        str[size - 1] = ch;
    }

    str[size] = '\0';

    printf("String : %s\n",str);

    free(str);
}

void frequencyCounter(void)
{
    int *freq;
    int n;
    int num;

    freq = calloc(100,sizeof(int));

    if(freq == NULL)
    {
        printf("calloc failed\n");
        return;
    }

    printf("Enter count : ");
    scanf("%d",&n);

    printf("Enter numbers between 0 and 99\n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);

        if(num >= 0 && num < 100)
        {
            freq[num]++;
        }
    }

    printf("Frequencies\n");

    for(int i=0;i<100;i++)
    {
        if(freq[i] > 0)
        {
            printf("%d -> %d\n",i,freq[i]);
        }
    }

    free(freq);
}

void memoryLeakDemo(void)
{
    int *ptr;

    ptr = malloc(5 * sizeof(int));

    if(ptr == NULL)
    {
        return;
    }

    for(int i=0;i<5;i++)
    {
        ptr[i] = i + 1;
    }

    printf("Memory allocated\n");

    /*
       Intentionally not freeing memory
       This creates a memory leak

       free(ptr);
    */
}

void tokenizeString(void)
{
    char str[200];
    char *token;
    char *words[50];
    int count = 0;

    printf("Enter Sentence : ");

    getchar();

    fgets(str,sizeof(str),stdin);

    str[strcspn(str,"\n")] = '\0';

    token = strtok(str," ");

    while(token != NULL)
    {
        words[count] = malloc(strlen(token) + 1);

        strcpy(words[count],token);

        count++;

        token = strtok(NULL," ");
    }

    printf("Words :\n");

    for(int i=0;i<count;i++)
    {
        printf("%s\n",words[i]);

        free(words[i]);
    }
}

void dynamicMenuArray(void)
{
    int *arr = NULL;
    int size = 0;
    int choice;
    int value;

    do
    {
        printf("\n1.Add\n");
        printf("2.Display\n");
        printf("3.Exit\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:

                printf("Enter Value : ");
                scanf("%d",&value);

                size++;

                arr = realloc(arr,size * sizeof(int));

                if(arr == NULL)
                {
                    printf("realloc failed\n");
                    return;
                }

                arr[size - 1] = value;

                break;

            case 2:

                printf("Array : ");

                for(int i=0;i<size;i++)
                {
                    printf("%d ",arr[i]);
                }

                printf("\n");

                break;

            case 3:

                break;

            default:

                printf("Invalid Choice\n");
        }

    }while(choice != 3);

    free(arr);
}



void safeMemoryAllocation(void)
{
    char *ptr;

    ptr = malloc(1024L * 1024L * 1024L);

    if(ptr == NULL)
    {
        printf("Allocation Failed\n");
        return;
    }

    printf("Allocation Successful\n");

    free(ptr);
}

void dynamicStructArray(void)
{
    int n;

    printf("Enter Number Of Persons : ");
    scanf("%d",&n);

    Person *p;

    p = malloc(n * sizeof(Person));

    if(p == NULL)
    {
        printf("malloc failed\n");
        return;
    }

    for(int i=0;i<n;i++)
    {
        printf("Enter Name : ");
        scanf("%s",p[i].name);

        printf("Enter Age : ");
        scanf("%d",&p[i].age);
    }

    printf("\nDetails\n");

    for(int i=0;i<n;i++)
    {
        printf("%s %d\n",p[i].name,p[i].age);
    }

    free(p);
}

void insertAtPosition(void)
{
    int n;
    int pos;
    int value;

    printf("Enter Size : ");
    scanf("%d",&n);

    int *arr;

    arr = malloc(n * sizeof(int));

    if(arr == NULL)
    {
        return;
    }

    printf("Enter Elements\n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter Position : ");
    scanf("%d",&pos);

    printf("Enter Value : ");
    scanf("%d",&value);

    arr = realloc(arr,(n + 1) * sizeof(int));

    if(arr == NULL)
    {
        return;
    }

    for(int i=n;i>pos;i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;

    n++;

    printf("Array : ");

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");

    free(arr);
}

void arrayOfIntegerPointers(void)
{
    int count;

    printf("Enter Count : ");
    scanf("%d",&count);

    int **arr;

    arr = malloc(count * sizeof(int *));

    if(arr == NULL)
    {
        return;
    }

    for(int i=0;i<count;i++)
    {
        arr[i] = malloc(sizeof(int));

        if(arr[i] == NULL)
        {
            return;
        }

        *arr[i] = (i + 1) * 10;
    }

    printf("Values : ");

    for(int i=0;i<count;i++)
    {
        printf("%d ",*arr[i]);
    }

    printf("\n");

    for(int i=0;i<count;i++)
    {
        free(arr[i]);
    }

    free(arr);
}

void fragmentationDemo(void)
{
    char *p1;
    char *p2;
    char *p3;
    char *p4;

    p1 = malloc(100);
    p2 = malloc(200);
    p3 = malloc(300);

    printf("Blocks Allocated\n");

    free(p2);

    printf("Middle Block Freed\n");

    p4 = malloc(150);

    if(p4 != NULL)
    {
        printf("New Block Allocated\n");
    }

    free(p1);
    free(p3);
    free(p4);
}