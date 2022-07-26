#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
// for leetcode
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

// optimal Solution to find the intersection of two linked list if exists else return null
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;
    ListNode *d1 = headA, *d2 = headB;
    while (d1 != d2)
    {
        if (d1 == NULL)
            d1 = headB;
        else
            d1 = d1->next;

        if (d2 == NULL)
            d2 = headA;
        else
            d2 = d2->next;
    }

    return d2;
}

void LinkedListTraversal(struct Node *head)
{
    struct Node *p = head;
    while (p->next != NULL)
    {
        printf("\n%d", p->data);
        p = p->next;
    }
    printf("\n%d", p->data);
}

// Remove all elements with matching data
struct Node *removeElements(struct Node *head, int val)
{
    struct Node *dummy = (struct Node *)malloc(sizeof(struct Node));
    dummy->next = head;
    struct Node *p = dummy;
    while (p != NULL)
    {
        if (p->next != NULL && p->next->data == val)
        {
            p->next = p->next->next;
        }
        else
        {
            p = p->next;
        }
    }

    return dummy->next;
}

// REVERSE LINKED BETWEEN GIVEN RANGE
struct Node *reverseBetween(struct Node *head, int m, int n)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct Node *dummy = (struct Node *)malloc(sizeof(struct Node));
    dummy->next = head;
    struct Node *p = dummy;
    struct Node *start = NULL;
    struct Node *end = NULL;
    int i = 0;

    while (p != NULL)
    {
        if (i == m - 1)
        {
            start = p;
        }
        else if (i == n)
        {
            end = p->next;
            break;
        }
        p = p->next;
        i++;
    }
    struct Node *prev = NULL;
    p = start->next;
    while (p != end)
    {
        struct Node *next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    start->next = prev;
    p = prev;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = end;

    return dummy->next;
}

// getMid element value;
int getMid(struct Node *head)
{
    struct Node *f = head; // fast
    struct Node *s = head; // slow
    while (f != NULL && f->next != NULL)
    {
        f = f->next->next;
        s = s->next;
    }
    int val = s->data;
    return val;
}
// here i am actually disecting and then joining the nodes instead of values
struct Node *insertionSortList(struct Node *head)
{
    struct Node *current = head;
    struct Node *sorted = NULL;

    while (current != NULL)
    {
        struct Node *next = current->next;
        struct Node *newNode = current;
        if (sorted == NULL || sorted->data >= newNode->data)
        {
            newNode->next = sorted;
            sorted = newNode;
        }
        else
        {
            current = sorted;
            // we r checking for current.next bcoz what if we dont hava any greater than it so we can put it at end
            while (current->next != NULL && current->next->data < newNode->data)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        current = next;
    }

    return sorted;
}
// here i am just changing the values in the node instead of nodes
struct Node *SelectionSortList(struct Node *head)
{
    struct Node *curr = head;

    while (curr != NULL)
    {
        struct Node *p = curr;
        struct Node *q = p->next;
        while (q != NULL)
        {
            if (p->data > q->data)
            {
                p = q;
            }
            q = q->next;
        }

        int temp = p->data;
        p->data = curr->data;
        curr->data = temp;

        curr = curr->next;
    }
    return head;
}

struct Node *InsertFromHead(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;

    head = newNode;

    return head;
}

struct Node *InsertInBetween(struct Node *head, int data, int index)
{
    int i = 0;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;

    struct Node *p = head;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    newNode->next = p->next;
    p->next = newNode;

    return head;
}

struct Node *InsertFromTail(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newNode;
    newNode->next = NULL;

    return head;
}

struct Node *DeleteFromHead(struct Node *head)
{
    struct Node *p = head;

    head = p->next;
    free(p);

    return head;
}

struct Node *DeleteInBetween(struct Node *head, int index)
{
    int i = 0;
    struct Node *p = head;
    struct Node *q = p->next;
    while (i != index - 1 && q->next != NULL)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *DeleteInBetweenV2(struct Node *head, int index)
{
    int i = 0;
    struct Node *p = head;

    while (i != (index - 1))
    {
        p = p->next;
        i++;
    }
    p = p->next->next;

    return head;
}

struct Node *DeleteFromTail(struct Node *head)
{
    struct Node *p = head;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;

    return head;
}

struct Node *UpdateInBetween(struct Node *head, int data, int index)
{
    int i = 0;
    struct Node *p = head;

    while (i != index && p->next != NULL)
    {
        p = p->next;
        i++;
    }
    if (i == index)
    {
        p->data = data;
    }
    return head;
}

int main()
{

    struct Node *head;
    struct Node *second;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = NULL;

    printf("\nInserting New Node From head\n");
    head = InsertFromHead(head, 5);
    LinkedListTraversal(head);

    printf("\nInserting New Node In between given Index \n");
    head = InsertInBetween(head, 39, 1);
    LinkedListTraversal(head);

    printf("\nInserting New Node from Tail\n");
    head = InsertFromTail(head, 44);
    head = InsertFromTail(head, 28);
    LinkedListTraversal(head);
    /*
    printf("\nDeleting from head\n");
    head=DeleteFromHead(head);
    LinkedListTraversal(head);

   printf("\nDeleting In between Linked List\n");
    DeleteInBetween(head,2);
    LinkedListTraversal(head);


    printf("\nDeleting From Tail\n");
    head=DeleteFromTail(head);
    LinkedListTraversal(head);

    */
    printf("\nUpdating In between in the linked list at given index\n");
    head = UpdateInBetween(head, 21, 3);

    LinkedListTraversal(head);

    printf("\nThe Mid Element is :%d", getMid(head));
    return 0;
}