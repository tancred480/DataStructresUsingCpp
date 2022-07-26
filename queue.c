#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
} Queue;

Queue *createQueue()
{
    Queue *q;
    printf("Enter the Size of Queue :");
    scanf("%d", &q->size);
    q->arr = (int *)malloc(q->size * sizeof(int));
    q->f = q->r = -1;

    return q;
}
int isFull(Queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    return 0;
}
int isEmpty(Queue *q)
{
    if (q->f == q->r)
        return 1;
    return 0;
}
void enqueue(Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is FULL");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        q->size--;
    }
}
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty");
        return -1;
    }
    q->f++;
    q->size++;
    return q->arr[q->f];
}
void DisplayQueue(Queue *q)
{
    if (!isEmpty(q))
    {
        for (int i = q->f + 1; i <= q->r; i++)
        {
            printf("\n%d", q->arr[i]);
        }
    }
}
int main()
{
    Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 11);
    enqueue(q, 12);
    DisplayQueue(q);
    printf("\nDequeue :%d", dequeue(q));

    DisplayQueue(q);
    return 0;
}
