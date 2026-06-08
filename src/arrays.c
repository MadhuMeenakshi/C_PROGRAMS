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

void removeDup(int a[],int n)
{
   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       {
           if(a[i]==a[j])
           {
               for(int k=0;k<n-1;k++)
               {
               a[j]=a[j+1];
               }
               n--;
               j--;
           }
       }
   }
}

void revArr(int a[], int start, int end)
{
    while(start<end)
    {
        int temp = a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
}

void lRotate(int a[],int n, int k)
{
    while(k--)
    {
    int temp = a[0];
   for(int i=0;i<n-1;i++)
   {
       a[i]=a[i+1];
         }
          a[n-1]=temp;
    }
}

void rRotate(int a[],int n, int k)
{
    while(k--)
    {
    int temp = a[n-1];
   for(int i=0;i<n-1;i++)
   {
       a[i]=a[i+1];
         }
          a[0]=temp;
    }
}

void rRotate(int a[],int n, int k)
{
    while(k--)
    {
    int temp = a[n-1];
   for(int i=n-1;i>0;i--)
   {
       a[i]=a[i-1];
         }
          a[0]=temp;
    }
}


void arrUnion(int a[],int b[], int n1 , int n2)
{
    for(int i=0;i<n1;i++)
    {
        printf("%d \n",a[i]);
    }
    for(int i=0;i<n2;i++)
    {
        int found=0;
        for(int j=i+1;j<n2;j++)
        {
            if(b[i]==a[j])
            {
                found=1;
                break;
            }
          
        }
          if(found==0)
        {
            printf("%d \n",b[i]);
        }
        
    }
}

void arrInt(int a[],int b[], int n1 , int n2)
{
    for(int i=0;i<n1;i++)
    {
       // printf("for loop 1\n");
        for(int j=0;j<n2;j++)
        {
           // printf("for loop 2\n");
            if(a[i]==b[j])
            {
               // printf("for loop 3\n");
                printf("%d \n",b[j]);
            }
        }
    }
}

void arrInt(int a[],int b[], int n1 , int n2)
{
    for(int i=0;i<n1;i++)
    {
        int found =0;
       // printf("for loop 1\n");
        for(int j=0;j<n2;j++)
        {
           if(a[i]==b[j])
            {
                found =1;
                
            }
            
        }
        if(found ==0)
            {
                printf("%d \n",a[i]);
            }
    }
}

void palind(int a[], int n)
{
     int flag=1;

    for(int i=0;i<n/2;i++)
    {
        if(a[i]!=a[n-1-i])
        {
            flag=0;
            break;
        }
    }

    if(flag)
        printf("Palindrome");
    else
        printf("Not palindrome");
    
}

void sumPair(int a[],int n , int sum)
{
    int pairCnt=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((a[i]+a[j])==sum)
            {
                pairCnt++;
            }
        }
    }
    printf("%d ",pairCnt);
    
}

void missingElement(int a[],int n )
{
    for(int i=0;i<n-1;i++)
    {
        
            //printf("loop 2 runs\n");
            if((a[i]+1)!=a[i+1])
            {
                printf("missing element is %d\n ",a[i]+1);
            }
        
    }
   
    
}

void duplicateCount(int a[],int n)
{
    int maxCount =0;
    for(int i=0;i<n;i++)
    {
        int duplicate =0;
        for(int j=0;j<i;j++)
        {
            if(a[i]==a[j])
            {
                duplicate =1;
                break;
            }
        }
        if(duplicate ==1 )
        {
            continue;
        }
        int count =1;
        for(int k=i+1;k<n;k++)
        {
            if(a[i]==a[k])
            {
                count++;
            }
        }
        printf("%d occured %d times\n",a[i],count);
    }
    
    
}

void negativeCount(int a[], int n)
{
    int count=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
            count++;
    }

    printf("Negative elements = %d",count);
}



void searchElement(int a[], int n, int key)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("Found at index %d",i);
            return;
        }
    }

    printf("Not found");
}

void secondLargest(int a[], int n)
{
    int largest=a[0];
    int second=-9999;

    for(int i=1;i<n;i++)
    {
        if(a[i]>largest)
        {
            second=largest;
            largest=a[i];
        }

        else if(a[i]>second && a[i]!=largest)
        {
            second=a[i];
        }
    }

    printf("Second largest = %d",second);
}

void diffMaxMin(int a[], int n)
{
    int max=a[0],min=a[0];

    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];

        if(a[i]<min)
            min=a[i];
    }

    printf("Difference = %d",max-min);
}

void sumEven(int a[], int n)
{
    int sum=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)
            sum+=a[i];
    }

    printf("Sum of even numbers = %d",sum);
}




void primeNumbers(int a[],int n)
{
    int flag =0;
    for(int i=0;i<n;i++)
    {
        flag =1;
    if(a[i]<=1)
    {
        flag =0;
    }
    for(int j=2;j<a[i];j++)
    {
        if((a[i]%j)==0)
        {
            flag =0;
            break;
        }
    }
        if(flag ==1)
        {
            printf("%d is prime\n",a[i]);
        }
        
    }
    
    
}

void splitArray(int a[], int n)
{
    int mid=n/2;

    printf("First half:\n");

    for(int i=0;i<mid;i++)
        printf("%d ",a[i]);

    printf("\nSecond half:\n");

    for(int i=mid;i<n;i++)
        printf("%d ",a[i]);
}

void segregate(int a[], int n)
{
    printf("Even numbers:\n");

    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)
            printf("%d ",a[i]);
    }

    printf("\nOdd numbers:\n");

    for(int i=0;i<n;i++)
    {
        if(a[i]%2!=0)
            printf("%d ",a[i]);
    }
}

void majority(int a[], int n)
{
    int count;

    for(int i=0;i<n;i++)
    {
        count=0;

        for(int j=0;j<n;j++)
        {
            if(a[i]==a[j])
                count++;
        }

        if(count>n/2)
        {
            printf("Majority element = %d",a[i]);
            return;
        }
    }

    printf("No majority element");
}

void leaders(int a[], int n)
{
    int flag;

    for(int i=0;i<n;i++)
    {
        flag=1;

        for(int j=i+1;j<n;j++)
        {
            if(a[j]>a[i])
            {
                flag=0;
                break;
            }
        }

        if(flag)
            printf("%d ",a[i]);
    }
}

void equilibrium(int a[], int n)
{
    int left,right;

    for(int i=0;i<n;i++)
    {
        left=0;
        right=0;

        for(int j=0;j<i;j++)
            left+=a[j];

        for(int j=i+1;j<n;j++)
            right+=a[j];

        if(left==right)
        {
            printf("Index = %d",i);
            return;
        }
    }
}

void secondSmallest(int a[], int n)
{
    int small=a[0];
    int second=9999;

    for(int i=1;i<n;i++)
    {
        if(a[i]<small)
        {
            second=small;
            small=a[i];
        }

        else if(a[i]<second && a[i]!=small)
        {
            second=a[i];
        }
    }

    printf("Second smallest = %d",second);
}

void subset(int a[], int b[], int n1, int n2)
{
    int found,flag=1;

    for(int i=0;i<n2;i++)
    {
        found=0;

        for(int j=0;j<n1;j++)
        {
            if(b[i]==a[j])
            {
                found=1;
                break;
            }
        }

        if(found==0)
        {
            flag=0;
            break;
        }
    }

    if(flag)
        printf("Subset");
    else
        printf("Not subset");
}

void sort012(int a[], int n)
{
    int temp;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}

void product(int a[], int n)
{
    int prod=1;

    for(int i=0;i<n;i++)
        prod*=a[i];

    printf("Product = %d",prod);
}

void maxDifference(int a[], int n)
{
    int maxDiff=a[1]-a[0];

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]-a[i]>maxDiff)
                maxDiff=a[j]-a[i];
        }
    }

    printf("Maximum difference = %d",maxDiff);
}

void minMax(int a[], int n)
{
    int min=a[0],max=a[0];

    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];

        if(a[i]<min)
            min=a[i];
    }

    printf("Min = %d\n",min);
    printf("Max = %d",max);
}

void closestZero(int a[], int n)
{
    int min=a[0]+a[1];
    int x=a[0],y=a[1];

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum=a[i]+a[j];

            if(abs(sum)<abs(min))
            {
                min=sum;
                x=a[i];
                y=a[j];
            }
        }
    }

    printf("%d %d",x,y);
}

void rearrange(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
            printf("%d ",a[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(a[i]>=0)
            printf("%d ",a[i]);
    }
}

void moveZero(int a[], int n)
{
    int temp[100];
    int k = 0;

    // Step 1: Copy all non-zero elements to the temp array
    for(int i = 0; i < n; i++)
    {
        if(a[i] != 0)
            temp[k++] = a[i];
    }

    // Step 2: Fill the rest of the temp array with zeros
    while(k < n)
        temp[k++] = 0;

    // Step 3: Copy the elements back from temp into the original array 'a'
    for(int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }
     for(int i = 0; i < n; i++)
    {
        printf("%d \n", temp[i]);
    }
}

void maxKsum(int a[], int n, int k)
{
    int max=0,sum;

    for(int i=0;i<=n-k;i++)
    {
        sum=0;

        for(int j=i;j<i+k;j++)
            sum+=a[j];

        if(sum>max)
            max=sum;
    }

    printf("Max sum = %d",max);
}

void rotate(int a[], int n, int k)
{
    int temp;

    while(k--)
    {
        temp=a[n-1];

        for(int i=n-1;i>0;i--)
            a[i]=a[i-1];

        a[0]=temp;
    }

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}

void longestSequence(int a[], int n)
{
    int count,max=1;

    for(int i=0;i<n;i++)
    {
        count=1;
        int num=a[i];

        while(1)
        {
            int found=0;

            for(int j=0;j<n;j++)
            {
                if(a[j]==num+1)
                {
                    found=1;
                    num++;
                    count++;
                    break;
                }
            }

            if(found==0)
                break;
        }

        if(count>max)
            max=count;
    }

    printf("Longest sequence = %d",max);
}

void missingTwo(int a[], int n)
{
    int max=n+2;

    for(int num=1;num<=max;num++)
    {
        int found=0;

        for(int i=0;i<n;i++)
        {
            if(a[i]==num)
            {
                found=1;
                break;
            }
        }

        if(found==0)
            printf("%d ",num);
    }
}