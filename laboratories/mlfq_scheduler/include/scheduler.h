
#ifndef MLFQ_SCHEDULER_SCHEDULER_H
#define MLFQ_SCHEDULER_SCHEDULER_H

#include "queue.h"

#define Q0_QUANTUM 2
#define Q1_QUANTUM 4
#define Q2_QUANTUM 8
#define BOOST_INTERVAL 20

typedef struct {
	Queue q0;
	Queue q1;
	Queue q2;
} Scheduler;

void init_scheduler(Scheduler *s);
void add_process(Scheduler *s, Process *p);
Process* select_process(Scheduler *s);
void demote_process(Scheduler *s, Process *p);
void priority_boost(Scheduler *s);

#endif //MLFQ_SCHEDULER_SCHEDULER_H