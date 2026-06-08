#include "arrays.h"



int printArray(int arr[] , int n)
{
    if(n==0)
    {
        printf("n is 0\n");
        return 1;
    }
    printf("the elements in the array are\n");
for(int i=0;i<n;i++)
{
    printf("%d \n",arr[i]);
}
return 0;
}



int arrSum(int arr[],int n)
{
    if(n==0)
    {
        printf("n is 0\n");
        return 1;
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    printf("the sum of the elements is %d \n",sum);
    return 0;
}




int largeSmall(int a[],int n)
{
    if(n==0)
    {
        printf("n is 0\n");
        return 1;
    }
  int largest=a[0];
  int smallest=a[0];

  for(int i=0;i<n;i++)
  {
    if(a[i]>largest)
    {
        largest=a[i];
    }
    if(a[i]<smallest)
    {
        smallest=a[i];
    }
  }
  
  printf("the largest is %d , and the smallest is %d\n",largest,smallest);
  return 0;

}





int oddEvenCnt(int arr[],int n)
{
int oddCnt=0;
int eveCnt=0;
if(n==0||n<=2)
{
        printf("n is 0\n");
        return 1;
}

for(int i=0;i<n;i++)
{
    if(arr[i]!=0 &&arr[i]!=1)
    {
        
    if((arr[i]%2)==0)
    {
        eveCnt++;
    }
    else 
    oddCnt++;
    }
}
printf("%d odd numbers , %d even numbers ",oddCnt,eveCnt);

return 0;
}

int cpyElements(int arr[],int n)
{
    int brr[n];

    if(n <= 0)
    {
        printf("0 element array\n");
        return 1;
    }

    for(int i = 0; i < n; i++)
    {
        brr[i] = arr[i];
    }

    printArray(brr, n);
    return 0;
}


void insert(int arr[],int n,int pos,int val)
{
    
   for(int i=n;i>=pos;i--)
   {
       arr[n]=arr[n-1];
   }
   arr[pos]=val;
   n++;
    printArray(arr,n);
   
}

void delet(int a[],int n, int pos)
{
    for(int i=pos;i<n;i++)
   {
       a[i]=a[i+1];
   }
   n--;
   for(int i=0;i<n;i++)
   printArray(a,n);
}

void sortAscend (int a[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printArray(a,n);
    
}

void sortDscend (int a[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printArray(a,n);
    
}

void merge(int a[], int b[], int sizA, int sizB)
{
    int n = sizA + sizB;

    for(int i = 0; i < sizB; i++)
    {
        a[sizA + i] = b[i];
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}



void occur(int a[], int n)
{
    int occ[10];
    
    for(int i = 0; i < n; i++)
    {
        occ[i] = 0;
    }
    
    
    
    for(int i = 0; i < n; i++)
    {
        if(occ[i] == 1)
        {
            continue;
        }
        
        int cnt = 1;
        for(int j = i + 1; j < n; j++)
        {
            // FIX 1: Compare a[i] with a[j] instead of a[i+1]
            if(a[i] == a[j])
            {
                cnt++;
                occ[j] = 1; // FIX 2: Mark index j as visited, not i
            }
        }
        
        printf("%d occured %d times \n", a[i], cnt);
        
        
    }
    
}

