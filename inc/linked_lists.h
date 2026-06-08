#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *random;
}Node;


/* Utility Functions */

Node *createNode(int data);

void insertEnd(Node **head,int data);

void printList(Node *head);

int length(Node *head);


/* 1. Merge Sorted Lists */

Node *mergeSortedLists(Node *head1,
                       Node *head2);


/* 2. Detect and Remove Loop */

int detectAndRemoveLoop(Node *head);


/* 3. Palindrome Check */

int isPalindrome(Node *head);


/* 4. Deep Copy with Random Pointers */

Node *copyRandomList(Node *head);


/* 5. Find Intersection Point */

Node *findIntersection(Node *head1,
                       Node *head2);


/* 6. Partition Around X */

Node *partitionList(Node *head,
                    int x);


/* 7. Add Two Numbers */

Node *addTwoNumbers(Node *head1,
                    Node *head2);


/* 8. Rotate Right by K */

Node *rotateRight(Node *head,
                  int k);


/* 9. Swap Kth Node from Start and End */

Node *swapKth(Node *head,
              int k);


/* 10. Merge Sort */

Node *mergeSort(Node *head);


/* 11. Nth Node From End */

Node *nthFromEnd(Node *head,
                 int n);


/* 12. Merge K Sorted Lists */

Node *mergeKLists(Node *lists[],
                  int k);


/* 13. Odd Even Rearrangement */

Node *oddEvenRearrange(Node *head);


/* 14. Reverse Nodes in Pairs */

Node *pairwiseReverse(Node *head);


/* 15. Reverse in Blocks of K */

Node *reverseKGroup(Node *head,
                    int k);


/* 16. Reverse Alternate K Nodes */

Node *reverseAlternateK(Node *head,
                        int k);


/* 17. Split Into Two Halves */

void splitHalf(Node *head,
               Node **first,
               Node **second);


/* 18. Merge Alternate Nodes */

Node *mergeAlternate(Node *head1,
                     Node *head2);


/* 19. Interleave Two Lists */

Node *interleaveLists(Node *head1,
                      Node *head2);


/* 20. Swap Adjacent Nodes */

Node *swapAdjacent(Node *head);

#endif