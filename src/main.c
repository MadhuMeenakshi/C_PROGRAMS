#include "arrays.h"

/*
 * Starts the program and reads input.
 * This function collects array data and calls the array functions.
 */
int main() {
    // Write C code here
   int n;    

printf("give the total number of array elements\n");
scanf("%d",&n);

int arr[n];

printf("enter %d elements\n",n);
for(int i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
   
}
printArray(arr,n);
arrSum(arr,n);






    return 0;
}