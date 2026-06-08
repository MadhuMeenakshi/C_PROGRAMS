#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *random;
} Node;

Node *createNode(int data);
void insertEnd(Node **head, int data);
void printList(Node *head);
int length(Node *head);
Node *mergeSortedLists(Node *head1, Node *head2);
int detectAndRemoveLoop(Node *head);
int isPalindrome(Node *head);
Node *copyRandomList(Node *head);
Node *findIntersection(Node *head1, Node *head2);
Node *partitionList(Node *head, int x);
Node *addTwoNumbers(Node *head1, Node *head2);
Node *rotateRight(Node *head, int k);
Node *swapKth(Node *head, int k);
Node *mergeSort(Node *head);
Node *nthFromEnd(Node *head, int n);
Node *mergeKLists(Node *lists[], int k);
Node *oddEvenRearrange(Node *head);
Node *pairwiseReverse(Node *head);
Node *reverseKGroup(Node *head, int k);
Node *reverseAlternateK(Node *head, int k);
void splitHalf(Node *head, Node **first, Node **second);
Node *mergeAlternate(Node *head1, Node *head2);
Node *interleaveLists(Node *head1, Node *head2);
Node *swapAdjacent(Node *head);

#endif /* LINKED_LISTS_H */
