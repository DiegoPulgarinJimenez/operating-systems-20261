
#ifndef MLFQ_SCHEDULER_QUEUE_H
#define MLFQ_SCHEDULER_QUEUE_H

#include "process.h"

#define MAX_PROCESSES 100

typedef struct {

    Process *items[MAX_PROCESSES];

    int front;
    int rear;

} Queue;

void init_queue(Queue *q);
int is_empty(Queue *q);
void enqueue(Queue *q, Process *p);
Process *dequeue(Queue *q);

#endif //MLFQ_SCHEDULER_QUEUE_H