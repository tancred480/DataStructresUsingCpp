#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};
struct Stack
{
    int top;
    int size;
    struct ListNode *stack;
    struct ListNode *tail;
};
int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
};
void push(struct Stack *ptr, int data)
{

    if (!isFull(ptr))
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (ptr->stack != NULL)
        {
            newNode->val = data;
            newNode->next = NULL;
            ptr->tail->next = newNode;
            ptr->tail = newNode;
        }
        else
        {
            newNode->val = data;
            newNode->next = NULL;
            ptr->stack = newNode;
            ptr->tail = newNode;
        }
        ptr->top++;
    }
    else
    {
        printf("\nStack is Full cant push\n");
    }
}
int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
void display(struct Stack *ptr)
{
    if (!isEmpty(ptr))
    {
        struct ListNode *p = ptr->stack;
        printf("\n");
        while (p != NULL)
        {
            printf("\t%d", p->val);
            p = p->next;
        }
    }
    else
    {
        printf("\nStack is Empty cant Display\n");
    }
}

int pop(struct Stack *ptr)
{
    if (!isEmpty(ptr))
    {
        struct ListNode *p = ptr->stack;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        int val = p->next->val;
        p->next = NULL;
        ptr->tail = p;

        ptr->top--;
        return val;
    }
    return -1;
}
int peek(struct Stack *ptr)
{
    if (!isEmpty(ptr))
    {
        return ptr->tail->val;
    }
    return -1;
}
int main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = -1;
    s->size = 5;

    push(s, 4);
    push(s, 6);
    push(s, 98);
    push(s, 12);
    push(s, 2);
    push(s, 34);
    display(s);
    pop(s);
    push(s, 34);
    display(s);
    printf("\nValue at top is :%d ", peek(s));
    return 0;
}