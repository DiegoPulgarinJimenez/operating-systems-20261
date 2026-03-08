
#include <stddef.h>
#include "queue.h"

void init_queue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}

int is_empty(Queue *q)
{
    return q->front == q->rear;
}

void enqueue(Queue *q, Process *p)
{
    if(q->rear >= MAX_PROCESSES)
        return;

    q->items[q->rear] = p;
    q->rear++;
}

Process* dequeue(Queue *q)
{
    if(is_empty(q))
        return NULL;

    Process *p = q->items[q->front];
    q->front++;

    if(q->front == q->rear)
    {
        q->front = 0;
        q->rear = 0;
    }

    return p;
}