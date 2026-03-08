
#include <stddef.h>
#include "scheduler.h"

void init_scheduler(Scheduler *s)
{
    init_queue(&s->q0);
    init_queue(&s->q1);
    init_queue(&s->q2);
}

void add_process(Scheduler *s, Process *p)
{
    p->current_queue = 0;
    enqueue(&s->q0, p);
}

Process* select_process(Scheduler *s)
{
    if(!is_empty(&s->q0))
        return dequeue(&s->q0);

    if(!is_empty(&s->q1))
        return dequeue(&s->q1);

    if(!is_empty(&s->q2))
        return dequeue(&s->q2);

    return NULL;
}

void demote_process(Scheduler *s, Process *p)
{
    if(p->current_queue < 2)
        p->current_queue++;

    if(p->current_queue == 0)
        enqueue(&s->q0, p);

    else if(p->current_queue == 1)
        enqueue(&s->q1, p);

    else
        enqueue(&s->q2, p);
}

void priority_boost(Scheduler *s)
{
    Process *p;

    while(!is_empty(&s->q1))
    {
        p = dequeue(&s->q1);
        p->current_queue = 0;
        enqueue(&s->q0, p);
    }

    while(!is_empty(&s->q2))
    {
        p = dequeue(&s->q2);
        p->current_queue = 0;
        enqueue(&s->q0, p);
    }
}