#include "pointers2.h"

struct Node *head = NULL;

void pointerDeclarationDemo(void)
{
    int a = 10;
    float b = 2.5f;
    char c = 'A';

    int *ip = &a;
    float *fp = &b;
    char *cp = &c;

    printf("%d\n", *ip);
    printf("%.2f\n", *fp);
    printf("%c\n", *cp);

    int *ptr = malloc(5 * sizeof(int));

    for(int i=0;i<5;i++)
    {
        *(ptr+i) = i+1;
    }

    free(ptr);
}

void arrayTraversal(int *arr,int n)
{
    int sum = 0;

    for(int *p=arr;p<arr+n;p++)
    {
        printf("%d ", *p);
        sum += *p;
    }

    printf("\nSum = %d\n", sum);
}

void reverseArray(int *arr,int n)
{
    int *left = arr;
    int *right = arr+n-1;

    while(left < right)
    {
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

void allocateMemory(int **ptr)
{
    *ptr = malloc(sizeof(int));

    **ptr = 100;
}

void doublePointerDemo(void)
{
    int *p = NULL;

    allocateMemory(&p);

    printf("%d\n", *p);

    free(p);
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void modifyArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        *(arr+i) *= 2;
    }
}

void dynamicMemoryDemo(void)
{
    int *p = malloc(5*sizeof(int));

    if(p == NULL)
        return;

    p = realloc(p,10*sizeof(int));

    int *q = calloc(5,sizeof(int));

    free(p);
    free(q);
}

void stringCopy(char *dest,const char *src)
{
    while(*src)
    {
        *dest = *src;

        dest++;
        src++;
    }

    *dest = '\0';
}

void stringReverse(char *str)
{
    char *left = str;
    char *right = str + strlen(str) - 1;

    while(left < right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

void safeBufferDemo(void)
{
    char *buf = malloc(20);

    fgets(buf,20,stdin);

    printf("%s",buf);

    free(buf);
}

void matrixDisplay(int (*arr)[3],int rows)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ", *(*(arr+i)+j));
        }

        printf("\n");
    }
}

void transposeMatrix(int (*arr)[3],int rows)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=i+1;j<3;j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}

void structureDemo(void)
{
    struct Student *s;

    s = malloc(sizeof(struct Student));

    s->id = 1;

    strcpy(s->name,"Madhu");

    printf("%d %s\n",s->id,s->name);

    free(s);
}

void fileIODemo(const char *filename)
{
    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
        return;

    fseek(fp,0,SEEK_END);

    long size = ftell(fp);

    rewind(fp);

    char *buffer = malloc(size+1);

    fread(buffer,1,size,fp);

    buffer[size] = '\0';

    printf("%s",buffer);

    free(buffer);

    fclose(fp);
}

void insertBegin(int data)
{
    struct Node *newNode =
    malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = head;

    head = newNode;
}

void insertEnd(int data)
{
    struct Node *newNode =
    malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while(temp->next)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void displayList(void)
{
    struct Node *temp = head;

    while(temp)
    {
        printf("%d ", temp->data);

        temp = temp->next;
    }

    printf("\n");
}

void deleteNode(int key)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    while(temp)
    {
        if(temp->data == key)
        {
            if(prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);
            return;
        }

        prev = temp;
        temp = temp->next;
    }
}

void reverseStringRec(char *start,char *end)
{
    if(start >= end)
        return;

    char temp = *start;
    *start = *end;
    *end = temp;

    reverseStringRec(start+1,end-1);
}

int recursiveSum(int *arr,int n)
{
    if(n == 0)
        return 0;

    return *arr + recursiveSum(arr+1,n-1);
}