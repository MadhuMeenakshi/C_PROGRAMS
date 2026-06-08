#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdio.h>

int printArray(int arr[] , int n);
int  arrSum(int arr[],int n);
int largeSmall(int a[],int n);
int oddEvenCnt(int arr[],int n);
int cpyElements(int arr[],int n);
void delet(int a[],int n, int pos);
void insert(int arr[],int n,int pos,int val);
void sortAscend (int a[],int n);
void sortDscend (int a[],int n);
void merge(int a[], int b[], int sizA, int sizB);
void occur(int a[], int n);

void occur(int a[], int n);

void removeDup(int a[], int n);

void secondLargest(int a[], int n);

void diffMaxMin(int a[], int n);

void lRotate(int a[], int n, int k);
void rRotate(int a[], int n, int k);

void sumEven(int a[], int n);

void primeNumbers(int a[], int n);

void duplicateCount(int a[], int n);

void splitArray(int a[], int n);

void segregate(int a[], int n);


// Worksheet 2

void arrUnion(int a[], int b[], int n1, int n2);

void arrInt(int a[], int b[], int n1, int n2);

void difference(int a[], int b[], int n1, int n2);

void palind(int a[], int n);

void sumPair(int a[], int n, int sum);

void missingElement(int a[], int n);

void majority(int a[], int n);

void kadane(int a[], int n);

void leaders(int a[], int n);

void equilibrium(int a[], int n);

void secondSmallest(int a[], int n);

void subset(int a[], int b[], int n1, int n2);

void sort012(int a[], int n);

void product(int a[], int n);

void maxDifference(int a[], int n);

void minMax(int a[], int n);

void occurrences(int a[], int n, int key);

void closestZero(int a[], int n);

void rearrange(int a[], int n);

void moveZero(int a[], int n);

void frequency(int a[], int n);

void maxKsum(int a[], int n, int k);

void rotate(int a[], int n, int k);

void longestSequence(int a[], int n);

void missingTwo(int a[], int n);

#endif /* ARRAYS_H */
