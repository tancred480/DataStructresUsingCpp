#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void DoublyLinkedListTraversal(struct Node *head)
{

    struct Node *p = head;
    while (p->next != NULL)
    {
        printf("\nItem data next : %d ", p->data);
        p = p->next;
    }
    printf("\nItem data next : %d\n ", p->data);
    do
    {
        printf("\nItem data prev : %d ", p->data);
        p = p->prev;
    } while (p != NULL);
}

struct Node *InsertFromHead(struct Node *head, int data)
{
    struct Node *p = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    // important steps
    newNode->next = head;
    head->prev = newNode;

    newNode->prev = NULL;
    head = newNode;

    return head;
}

struct Node *InsertInBetween(struct Node *head, int data, int index)
{
    int i = 0;
    struct Node *p = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    newNode->next = p->next;
    newNode->prev = p;

    p->next->prev = newNode;
    p->next = newNode;

    return head;
}

struct Node *InsertFromTail(struct Node *head, int data)
{
    struct Node *p = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    while (p->next != NULL)
    {
        p = p->next;
    }
    newNode->prev = p;
    newNode->next = NULL;

    p->next = newNode;

    return head;
}

struct Node *DeleteFromHead(struct Node *head)
{ // just like pop_front
    struct Node *p = head;
    struct Node *q;
    q = p;
    p->next->prev = NULL;
    head = p->next;
    free(q);

    return head;
}

struct Node *DeleteInBetween(struct Node *head, int index)
{
    int i = 0;
    struct Node *p = head;
    struct Node *q = p->next;

    while (i != index - 1 && p->next != NULL)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    q->next->prev = p;
    free(q);
    return head;
}

struct Node *DeleteInBetweenV2(struct Node *head, int index)
{
    int i = 0;
    struct Node *p = head;

    while (i != index - 1 && p->next != NULL)
    {
        p = p->next;
        i++;
    }
    p->next = p->next->next;
    p->next->next->prev = p;

    return head;
}

struct Node *DeleteFromTail(struct Node *head)
{ // pop_back operation
    struct Node *p = head;
    struct Node *q = p->next;

    while (q->next != NULL)
    { // or p->next->next!=NULL
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    q->prev = NULL;
    free(q);

    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->prev = NULL;
    head->next = second;

    second->data = 2;
    second->prev = head;
    second->next = third;

    third->data = 3;
    third->prev = second;
    third->next = fourth;

    fourth->data = 4;
    fourth->prev = third;
    fourth->next = NULL;

    printf("\nAll Elements of Doubly");
    DoublyLinkedListTraversal(head);

    printf("\nDoubly Linked List Insertion from head");
    head = InsertFromHead(head, 33);
    DoublyLinkedListTraversal(head);

    printf("\nDoubly Linked List Insertion in Between at index 2");
    InsertInBetween(head, 12, 2);
    DoublyLinkedListTraversal(head);

    printf("\nDoubly Linked List Insertion from Tail");
    head = InsertFromTail(head, 98);
    DoublyLinkedListTraversal(head);
    /*
        printf("\nDeletion from head\n");
        head=DeleteFromHead(head);
        DoublyLinkedListTraversal(head);


        printf("\nDeletion In Between the list at index 2\n");
        head=DeleteInBetweenV2(head,2);
        DoublyLinkedListTraversal(head);
    */

    printf("\nDeletion From Tail\n");
    head = DeleteFromTail(head);
    DoublyLinkedListTraversal(head);
    return 0;
}