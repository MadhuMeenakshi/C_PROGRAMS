#include "linked_lists.h"



Node *createNode(int data)
{
    Node *newNode =
    (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->random = NULL;

    return newNode;
}

void insertEnd(Node **head,int data)
{
    Node *newNode = createNode(data);

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;

    while(temp->next)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(Node *head)
{
    while(head)
    {
        printf("%d ",head->data);
        head = head->next;
    }

    printf("\n");
}

int length(Node *head)
{
    int count = 0;

    while(head)
    {
        count++;
        head = head->next;
    }

    return count;
}


Node *mergeSortedLists(Node *head1,
                       Node *head2)
{
    Node dummy;

    Node *tail = &dummy;

    dummy.next = NULL;

    while(head1 && head2)
    {
        if(head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
        }

        tail = tail->next;
    }

    if(head1)
    {
        tail->next = head1;
    }

    if(head2)
    {
        tail->next = head2;
    }

    return dummy.next;
}



int detectAndRemoveLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            break;
        }
    }

    if(fast == NULL || fast->next == NULL)
    {
        return 0;
    }

    slow = head;

    if(slow == fast)
    {
        while(fast->next != slow)
        {
            fast = fast->next;
        }

        fast->next = NULL;

        return 1;
    }

    while(slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;

    return 1;
}


int isPalindrome(Node *head)
{
    int arr[1000];

    int i = 0;

    Node *temp = head;

    while(temp)
    {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    int left = 0;
    int right = i - 1;

    while(left < right)
    {
        if(arr[left] != arr[right])
        {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}



Node *copyRandomList(Node *head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node *curr = head;

    while(curr)
    {
        Node *copy =
        createNode(curr->data);

        copy->next = curr->next;

        curr->next = copy;

        curr = copy->next;
    }

    curr = head;

    while(curr)
    {
        if(curr->random)
        {
            curr->next->random =
            curr->random->next;
        }

        curr = curr->next->next;
    }

    curr = head;

    Node *copyHead = head->next;

    while(curr)
    {
        Node *copy = curr->next;

        curr->next = copy->next;

        if(copy->next)
        {
            copy->next =
            copy->next->next;
        }

        curr = curr->next;
    }

    return copyHead;
}



Node *findIntersection(Node *head1,
                       Node *head2)
{
    int len1 = length(head1);

    int len2 = length(head2);

    int diff;

    if(len1 > len2)
    {
        diff = len1 - len2;

        while(diff--)
        {
            head1 = head1->next;
        }
    }
    else
    {
        diff = len2 - len1;

        while(diff--)
        {
            head2 = head2->next;
        }
    }

    while(head1 && head2)
    {
        if(head1 == head2)
        {
            return head1;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}


Node *partitionList(Node *head,
                    int x)
{
    Node lessDummy;
    Node greaterDummy;

    Node *less = &lessDummy;
    Node *greater = &greaterDummy;

    less->next = NULL;
    greater->next = NULL;

    while(head)
    {
        if(head->data < x)
        {
            less->next = head;
            less = less->next;
        }
        else
        {
            greater->next = head;
            greater = greater->next;
        }

        head = head->next;
    }

    greater->next = NULL;

    less->next = greaterDummy.next;

    return lessDummy.next;
}



Node *addTwoNumbers(Node *head1,
                    Node *head2)
{
    Node dummy;

    Node *tail = &dummy;

    dummy.next = NULL;

    int carry = 0;

    while(head1 || head2 || carry)
    {
        int sum = carry;

        if(head1)
        {
            sum += head1->data;
            head1 = head1->next;
        }

        if(head2)
        {
            sum += head2->data;
            head2 = head2->next;
        }

        carry = sum / 10;

        tail->next =
        createNode(sum % 10);

        tail = tail->next;
    }

    return dummy.next;
}



Node *rotateRight(Node *head,
                  int k)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    int len = 1;

    Node *tail = head;

    while(tail->next)
    {
        len++;
        tail = tail->next;
    }

    k = k % len;

    if(k == 0)
    {
        return head;
    }

    tail->next = head;

    int steps = len - k;

    Node *newTail = head;

    for(int i=1;i<steps;i++)
    {
        newTail = newTail->next;
    }

    Node *newHead = newTail->next;

    newTail->next = NULL;

    return newHead;
}



Node *swapKth(Node *head,
              int k)
{
    int n = length(head);

    if(k > n)
    {
        return head;
    }

    if((2*k - 1) == n)
    {
        return head;
    }

    Node *xPrev = NULL;
    Node *x = head;

    for(int i=1;i<k;i++)
    {
        xPrev = x;
        x = x->next;
    }

    Node *yPrev = NULL;
    Node *y = head;

    for(int i=1;i<n-k+1;i++)
    {
        yPrev = y;
        y = y->next;
    }

    if(xPrev)
    {
        xPrev->next = y;
    }

    if(yPrev)
    {
        yPrev->next = x;
    }

    Node *temp = x->next;

    x->next = y->next;

    y->next = temp;

    if(k == 1)
    {
        head = y;
    }

    if(k == n)
    {
        head = x;
    }

    return head;
}


static Node *sortedMerge(Node *a,
                         Node *b)
{
    if(a == NULL)
    {
        return b;
    }

    if(b == NULL)
    {
        return a;
    }

    Node *result;

    if(a->data <= b->data)
    {
        result = a;

        result->next =
        sortedMerge(a->next,b);
    }
    else
    {
        result = b;

        result->next =
        sortedMerge(a,b->next);
    }

    return result;
}

static void frontBackSplit(Node *source,
                           Node **front,
                           Node **back)
{
    Node *slow = source;
    Node *fast = source->next;

    while(fast)
    {
        fast = fast->next;

        if(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;

    *back = slow->next;

    slow->next = NULL;
}

Node *mergeSort(Node *head)
{
    if(head == NULL ||
       head->next == NULL)
    {
        return head;
    }

    Node *a;
    Node *b;

    frontBackSplit(head,
                   &a,
                   &b);

    a = mergeSort(a);

    b = mergeSort(b);

    return sortedMerge(a,b);
}


Node *nthFromEnd(Node *head,
                 int n)
{
    Node *first = head;
    Node *second = head;

    for(int i = 0; i < n; i++)
    {
        if(first == NULL)
        {
            return NULL;
        }

        first = first->next;
    }

    while(first)
    {
        first = first->next;
        second = second->next;
    }

    return second;
}


Node *mergeKLists(Node *lists[],
                  int k)
{
    if(k == 0)
    {
        return NULL;
    }

    Node *result = lists[0];

    for(int i = 1; i < k; i++)
    {
        result =
        mergeSortedLists(result,
                         lists[i]);
    }

    return result;
}



Node *oddEvenRearrange(Node *head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = even;

    while(even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}



Node *pairwiseReverse(Node *head)
{
    if(head == NULL ||
       head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;

    head = head->next;

    while(curr && curr->next)
    {
        Node *next = curr->next;
        Node *nextPair = next->next;

        next->next = curr;

        if(prev)
        {
            prev->next = next;
        }

        curr->next = nextPair;

        prev = curr;
        curr = nextPair;
    }

    return head;
}



Node *reverseKGroup(Node *head,
                    int k)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    int count = 0;

    while(curr && count < k)
    {
        next = curr->next;

        curr->next = prev;

        prev = curr;

        curr = next;

        count++;
    }

    if(next)
    {
        head->next =
        reverseKGroup(next, k);
    }

    return prev;
}

Node *reverseAlternateK(Node *head,
                        int k)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    int count = 0;

    while(curr && count < k)
    {
        next = curr->next;

        curr->next = prev;

        prev = curr;

        curr = next;

        count++;
    }

    if(head)
    {
        head->next = curr;
    }

    count = 0;

    while(curr && count < k - 1)
    {
        curr = curr->next;
        count++;
    }

    if(curr)
    {
        curr->next =
        reverseAlternateK(curr->next,
                          k);
    }

    return prev;
}




void splitHalf(Node *head,
               Node **first,
               Node **second)
{
    if(head == NULL)
    {
        *first = NULL;
        *second = NULL;
        return;
    }

    Node *slow = head;
    Node *fast = head->next;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *first = head;

    *second = slow->next;

    slow->next = NULL;
}




Node *mergeAlternate(Node *head1,
                     Node *head2)
{
    Node *p1 = head1;
    Node *p2 = head2;

    while(p1 && p2)
    {
        Node *next1 = p1->next;
        Node *next2 = p2->next;

        p1->next = p2;

        if(next1 == NULL)
        {
            break;
        }

        p2->next = next1;

        p1 = next1;
        p2 = next2;
    }

    return head1;
}


Node *interleaveLists(Node *head1,
                      Node *head2)
{
    Node dummy;

    Node *tail = &dummy;

    dummy.next = NULL;

    while(head1 && head2)
    {
        tail->next = head1;
        head1 = head1->next;
        tail = tail->next;

        tail->next = head2;
        head2 = head2->next;
        tail = tail->next;
    }

    while(head1)
    {
        tail->next = head1;
        head1 = head1->next;
        tail = tail->next;
    }

    while(head2)
    {
        tail->next = head2;
        head2 = head2->next;
        tail = tail->next;
    }

    return dummy.next;
}



Node *swapAdjacent(Node *head)
{
    if(head == NULL ||
       head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;

    head = head->next;

    while(curr && curr->next)
    {
        Node *next = curr->next;
        Node *nextPair = next->next;

        next->next = curr;

        if(prev)
        {
            prev->next = next;
        }

        curr->next = nextPair;

        prev = curr;
        curr = nextPair;
    }

    return head;
}




Node *createNode(int data)
{
    Node *newNode =
    (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->random = NULL;

    return newNode;
}

void insertEnd(Node **head,int data)
{
    Node *newNode = createNode(data);

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;

    while(temp->next)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(Node *head)
{
    while(head)
    {
        printf("%d ",head->data);
        head = head->next;
    }

    printf("\n");
}

int length(Node *head)
{
    int count = 0;

    while(head)
    {
        count++;
        head = head->next;
    }

    return count;
}


Node *mergeSortedLists(Node *head1,
                       Node *head2)
{
    Node dummy;

    Node *tail = &dummy;

    dummy.next = NULL;

    while(head1 && head2)
    {
        if(head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
        }

        tail = tail->next;
    }

    if(head1)
    {
        tail->next = head1;
    }

    if(head2)
    {
        tail->next = head2;
    }

    return dummy.next;
}



int detectAndRemoveLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            break;
        }
    }

    if(fast == NULL || fast->next == NULL)
    {
        return 0;
    }

    slow = head;

    if(slow == fast)
    {
        while(fast->next != slow)
        {
            fast = fast->next;
        }

        fast->next = NULL;

        return 1;
    }

    while(slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;

    return 1;
}


/nt isPalindrome(Node *head)
{
    int arr[1000];

    int i = 0;

    Node *temp = head;

    while(temp)
    {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    int left = 0;
    int right = i - 1;

    while(left < right)
    {
        if(arr[left] != arr[right])
        {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}



Node *copyRandomList(Node *head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node *curr = head;

    while(curr)
    {
        Node *copy =
        createNode(curr->data);

        copy->next = curr->next;

        curr->next = copy;

        curr = copy->next;
    }

    curr = head;

    while(curr)
    {
        if(curr->random)
        {
            curr->next->random =
            curr->random->next;
        }

        curr = curr->next->next;
    }

    curr = head;

    Node *copyHead = head->next;

    while(curr)
    {
        Node *copy = curr->next;

        curr->next = copy->next;

        if(copy->next)
        {
            copy->next =
            copy->next->next;
        }

        curr = curr->next;
    }

    return copyHead;
}



Node *findIntersection(Node *head1,
                       Node *head2)
{
    int len1 = length(head1);

    int len2 = length(head2);

    int diff;

    if(len1 > len2)
    {
        diff = len1 - len2;

        while(diff--)
        {
            head1 = head1->next;
        }
    }
    else
    {
        diff = len2 - len1;

        while(diff--)
        {
            head2 = head2->next;
        }
    }

    while(head1 && head2)
    {
        if(head1 == head2)
        {
            return head1;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}


Node *partitionList(Node *head,
                    int x)
{
    Node lessDummy;
    Node greaterDummy;

    Node *less = &lessDummy;
    Node *greater = &greaterDummy;

    less->next = NULL;
    greater->next = NULL;

    while(head)
    {
        if(head->data < x)
        {
            less->next = head;
            less = less->next;
        }
        else
        {
            greater->next = head;
            greater = greater->next;
        }

        head = head->next;
    }

    greater->next = NULL;

    less->next = greaterDummy.next;

    return lessDummy.next;
}



Node *addTwoNumbers(Node *head1,
                    Node *head2)
{
    Node dummy;

    Node *tail = &dummy;

    dummy.next = NULL;

    int carry = 0;

    while(head1 || head2 || carry)
    {
        int sum = carry;

        if(head1)
        {
            sum += head1->data;
            head1 = head1->next;
        }

        if(head2)
        {
            sum += head2->data;
            head2 = head2->next;
        }

        carry = sum / 10;

        tail->next =
        createNode(sum % 10);

        tail = tail->next;
    }

    return dummy.next;
}



Node *rotateRight(Node *head,
                  int k)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    int len = 1;

    Node *tail = head;

    while(tail->next)
    {
        len++;
        tail = tail->next;
    }

    k = k % len;

    if(k == 0)
    {
        return head;
    }

    tail->next = head;

    int steps = len - k;

    Node *newTail = head;

    for(int i=1;i<steps;i++)
    {
        newTail = newTail->next;
    }

    Node *newHead = newTail->next;

    newTail->next = NULL;

    return newHead;
}



Node *swapKth(Node *head,
              int k)
{
    int n = length(head);

    if(k > n)
    {
        return head;
    }

    if((2*k - 1) == n)
    {
        return head;
    }

    Node *xPrev = NULL;
    Node *x = head;

    for(int i=1;i<k;i++)
    {
        xPrev = x;
        x = x->next;
    }

    Node *yPrev = NULL;
    Node *y = head;

    for(int i=1;i<n-k+1;i++)
    {
        yPrev = y;
        y = y->next;
    }

    if(xPrev)
    {
        xPrev->next = y;
    }

    if(yPrev)
    {
        yPrev->next = x;
    }

    Node *temp = x->next;

    x->next = y->next;

    y->next = temp;

    if(k == 1)
    {
        head = y;
    }

    if(k == n)
    {
        head = x;
    }

    return head;
}


static Node *sortedMerge(Node *a,
                         Node *b)
{
    if(a == NULL)
    {
        return b;
    }

    if(b == NULL)
    {
        return a;
    }

    Node *result;

    if(a->data <= b->data)
    {
        result = a;

        result->next =
        sortedMerge(a->next,b);
    }
    else
    {
        result = b;

        result->next =
        sortedMerge(a,b->next);
    }

    return result;
}

static void frontBackSplit(Node *source,
                           Node **front,
                           Node **back)
{
    Node *slow = source;
    Node *fast = source->next;

    while(fast)
    {
        fast = fast->next;

        if(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;

    *back = slow->next;

    slow->next = NULL;
}

Node *mergeSort(Node *head)
{
    if(head == NULL ||
       head->next == NULL)
    {
        return head;
    }

    Node *a;
    Node *b;

    frontBackSplit(head,
                   &a,
                   &b);

    a = mergeSort(a);

    b = mergeSort(b);

    return sortedMerge(a,b);
}


Node *nthFromEnd(Node *head,
                 int n)
{
    Node *first = head;
    Node *second = head;

    for(int i = 0; i < n; i++)
    {
        if(first == NULL)
        {
            return NULL;
        }

        first = first->next;
    }

    while(first)
    {
        first = first->next;
        second = second->next;
    }

    return second;
}


Node *mergeKLists(Node *lists[],
                  int k)
{
    if(k == 0)
    {
        return NULL;
    }

    Node *result = lists[0];

    for(int i = 1; i < k; i++)
    {
        result =
        mergeSortedLists(result,
                         lists[i]);
    }

    return result;
}



Node *oddEvenRearrange(Node *head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = even;

    while(even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}



Node *pairwiseReverse(Node *head)
{
    if(head == NULL ||
       head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;

    head = head->next;

    while(curr && curr->next)
    {
        Node *next = curr->next;
        Node *nextPair = next->next;

        next->next = curr;

        if(prev)
        {
            prev->next = next;
        }

        curr->next = nextPair;

        prev = curr;
        curr = nextPair;
    }

    return head;
}



Node *reverseKGroup(Node *head,
                    int k)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    int count = 0;

    while(curr && count < k)
    {
        next = curr->next;

        curr->next = prev;

        prev = curr;

        curr = next;

        count++;
    }

    if(next)
    {
        head->next =
        reverseKGroup(next, k);
    }

    return prev;
}

Node *reverseAlternateK(Node *head,
                        int k)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    int count = 0;

    while(curr && count < k)
    {
        next = curr->next;

        curr->next = prev;

        prev = curr;

        curr = next;

        count++;
    }

    if(head)
    {
        head->next = curr;
    }

    count = 0;

    while(curr && count < k - 1)
    {
        curr = curr->next;
        count++;
    }

    if(curr)
    {
        curr->next =
        reverseAlternateK(curr->next,
                          k);
    }

    return prev;
}




void splitHalf(Node *head,
               Node **first,
               Node **second)
{
    if(head == NULL)
    {
        *first = NULL;
        *second = NULL;
        return;
    }

    Node *slow = head;
    Node *fast = head->next;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *first = head;

    *second = slow->next;

    slow->next = NULL;
}




Node *mergeAlternate(Node *head1,
                     Node *head2)
{
    Node *p1 = head1;
    Node *p2 = head2;

    while(p1 && p2)
    {
        Node *next1 = p1->next;
        Node *next2 = p2->next;

        p1->next = p2;

        if(next1 == NULL)
        {
            break;
        }

        p2->next = next1;

        p1 = next1;
        p2 = next2;
    }

    return head1;
}


/*                                                                 
   19. Interleave Two Lists
                                                                    */

Node *interleaveLists(Node *head1,
                      Node *head2)
{
    Node dummy;

    Node *tail = &dummy;

    dummy.next = NULL;

    while(head1 && head2)
    {
        tail->next = head1;
        head1 = head1->next;
        tail = tail->next;

        tail->next = head2;
        head2 = head2->next;
        tail = tail->next;
    }

    while(head1)
    {
        tail->next = head1;
        head1 = head1->next;
        tail = tail->next;
    }

    while(head2)
    {
        tail->next = head2;
        head2 = head2->next;
        tail = tail->next;
    }

    return dummy.next;
}



Node *swapAdjacent(Node *head)
{
    if(head == NULL ||
       head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;

    head = head->next;

    while(curr && curr->next)
    {
        Node *next = curr->next;
        Node *nextPair = next->next;

        next->next = curr;

        if(prev)
        {
            prev->next = next;
        }

        curr->next = nextPair;

        prev = curr;
        curr = nextPair;
    }

    return head;
}